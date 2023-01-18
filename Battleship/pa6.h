#define HORIZONTAL 0
#define NUM_ROWS 10
#define NUM_COLS 10
#define NUMSHIPS 5

typedef struct stats
{
	int total_hits;
	int total_misses;
	int total_shots;
	double hits_misses;
}Stats;



//function: displays the welcome screen
void welcome_screen();

//function: gets menu option
int get_menu_option();

//function: initialize game board
void initialize_game_board(char board[][NUM_COLS]);

//function: prints the game board
void print_board(char board[][NUM_COLS]);

//function: select who starts first
int select_who_starts_first();

//function: how to place ships
int how_place_ships();

//function: manually get a direction
int get_direction();

//function: manually get a starting row_point
int get_start_row();

//function: manually get a starting col_point
int get_start_col();

//function: checks if ship has valid spot to be placed
int check_valid_ship(char board[][NUM_COLS], int start_row_pt, int start_col_pt, int ship_length, int ship_direction);

//function: manually placing ships
void manually_place_ships_on_board(char board[][NUM_COLS], char ship_symbol, int ship_length, int ship_direction, int start_row_pt, int start_col_pt);

//function: generate direction
int gen_direction();

//function: generate starting row point
int gen_start_row_pt(int dir, int ship_length);

//function: generate starting row point
int gen_start_col_pt(int dir, int ship_length);

//function: randomly placing ships
void randomly_place_ships_on_board(char board[][NUM_COLS], char ship_symbols, int ship_length, int ship_direction, int start_row_pt, int start_col_pt);

//function: getsuser shot row placement
int user_shot_row();

//function: getsuser shot col placement
int user_shot_col();

//function: gens ai shot row placement
int ai_shot_row();

//function: gens ai shot col placement
int ai_shot_col();

//function: checks if already shot there before
int is_valid_shot(char board[NUM_ROWS][NUM_COLS], int row_pt, int col_pt);

//function: updates the board
void update_shots_board(char board[][NUM_COLS], int row_pt, int col_pt, int shot);

//function: updates player and AI boards only to display hits on their ships
void update_board(char board[][NUM_COLS], int row_pt, int col_pt, int shot);

//function: checks shot
int check_shot(char board[][NUM_COLS], int row_pt, int col_pt);

//function: num of hits for each ship
int number_of_hits(int shot, int num_hits[5], char ship_symbols, int ship_length);

//function: total number of hits
int total_hits(int num_hits[5]);

//function: determines winner
int is_winner(int num_hits);

//function: outputs current player move
void output_move_user(FILE*outfile, Stats*p1, char board[][NUM_COLS], int p1_board[], int row_pt, int col_pt, int shot, int sunk, int *ship_length, int *ship_symbols);

//function: outputs current ai move
void output_move_ai(FILE*outfile, Stats*ai, char board[][NUM_COLS], int ai_board[], int row_pt, int col_pt, int shot, int sunk, int *ship_length, int *ship_symbols);

//function: check if a ship has sunk or not
int check_if_ship_sunk(char board[][NUM_COLS], int num_rows, int num_cols, int *ship_symbols, int *ship_length, int *num_hits);

//function: outputs the final stats for each player
void output_stats(FILE*outfile, Stats*p1, Stats*ai, char board[][NUM_COLS], int num_hits, int num_misses, int shot);

//function: play again?
int play_again();