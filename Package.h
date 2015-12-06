#pragma once

#include <iostream>
#include <string.h>
#include <ctime>

#define MIN 10
#define MAX 255

using namespace std;

class Package
{
public:
	Package();
	~Package();

	string generatePackage();

private:
	string _package;
};