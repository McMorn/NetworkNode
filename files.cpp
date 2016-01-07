#include "files.h"

void Save(string path, Node* node)
{
	fstream file;
	file.open(path, ios::out);

	file << "Obs³u¿ono pakietów: " << node->GetProceed() << endl;
	file << "Iloœæ znaków numerycznych: " << node->GetDigit() << endl;
	file << "Iloœæ znaków alfabetycznych: " << node->GetAlpha() << endl;
	file << "Iloœæ pakietów pozosta³ych w kolejce: " << node->GetQueue() << endl;

	file.close();
}