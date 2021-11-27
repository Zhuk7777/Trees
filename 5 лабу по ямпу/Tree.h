#pragma once
#include<string>

struct TreeNode
{
	std::string data;
	TreeNode* left;
	TreeNode* right;

};

typedef TreeNode* TTree;

class BinaryTree
{
	TTree root;
	TTree p;

	std::string findSuccessor(TTree& obj);
	void normalize();
	TTree searchDomestic(std::string elem);
	void clear(TTree& obj);
	void copy(TTree obj, TTree& newRoot);

public:

	BinaryTree();
	BinaryTree(std::string elem);

	~BinaryTree();

	BinaryTree(const BinaryTree& obj);
	BinaryTree& operator=(const BinaryTree& obj);

	void insertElem(std::string elem);
	void deleteElem(std::string elem);


	bool search(std::string elem);

	void printTree(TTree obj, int ind);
};