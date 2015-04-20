#include <iostream>
#include "EntryClass.h"

using namespace std;

int main()
{
    /*Liczenie syf("112x^19", "Syf");
	string a=syf.monomial();
	cout<<a;
	return 0;*/
	
	EntryClass syf("25x^(28) + 54sin(x)^(2)");
	for(int i=0; i<syf.function.size(); i++)
	{
		cout << syf.function[i].token << " to byl token " << syf.function[i].mainFunction << endl;
	}
	
	return 0;
}

//(sin(e^(2(cos(x-1)))))^(2)*cos(tg(x^(1/2)-pi/2)) 