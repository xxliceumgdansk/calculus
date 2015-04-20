#include "EntryClass.h"
#include <cmath>
#include <iostream>
using namespace std;

EntryClass::EntryClass(string entry)
{
    this->entry = entry;
    parseOnAddition();
}

//TODO narazie rozpoznaje tylko mnozenie przed funkcja bez '*', dodaj zeby dzialalo z '*', moze nie dzialac jak poczatek zaczyna sie od '-';
void EntryClass::parseOnAddition()
{
	functionPiece tempFunctionPiece;
	tempFunctionPiece.mainFunction = "";
    tempFunctionPiece.token = 0;

    int startOfAPiece=0;
    int parenthesisNumber = 0;

    for(int i=0; i<entry.length(); i++)
    {
        if(entry[i]=='(')
            parenthesisNumber++;
        else if(entry[i]==')')
            parenthesisNumber--;
        else if(canParseFunctionThere(entry[i], parenthesisNumber) || i==(entry.length()-1)) //dzieli na znakach +/- i ostatni kawalek
        {
                

            tempFunctionPiece.token=setTokenSign(entry[startOfAPiece]);
            if(startOfAPiece == 0)
            	tempFunctionPiece.token=1;
            
            int j = startOfAPiece + 1;
			
			tempFunctionPiece.token*=setTokenValue(j, i);
			tempFunctionPiece.mainFunction = setMainFunction(j, i);

            if(i==entry.length()-1)
            	tempFunctionPiece.mainFunction+=entry[i];
            	
            function.push_back(tempFunctionPiece);
            startOfAPiece=i;
            tempFunctionPiece.mainFunction = "";
            tempFunctionPiece.token = 0;
        }

    }

    return;
}

int EntryClass::setTokenValue(int &start, int end)
{
	string value="";
	int i=start;
	for(i; isANumber(entry[i]) && i < end; i++)
	{
		value+=entry[i];
	}
	
	start = i;
	return stringToInt(value);
}

string EntryClass::setMainFunction(int &start, int end)
{
	string mainFunction = "";
	int i = start;
	for(i; i < end; i++)
	{
		mainFunction+=entry[i];
	}
	
	start = i;
	return mainFunction;
}

bool EntryClass::canParseFunctionThere(char character, int paranthesisNumber)
{
	if((character=='+' || character=='-') && paranthesisNumber == 0)
		return true;
		
	return false;
}

int EntryClass::setTokenSign(char startingSign) //zmien nazwe
{
	if(startingSign=='-')
		return -1; 
	else
		return 1;
}

bool EntryClass::isANumber(char character)
{
	if((int)character <= 57  && (int)character >= 48) //na podstawie kodu ACII
		return true;
		
	return false; 
}


int EntryClass::stringToInt(string iString)
{
	int oInt=0;
	
	for(int j=iString.length()-1; j>=0; j--) 
    {
    	oInt+=(pow(10, (iString.length()-j-1)))*((int)iString[j]-48); // -48 z ASCII
    }
	
	return oInt;
}

EntryClass::~EntryClass()
{
	
}
