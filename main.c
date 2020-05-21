#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "headers.h"
#include "functions.c"
/***********************************
Name: Brenden Nelson
Date: 10/12/18
Updated: 04/08/20
Description: Currently Takes 1 user through the game of yahtzee and determines the winnner.
***********************************/

int main(void)
{
	int sum = 0, option = 0, save = 0, reroll = 0, spot = 0, sum_u = 0, 
	sum_l = 0, turn = 0, turn2 = 0, round = 0, total_sum1 = 0, total_sum2 = 0;
	int valid = -1;

	int dice[5]; //5 dice that will be rolled by users
	int dice_count[7];//count how many of each number was rolled
	int whichs[5];//which dice user chooses to reroll

	int scorecard1[14];//user scorecard sums
	int scorecard2[14];//user scorecard sums
	int scorecard_parallel1[14];//tracks which spots have been used
	int scorecard_parallel2[14];//tracks which spots have been used


	print_menu();
	option = get_option();
	
	//print_rules();

	while (option == 1)
	{
		
		init_scorecard(scorecard1);
		init_scorecard(scorecard2);

		init_scorecard(scorecard_parallel1);
		init_scorecard(scorecard_parallel2);

		round = 1;
		while (round <= 13)//13 total rounds in the game
		{
			printf("\n\n\n\tRound %d, Good luck Player 1!!\n", round);
			init_dice(dice);
			init_dice_count(dice_count);

			roll_die(dice);
			turn = 1; //turn #1 for each round
			display_die_values(dice);

			sum = sum_dice(dice);
			printf("sum is %d\n", sum);
			count_dice(dice, dice_count);
			//display_count_dice(dice_count);

			while (turn < 3) //user can only reroll 2 times plus initial roll
			{
				
				save = ask_save_score();

				if (save == 0)
				{
					//not saving score
					init_dice(whichs);
					init_dice_count(dice_count);
					reroll = how_many_reroll();
					which_dice(whichs, reroll, dice);
					reroll_dice(dice, whichs);
					count_dice(dice, dice_count);
					++turn; //turns #2 and 3
					display_die_values(dice);
					sum = sum_dice(dice);
				}
				if (save == 1 || turn == 3)
				{	//force user here after 2 rerolls
					//saving score
					display_upper_section();
					display_lower_section();
					spot = which_spot();
					valid = valid_save_option(dice_count, spot, scorecard_parallel1);
					printf("valid = %d\n", valid);

					while (valid == -1)
					{	//if spot already taken
						//user must choose new spot
						spot = which_spot();
						valid = valid_save_option(dice_count, spot, scorecard_parallel1);
					}
					save_score(scorecard1, sum, valid, spot, dice_count, scorecard_parallel1);
					display_card(scorecard1);
					turn = 3;//set turn to 3 to jump out of turn loop and into next round loop
				}
			}
			printf("\n\n\n\tRound %d, Good luck Player 2!!\n", round);
			init_dice(dice);
			init_dice_count(dice_count);

			roll_die(dice);
			turn2 = 1;
			display_die_values(dice);

			sum = sum_dice(dice);
			printf("sum is %d\n", sum);
			count_dice(dice, dice_count);
			while (turn2 < 3) //user can only reroll 2 times plus initial roll
			{
				
				save = ask_save_score();

				if (save == 0)
				{
					//not saving score
					init_dice(whichs);
					init_dice_count(dice_count);
					reroll = how_many_reroll();
					which_dice(whichs, reroll, dice);
					reroll_dice(dice, whichs);
					count_dice(dice, dice_count);
					++turn2; //turns #2 and 3
					display_die_values(dice);
					sum = sum_dice(dice);
				}
				if (save == 1 || turn2 == 3)
				{	//force user here after 2 rerolls
					//saving score
					display_upper_section();
					display_lower_section();
					spot = which_spot();
					valid = valid_save_option(dice_count, spot, scorecard_parallel2);
					printf("valid = %d\n", valid);

					while (valid == -1)
					{	//if spot already taken
						//user must choose new spot
						spot = which_spot();
						valid = valid_save_option(dice_count, spot, scorecard_parallel2);
					}
					save_score(scorecard2, sum, valid, spot, dice_count, scorecard_parallel2);
					display_card(scorecard2);
					turn2 = 3;//set turn to 3 to jump out of turn loop and into next round loop
				}
			}

			++round;
		}
		//BOTH PLAYERS WILL HAVE FINISHED 13 ROUNDS
		//SCORES WILL BE CALCULATED AND WINNER DETERMINED

		//checking for bonus earned and adding bonus if earned
		//first player
		sum_u = sum_upper(scorecard1);
		sum_u = bonus_score_earned(sum_u);
		sum_l = sum_lower(scorecard1);
		total_sum1 = sum_u + sum_l;


		//second player
		sum_u = sum_upper(scorecard2);
		sum_u = bonus_score_earned(sum_u);
		sum_l = sum_lower(scorecard2);
		total_sum2 = sum_u + sum_l;

		//calculating winner
		display_scores(total_sum1, total_sum2);
		display_winner(total_sum1, total_sum2);

		option = One_more_game();
	}

	printf("Hope you enjoyed BUDDY\nPlay again sometime PAL\n");

	return 0;
}