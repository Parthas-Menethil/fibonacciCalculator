/**
 * Author: Luke Jingwei Sun
 * Version: 1.0
 * Last Update: February 9th, 2014
 * Compile command:  g++ Calc.cpp -lgmpxx -lgmp
*/ 
#include <stdio.h>
#include <gmp.h>
#include <iostream>
#define PRECISION 16384
#define OUTPUT_DIGITS 1000
using namespace std;
int main(){
	mpf_t cst_numone;
	mpf_t integ, five_rt, inver_five_rt, cst_one, cst_two;
	mpf_init2 (integ, PRECISION);
	mpf_init2  (five_rt, PRECISION);
	mpf_init2  (inver_five_rt, PRECISION);
	mpf_init2  (cst_one, PRECISION);
	mpf_init2  (cst_two, PRECISION);
	mpf_init2 (cst_numone, PRECISION);
	
	mpf_set_str(five_rt, "5", 10);
	mpf_set_str(inver_five_rt, "5", 10);
	mpf_set_str(cst_one, "1", 10);
	mpf_set_str(cst_two, "1", 10);
	mpf_set_str(cst_numone, "1", 10);
	
	
	
	
	unsigned long int num = 0u;
	printf("Please enter a number:");
	cin >> num;
	
	mpf_sqrt (five_rt, five_rt);
	mpf_div(inver_five_rt, cst_numone, five_rt);
	
	mpf_add (cst_one, cst_one, five_rt);
	mpf_sub (cst_two, cst_two, five_rt);
	
	mpf_div_ui  (cst_one, cst_one, 2);
	mpf_div_ui  (cst_two, cst_two, 2);
	
	mpf_pow_ui (cst_one, cst_one, num);
	mpf_pow_ui (cst_two, cst_two, num);
	
	mpf_sub (cst_one, cst_one, cst_two);
	
	mpf_mul (integ, cst_one, inver_five_rt);
	
	gmp_printf ("Resule %.*Ff with %d digits\n", OUTPUT_DIGITS, integ, OUTPUT_DIGITS);
	
	mpf_clear (integ);
	mpf_clear (five_rt);
	mpf_clear (inver_five_rt);
	mpf_clear (cst_one);
	mpf_clear (cst_two);
	mpf_clear (cst_numone);
	return 0;
}