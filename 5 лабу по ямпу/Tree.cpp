#include "Tree.h"
#include<iostream>

BinaryTree::BinaryTree()
{
	root = nullptr;
	p = root;
}

BinaryTree::BinaryTree(std::string elem)
{
	root = new TreeNode;
	root->data = elem;
	p = root;
	root->left = nullptr;
	root->right = nullptr;
}

BinaryTree::~BinaryTree()
{
	clear(root);
	normalize();
}

BinaryTree::BinaryTree(const BinaryTree& obj)
{
	copy(obj.root, root);

}

BinaryTree& BinaryTree::operator=(const BinaryTree& obj)
{
	if (this == &obj)return *this;
	clear(root);
	copy(obj.root, root);
	return *this;
}

void BinaryTree::clear(TTree& obj)
{
	if (obj)
	{
		clear(obj->left);
		clear(obj->right);

		delete obj;
		obj = nullptr;
	}
}

void BinaryTree::copy(TTree obj,TTree & newRoot)
{
	if (obj)
	{
		newRoot = new TreeNode;
		newRoot->data = obj->data;
		newRoot->left = nullptr;
		newRoot->right = nullptr;
		copy(obj->left, newRoot->left);
		copy(obj->right, newRoot->right);
	}
	else
		newRoot = nullptr;
}

void BinaryTree::normalize()
{
	p = root;
}

void BinaryTree::insertElem(std::string elem)
{
	if (!root)
	{
		root = new TreeNode;
		root->data = elem;
		root->left = nullptr;
		root->right = nullptr;
		normalize();
	}
	else {

		int ind = 0;
		TTree cur = nullptr;

		while (p)
		{
			cur = p;

			ind = elem.compare(p->data);

			if (ind == -1)//если меньше
				p = p->left;
			if (ind == 1)//если больше
				p = p->right;
		}

		p = new TreeNode;
		p->data = elem;
		p->left = nullptr;
		p->right = nullptr;
		if (ind == -1)
			cur->left = p;
		if (ind == 1)
			cur->right = p;
		normalize();
	}
}

void BinaryTree::deleteElem(std::string elem)
{
	p = searchDomestic(elem);

	if (p->left == nullptr || p->right == nullptr)
	{
		delete p;
		p = nullptr;
	}
	else
	{
		TTree delNode;

		if (p->left == nullptr || p->right == nullptr)
		{
			delNode = p;

			if (p->left == nullptr)
				p = p->right;
			else
				p = p->left;

			delete delNode;
			delNode = nullptr;
		}

		else
			p->data = findSuccessor(p->right);
	}
	normalize();
}

bool BinaryTree::search(std::string elem)
{
	if (root)
	{
		while (p)
		{
			if (elem == p->data) {
				normalize();
				return 1;
			}
			if (elem < p->data)
				p = p->left;
			if (elem > p->data)
				p = p->right;
		}
	}

	normalize();

	return 0;
}

BinaryTree::TTree BinaryTree::searchDomestic(std::string elem)
{
	if (root)
	{
		while (p)
		{
			if (elem == p->data)
				return p;
			if (elem < p->data)
				p = p->left;
			if (elem > p->data)
				p = p->right;
		}
	}

	normalize();

	return nullptr;
}

void BinaryTree::printTree(int ind)
{
	printTreeDomestic(p, ind);
	normalize();
}

void BinaryTree::printTreeDomestic(TTree obj, int ind)//1-прямой,2-симметричный, 3-обратный
{
	switch (ind)
	{
	case 1:
		if (obj)
		{
			std::cout << obj->data << " ";
			printTreeDomestic(obj->left, ind);
			printTreeDomestic(obj->right, ind);
		}
		break;

	case 2:
		if (obj)
		{
			printTreeDomestic(obj->left, ind);
			std::cout << obj->data << " ";
			printTreeDomestic(obj->right, ind);
		}
		break;

	case 3:
		if (obj)
		{
			printTreeDomestic(obj->left, ind);
			printTreeDomestic(obj->right, ind);
			std::cout << obj->data << " ";
		}
		break;
	}
}

std::string BinaryTree::findSuccessor(TTree& obj)
{
	if (obj->left == nullptr)
	{
		std::string elem = obj->data;
		TTree delNode = obj;
		obj = obj->right;
		delete delNode;
		return elem;
	}
	else
		findSuccessor(obj->left);
}

int BinaryTree::dist(std::string a, std::string b, int i, int j)
{
	if (i == 0 || j == 0)//если строка пустая, то расстояние равно либо j-му количеству вставок либо i раз удалить элемент из строки 
		return std::max(i, j);

	else {

		if (a[i-1] == b[j-1])//если последние символы одинаковые, то не трогаем их и переходим к подстрокам до этих символов
			return dist(a, b, i - 1, j - 1);

		else
			return 1 + std::min(dist(a, b, i - 1, j),//удаление символа
				std::min(dist(a, b, i, j - 1),//вставка символа
					dist(a, b, i - 1, j - 1)));//замена символа

	}
}

double BinaryTree::similarity(std::string a, std::string b)
{
	int i = a.size();
	int j = b.size();

	double distance = dist(a, b, i, j);
	double bigger = std::max(a.size(), b.size());
	double pct = ((bigger - distance) / bigger) * 100;

	return pct;
}

void BinaryTree::searchWord(std::string word)
{
	bool ind = searchWordDomes(p, word);

	if (ind)
		std::cout << "Есть\n";
	else
		std::cout << "Нет\n";

	normalize();
}

bool BinaryTree::searchWordDomes(TTree obj, std::string word)
{
	double percent;
	if (obj)
	{
		percent = similarity(obj->data, word);
		if (percent >= 70.0)
			return true;
		return searchWordDomes(obj->left, word) || searchWordDomes(obj->right, word);
	}
	return false;
}