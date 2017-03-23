/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 5

*/


#include "assignment-5_calculator.h"
#include <stdlib.h>
#include <stdio.h>

// code for eval should allocate an operand_stack (declared in assignment-5_calculator.h)
// and push operands into the stack, and pop arguments when operator is encountered
// e.g. 2 2 + 3 *
// [] -> [2] -> [2,2] -> [2] - > [] -> [4] -> [4,3] -> [4] -> [] -> [7]
// return the last value in the stack
// if size > 1 when done, assert an error


double eval( char expr[][MAX_EXPR_LENGTH], int N ) {

	if (N == 0) {
		return(0);
	}

	stack *str = stack_init();

	int i = 0;
	int *pt;
	double number;
	double val1;
	double val2;
	double operation;

	

	while (i < N) {
		pt = &expr[i][0];

		if (atof(pt)) {
			number = atof(pt);
		}
		else if (*pt == 48 || (*pt==12333) ) {	// 12333 refers to "-0"
		number = 0;
		}

		else {
			number = (double)expr[i][0];
		}


		if (number != '+' && number != '-' && number != '/' && number != '*') {
			push(str, number);
		}

		else {
			operation = number;
			val1 = pop(str);
			val2 = pop(str);

			if (operation == '+') {
				push(str, val1 + val2);
			}

			if (operation == '-') {
				push(str, val1 - val2);
			}

			if (operation == '*') {
				push(str, val1*val2);
			}

			if (operation == '/') {
				push(str, val1 / val2);
			}

		}

		i++;




	}

	double value = pop(str);
	free(str);
	return(value);
}
