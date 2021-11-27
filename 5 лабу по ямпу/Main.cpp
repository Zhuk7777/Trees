#include"Tree.h"
#include<iostream>
#include<fstream>

void createTree(BinaryTree& tree, std::ifstream& fin)
{
	std::string word;

	while (getline(fin, word)&&word!="")
	{
		tree.insertElem(word);
	}

}


int main()
{
	setlocale(0, "");

	BinaryTree tree;

	std::ifstream fin;
	std::string path = "file.txt";

	fin.open(path);
	if (!fin.is_open()) {
		std::cout << "ошибка открыти€ файла\n";
		return 0;
	}

	createTree(tree, fin);
	fin.close();

	std::string word;

	std::cout << "¬ведите слово\n";
	std::cin >> word;

	tree.searchWord(word);

	return 0;
}