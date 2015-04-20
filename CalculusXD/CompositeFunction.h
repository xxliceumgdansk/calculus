#ifndef COMPOSITEFUNCTION_H
#define COMPOSITEFUNCTION_H

#include<vector>
#include<string>

using namespace std;


class CompositeFunction
{
    public:
        CompositeFunction(string entryFunction);
        virtual ~CompositeFunction();
    protected:
    private:
    	string entryFunction;
    	void distributingOfFunction();
    	
};

#endif // COMPOSITEFUNCTION_H

