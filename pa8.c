/*
Function name: my_str_n_cat
Description: copys one string to the end of another without using <string.h> help
input: dest pointer and source pointer
output: dest
*/
void my_str_n_cat(char dest[], char source[])
{
	int i;
	for (i = 0; dest[i] != '\0'; ++i)
	{
		continue;
	}
	for (int j = 0; source[j] != '\0'; ++j, ++i)
	{
		dest[i] = source[j];
	}
	puts(dest);
}

/*
Function name: binary search
Description: searches through a sorted list for a target value. Returns target index if value is found
input: list, target
output: target index
*/
int binary_search(int list[], int target)
{
	int target_index = -1;
	int left = 1;
	int right = 20;
	int midpoint = 0;
	int found = 0; //false

	while (found == 0 && left <= right)
	{
		midpoint = (left + right) / 2;
		if (target == list[midpoint])
		{
			found = 1; //true
			target_index = midpoint;
		}
		else if (target < list[midpoint])
		{
			right = midpoint - 1;
		}
		else if (target > list[midpoint])
		{
			left = midpoint + 1;
		}
	}
 	return target_index; // -1 if target not found. number of target index if target is found
}

/*
Function name: bubble sort
Description: sorts the string according to asci values
input: str, temp, num_strings
output: n/a
*/
void bubble_sort(char str[], int num_strings)
{
	char temp;
	int u = num_strings;
	//int c = 1;
	while (u > 1)
	{
	int	c = 1;
		while (c <= u)
		{
			if (str[c] == '\0')//dont record spaces
			{
				c++;
			}
			if (str[c] < str[c - 1]) // if c less than c-1 in str
			{
				temp = str[c - 1];
				str[c - 1] = str[c];
				str[c] = temp;
			}
			c++;
		}
		u--;
	}
	for (int i = 0; i < num_strings; ++i)
	{
		printf("%c, ", str[i]);
	}
	printf("\n");
}

/*
Function name: Is palindrome
Description: determines if a string is a palindrome
input: pal_str, length
output: palindrome. 1 for yes, 0 for no palindrome
*/
int is_palindrome(char *pal_str, int pal_length, int i)
{
	//base case if first and last chars are the same
	int palindrome = -1;
	//int i = 0;
	while (i <= pal_length && (palindrome != 1 && palindrome != 0))
	{
		if (pal_str[i] == pal_str[pal_length] && (i == pal_length || i == pal_length - 1))
		{
			palindrome = 1;
		}
		else if (pal_str[i] == pal_str[pal_length] && i < pal_length)
		{
			palindrome = is_palindrome(pal_str, pal_length - 1, i + 1);
		}
		else
		{
			palindrome = 0;
		}
	}
	return palindrome;
}

/*
Function name: sum primes
Description: sums the prime numbers of n using recursion
input: n
output: sum
*/
int sum_primes(unsigned int n, unsigned int j, int sum)
{
	if (j <= n)
	{
		if (j == 3 || j == 5 || j == 7)
		{
			sum += j;
		}
		else if (j % 2 != 0 && j % 3 != 0 && j % 5 != 0 && j % 7 != 0)
		{
			sum += j;
		}
		sum = sum_primes(n, j + 1, sum);
	}
	return sum;
}


/*
Function name: maximum_occurences
Description: determines the frequency of each character found in the array
input: string, array, struct occurences, integer, character
output: max number of occurences and which letter appears most/ no actual output. output through pointers
*/
void maximum_occurences(char *string, Occurences *occ, int *number, char *hhh)
{
	int j = strlen(string);
	int max = -1000;
	
	for (int l = 0; l < j; ++l)
	{
		occ[l].num_occurences = 0;
		occ[l].frequency = 0.0;

		for (int i = 0; i < 26; ++i)
		{
			
			if (string[l] == string[i]) //repeat letter
			{
				occ[l].num_occurences += 1;
			}
			
			if (occ[l].num_occurences > max)//new max
			{
				max = occ[l].num_occurences;
				*number = max;
				*hhh = string[l];
			}

			occ[i].frequency = ((occ[i].num_occurences) / j);
		}
	}
}