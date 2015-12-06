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

public:
	string virtual GeneratePackage() = 0;
};

class NumericPackage : public Package
{
public:
	NumericPackage();
	string GeneratePackage();
};

class AlphabeticPackage : public Package
{
public:
	AlphabeticPackage();
	string GeneratePackage();
};

class AlphaNumericPackage : public Package
{
public:
	AlphaNumericPackage();
	string GeneratePackage();
};