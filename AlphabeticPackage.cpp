#include "Package.h"

AlphabeticPackage::AlphabeticPackage()
{
	GeneratePackage();
}

void AlphabeticPackage::GeneratePackage()
{
	packageLength = GenerateSize();
	package = "";
	for (int i = 0; i < packageLength; i++)
	{
		package += alphanum[rand() % (sizeof(alphanum) - 11) + 10];
	}
}