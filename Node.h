#pragma once
#include <queue>
#include "Package.h"

class Node
{
	bool working;
	std::queue< Package > queue;
	int time;

	void PackageProcessing(Package& p);

public:
	Node();
};
