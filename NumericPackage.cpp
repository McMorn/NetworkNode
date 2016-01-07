#include "Package.h"

NumericPackage::NumericPackage()
{
	GeneratePackage();
}

void NumericPackage::GeneratePackage()
{
	packageLength = GenerateSize();
	package = "";
	for (int i = 0; i < packageLength; i++)
	{
		package += alphanum[rand() % 10];
	}
}