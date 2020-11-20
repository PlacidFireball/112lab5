#include "fns.h"	// defines boolean_t and functions
#include <math.h>	// for logarithms and pow()
#include <stdio.h>	// for I/O

boolean_t is_palindrome(int num) {
	if(num < 0) num = -num;			// handle negative numbers
	if(num < 10) return true;		// base case
	else {
		int y = num % 10; 		// last digit
		num = num / 10; 		// yeet it
		int x = (int)pow(10.0, (int)log10((double)num)); // number of digits
		int z = num / x;		// calculate value of top digit
		if(y != z) return false;	// if the first and last digits are not equal, return false
		num = num % x;			// lop off the last digit
		return is_palindrome(num); 	// call is_palindrome with the new number
	}
}

// read in the numbers
void read_nums(FILE* in) {
	char buff[20];
	while(fgets(buff, 20, in) != NULL) { 	// for each number that fgets retrieves, call is palindrome with it
		printf("Is %d a palindrome? %s\n", atoi(buff), (is_palindrome(atoi(buff))) ? "yes" : "no");
	}
}

int main(void) {
	// Open the file
	FILE* in = fopen("numbers.txt", "r");
	if(in == NULL) { 		// if the input file doesn't work
		perror("ERROR: "); 	// print out an error
		return -1;
	}
	read_nums(in); 			// read in the numbers
	return 0; 			// exit
}
