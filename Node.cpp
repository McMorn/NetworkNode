#include "Node.h"

Node::Node()
{
	working = false;
	time = 0;
}

void Node::PackageProcessing(Package& p)
{
	string pstr = p.GetPackage();
	for (int i = 0; i < p.GetLength(); i++)
	{

	}
}