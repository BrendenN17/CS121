
typedef struct occurences
{
	int num_occurences;
	double frequency;
}Occurences;

//function 1: mystrnncat
void my_str_n_cat(char dest[], char source[]);

//function 2: binary search
int binary_search(int list[], int target);

//function 3:bubble_sort
void bubble_sort(char str[], int num_strings);

//function 4: is palindrome
int is_palindrome(char *pal_str, int pal_length, int i);

//function 5: sum of primes
int sum_primes(unsigned int n, unsigned int j, int sum);

//function 6: maximum occurences
void maximum_occurences(char *string, Occurences *occ, int *number, char *hhh);
