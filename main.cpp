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

void showHelp()
{
	cout << "Program nalezy uruchomic z nastêpuj¹cymi parametrami:" << endl;
	cout << "-n <odstep pomiedzy pakietami>" << endl;
	cout << "-t <czas symulacji>" << endl;
	cout << "-o <sciezka do pliku wyjsciowego>";

	_getch();
	exit(0);
}

void initProgram(int paramSize, char *param[])
{
	bool time = false, symTime = false, oFile = false;	// flagi
	
	for (int i = 0; i < paramSize; i++)
	{
		if (strcmp(param[i], "-n") == 0)
		{
			n = atoi(param[i + 1]);
			time = true;
		}
		if (strcmp(param[i], "-t") == 0)
		{
			t = atoi(param[i + 1]);
			symTime = true;
		}
		if (strcmp(param[i], "-o") == 0)
		{
			filePath = param[i + 1];
			oFile = true;
		}
		if (strcmp(param[i], "-h") == 0)
		{
			showHelp();
		}
	}

	if (!time || !symTime || !oFile)
		showHelp();
}

void setTime(int time)
{
	currentTime += time;
}

bool getTime()
{
	if (currentTime < t)
		return false;
	cout << "Przekroczono czas. Konczenie pracy programu..." << endl << endl;
	return true;
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
		//cout << "Obecny czas: " << currentTime << endl;
	}
}

void ShowStats()
{
	cout << "Czas trwania symulacji: " << t << "ms" << endl;
	cout << "Odstep pomiedzy pakietami: " << n << "ms" << endl << endl;

	cout << "Obsluzono pakietow: " << node->GetProceed() << endl;
	cout << "Srednia d³ugosc pakietu: " << node->GetAverageSize() << endl;
	cout << "Najdluzszy pakiet: " << node->GetMaxSize() << endl;
	cout << "Najkrotszy pakiet: " << node->GetMinSize() << endl;
	cout << "Ilosc znakow numerycznych: " << node->GetDigit() << endl;
	cout << "Ilosc znakow alfabetycznych: " << node->GetAlpha() << endl;
	cout << "Ilosc pakietow pozostalych w kolejce: " << node->GetQueue() << endl;
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

	Save(filePath, node, n, t);
	ShowStats();

	_getch();
	return 0;
}