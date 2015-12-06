#include "Package.h"

Package::Package()
{

}

Package::~Package()
{
	
}

string Package::generatePackage()
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	int packageLength = (rand() % (MAX - MIN + 1)) + MIN;
	_package = "";

	for (int i = 0; i < packageLength; i++)
	{
		_package += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return _package;
}