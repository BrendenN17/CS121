#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include "pa8.h"
#include "pa8.c"

#define num_strings 5//change value to match test 3 var count

/*
Name: Brenden Nelson
Date: 11/28/18
Description: PA8. A lot of miscellaneous calculations/functions
with a few random test cases. For cpts121
*/


int main(void)
{
	//Test 1 vars (strncat without using <string.h>)
	char destination[] = "boss";
	char source[] = "swag";

	//Test 2 vars (binary search to find target value)
	int list[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	int target1 = 18;
	int target2 = 20;
	int found = 0; 

	//Test 3 vars (bubble sort according to ascii value)
	char str[100] = { 'a', 'y', 'x', 'b', 'g'};

	//Test 4 vars (testing if a string is a palindrome)
	int palindrome1 = 0;
	int palindrome2 = 0;
	char pal_str1[100] = "racecar";
	char pal_str2[100] = "palindrome";
	int pal1_length = strlen(pal_str1) - 1;
	int pal2_length = strlen(pal_str2) - 1;
	int i = 0;

	//Test 5 vars (sums prime numbers of n)
	unsigned int n = 10;
	int sum = 0;
	unsigned int j = 2;

	char string[100] = { "test string" };
	char strings[100] = { "random stuff  ff" };
	int *number = 0;
	char *hhh = NULL;
	Occurences occ[26];
	int max = 0;
	
	
	//testing function 1 
	my_str_n_cat(destination, source);

	//testing function 2
	found = binary_search(list, target1);
	printf("found: %d\n", found);//testing function 2 expecting 18
	found = binary_search(list, target2);
	printf("found: %d\n", found);//testing function 2 expecting -1

	//testing function 3
	bubble_sort(str, num_strings);//testing bubble sort function. expecting a, b, g, x, y all on newlines
	
	//testing function 4
	palindrome1 = is_palindrome(pal_str1, pal1_length, i); //testing palindrome function
	printf("Palindrome: %d\n", palindrome1); //expecting 1 (yes palindrome)
	palindrome2 = is_palindrome(pal_str2, pal2_length, i); //testing palindrome function
	printf("Palindrome: %d\n", palindrome2); //expecting 0 (no palindrome)

	//testing function 5
	sum = sum_primes(n, j, sum);//testing prime number function
	printf("SUM: %d\n", sum); //expecting 15

	//testing function 6
	maximum_occurences(string, occ, &number, &hhh); //testing max occur functoin
	printf("max character is %c : and occurs %d times\n", hhh, number); //expecting t 3 times
	maximum_occurences(strings, occ, &number, &hhh); //testing max occur functoin
	printf("max character is %c : and occurs %d times\n", hhh, number); //expecting f 4 times


	return 0;
}