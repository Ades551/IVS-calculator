#include <iostream>
#include "../lib/cmath.h"
#include <stdlib.h>

int main() {
	double *numbers;
	double num;
	double arith2 = 0;
	double sum2 = 0;
	double s = 0;

	numbers = (double *) malloc(sizeof(double));
	if(numbers == NULL){
		std::cout << "Malloc failed" << std::endl;
		return 1;
	}
	numbers[0] = 0;

	while(std::cin >> num){
		numbers[0]++;
		numbers = (double *) realloc(numbers, sizeof(double) + sizeof(double) * numbers[0]);
		if(numbers == NULL){
			std::cout << "Realloc failed" << std::endl;
			return 1;
		}
		numbers[((int) numbers[0])] = num;
	}

	/*		Odtialto to ma aj cmath.h, ale nie v cykloch*/

	for(int i = 1; i<=numbers[0] ; i++){
		arith2 = CalcMath::add(arith2,numbers[i]);
		sum2 = CalcMath::add(sum2,CalcMath::pow(numbers[i],2));
	}
	arith2 = CalcMath::div(arith2,numbers[0]);
	arith2 = CalcMath::pow(arith2,2);
	arith2 = CalcMath::mult(arith2,numbers[0]);

	s = CalcMath::sub(sum2, arith2);
	s = CalcMath::div(s,CalcMath::sub(numbers[0],1));
	s = CalcMath::root(2,s);

	std::cout << s << std::endl;

	free(numbers);
	return 0;
}