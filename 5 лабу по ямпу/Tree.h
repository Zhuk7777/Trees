#pragma once
#include<string>

class BinaryTree
{

	struct TreeNode
	{
		std::string data;
		TreeNode* left;
		TreeNode* right;

	};

	typedef TreeNode* TTree;

	TTree root;
	TTree p;

	std::string findSuccessor(TTree& obj);
	void normalize();

	TTree searchDomestic(std::string elem);
	bool searchWordDomes(TTree obj, std::string word);

	void printTreeDomestic(TTree obj, int ind);

	void clear(TTree& obj);
	void copy(TTree obj, TTree& newRoot);

	double similarity(std::string a, std::string b);
	int dist(std::string a, std::string b, int i, int j);

public:

	BinaryTree();
	BinaryTree(std::string elem);

	~BinaryTree();

	BinaryTree(const BinaryTree& obj);
	BinaryTree& operator=(const BinaryTree& obj);

	void insertElem(std::string elem);
	void deleteElem(std::string elem);


	bool search(std::string elem);

	void printTree(int ind);

	void searchWord(std::string word);
};