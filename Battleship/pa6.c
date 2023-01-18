
/*
Function: welcome screen
Description: prints the welcome screen and rules to the user
parameteres: n/a
returns: n/a
*/
void welcome_screen(void)
{
	printf("\n\n\t\tWelcome to Battleship!!\n\n");
	printf("The object of the game is to sink all 5 of your opponents ships\n");
	printf("Start by secretly placing your fleet of 5 ships on your ocean grid\n");
	printf("Your ships cannot overlap but can be placed either vertically or horizontally\n");
	printf("You cannot place your ships diagonally or so that any part of the ship is off the board\n");
	printf("Do not change the position of your ships once the game has begun\n");
	printf("You and the AI will alternate turns, calling one shot per turn in an attempt to hit your oponents ship\n");
	printf("On your turn, pick a target on your opponents grid to shoot at\n");
	printf("If your shot lands on a spot your opponent has placed their ship then your shot is a hit!!\n");
	printf("If your shot hits a spot not occupied by your opponents ship then your shot is a miss\n");
	printf("After a hit or miss, your turn is over and it becomes the AIs turn\n");
	printf("Play alternates in this fashion until a winner is determined\n");
	printf("Once a ship has been hit on every peg, it has been sunk\n");
	printf("The first player to sink their opponents entire fleet of 5 ships wins the game!\n\n");

	printf("\t1. Play Battleship\n");
	printf("\t2. Exit\n");
}
/*
Function: get menu option
Description: gets the menu option from the user
parameteres: n/a
returns: option
*/
int get_menu_option()
{
	int option = 0;
	printf("\n\tplease select an option\n");
	while (option != 1 && option != 2)
	{
		scanf("%d", &option);
	}
	return option;
}
/*
Function: initialize game board
Description: sets the ai and user game board to ~ for all row and column points
parameteres: board and num rows adn columns
returns: n/a
*/
void initialize_game_board(char board[][NUM_COLS])
{
	for (int row_index = 0; row_index < NUM_ROWS; ++row_index)
	{
		for (int col_index = 0; col_index < NUM_COLS; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}
/*
Function: prints board
Description: prints the current board to the screen
parameteres: board and num rows and num cols
returns: n/a
*/
void print_board(char board[][NUM_COLS])
{
	for (int row_index = 0; row_index < NUM_ROWS; ++row_index)
	{
		for (int col_index = 0; col_index < NUM_COLS; ++col_index)
		{
			printf("%c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}
/*
Function: selects who goes first
Description: Randomly determines whether the user or the AI will start the game
parameteres: n/a
returns: first
*/
int select_who_starts_first()
{
	srand(time(NULL));
	int first = 0;
	first = rand() % 2;
	return first;
	//1 means ai, 0 means user
}
/*
Function: how place ships
Description: Asks the user how they want to place their ships on the board
parameteres: n/a
returns: place
*/
int how_place_ships()
{
	int place = 0;
	printf("How would you like to place your ships?\n");
	printf("Enter 1 for manual placement and 2 for random placement\n");
	while (place != 1 && place != 2)
	{
		scanf("%d", &place);
	}
	return place;
}
/*
Function: get direction
Description: gets the direction the user wishes to place their ships
parameteres: n/a
returns: direction
*/
int get_direction()
{
	int direction = -1;
	printf("please enter which direction you wish to place your ship\n");
	printf("0 for horizontal and 1 for vertical\n");
	while(direction != 0 && direction != 1)
	{
		scanf("%d", &direction);
	}
	return direction;
}
/*
Function: get start row point
Description: gets the starting point 
parameteres: row pt
returns: n/a
*/
int get_start_row()
{
	int row_pt = -1;
	while (row_pt > 9 || row_pt < 0)
	{
		printf("please enter a starting row number from 0-9.\n");
		scanf("%d", &row_pt);
	}
	return row_pt;
}

int get_start_col()
{
	int col_pt = -1;
	while (col_pt > 9 || col_pt < 0)
	{
		printf("please enter a starting col number from 0-9.\n");
		scanf("%d", &col_pt);
	}
	return col_pt;
}

/*
Function: checks valid ship
Description: checks to make sure the ship placement is valid
parameteres: board, wor, col, ship length and direction
returns: valid
*/
int check_valid_ship(char board[][NUM_COLS], int start_row_pt, int start_col_pt, int ship_length, int ship_direction)
{
	//printf("ship length is %d\n", ship_length);
	int valid = 1;
	if (ship_direction == HORIZONTAL)
	{
		for (int i = 0; i < ship_length; ++i)
		{
			if (board[start_row_pt][start_col_pt + i] != '~')
			{
				valid = 0;
			}
		}
	}
	else //verical
	{
		for (int i = 0; i < ship_length; ++i)
		{
			if (board[start_row_pt + i][start_col_pt] != '~')
			{
				valid = 0;
			}
		}
	}
	return valid;
}
/*
Function: manually place ships on board
Description: allows the user to choose where to place each ship by picking starting points
parameteres: board, rows, cols, ship symbol, ship length, direction, row pt, col pt
returns: n/a
*/
void manually_place_ships_on_board(char board[][NUM_COLS], char ship_symbols, int ship_length, int ship_direction, int start_row_pt, int start_col_pt)
{
	int i = 0;
	if (ship_direction == HORIZONTAL)
	{
		for (i = 0; i < ship_length; ++i)
		{
			board[start_row_pt][start_col_pt + i] = ship_symbols;
		}
	}
	else // vertical
	{
		for (i = 0; i < ship_length; ++i)
		{
			board[start_row_pt + i][start_col_pt] = ship_symbols;
		}
	}
}
/*
Function: generate direction
Description: generates a random direction 
parameteres: n/a
returns: dir
*/
int gen_direction()
{
	int dir = 0;
	dir = rand() % 2;
	return dir;
}
/*
Function: generate starting point
Description: generates a random starting point for ai ships or if user chooses random placement
parameteres: dir, length, row and col ptr
returns:n/a
*/
int gen_start_row_pt(int dir, int ship_length)
{
	int row = -1;
	if (dir == HORIZONTAL)
	{
		row = rand() % NUM_ROWS;
	}
	else //vertical
	{
		row = rand() % (NUM_ROWS - ship_length + 1);
	}
	return row;
}
/*
Function: generate starting point
Description: generates a random starting point for ai ships or if user chooses random placement
parameteres: dir, length, row and col ptr
returns:n/a
*/
int gen_start_col_pt(int dir, int ship_length)
{
	int col = -1;
	if (dir == HORIZONTAL)
	{
		col = rand() % (NUM_COLS - ship_length + 1);
	}
	else //vertical
	{
		col = rand() % NUM_COLS;
	}
	return col;
}
/*
Function: randomly place ships
Description: randomly places ships on the board 
parameteres: same as manual function parameters
returns: n/a
*/
void randomly_place_ships_on_board(char board[][NUM_COLS], char ship_symbols, int ship_length, int ship_direction, int start_row_pt, int start_col_pt)
{
	int i = 0;
	if (ship_direction == HORIZONTAL)
	{
		for (; i < ship_length; ++i)
		{
			board[start_row_pt][start_col_pt + i] = ship_symbols;
		}
	}
	else //vertical
	{
		for (i = 0; i < ship_length; ++i)
		{
			board[start_row_pt + i][start_col_pt] = ship_symbols;
		}
	}
}

/*
Function: user shot
Description: gets coordinates from the user to see where their shot hits
parameteres: 
returns: board shot row coordinates
*/
int user_shot_row()
{
	int row_pt = -1;
	while (row_pt >= NUM_ROWS || row_pt < 0)
	{
		printf("please enter the row number for your shot\n");
		scanf("%d", &row_pt);
	}
	return row_pt;
}
/*
Function: user shot
Description: gets coordinates from the user to see where their shot hits
parameteres: 
returns: board shot row coordinates
*/
int user_shot_col()
{
	int col_pt = -1;
	while (col_pt >= NUM_COLS || col_pt < 0)
	{
		printf("please enter the col number for your shot\n");
		scanf("%d", &col_pt);
	}
	return col_pt;
}
/*
Function: ai shot
Description: takes a random shot for the ai
parameteres: 
returns: board shot coordinates
*/
int ai_shot_row()
{
	int row_pt = -1;
	row_pt = rand() % 10;

	return row_pt;
}
/*
Function: ai shot
Description: takes a random shot for the ai
parameteres: 
returns: board shot coordinates
*/
int ai_shot_col()
{
	int col_pt = -1;
	col_pt = rand() % 10;

	return col_pt;
}

int is_valid_shot(char board[NUM_ROWS][NUM_COLS], int row_pt, int col_pt)
{
	int valid = 0;
	if (board[row_pt][col_pt] == '~')
	{
		valid = 1;
	}
	return valid;
}

/*
Function: update board
Description: updates the board including hit or miss
parameteres: board, row pt, col pt, shot
returns: n/a
*/
void update_shots_board(char board[][NUM_COLS], int row_pt, int col_pt, int shot)
{
	if (shot == 1) //hit
	{
		board[row_pt][col_pt] = '*';
	}
	else //miss
	{
		board[row_pt][col_pt] = 'm';
	}
}
void update_board(char board[][NUM_COLS], int row_pt, int col_pt, int shot)
{
	if (shot == 1) //hit
	{
		board[row_pt][col_pt] = '*';
	}
}
/*
Function: chceck shot
Description: checks to see whether the shot was a hit or a miss
parameteres: board, row pt col pt
returns: shot
*/
int check_shot(char board[][NUM_COLS], int row_pt, int col_pt)
{
	int shot = 0;
	if (board[row_pt][col_pt] == '~')
	{
		shot = 0; //miss
	}
	else
	{
		shot = 1; //hit
	}
	
	return shot;
}
/*
Function: number of hits
Description: keeps track of the number of hits each ship has taken
parameteres: shot, num_hits, ship_symbols, ship_length
returns: num_hits
*/
int number_of_hits(int shot, int num_hits[5], char ship_symbols, int ship_length)
{
	int i = 0;
	for (; i < 5; ++i)
	{

		switch (ship_symbols)
		{
		case 'c':

			if (shot == 1)
			{
				num_hits[0] += 1;
			}
			else
			{
				num_hits[0] += 0;
			}
			break;

		case 'b':

			if (shot == 1)
			{
				num_hits[1] += 1;
			}
			else
			{
				num_hits[1] += 0;
			}
			break;

		case 's':

			if (shot == 1)
			{
				num_hits[2] += 1;
			}
			else
			{
				num_hits[2] += 0;
			}
			break;

		case 'r':

			if (shot == 1)
			{
				num_hits[3] += 1;
			}
			else
			{
				num_hits[3] += 0;
			}
			break;

		case 'd':

			if (shot == 1)
			{
				num_hits[4] += 1;
			}
			else
			{
				num_hits[4] += 0;
			}
		}
		return num_hits;
	}
}
/*
Function: total hits
Description: totals the number of hits from num_hits
parameteres: num_hits
returns: total_hits
*/
int total_hits(int num_hits[5])
{
	int total_hits = 0;
	for (int i = 0; i < 5; ++i)
	{
		total_hits += num_hits[i];
	}
}
/*
Function: check ship sunk
Description: checks to see if a ship has been hit enough times to sink
parameteres:board, shipsymbol, ship length, num hits
returns: sunk
*/
int check_if_ship_sunk(char board[][NUM_COLS], int num_rows, int num_cols, int *ship_symbols, int *ship_length, int *num_hits)
{
	int sunk = 0, i = 0;
	for (; i < 5; ++i)
	{
		if (num_hits[i] == ship_length[i])
		{
			printf("congrats you have sunk your opponents ship: %c ", ship_symbols[i]);
			sunk = 1; //ship sunk
		}
		else
		{
			sunk = 0; //ship not sunk
		}
	}
	return sunk;
}
/*
Function: is winner
Description: determines who the winner is
parameteres: num_hits
returns: 
*/
int is_winner(int num_hits)
{
	int win = 0;
	if (num_hits == 17)
	{
		printf("You win!\n");
		win = 1; 
	}
	else
	{
		win = 0;
	}
	return win;
}
/*
Function: output move for user
Description: outputs the current move to battleship.log, whether its a hit or miss
parameteres: hits, misses, row, col
returns: n/a
*/
void output_move_user(FILE*outfile, Stats*p1, char board[][NUM_COLS], int p1_hits[], int row_pt, int col_pt, int shot, int sunk, int *ship_length, int *ship_symbols)
{
	if (shot == 1)//hit
	{
		fprintf(outfile, "user hit on %d, %d!\n", row_pt, col_pt);
		p1->total_hits += 1;
		p1->total_shots += 1;
	}
	if (shot == 0)//miss
	{
		fprintf(outfile, "user miss on %d, %d!\n", row_pt, col_pt);
		p1->total_misses += 1;
		p1->total_shots += 1;
	}
	if (sunk == 1)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (p1_hits[i] == ship_length[i])
			{
				fprintf(outfile, "user has sunk opponents %d!\n", ship_symbols);
			}
			
		}
	}
}
/*
Function: output move for ai
Description: outputs the current move to battleship.log, whether its a hit or miss
parameteres: hits, misses, row, col
returns: n/a
*/
void output_move_ai(FILE*outfile, Stats*ai, char board[][NUM_COLS], int ai_hits[],int row_pt, int col_pt, int shot, int sunk, int *ship_length, int *ship_symbols)
{
	if (shot == 1)//hit
	{
		fprintf(outfile, "ai hit on %d, %d!\n", row_pt, col_pt);
		ai->total_hits += 1;
		ai->total_shots += 1;
	}
	if (shot == 0)//miss
	{
		fprintf(outfile, "ai miss on %d, %d!\n", row_pt, col_pt);
		ai->total_misses += 1;
		ai->total_shots += 1;
	}
	if (sunk == 1)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (ai_hits[i] == ship_length[i])
			{
				fprintf(outfile, "ai has sunk your %d!\n", ship_symbols);
			}
		}
	}
}
/*
Function: output total stats
Description: outputs the total of all stats to battleship.log including hits, misses, and win or lose
parameteres: 
returns: n/a
*/
void output_stats(FILE*outfile, Stats*p1, Stats*ai, char board[][NUM_COLS], int num_hits, int num_misses, int shot)
{
	fprintf(outfile, "Total user hits: %d", p1->total_hits);
	fprintf(outfile, "Total user misses: %d", p1->total_misses);
	fprintf(outfile, "Total user shots: %d", p1->total_shots);
	p1->hits_misses = (p1->total_hits / p1->total_misses);
	fprintf(outfile, "Total user shot percentage: %.2lf", p1->hits_misses);
	if (p1->total_hits == 17)
	{
		fprintf(outfile, "Congrats, You have beaten the ai!! supergenius!!\n");
	}
	else if (ai->total_hits == 17)
	{
		fprintf(outfile, "WOW, you let a computer beat you...\n");
	}

	fprintf(outfile, "Total ai hits: %d", ai->total_hits);
	fprintf(outfile, "Total ai misses: %d", ai->total_misses);
	fprintf(outfile, "Total ai shots: %d", ai->total_shots);
	ai->hits_misses = (ai->total_hits / ai->total_misses);
	fprintf(outfile, "Total ai shot percentage: %.2lf", ai->hits_misses);
}

int play_again()
{
	int option = 0;
	printf("would you like to play again?\n");
	printf("press 1 for yes or 2 to quit\n");
	while (option != 1 && option != 2)
	{
		scanf("%d", &option);
	}
	return option;
}