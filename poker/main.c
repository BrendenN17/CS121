#include"poker.h"

int main(void)
{
	Card p1hand[5] = { 0,0,0,0,0 };
	Card aihand[5] = { 0,0,0,0,0 };

	

	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	int p1pair = 0, p1pairs = 0, p1option = 0, round = 0, p1kind = 0, p1kinds = 0, p1num = 0, p1fold = 0, winner = 0;
	int p1flush = 0, p1straight = 0, p1high = 0, p1rank = 0, better = 0, ainum = 0;
	int aipair = 0, aipairs = 0, aikind = 0, aikinds = 0, aiflush = 0, aistraight = 0, aihigh = 0, airank = 0;
	int which[5] = { 0,0,0,0,0 };

	welcome_screen();


	p1option = get_option();

	while(p1option == 1)
	{
		//initializing bothplayers hands
		init_card(p1hand);
		init_card(aihand);
		give_instruct();
		system("pause");
		system("cls");
		shuffle(deck);
		//deal(deck, face, suit, p1hand);
		//deal(deck, face, suit, aihand);
		do
		{
			init_which(which);
			//shuffle(deck);

			deal(deck, face, suit, p1hand);
			//deal(deck, face, suit, aihand);
			dealai(deck, face, suit, aihand);
			p1fold = fold_();//0 fold and 1 calls
			if (p1fold == 0)
			{
				winner = 0; //ai wins round
				printf("ai wins this round\n");
			}
			else
			{
				p1num = how_many_redraw();
				which_redraw(p1num, which);
				if (p1num >= 1)
				{
					redeal(deck, face, suit, p1hand, p1num, which);
					print_card(p1hand);


					p1pairs = is_two_pairs(p1hand);
					p1pair = is_pair(p1hand);
					p1kind = three_of_akind(p1hand);
					p1kinds = four_of_akind(p1hand);
					p1flush = isflush(p1hand);
					p1straight = isstraight(p1hand);
					p1high = high_card(p1hand);
					p1rank = hand_rank(p1pair, p1pairs, p1kind, p1kinds, p1flush, p1straight);



					aipairs = is_two_pairs(aihand);
					aipair = is_pair(aihand);
					aikind = three_of_akind(aihand);
					aikinds = four_of_akind(aihand);
					aiflush = isflush(aihand);
					aistraight = isstraight(aihand);
					aihigh = high_card(aihand);
					airank = hand_rank(aipair, aipairs, aikind, aikinds, aiflush, aistraight);
					ainum = ai_redraw_logic(aihand, airank);
					if (ainum >= 1)
					{
						airedeal(deck, face, suit, aihand, ainum, which);
						aipairs = is_two_pairs(aihand);
						aipair = is_pair(aihand);
						aikind = three_of_akind(aihand);
						aikinds = four_of_akind(aihand);
						aiflush = isflush(aihand);
						aistraight = isstraight(aihand);
						aihigh = high_card(aihand);
						airank = hand_rank(aipair, aipairs, aikind, aikinds, aiflush, aistraight);
						ainum = ai_redraw_logic(aihand, airank);
					}

					better = better_hand(p1rank, airank, p1high, aihigh);

					if (better == 1)
					{
						printf("YOU WIN!!! this round..\n");
					}
					else if (better == 2)
					{
						printf("YOU LOSE!! TRASH..\n");
					}
					else if (better == 3)
					{
						printf("TIIIEEEEE\n");
					}
				}
				else
				{
					print_card(p1hand);

					if (ainum >= 0)
					{
						airedeal(deck, face, suit, aihand, ainum, which);
						p1pairs = is_two_pairs(p1hand);
						p1pair = is_pair(p1hand);
						p1kind = three_of_akind(p1hand);
						p1kinds = four_of_akind(p1hand);
						p1flush = isflush(p1hand);
						p1straight = isstraight(p1hand);
						p1high = high_card(p1hand);
						p1rank = hand_rank(p1hand, p1pair, p1pairs, p1kind, p1kinds, p1flush, p1straight);



						aipairs = is_two_pairs(aihand);
						aipair = is_pair(aihand);
						aikind = three_of_akind(aihand);
						aikinds = four_of_akind(aihand);
						aiflush = isflush(aihand);
						aistraight = isstraight(aihand);
						aihigh = high_card(aihand);
						airank = hand_rank(aipair, aipairs, aikind, aikinds, aiflush, aistraight);

						better = better_hand(p1rank, airank, p1high, aihigh);
					
					}

					if (better == 1)
					{
						printf("YOU WIN!!! this round..\n");
					}
					else if (better == 2)
					{
						printf("YOU LOSE!! TRASH..\n");
					}
					else if (better == 3)
					{
						printf("TIIIEEEEE\n");
					}
					//printf("1 pair test: %d\n", pair);
					//printf("2 pairs test: %d\n", pairs);
				}
			}
			











			
			system("pause");
			system("cls");
			system("pause");
			++round;
		} while (round < 10);
		p1option = get_option();
	}


	return 0;
}