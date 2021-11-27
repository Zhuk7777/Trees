#include"Tree.h"
#include<iostream>
#include<fstream>

int dist(std::string a, std::string b, int i, int j)
{
	if (i == 0 || j == 0)//если строка пустая, то расстояние равно либо j-му количеству вставок либо i раз удалить элемент из строки 
		return std::max(i, j);

	else {

		if (a[i] == b[j])//если последние символы одинаковые, то не трогаем их и переходим к подстрокам до этих символов
			return dist(a, b, i - 1, j - 1);

		else
			return 1 + std::min(dist(a, b, i - 1, j),//удаление символа
				std::min(dist(a, b, i, j - 1),//вставка символа
					dist(a, b, i - 1, j - 1)));//замена символа

	}
}

double similarity(std::string a, std::string b)
{
	int i = a.size() - 1;
	int j = b.size() - 1;

	double distance = dist(a, b, i, j);
	double bigger = std::max(a.size(), b.size());
	double pct = ((bigger - distance) / bigger) * 100;

	return pct;
}

int main()
{
	setlocale(0, "");
	return 0;
}