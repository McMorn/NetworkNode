#include <iostream>
#include <conio.h>
#include <string>
#include "Package.h"
#include "Node.h"
#include "stats.h"
#include "files.h"

int n, t;
string filePath;
int currentTime = 0;

Node* node = new Node();
AlphabeticPackage* alphaPk = new AlphabeticPackage();
NumericPackage* numericPk = new NumericPackage();
AlphaNumericPackage* alphanumPk = new AlphaNumericPackage();

Package *pck = alphaPk;

void initProgram(int paramSize, char *param[])
{
	for (int i = 0; i < paramSize; i++)
	{
		if (strcmp(param[i], "-n") == 0)
		{
			n = atoi(param[i + 1]);
		}
		if (strcmp(param[i], "-t") == 0)
		{
			t = atoi(param[i + 1]);
		}
		if (strcmp(param[i], "-o") == 0)
		{
			filePath = param[i + 1];
		}
	}
}

void setTime(int time)
{
	currentTime += time;
}

void generatePackage()
{
	if (currentTime % n == 0)
	{
		switch ((rand() % (3 - 1 + 1)) + 1)
		{
		case 1:
			pck = alphaPk;
			break;
		case 2:
			pck = numericPk;
			break;
		case 3:
			pck = alphanumPk;
			break;
		}
		pck->GeneratePackage();
		node->ReceivePackage(pck);
		cout << "Obecny czas: " << currentTime << endl;
	}
}

int main(int argc, char ** argv)
{
	srand(time(NULL));
	initProgram(argc, argv);
	
	while (currentTime < t)
	{
		generatePackage();
		node->Processing();
		currentTime++;
	}

	Save(filePath, node);

	_getch();
	return 0;
}