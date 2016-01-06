#pragma once

#include <iostream>
#include <string.h>
#include <ctime>

#define MIN 10
#define MAX 255

using namespace std;

static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

class Package
{
protected:
	string package;
	int packageLength;

	int GenerateSize();
	string virtual GeneratePackage() = 0;

public:
	int GetLength();
	string GetPackage();
};

class NumericPackage : public Package
{
	string GeneratePackage();

public:
	NumericPackage();
};

class AlphabeticPackage : public Package
{
	string GeneratePackage();

public:
	AlphabeticPackage();
};

class AlphaNumericPackage : public Package
{
	string GeneratePackage();

public:
	AlphaNumericPackage();
};