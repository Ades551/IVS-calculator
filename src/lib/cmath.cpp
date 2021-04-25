#include "cmath.h"
#include <math.h>
#include <stdexcept>

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
		throw std::invalid_argument("Division by zero!");
    return dividend / divisor;
}

double CalcMath::pow(double basis, double exponent){
    return std::pow(basis,exponent);
}

double CalcMath::root(double degree, double number){
	if(degree != lround(degree))
		throw std::invalid_argument("nth root, n is not an integer!");
	if(degree < 1)
		throw std::invalid_argument("nth root, n is lower than 1!");
	long ln_root = lround(degree);
	if(number < 0 && (ln_root % 2) == 0)
		throw std::invalid_argument("nth root, number cannot be negative if root is even!");
	if(number < 0)
		return -std::pow(-number,1/degree);
	return std::pow(number,1/degree);
}

double CalcMath::log(double basis, double number){
	if(basis <= 0)
		throw std::invalid_argument("basis cannot be lower or equal to zero!");
	if(basis == 1)
		throw std::invalid_argument("basis cannot be 1!");
	if(number <= 0)
		throw std::invalid_argument("number cannot be lower or equal to zero!");
	return std::log(number)/std::log(basis);
}

unsigned long CalcMath::fact(double number){
	if(number < 0 || number != lround(number))
		throw std::invalid_argument("number must be positive integer!");
	unsigned long fact = 1;
	for(unsigned long i = number; i > 1;i--)
		fact *= i;
	return fact;
}