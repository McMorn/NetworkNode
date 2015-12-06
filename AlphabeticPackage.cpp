#include "Package.h"

AlphabeticPackage::AlphabeticPackage()
{
	packageLength = GenerateSize();
	package = "";
}

string AlphabeticPackage::GeneratePackage()
{
	for (int i = 0; i < packageLength; i++)
	{
		package += alphanum[rand() % (sizeof(alphanum) - 11) + 10];
	}
	return package;
}