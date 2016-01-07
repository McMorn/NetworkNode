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
	void virtual GeneratePackage() = 0;
	int GetLength();
	string GetPackage();
};

class NumericPackage : public Package
{
public:
	NumericPackage();
	void GeneratePackage();
};

class AlphabeticPackage : public Package
{
public:
	AlphabeticPackage();
	void GeneratePackage();
};

class AlphaNumericPackage : public Package
{
public:
	AlphaNumericPackage();
	void GeneratePackage();
};