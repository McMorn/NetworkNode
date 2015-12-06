#include "Package.h"

NumericPackage::NumericPackage()
{
	packageLength = GenerateSize();
	package = "";
}

string NumericPackage::GeneratePackage()
{
	for (int i = 0; i < packageLength; i++)
	{
		package += alphanum[rand() % 10];
	}
	return package;
}