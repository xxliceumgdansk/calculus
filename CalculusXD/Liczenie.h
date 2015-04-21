#ifndef LICZENIE_H
#define LICZENIE_H


#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class Liczenie
{
private:
	long long coefficient;
	string function;
	string type;
public:
	Liczenie(string x, string y, long long coeff);
	string monomial();
	string trigonometry();
	string powerFunction();
	string exponentialBasedE();
	string logarithmBasedE();
	string exponentialBasedA();
	string logarithmBasedA();
	
	//empty space for composition of functions???
	
	//string multi(string function);
	//string division(string function);								
};	//smuteg

#endif