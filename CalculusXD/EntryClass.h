#ifndef ENTRYCLASS_H
#define ENTRYCLASS_H

#include<vector>
#include<string>
#include<cmath>

using namespace std;

struct FunctionPiece
{
    string mainFunction;
    int token;
    
    FunctionPiece(string mainFunction, int token)
    {
    	this->mainFunction = mainFunction;
    	this->token = token;
    };
};

class EntryClass
{
    public:
        vector<FunctionPiece> function;
        EntryClass(string entry);
        virtual ~EntryClass();
    protected:
    private:
        void parseOnAddition(FunctionPiece entry);
        
        bool canParseFunctionThere(char character, int paranthesisNumber);
        int setTokenSign(char startingSign);        
        int setTokenValue(string entry, int &start, int end);
        string setMainFunction(string entry, int &start, int end);
        bool isANumber(char character);
        int stringToInt(string stringToken);
        bool isCompletelyParsed(FunctionPiece functionPiece);
        
        int parsedFunctions = 0;
};

#endif // ENTRYCLASS_H

