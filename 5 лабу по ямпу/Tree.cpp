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

int BinaryTree::copy(TTree obj,TTree & newRoot)
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

	}
	else
	{
		while (p)
		{
			if (elem < p->data)
				p = p->left;
			if (elem > p->data)
				p = p->right;
		}
		p = new TreeNode;
		p->data = elem;
		p->left = nullptr;
		p->right = nullptr;
	}

	normalize();
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

TTree BinaryTree::searchDomestic(std::string elem)
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

void BinaryTree::printTree(TTree obj, int ind)//1-прямой,2-симметричный, 3-обратный
{
	switch (ind)
	{
	case 1:
		if (obj)
		{
			std::cout << obj->data << " ";
			printTree(obj->left, ind);
			printTree(obj->right, ind);
		}
		break;

	case 2:

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
