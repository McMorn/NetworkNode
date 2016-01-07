#include "files.h"

void Save(string path, Node* node, int n, int t)
{
	fstream file;
	file.open(path, ios::out);

	file << "Czas trwania symulacji: " << t << "ms" << endl;
	file << "Odst�p pomi�dzy pakietami: " << n << "ms" << endl << endl;

	file << "Obs�u�ono pakiet�w: " << node->GetProceed() << endl;
	file << "�rednia d�ugo�� pakietu: " << node->GetAverageSize() << endl;
	file << "Najd�u�szy pakiet: " << node->GetMaxSize() << endl;
	file << "Najkr�tszy pakiet: " << node->GetMinSize() << endl;
	file << "Ilo�� znak�w numerycznych: " << node->GetDigit() << endl;
	file << "Ilo�� znak�w alfabetycznych: " << node->GetAlpha() << endl;
	file << "Ilo�� pakiet�w pozosta�ych w kolejce: " << node->GetQueue() << endl;

	file.close();
}