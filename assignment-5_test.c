
#include "assignment-5_calculator.h"
#include "assignment-5_log-mgr.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void log_mgr_tests();
void calculator_tests();

int main() {
	calculator_tests();
	log_mgr_tests();
	
	return 0;
}

void calculator_tests() {
	/////////////////////////////
	stack *str = stack_init();
	push(str, 5);
	int x = peek(str);
	push(str, 6);
	push(str, 8);
	int z = stack_size(str);
	x = peek(str);
	int y = stack_index_of(str, 5);
	stack_print(str);
	pop(str);
	pop(str);
	x = peek(str);
	x = stack_index_of(str, 5);
	pop(str);
	x = stack_index_of(str, 5);
	x = stack_size(str);
	x++;
	////////////////////////////////
    char expr1[][MAX_EXPR_LENGTH] = {"2", "2", "+"};
    char expr2[][MAX_EXPR_LENGTH] = {"2", "2", "+", "3", "*"};
	char expr3[][MAX_EXPR_LENGTH] = {"4.876555", "7", "3", "+", "*"};
	char expr4[][MAX_EXPR_LENGTH] = { "-4.8", "7", "3", "+", "*" };
	char expr5[][MAX_EXPR_LENGTH] = { "-4.8", "-7", "-3", "+", "*" };
	char expr6[][MAX_EXPR_LENGTH] = { "-0", "-7", "-3", "+", "*" };
	char expr7[][MAX_EXPR_LENGTH] = { "2.5", "-7", "-3", "+", "*", "-5.3", "/", "6.2", "-" };
	char expr8[][MAX_EXPR_LENGTH] = { "2.5", "-7", "-3", "+", "*", "0", "/", "6.2", "-" };
	char expr9[][MAX_EXPR_LENGTH] = { "2.2", "2.5", "-7", "-3", "+", "*", "-5.3", "/", "6.2", "-", "*"};
	char expr10[][MAX_EXPR_LENGTH] = { "2.5", "-7", "-3", "+", "*", "0.2", "/", "6.2", "-" };
	char expr11[][MAX_EXPR_LENGTH] = { "12333", "-2", "*" };

	printf("expr11 = %lf \n", eval(expr11, sizeof(expr11) / sizeof(expr11[0])));
	printf("expr6 = %lf \n", eval(expr6, sizeof(expr6) / sizeof(expr6[0])));
	assert(eval(expr6, sizeof(expr6) / sizeof(expr6[0])) == 0);
	printf("expr4 = %lf \n", eval(expr4, sizeof(expr4) / sizeof(expr4[0])));
	printf("expr5 = %lf \n", eval(expr5, sizeof(expr5) / sizeof(expr5[0])));
	printf("expr7 = %lf \n", eval(expr7, sizeof(expr7) / sizeof(expr7[0])));
	assert(eval(expr7, sizeof(expr7) / sizeof(expr7[0])) == 5.988);
	printf("expr8 = %lf \n", eval(expr8, sizeof(expr8) / sizeof(expr8[0])));
	printf("expr9 = %lf \n", eval(expr9, sizeof(expr9) / sizeof(expr9[0])));
	printf("expr10 = %lf \n", eval(expr10, sizeof(expr10) / sizeof(expr10[0])));





	printf("expr1 = %lf \n", eval( expr1, sizeof(expr1)/sizeof(expr1[0]) ) );
    	assert( eval( expr1, sizeof(expr1)/sizeof(expr1[0]) ) == 4 );
	
	printf("expr2 = %lf \n", eval( expr2, sizeof(expr2)/sizeof(expr2[0]) ) );
    	assert( eval( expr2, sizeof(expr2)/sizeof(expr2[0]) ) == 12 );

	printf("expr3 = %lf \n", eval( expr3, sizeof(expr3)/sizeof(expr3[0]) ) );
    	assert( eval( expr3, sizeof(expr3)/sizeof(expr3[0]) ) == 48.76555 );
    
	printf("All tests passed successfully :-) \n");
}


#define WINDOW_SIZE 2

void log_mgr_tests() {
	/////////////////////////
	
	queue *str = queue_init();
	enqueue(str, 1);
	int x = queue_size(str);
	enqueue(str, 2);
	enqueue(str, 3);
	x = queue_size(str);
	insert(str, 9, 2);
	x = queue_index_of(str, 1);
	queue_print(str);
	

	//////////////////////
    log_manager *log = create_log_mgr( WINDOW_SIZE );
	/*assert(add_to_log(log,-1 ) == 1);
	assert(add_to_log(log, 0 ) == 2);
	assert(add_to_log(log, 2 ) == 2);*/
    assert( add_to_log( log, 1 ) == 1 );
    assert( add_to_log( log, 2 ) == 2 );
    assert( add_to_log( log, 3 ) == 3 );
    assert( add_to_log( log, 4 ) == 3 );
    assert( add_to_log( log, 4 ) == 4 );
    assert( add_to_log( log, 10 ) == 1 );
	assert(add_to_log(log, 10) == 2);
	assert(add_to_log(log, 12) == 3);
	




	printf("All tests passed successfully :-) \n");
	getchar();
}
