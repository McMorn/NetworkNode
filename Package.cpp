#include "Package.h"


int Package::GenerateSize()
{
	return (rand() % (MAX - MIN + 1)) + MIN;
}

int Package::GetLength()
{
	return packageLength;
}

string Package::GetPackage()
{
	return package;
}