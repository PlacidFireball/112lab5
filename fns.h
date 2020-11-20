#ifndef FNS_H	// file guards
#define FNS_H

#include <stdio.h>	// for I/O
#include <math.h>	// for math functions, log10() and pow()
#include <stdlib.h>	// just in case

typedef enum { false, true } boolean_t;	// boolean enum
boolean_t is_palindrome(int num);	// function that tests if an integer is a palindrome
void read_nums(FILE* in);		// reads in the nubers from a file

#endif
