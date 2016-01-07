#include "Node.h"

Node::Node()
{
	working = false;
	time = 0;
	proceed = 0;
	digit = 0;
	alpha = 0;
	size = 0;
	minSize = 255;
	maxSize = 0;
}

void Node::ReceivePackage(Package* package)
{
	pck.content = package->GetPackage();
	pck.size = package->GetLength();
	pck.toDo = true;

	//cout << "Receive package" << endl;

	if (working)
	{
		queue.push(pck);
		//cout << "Package pushed into the queue. Packages in queue: " << queue.size() << endl;
	}
}

void Node::Processing()
{
	working = true;
	if (!queue.empty())
	{
		active = queue.front();
		queue.pop();
		//cout << "Package pop out of the queue. Packages in queue: " << queue.size() << endl;
	}
	else if (pck.toDo)
	{
		active = pck;
		pck.toDo = false;
	}
	if (active.toDo)
	{
		size += active.size;
		minSize = (active.size < minSize) ? active.size : minSize;
		maxSize = (active.size > maxSize) ? active.size : maxSize;
		//cout << "Stat processing package..." << endl;
		for (int i = 0; i < active.size; i++)
		{
			if (isdigit(active.content[i]))
			{
				time += 1;
				setTime(1);
				digit++;
			}
			else
			{
				time += 2;
				setTime(2);
				alpha++;
			}
			generatePackage();
			
			if (getTime()) return;
		}
		active.toDo = false;
		proceed++;
		//cout << "Package proceed!" << endl;
	}
	working = false;
}

int Node::GetAlpha()
{
	return alpha;
}

int Node::GetDigit()
{
	return digit;
}

int Node::GetProceed()
{
	return proceed;
}

int Node::GetQueue()
{
	return queue.size();
}

int Node::GetAverageSize()
{
	return size / proceed;
}

int Node::GetMinSize()
{
	return minSize;
}

int Node::GetMaxSize()
{
	return maxSize;
}