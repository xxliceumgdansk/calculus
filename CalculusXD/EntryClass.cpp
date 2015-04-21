#include "EntryClass.h"

using namespace std;

EntryClass::EntryClass(string entry)
{
	FunctionPiece entryFunction(entry, 1);
    parseOnAddition(entryFunction);
}

//TODO narazie rozpoznaje tylko mnozenie przed funkcja bez '*', dodaj zeby dzialalo z '*', moze nie dzialac jak poczatek zaczyna sie od '-';
void EntryClass::parseOnAddition(FunctionPiece entry)
{
	FunctionPiece tempFunctionPiece("", 0);

    int startOfAPiece=0;
    int parenthesisNumber = 0;

    for(int i=0; i<entry.mainFunction.length(); i++)
    {
        if(entry.mainFunction[i]=='(')
            parenthesisNumber++;
        else if(entry.mainFunction[i]==')')
            parenthesisNumber--;
        else if(canParseFunctionThere(entry.mainFunction[i], parenthesisNumber) || i==(entry.mainFunction.length()-1)) //dzieli na znakach +/- i ostatni kawalek
        {            
            tempFunctionPiece.token=setTokenSign(entry.mainFunction[startOfAPiece]);
            if(startOfAPiece == 0)
            	tempFunctionPiece.token=1;
            
            int j = startOfAPiece + 1;
			
			tempFunctionPiece.token*=setTokenValue(entry.mainFunction, j, i);
			tempFunctionPiece.token*=entry.token; //mnozysz razy token przed cala podana funkcja(nawiasy itp)
			tempFunctionPiece.mainFunction = setMainFunction(entry.mainFunction, j, i);

            if(i==entry.mainFunction.length()-1)
            	tempFunctionPiece.mainFunction+=entry.mainFunction[i];
            	
            function.push_back(tempFunctionPiece);
            startOfAPiece=i;
            tempFunctionPiece.mainFunction = "";
            tempFunctionPiece.token = 0;
        }     
    }
    for(int j=parsedFunctions; j<function.size(); j++)
    {
    	if(isCompletelyParsed(function[j]))
    	{
    		//TODO usun poczatek i koniec ('(' i ')')
    		parseOnAddition(function[j]);
    		//TODO function[i].erase
    		parsedFunctions = j-1;
    	}
    }
    return;
}

bool EntryClass::canParseFunctionThere(char character, int paranthesisNumber)
{
	if((character=='+' || character=='-') && paranthesisNumber == 0)
		return true;
		
	return false;
}

int EntryClass::setTokenSign(char startingSign)
{
	if(startingSign=='-')
		return -1; 
	else
		return 1;
}

int EntryClass::setTokenValue(string entry, int &start, int end)
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

string EntryClass::setMainFunction(string entry, int &start, int end)
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

bool EntryClass::isCompletelyParsed(FunctionPiece functionPiece)
{
	if(functionPiece.mainFunction[0] == '(')
		return false;
		
	return true;

}


EntryClass::~EntryClass()
{
	
}
