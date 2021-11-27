#include"Tree.h"
#include<iostream>
#include<fstream>

int dist(std::string a, std::string b, int i, int j)
{
	if (i == 0 || j == 0)//���� ������ ������, �� ���������� ����� ���� j-�� ���������� ������� ���� i ��� ������� ������� �� ������ 
		return std::max(i, j);

	else {

		if (a[i] == b[j])//���� ��������� ������� ����������, �� �� ������� �� � ��������� � ���������� �� ���� ��������
			return dist(a, b, i - 1, j - 1);

		else
			return 1 + std::min(dist(a, b, i - 1, j),//�������� �������
				std::min(dist(a, b, i, j - 1),//������� �������
					dist(a, b, i - 1, j - 1)));//������ �������

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