#include "Package.h"

AlphaNumericPackage::AlphaNumericPackage()
{
	packageLength = GenerateSize();
	package = "";
}

string AlphaNumericPackage::GeneratePackage()
{
	for (int i = 0; i < packageLength; i++)
	{
		package += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return package;
}