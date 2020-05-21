
/*
Function: Print menu
Description: prints the menu to the screen
Input:
Returns:
precondition:
postcondition:
*/
void print_menu(void)
{
	printf("please select an option!\n");
	printf("1.Start game of yahtzee for you and a friend!\n");
	printf("anything other # to  Exit\n");
}
/*
Function: Get menu option
Description: Gets an option from the user correlating to the menu options
Input:
Returns: option / int
precondition:
postcondition:
*/
int get_option()
{
	int option = 0;
	scanf("%d", &option);
	return option;
}
/*
Function: Print rules
Description: prints the rules to the screen
Input:
Returns:
precondition:
postcondition:
*/
void print_rules(void)
{
	printf("The challenge of the game is to outduel the other player by\n");
	printf("scoring the most points.Points are obtained by rolling five 6 - sided\n");
	printf("die across thirteen rounds.During each round, each player may roll\n");
	printf("the dice up to three times to make one of the possible scoring\n");
	printf("combinations.Once a combination has been achieved by the player,\n");
	printf("it may not be used again in future rounds, except for the Yahtzee\n");
	printf("combination may be used as many times as the player makes the\n");
	printf("combination.Each scoring combination has different point totals.\n");
	printf("Some of these totals are achieved through the accumulation of points\n");
	printf("across rolls and some are obtained as fixed sequences of values.\n\n");

	printf("The scorecard used for Yahtzee is composed of two sections. A upper section\n");
	printf("and a lower section. A total of thirteen boxes or thirteen scoring combinations\n");
	printf("are divided amongst the sections. The upper section consists of boxes that are scored\n");
	printf("by summing the value of the dice matching the faces of the box. If a player rolls four \n");
	printf("3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination\n");
	printf("is no longer in play for future rounds. If the sum of the scores in the upper section\n");
	printf("is greater than or equal to 63, then 35 more points are added to the players overall\n");
	printf("score as a bonus. The lower section contains a number of poker like combinations.\n");
	printf("See the table provided below\n\n");
	printf("\n\n");
}
/*
Function: inititlize dice array
Description: initially sets all items in array to 0
Input:
Returns: 
precondition:
postcondition:
*/
void init_dice(int dice[])
{
	for (int i = 0; i < SIZE; ++i)
	{
		dice[i] = 0;
	}
}
/*
Function: Initializes dice_count array
Description: initializes all values in the dice_count array to 0
Input:
Returns:
precondition:
postcondition:
*/
void init_dice_count(int dice_count[])
{//1 -6
	for (int i = 1; i <= DIENUM; ++i)
	{
		dice_count[i] = 0;
	}
}
/*
Function: Initializes Scorecard array
Description: initializes all values in the scorecard array to 0
Input:
Returns:
precondition:
postcondition:
*/
void init_scorecard(int scorecard[])
{
	for (int i = 1; i <= CARDSIZE; ++i)
	{
		scorecard[i] = 0;
	}
}

/*
Function: Roll dice
Description: Rolls the dice and sets to array
Input:
Returns: die value
precondition:
postcondition:
*/
void roll_die(int dice[])
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; ++i)
	{
		dice[i] = (rand() % 6 + 1);
	}
}
/*
Function: Display Dice values
Description: Displays the dice value to the screen
Input:
Returns:
precondition:
postcondition:
*/
void display_die_values(int dice[])
{
	printf("\n\t");
	for (int i = 0; i < SIZE; ++i)
	{
		printf("die %d: %d\t", i + 1, dice[i]);
	}
	printf("\n\n");
}
/*
Function: Sum of the dice values
Description: Sums up the value of the dice
Input:
Returns:
precondition:
postcondition:
*/
int sum_dice(int dice[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		sum = sum + dice[i];
	}
	return sum;
}
/*
Function: Count dice
Description: Counts how many of each die is rolled
Input:
Returns:
precondition:
postcondition:
*/
void count_dice(int dice[], int dice_count[])
{
	for (int i = 0; i < SIZE; ++i)
	{
		dice_count[dice[i]] += 1;
	}
}
/*
Function: Prints dice count
Description: prints the number of each dice rolled.
Input:
Returns:
precondition:
postcondition:
*/
void display_count_dice(int dice_count[])
{
	for (int i = 1; i <= DIENUM; ++i)
	{
		printf("die_count %d: %d\n", i , dice_count[i]);
	}
	printf("\n\n");
}
/*
Function: Ask to save score
Description: Asks the user if they want to save their score
Input: Y/y || N/n
Returns:
precondition:
postcondition:
*/
int ask_save_score()
{
	int save = -1;
	printf("\nwould you like to save your score? Enter 1 for yes and 0 for no  \n");
	while (save != 1 && save != 0)
	{
		scanf("%d", &save);
	}
	return save;
}

