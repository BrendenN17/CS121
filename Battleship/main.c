#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "pa6.h"
#include "pa6.c"
/*
Name: Brenden Nelson
Date: 11/1/18
Updated: 04/13/20
Description: Takes a user through a game of battleship with an ai as player 2
*/

//will keep a seperate board to record all user hits and misses
int main(void)
{
	int option = 0, first = 0, valid = 0, how = 0, shot = 0;
	int row_pt = 0, col_pt = 0;//starting coordinates for placing ships
	int direction = -1;//0 for horizontal, 1 for vertical
	int turn = 0;//helps alternate players
	char board[NUM_ROWS][NUM_COLS];//user game board
	char AIboard[NUM_COLS][NUM_ROWS];//AI game board
	char shipSymbol[] = {'c', 'b', 'r', 's', 'd'};
	int shiplength[] = {5, 4, 3, 3, 2};
	char *shipname[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
	char hits[] = "xxxxxxxxxxxxxxx";
	char misses[] = "oooooooooooooooo";
	bool isendgame = false;

	char ushotsboard[NUM_ROWS][NUM_COLS];
	char AIshotsboard[NUM_ROWS][NUM_COLS];

	welcome_screen();
	option = get_menu_option();
	while (option != 2)//loop until user chooses to quit
	{
		initialize_game_board(board);
		initialize_game_board(AIboard);
		initialize_game_board(ushotsboard);
		initialize_game_board(AIshotsboard);

		how = how_place_ships();
		if (how == 1)//manual placement
		{
			for (int i = 0; i < NUMSHIPS; i++)
			{
				printf("YOU ARE PLACING YOUR %s\n\n", shipname[i]);
				direction = get_direction();
				row_pt = get_start_row();
				col_pt = get_start_col();
				valid = check_valid_ship(board, row_pt, col_pt, shiplength[i], direction);
				printf("Valid = %d\n", valid);
				if (valid == 1)
				{
					manually_place_ships_on_board(board, shipSymbol[i], shiplength[i], direction, row_pt, col_pt);
				}
				else if (valid == 0)
				{
					printf("INVALID SPOT\n");
					printf("please try again!\n");
					i--;//stay on trying to place same ship
				}
				print_board(board);
				printf("\n");
			}
			//all ships validly placed by user now
			printf("\nUSER BOARD\n");
			print_board(board);
		}
		else if (how == 2)//random placement
		{
			for (int i = 0; i < NUMSHIPS; i++)
			{
				direction = gen_direction();
				row_pt = gen_start_row_pt(direction, shiplength[i]);
				col_pt = gen_start_col_pt(direction, shiplength[i]);
				//printf("row pt %d  col pt %d", row_pt, col_pt);
				valid = check_valid_ship(board, row_pt, col_pt, shiplength[i], direction);
				//printf("Valid = %d\n", valid);
				if (valid == 1)
				{
					randomly_place_ships_on_board(board, shipSymbol[i], shiplength[i], direction, row_pt, col_pt);
				}
				else if (valid == 0)
				{
					i--; //stay on trying to place same ship
				}
			}
			//all ships validly randomly placed now
			print_board(board);
		}
		//now want to place all AI ships on AIboard
		for (int i = 0; i < NUMSHIPS; i++)
		{
			direction = gen_direction();
			row_pt = gen_start_row_pt(direction, shiplength[i]);
			col_pt = gen_start_col_pt(direction, shiplength[i]);
			//printf("row pt %d  col pt %d", row_pt, col_pt);
			valid = check_valid_ship(AIboard, row_pt, col_pt, shiplength[i], direction);
			//printf("Valid = %d\n", valid);
			if (valid == 1)
			{
				randomly_place_ships_on_board(AIboard, shipSymbol[i], shiplength[i], direction, row_pt, col_pt);
			}
			else if (valid == 0)
			{
				i--; //stay on trying to place same ship
			}
		}
		//print_board(AIboard);
		first = select_who_starts_first();
		if (first == 0)
		{
			printf("user goes first\n\n");
			turn = 0;
		}
		if (first == 1)
		{
			printf("AI goes first\n\n");
			turn = 1;
		}
		while (isendgame == false)//main gameplay loop
		{
			if (turn % 2 == 0)//user turn
			{
				valid = 0;
				while(valid != 1)
				{
					row_pt = user_shot_row();
					col_pt = user_shot_col();
					valid = is_valid_shot(ushotsboard, row_pt, col_pt);
				}//valid is 1 upon exit
				shot = check_shot(AIboard, row_pt, col_pt);
				update_board(AIboard, row_pt, col_pt, shot);
				update_shots_board(ushotsboard, row_pt, col_pt, shot);
				//print_board(AIboard);
				printf("\nUSER SHOT BOARD\n");
				print_board(ushotsboard);

				++turn;
			}
			else if(turn % 2 == 1)//AI turn
			{
				valid = 0;
				while (valid != 1)
				{
					row_pt = ai_shot_row();
					col_pt = ai_shot_col();
					valid = is_valid_shot(AIshotsboard, row_pt, col_pt);
				}//valid is 1 upon exit
				shot = check_shot(board, row_pt, col_pt);
				update_board(board, row_pt, col_pt, shot);
				update_shots_board(AIshotsboard, row_pt, col_pt, shot);
				//print_board(board);
				printf("\nAI SHOT BOARD\n");
				print_board(AIshotsboard);

				++turn;
			}
			

		}
		



		option = play_again();
	}


	return 0;
}