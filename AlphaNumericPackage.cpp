#include "Package.h"

AlphaNumericPackage::AlphaNumericPackage()
{
	GeneratePackage();
}

void AlphaNumericPackage::GeneratePackage()
{
	packageLength = GenerateSize();
	package = "";
	for (int i = 0; i < packageLength; i++)
	{
		package += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
}