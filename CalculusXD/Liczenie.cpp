#include "Liczenie.h"
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
	ostringstream show;
	if(function[0]=='s')
	{
		show << coefficient << "cos";
		int i=3;
		while(function[i]!=')')
		{
			show << function[i];
			i++;
		}
		show << ')';
		return show.str();
	}
	if(function[0]=='c' && function[1]=='o')
	{
		coefficient*=(-1);
		show << coefficient << "sin";
		int i=3;
		while(function[i]!=')')
		{
			show << function[i];
			i++;
		}
		show << ')';
		return show.str();
	}
	if(function[0]=='t')
	{
		show << coefficient << "/(" << "cos";
		int i=3;
		while(function[i]!=')')
		{
			show << function[i];
			i++;
		}
		show << "))^2";
		return show.str();
	}
	if(function[0]=='c' && function[1]=='t')
	{
		show << (-1)*coefficient << "/(" << "sin";
		int i=3;
		while(function[i]!=')')
		{
			show << function[i];
			i++;
		}
		show << "))^2";
		return show.str();
	}
}

string Liczenie::powerFunction()
{
	long long denominator = 0;
	int j = function.length()-2;
	while(function[j]!='/')
	{
		denominator += pow(10, function.length()-2-j) * (function[j] - 48);
		j--;
	}
	int k=j;
	j--;
	long long nominator = 0;
	while(function[j]!='(')
	{
		if(function[j]=='-')
		{
			nominator*=(-1);
			j--;
		}
		else
		{
			nominator += pow(10, k-j-1) * (function[j] - 48);
			j--;
		}
	}
	
	coefficient*=nominator;
	nominator-=denominator;
	ostringstream show;
	show << coefficient;
	int i=0;
	while(i<=j)
	{
		show << function[i];
		i++;
	}
	show << nominator << '/' << denominator << ')' << '/' << denominator;
	return show.str();
}

string Liczenie::exponentialBasedE()
{
	ostringstream show;
	show << coefficient << function;
	return show.str();
}

string Liczenie::exponentialBasedA()
{
	ostringstream show;
	string a = "";
	int i=0;
	while(function[i]!='^')
	{
		a+=function[i];
		i++;
	}
	show << coefficient << '*' << function << "*ln(" << a << ')';
	return show.str();
}

string Liczenie::logarithmBasedE()
{
	ostringstream show;
	show << coefficient << "/(";
	int j=3;
	while(function[j]!=')')
	{
		show << function[j];
		j++;
	}
	show << ')';
	return show.str();
}

string Liczenie::logarithmBasedA()
{
	ostringstream show;
	show << coefficient << "/((";
	int i=0;
	while(true)
	{
		if(function[i]!='(')
			i++;
		else
			break;
	}
	int stop=i;
	i++;
	while(function[i]!=')')
	{
		show << function[i];
		i++;
	}
	show << ")*ln(";
	int j=3;
	while(j<stop)
	{
		show << function[j];
		j++;
	}
	show << "))";
	return show.str();
}