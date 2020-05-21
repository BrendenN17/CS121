#define _CRT_SECURE_NO_WARNINGS
#define QUIT 2
#define SIZE 5
#define DIENUM 6
#define CARDSIZE 13

//function : prints game menu
void print_menu(void);

//function : gets option from user
int get_option();

//function : prints game rules
void print_rules(void);

//function : initializes dice array
void init_dice(int dice[]);

//function : Initializes count_dice array
void init_dice_count(int dice_count[]);

//function : initializes scorecard array
void init_scorecard(int scorecard[]);

//function : Rolls a dice
void roll_die(int dice[]);

//function : displays dice value
void display_die_values(int dice[]);

//function : sums the value of all 5 dice
int sum_dice(int dice[]);

//function : counts how many of each dice
void count_dice(int dice[], int dice_count[]);

//function : displays dice counts
void display_count_dice(int dice_count[]);

//function : Asks the user if they want to save their score
int ask_save_score();

//function : gets how many dice to reroll
int how_many_reroll();

//function : Asks user which dice to reroll
void which_dice(int whichs[], int reroll, int dice[]);

//function : Reroll user selected dice
void reroll_dice(int dice[], int whichs[]);

//function : Displays upper section scorecard
void display_upper_section();

//function : Displays lower section scorecard
void display_lower_section();

//function : Asks user which spot they wish to save their score into
int which_spot();

//function : Verifies that the user selected option is valid
int valid_save_option(int dice_count[], int spot, int scorecard_parallel[]);

//function : Saves users score to scorecard array
void save_score(int scorecard[], int sum, int valid, int spot, int dice_count[], int scorecard_parallel[]);

//function : sum of the upper section
int sum_upper(int scorecard[]);

//function : bonus score?
int bonus_score_earned( int sum_u);

//function : sum of the total scorecard
int sum_lower(int scorecard[]);

//function : Print scores for both players
void display_scores(int player1_score, int player2_score);

//function : Determine and print winner
void display_winner(int player1_score, int player2_score);

//function : Asks user to play again
int One_more_game();

//function : prints out scorecard
void display_card(int scorecard[]);