#include "files.h"

void Save(string path, Node* node, int n, int t)
{
	fstream file;
	file.open(path, ios::out);

	file << "Czas trwania symulacji: " << t << "ms" << endl;
	file << "Odstêp pomiêdzy pakietami: " << n << "ms" << endl << endl;

	file << "Obs³u¿ono pakietów: " << node->GetProceed() << endl;
	file << "Œrednia d³ugoœæ pakietu: " << node->GetAverageSize() << endl;
	file << "Najd³u¿szy pakiet: " << node->GetMaxSize() << endl;
	file << "Najkrótszy pakiet: " << node->GetMinSize() << endl;
	file << "Iloœæ znaków numerycznych: " << node->GetDigit() << endl;
	file << "Iloœæ znaków alfabetycznych: " << node->GetAlpha() << endl;
	file << "Iloœæ pakietów pozosta³ych w kolejce: " << node->GetQueue() << endl;

	file.close();
}