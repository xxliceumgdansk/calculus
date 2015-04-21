#include <iostream>
#include "Liczenie.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


//using namespace std;

/*int main()
{
	Liczenie xd("x^15", "Syf", 13);
	string b=xd.monomial();
	cout << b;
	return 0;
}*/
/*/Liczenie xd (mainFunction, coeeficent)

	if(jestTrygonometryczna)
	{
		xd.trigonometry();
	}
	else if(jest monomialem)
*/
TEST_CASE( "Monomials are computed") {
	Liczenie xd("x^15", "Syf", 13);
    REQUIRE( xd.monomial() == "195x^14");
}

TEST_CASE("simple logarithm")
{
	Liczenie xd("log14(5x+1)", "Syf", 13);
	REQUIRE( xd.logarithmBasedA() == "13/((5x+1)*ln(14))");
}