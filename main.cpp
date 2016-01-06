#include <iostream>
#include <conio.h>
#include <string>
#include "Package.h"

int n, t;

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
	}
}

int main(int argc, char ** argv)
{
	srand(time(NULL));
	initProgram(argc, argv);

	cout << argc << " " << n << " " << t;

	_getch();
	return 0;
}