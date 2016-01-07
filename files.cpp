#include "files.h"

void Save(string path, Node* node)
{
	fstream file;
	file.open(path, ios::out);

	file << "Obs�u�ono pakiet�w: " << node->GetProceed() << endl;
	file << "Ilo�� znak�w numerycznych: " << node->GetDigit() << endl;
	file << "Ilo�� znak�w alfabetycznych: " << node->GetAlpha() << endl;
	file << "Ilo�� pakiet�w pozosta�ych w kolejce: " << node->GetQueue() << endl;

	file.close();
}