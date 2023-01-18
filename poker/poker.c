#include"poker.h"



/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = 1; card <= 5; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					*hand[card].face = column + 1;
					*hand[card].suit = row + 1;
				}
			}
		}
	}
}
void dealai(const int wDeck[][13], const char * wFace[], const char * wSuit[], Card hand[5])
{
	
		int row = 0;    /* row number */
		int column = 0; /*column number */
		int card = 0;   /* card counter */

						/* deal each of the 52 cards */
		for (card = 1; card <= 5; card++)
		{
			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == card+5)
					{
						//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
						*hand[card].face = column + 1;
						*hand[card].suit = row + 1;
					}
				}
			}
		}
	
}
/*
Function name: redeal
description: redeals the selected cards into the players hand
input: deck, hand, num which redraw
returns: n/a
*/
void redeal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5], int num, int which[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = 1; card <= num; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card+5)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					*hand[which[card]].face = column + 1;
					*hand[which[card]].suit = row + 1;
				}
			}
		}
	}
}
/*
Function name: ai redeal
description: redeals the selected cards into the players hand
input: deck, hand, num which redraw
returns: n/a
*/
void airedeal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5], int num, int which[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = 1; card <= num; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card + 5)
				{
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					*hand[which[card]].face = column + 1;
					*hand[which[card]].suit = row + 1;
				}
			}
		}
	}
}
/*
Function name: Welcome screen
description: prints out the welcome screen to the user
input: n/a
returns: n/a
*/
void welcome_screen(void)
{
	printf("\tWelcome to Poker\n");
	printf("Please enter 1 to play or 0 to exit\n");
}
/*
Function name: get option
description: gets option from user whether they want to play or not
input: n/a
returns: option
*/
int get_option(void)
{
	int option = 0;
	scanf("%d", &option);
	return option;
}
/*
Function name: give instructions
description: prints instructions to the screen once user chooses to play
input: n/a
returns: n/a
*/
void give_instruct(void)
{
	printf("\tHere are the rules of Poker\n\n");
	printf("Play begins with both you and the house being dealt 5 cards\n");
	printf("One at a time, all face down. The remaining deck is placed aside\n");
	printf("Often protected by a chip or other marker on it. Players pick up\n");
	printf("The cards and hold them in their hands, being careful to keep them\n");
	printf("Concealed from the other players. If more than one player remains \n");
	printf("After the first round, the 'draw' phase begins. Each player specifies\n");
	printf("how many of their cards they wish to replace and discards them. The deck\n");
	printf("Is retrieved, and each player is dealt in turn from the deck the same \n");
	printf("Number of cards they discarded so that each player again has 5 cards. A\n");
	printf("Second 'after the draw' betting round occurs beginning with the player\n");
	printf("who opened the first round. This is followed by a showdown, if more than\n");
	printf("One player remains, in which the player with the best hand wins tht pot\n");
	system("pause");
}
/*
Function name: initialize hand
description: initializes the hands with all 0s
input: n/a
returns: n/a
*/
void init_card(Card hand[5])
{
	for (int i = 1; i <= 5; ++i)
	{
		*hand[i].face = 0;
		*hand[i].face = 0;
	}
}
/*
Function name: print card
description: prints the card to the screen
input: hand
returns: n/a
*/
void print_card(Card hand[5])
{
	printf("Your hand contains:\n\n");
	for (int i = 1; i <= 5; ++i)
	{
		printf("%d\n", *hand[i].face);
		printf("%d\n", *hand[i].suit);
	}
}
/*
Function name: ispair
description: determines if the hand contains 1 pair
input: hand
returns: pair
*/
int is_pair(Card hand[5])
{
	int pair = 0;
	if (*hand[0].face == *hand[1].face || *hand[0].face == *hand[2].face || *hand[0].face == *hand[3].face || *hand[0].face == *hand[4].face)
	{
		pair = 1;
	//	printf("you have a pair\n");

	}
	else if (*hand[1].face == *hand[2].face || *hand[1].face == *hand[3].face || *hand[1].face == *hand[4].face)
	{
		pair = 1;
	//	printf("you have a pair\n");

	}
	else if (*hand[2].face == *hand[3].face || *hand[2].face == *hand[4].face)
	{
		pair = 1;
	//	printf("you have a pair\n");

	}
	else if (*hand[3].face == *hand[4].face)
	{
		pair = 1;
	//	printf("you have a pair\n");
	}
	else 
	{
		pair = 0; //no pair
	}

	return pair;
}
/*
Function name: is two pairs
description: determines if the hand contains 2 pairs
input: hand
returns: pairs
*/
int is_two_pairs(Card hand[5])
{
	int pairs = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 5; ++j)
		{
			if (*hand[i].face == *hand[j].face)
			{
				pairs = 1; //2 pairs
		//		printf("you have 2 pairs\n");

			}
			else
			{
				pairs = 0; //no  2 pairs
			}
		}
	}
	return pairs;
}
/*
Function name: three of a kind
description: determines if the hand contains 3 of the same card
input: hand
returns: kind
*/
int three_of_akind(Card hand[5])
{
	int kind = 0;
	if (*hand[0].face == *hand[1].face && *hand[2].face)
	{
		kind = 1;
		//printf("you have 3 of a kind!\n");

	}
	else if (*hand[0].face == *hand[2].face && *hand[3].face)
	{
		kind = 1;
//		printf("you have 3 of a kind!\n");

	}
	else if (*hand[0].face == *hand[3].face && *hand[4].face)
	{
		kind = 1;
	//	printf("you have 3 of a kind!\n");

	}
	else if (*hand[1].face == *hand[2].face && *hand[3].face)
	{
		kind = 1;
	//	printf("you have 3 of a kind!\n");

	}
	else if (*hand[1].face == *hand[3].face && *hand[4].face)
	{
		kind = 1;
	//	printf("you have 3 of a kind!\n");

	}
	else if (*hand[2].face == *hand[3].face && *hand[4].face)
	{
		kind = 1;
	//	printf("you have 3 of a kind!\n");

	}
	else
	{
		kind = 0; //no 3 of a kind
	}
	return kind;
}
/*
Function name: four of a kind
description: determines if the hand contains 4 of the same card
input: hand
returns: kinds
*/
int four_of_akind(Card hand[5])
{
	int kinds = 0;
	if (*hand[0].face == *hand[1].face && *hand[2].face && *hand[3].face)
	{
	//	printf("you have 4 of a kind!\n");

		kinds = 1;
	}
	else if (*hand[0].face == *hand[2].face && *hand[3].face && *hand[4].face)
	{
		kinds = 1;
	//	printf("you have 4 of a kind!\n");

	}
	else if (*hand[0].face == *hand[1].face && *hand[3].face && *hand[4].face)
	{
		kinds = 1;
	//	printf("you have 4 of a kind!\n");

	}
	else if (*hand[1].face == *hand[2].face && *hand[3].face && *hand[4].face)
	{
		kinds = 1;
	//	printf("you have 4 of a kind!\n");

	}
	else
	{
		kinds = 0; //no 4 of a kind
	}
	return kinds;
}
/*
Function name: flush
description: determines if the card contains a flush
input: hand
returns: flush
*/
int isflush(Card hand[5])
{
	int flush = 0;
	if (*hand[0].suit == *hand[1].suit && *hand[2].suit && *hand[3].suit && *hand[4].suit)
	{
	//	printf("you have a flush!\n");

		flush = 1; //flush
	}
	else
	{
		flush = 0; //no flush
	}
	return flush;
}
/*
Function name: straight
description: determines if the card contains a straight
input: hand
returns: straight
*/
int isstraight(Card hand[5])
{
	int straight = 0;
	if (*hand[0].face == *hand[1].face + 1 && *hand[2].face + 2 && *hand[3].face + 3 && hand[4].face + 4)
	{
		straight = 1;//straight
		//printf("you have a straight!!\n");

	}
	else if (*hand[4].face == *hand[3].face + 1 && *hand[2].face + 2 && *hand[1].face + 3 && hand[0].face + 4)
	{
		straight = 1;//straight
		//printf("you have a straight!!\n");

	}
	else
	{
		straight = 0; //no straight
	}
	return straight;
}
/*
Function name: high card
description: determines the highest card in the hand
input: hand
returns: high
*/
int high_card(Card hand[])
{
	int high = -10000;
	for (int i = 0; i < 5; ++i)
	{
		if (*hand[i].face > high)
		{
			high = *hand[i].face;
		}
	}
	return high;
}
/*
Function name: hand rank
description: determines the rank of a hand
input: hand, pair, pairs, kind, kinds, flush, straight
returns: rank
*/
int hand_rank(int pair, int pairs, int kind, int kinds, int flush, int straight)
{
	int rank = 0;
	if (kinds == 1)
	{
		rank = 6;
	}
	else if (kind == 1)
	{
		rank = 3;
	}
	else if (pairs == 1)
	{
		rank = 2;
	}
	else if (pair == 1)
	{
		rank = 1;
	}
	else if (flush == 1)
	{
		rank = 5;
	}
	else if (straight == 1)
	{
		rank = 4;
	}
	else
	{
		rank = 0;
	}
	return rank;
}
/*
Function name: better hand
description: determines which player has the better hand based on hand rank
input: p1rank, airank, p1high, aihigh
returns: better
*/
int better_hand(int p1rank, int airank, int p1high, int aihigh)
{
	int better = 0;
	if (p1rank > airank)
	{
		better = 1; //p1 wins
	}
	else if (p1rank < airank)
	{
		better = 2; //ai wins
	}
	else if (p1rank == airank)
	{
		if (p1high > aihigh)
		{
			better = 1; //p1 wins
		}
		else if (p1high < aihigh)
		{
			better = 2; //ai wins
		}
		else if (p1high == aihigh)
		{
			better = 3; //tie
		}
	}

	return better;
}
/*
Function name: how many redraw
description: gets the number of cards to redraw from the user
input: hand
returns: num
*/
int how_many_redraw(void)
{
	int num = 0;
	int redraw = 0;
	printf("How many cards would you like to redraw?\n");
	printf("you can draw up to 3 cards\n");
	scanf("%d", &redraw);
	if (redraw <= 3)
	{
		num = redraw;
	}
	else
	{
		num = 3;
	}
	return num;
}
/*
Function name: initialize which
description: initializes the which redraw function
input: which
returns: n/a
*/
void init_which(int which[])
{
	int i = 0;
	for (; i < 5; ++i)
	{
		which[i] = 0;
	}
}
/*
Function name: ai redraw logic
description: ai logic to determine if they should pick up new cards and how many
input: hand, rank
returns: num
*/
int ai_redraw_logic(Card hand[5], int rank)
{
	int num = 0;
	if (rank == 1)
	{
		num = 3;
	}
	else if (rank == 2)
	{
		num = 1;
	}
	else if (rank == 3)
	{
		num = 2;
	}
	else if (rank == 4)
	{
		num = 0;
	}
	else if (rank == 5)
	{
		num = 0;
	}
	else if (rank == 6)
	{
		num = 1;
	}
}
/*
Function name: fold
description: asks the user to fold or not
input: 
returns: fold
*/
int fold_(void)
{
	int fold = 0;
	printf("would you like to fold?\n");
	printf("press 0 to fold and 1 to call\n");
	scanf("%d", &fold);
	return fold;
}

/*
Function name: which redraw
description: determines which cards to redraw
input: num, which
returns: which
*/
int which_redraw(int num, int which[])
{
	int i = 0;
	int input = 0;
	for (; i < num; ++i)
	{
		printf("Which cards would you like to redraw?\n");
		scanf("%d", &input);
		which[i] = input;
	}
	return which;
}




