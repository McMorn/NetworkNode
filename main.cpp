#include <iostream>
#include <conio.h>
#include <string>
#include "Package.h"


int main()
{
	srand(time(NULL));

	Package package = Package();
	string str = package.generatePackage();

	cout << str;

	_getch();
	return 0;
}