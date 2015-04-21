#define CATCH_CONFIG_MAIN
#include "CatchUnitTest.hpp"

TEST_CASE( "Function is parsed") {
	EntryClass entryClass("23535x^15326+23sin(x)^123-543x^22+54x^12")
    for(int i=0; i<entryClass.function.size(); i++)
    	REQUIRE( entryClass.function );
}

