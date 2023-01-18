/*
Name: Brenden Nelson
Date: 11/09/18
Description: Takes a user through a game of poker against the house
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

typedef struct card
{
	int face[13];
	int suit[4];
} Card;



//function: shuffles the deck
void shuffle(int wDeck[][13]);

//function: deals the cards in the deck
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand [5]);

//function: deals ai without printing
void dealai(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5]);

//function: redeals the cards chosen
void redeal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5], int num, int which[]);

//function: welcome screen
void welcome_screen(void);

//function: get user option
int get_option(void);

//function: instructions
void give_instruct(void);

//function: initialize hand
void init_card(Card hand[5]);

//function: prints the struct
void print_card(Card hand[5]);

//function: determines if hand has a pair
int is_pair(Card hand[5]);

//function: determines if hand has 2 pairs
int is_two_pairs(Card hand[5]);

//function: determines if hand has 3 of a kind
int three_of_akind(Card hand[5]);

//function: determines if hand has 4 of a kind
int four_of_akind(Card hand[5]);

//function: determines if hand contains a flush
int isflush(Card hand[5]);

//function: determines if the hand contains a straight
int isstraight(Card hand[5]);

//function: Determines highest card in the hand
int high_card(Card hand[]);

//function: Determines which hand has a higher rank
int hand_rank(int pair, int pairs, int kind, int kinds, int flush, int straight);

//function: Determine better hand
int better_hand(int p1rank, int airank, int p1high, int aihigh);

//function: how many redraw
int how_many_redraw(void);

//function: which redraw
int which_redraw(int num, int which[]);

//function: initializes which card function
void init_which(int which[]);

//function: redraws ai cards
int ai_redraw_logic(Card hand[5], int rank);

//function: Would you like to fold?
int fold_(void);

//function: redeals for the ai
void airedeal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5], int num, int which[]);
