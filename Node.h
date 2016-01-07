#pragma once
#include <queue>
#include <cctype>
#include "Package.h"
#include "stats.h"


class Node
{
	struct PCK
	{
		int size;
		string content;
		bool toDo;
	};
	PCK pck;
	PCK active;
	bool working;
	std::queue<PCK> queue;
	int time;
	int proceed, size, minSize, maxSize, digit, alpha;
	

public:
	Node();

	void ReceivePackage(Package* package);
	void Processing();

	int GetDigit();
	int GetAlpha();
	int GetProceed();
	int GetQueue();
	int GetAverageSize();
	int GetMinSize();
	int GetMaxSize();
};
