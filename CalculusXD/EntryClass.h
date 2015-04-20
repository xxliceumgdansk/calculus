#ifndef ENTRYCLASS_H
#define ENTRYCLASS_H

#include<vector>
#include<string>

using namespace std;

struct functionPiece
{
    string mainFunction; 
    int token;  
};

class EntryClass
{
    public:
        vector<functionPiece> function;
        EntryClass(string entry);
        virtual ~EntryClass();
    protected:
    private:
        string entry;
        void parseOnAddition();
        int setTokenValue(int &start, int end);
        string setMainFunction(int &start, int end);
        int setTokenSign(char startingSign);
        bool canParseFunctionThere(char character, int paranthesisNumber);
        bool isANumber(char character);
        int stringToInt(string stringToken);
};

#endif // ENTRYCLASS_H

