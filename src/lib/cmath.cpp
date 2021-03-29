#include "cmath.h"
#include <math.h>
#include "stdio.h"

double CalcMath::add(double number_1, double number_2){
    return number_1 + number_2;
}

double CalcMath::sub(double number_1, double number_2){
    return number_1 - number_2;
}

double CalcMath::mult(double number_1, double number_2){
    return number_1 * number_2;
}

double CalcMath::div(double dividend, double divisor){
	if(divisor == 0)
		return false;
    return dividend / divisor;
}

double CalcMath::pow(double basis, double exponent){
    return std::pow(basis,exponent);
}

double CalcMath::root(double n_root, double number){
	if(n_root != lround(n_root) || n_root < 1)
		return false;
	long ln_root = lround(n_root);
	if(number < 0 && (ln_root % 2) == 0)
		return false;
	if(number < 0)
		return -std::pow(-number,1/n_root);
	return std::pow(number,1/n_root);
}

double CalcMath::log(double basis, double logarithm){
	if(basis <= 0 || basis == 1 || logarithm <= 0)
		return false;
	return std::log(logarithm)/std::log(basis);
}

unsigned long CalcMath::fact(double number){
	if(number < 0 || number != lround(number))
    	return false;
	unsigned long fact = 1;
	for(unsigned long i = number; i > 1;i--)
		fact *= i;
	return fact;
}