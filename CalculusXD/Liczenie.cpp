/*#include "Liczenie.h"
using namespace std;

Liczenie::Liczenie(string x, string y, long long coeff)
{
	function=x;
	type=y;
	coefficient = coeff;
}

string Liczenie::monomial()
{
	long long exponent = 0;
	int j = function.length()-1;
	while(function[j]!='^')
	{
		exponent += pow(10, function.length()-1-j) * (function[j] - 48);
		j--;
	}
	
	coefficient*=exponent;
	exponent--;
	
	ostringstream show;
	show << coefficient;
	int i=0;
	while(i<=j)
	{
		show << function[i];
		i++;
	}
	show << exponent;
	return show.str();
}

string Liczenie::trigonometry()
{
	

}*/
