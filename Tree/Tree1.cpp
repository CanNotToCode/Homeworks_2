// Tree1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct Node
{
	int info;
	Node *left;
	Node *right;
};

struct Tree
{
	Node *root;
};
void Create(Tree *&tree)
{
	tree = new Tree;
	tree->root = nullptr;
}

Node* InsertNode(Node *root, int element)
{
	if (root == nullptr)
	{
		root = new Node;
		root->info = element;
		root->left = nullptr;
		root->right = nullptr;
	}

	else if (element <= root->info)
	{
		root->left = InsertNode(root->left, element);
	}
	else
	{
		root->right = InsertNode(root->right, element);
	}

	return root;
}

void Insert(Tree *&tree, int element)
{
	tree->root = InsertNode(tree->root, element);
}

void PrintTree(Node *root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "--";
		}

		cout << root->info << endl;

		PrintTree(root->left, level + 1);
	}
}

void Print(Tree *tree)
{
	PrintTree(tree->root, 0);
}

void InOrder(Node *root)
{
	if (root != nullptr)
	{
		InOrder(root->left);
		cout << root->info << " ";
		InOrder(root->right);
	}
}

void InOrderPrint(Tree *tree)
{
	InOrder(tree->root);
}
void Sum(Node *root, int &sum) {
	if (root != nullptr)
	{
		Sum(root->left, sum);
		sum = sum + root->info;
		Sum(root->right, sum);
	}

}
void ReadTree(Tree *&tree) {
	int n = 0;
	int i = 0;
	int element = 0;
	cout << "Inter count of elements"<<endl;
	cin >> n;
	cout << "Inter elements"<<endl;
	while (i < n) {
		cin >> element;
		Insert(tree, element);
		i++;
	}
}
void  FindSum(Tree *tree, int &sum) {
	Sum(tree->root, sum);
}
int main()
{
	Tree *tree;
	Create(tree);
	ReadTree(tree);
	int sum = 0;
	FindSum(tree, sum);
	cout << endl<<"Sum is "<<sum<<endl;
	system("pause");
	return 0;
}