/*
Function: How many to reroll
Description: asks the user to scan in the amount of dice to reroll
Input:
Returns:
precondition:
postcondition:
*/
int how_many_reroll()
{
	int reroll = -1;
	printf("\nHow many dice would you like to reroll?\n");
	while (reroll >= 5 || reroll <= 0)
	{
		scanf("%d", &reroll);
	}
	return reroll;
}
/*
Function: Which dice
Description: Asks the user which dice to reroll
Input:
Returns:
precondition:
postcondition:
*/
void which_dice(int whichs[], int reroll, int dice[])
{
	int input = 0;
	
	for (int i = 0; i < SIZE; ++i)
	{
		if (reroll != 0)
		{
			printf("\nwould you like to reroll this dice?\nDice number %d with value %d\n1 for yes. 0 for no:\n\n", i+1, dice[i]);
			scanf("%d", &input); //scans in which dice to reroll
			whichs[i] = input;
			if (input == 1)
			{
				--reroll;
			}
		}
	}
}
/*
Function: Reroll dice
Description: rerolls the user selected dice
Input:
Returns:
precondition:
postcondition:
*/
void reroll_dice(int dice[], int whichs[])
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; ++i)
	{
		if (whichs[i] == 1)//reroll this dice
		{
			dice[i] = (rand() % 6 + 1);
		}
	}
}
/*
Function: Displays upper selection
Description: Displays the upper section of scorecard to show user their options
when saving
Input:
Returns:
precondition:
postcondition:
*/
void display_upper_section()
{
	printf("\n1. Sum of 1's  2. Sum of 2's  3. Sum of 3's ");
	printf("4. Sum of 4's  5. Sum of 5's  6. Sum of 6's\n");
}
/*
Function: Displays Lower selection
Description: Displays the lower section of scorecard to show user their options
when saving
Input:
Returns:
precondition:
postcondition:
*/
void display_lower_section()
{
	printf("7. Three of a kind  8. Four of a kind  9. Full house ");
	printf("10. Small straight  11. Large straight  12. Yahtzee  13. Chance\n");
}
/*
Function: which spot
Description: asks the user which spot they wish to save their score to
Input:
Returns: spot
precondition:
postcondition:
*/
int which_spot()
{
	int spot = 0;
	printf("\n\nwhich spot would you like to save your score into?\n");
	while (spot <= 0 || spot >= 14)
	{
		scanf("%d", &spot);
	}
	return spot;
}
/*
Function: valid save option
Description: verifys the users input is valid
Input:
Returns: valid
precondition:
postcondition:
*/
int valid_save_option(int dice_count[], int spot, int scorecard_parallel[])
{
	int valid = 0;
	display_count_dice(dice_count);
	switch (spot)
	{
	case 1://sum of 1s
		if (dice_count[1] >= 1)
		{
			valid = 1;
		}
		break;
	case 2://sum of 2s
		if (dice_count[2] >= 1)
		{
			valid = 1;
		}
		break;
	case 3://sum of 3s
		if (dice_count[3] >= 1)
		{
			valid = 1;
		}
		break;
	case 4://sum of 4s
		if (dice_count[4] >= 1)
		{
			valid = 1;
		}
		break;
	case 5://sum of 5s
		if (dice_count[5] >= 1)
		{
			valid = 1;
		}
		break;
	case 6://sum of 6s
		if (dice_count[6] >= 1)
		{
			valid = 1;
		}
		break;
	case 7://3 of a kind
		printf("validating 3 of a kind\n");
		for (int i = 1; i <= DIENUM; ++i)
		{
			if (dice_count[i] >= 3)
			{
				valid = 1;
			}
		}
		break;
	case 8://4 of a kind
		printf("validating 4 of a kind\n");
		for (int i = 1; i <= DIENUM; ++i)
		{
			if (dice_count[i] >= 4)
			{
				valid = 1;
			}
		}
		break;
	case 9://full house
		printf("validating full house\n");
		for (int i = 1; i <= DIENUM; ++i)
		{//check 2 of a kind. check rest of dice for 3 of a kind
			if (dice_count[i] == 2)
			{
				for (int k = i; k < DIENUM; ++k)
				{
					if (dice_count[k] == 3)
					{
						valid = 1;
					}
				}
			}
		}
		break;
	case 10://small straight
		printf("validating small str8\n");
		if ((dice_count[1] >= 1 && dice_count[2] >= 1 && dice_count[3] >= 1
			&& dice_count[4] >= 1)
			|| (dice_count[2] >= 1 && dice_count[3] >= 1 && dice_count[4] >= 1
			&& dice_count[5] >= 1) || (dice_count[3] >= 1 && dice_count[4] >= 1 && dice_count[5] >= 1
			&& dice_count[6] >= 1))
		{
			valid = 1;
		}
		break;
	case 11://large straight
		printf("validating large str8\n");
		if ((dice_count[1] >= 1 && dice_count[2] >= 1 && dice_count[3] >= 1
			&& dice_count[4] >= 1 && dice_count[5] >= 1) || (dice_count[2] >= 1 && dice_count[3] >= 1 && dice_count[4] >= 1
			&& dice_count[5] >= 1 && dice_count[6] >= 1))
		{
			valid = 1;
		}
		break;
	case 12://yahtzee
		printf("validating yahtzee\n");
		for (int i = 1; i <= DIENUM; ++i)
		{
			if (dice_count[i] == 5)
			{
				valid = 1;
			}
		}
		break;
	case 13://chance
		valid = 1;
		break;
	default:
		break;
	}
	if (scorecard_parallel[spot] == 1)
	{
		valid = -1;
	}
	return valid;//0 for not scorable but unused position, -1 for used position, 1 for valid, scorable, unused position
}
/*
Function: saves scores to an array
Description: saves the users score to the array
Input:
Returns: 
precondition:
postcondition:
*/
void save_score(int scorecard[], int sum, int valid, int spot, int dice_count[], int scorecard_parallel[])
{
	int i = 0;
	int j = 0;
	if (valid == 1)
	{
			if (spot >= 1 && spot <= 6)
			{//sum of 1,2,3,4,5 or 6
				sum = dice_count[spot] * spot;
				scorecard[spot] = sum;
				scorecard_parallel[spot] = 1;
			}
			else if (spot == 7 || spot == 8 || spot == 13)
			{//3 or 4 of kind or chance
				scorecard[spot] = sum;
				scorecard_parallel[spot] = 1;
			}
			else if (spot == 9)
			{//full house
				sum = 25;

				scorecard[9] = sum;
				scorecard_parallel[9] = 1;
			}
			else if (spot == 10)
			{//small strt
				sum = 30;

				scorecard[10] = sum;
				scorecard_parallel[10] = 1;
			}
			else if (spot == 11)
			{//lrge strt
				sum = 40;

				scorecard[11] = sum;
				scorecard_parallel[11] = 1;
			}
			else if (spot == 12)
			{//yahtzee
				sum = 50;

				scorecard[12] += sum;
			}
	}
	else if (valid == 0)
	{
		scorecard[spot] = 0;
		scorecard_parallel[spot] = 1;
	}
}
/*
Function: Sum of upper 
Description: calculates the sum of the upper array scorecard
Input:
Returns: sum
precondition:
postcondition:
*/
int sum_upper(int scorecard[])
{
	int sum = 0;
	for (int i = 1; i <= DIENUM; ++i)
	{
		sum += scorecard[i];
	}
	return sum;
}
/*
Function: bonus save score earned
Description: determines if user earned bonus points 
Input:
Returns: bonus
precondition:
postcondition:
*/
int bonus_score_earned(int sum_u)
{
	if (sum_u >= 63)
	{
		sum_u += 35;
	}
	return sum_u;
}
/*
Function: sum of scorecard 
Description: determines the sum of the total scorecard
Input:
Returns: sum
precondition:
postcondition:
*/
int sum_lower(int scorecard[])
{
	int sum = 0;
	for (int i = 7; i <= CARDSIZE; ++i)
	{
		sum += scorecard[i];
	}
	return sum;
}
/*
Function: display scores
Description: displays both players scores after round 14
Input:
Returns: 
precondition:
postcondition:
*/
void display_scores(int player1_score, int player2_score)
{
	printf("\n\n\n\n");
	printf("Player 1 score: %d\n", player1_score);
	printf("Player 2 score: %d\n", player2_score);
}
/*
Function: Display winner
Description: determines and displays the winner of the game
Input:
Returns: 
precondition:
postcondition:
*/
void display_winner(int player1_score, int player2_score)
{
	if (player1_score > player2_score)
	{
		printf("PLayer 1 is the winner. PLAYER 2 SUCKS!!!\n");
	}
	else if (player1_score < player2_score)
	{
		printf("Player 2 is the winner. PLAYER 1 SUCKS!!!\n");
	}
	else if (player1_score == player2_score)
	{
		printf("Its a TIE... boring...\n");
	}
}
/*
Function: One more game
Description: asks user for another game?
Input:
Returns: 
precondition:
postcondition:
*/
int One_more_game()
{
	int option = -1;
	printf("Would you like to play another game?\n");
	printf("please enter 1 for Y or 0 for N\n");
	while (option != 1 && option != 0)
	{
		scanf("%d", &option);
	}
	return option;
}

void display_card(int scorecard[])
{
	for (int i = 1; i <= 13; ++i)
	{
		printf("spot %d contains %d\n", i, scorecard[i]);
	}
}