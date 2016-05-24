// Tree1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct List
{
	int info;
	List *left;
	List *right;
};

struct Tree
{
	List *root;
};
void Create(Tree *&tree)
{
	tree = new Tree;
	tree->root = nullptr;
}

List* InsertNode(List *root, int element)
{
	if (root == nullptr)
	{
		root = new List;
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

void PrintTree(List *root, int level)
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

void InOrder(List *root)
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

void ReadTree(Tree *&tree) {
	int n = 0;
	int i = 0;
	int element = 0;
	cout << "Inter count of elements" << endl;
	cin >> n;
	cout << "Inter elements" << endl;
	while (i < n) {
		cin >> element;
		Insert(tree, element);
		i++;
	}
}
struct Node {
	int info;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
	int count = 0;
};

void Add(int value, LinkedList *&l) {
	Node *temp = new Node;
	temp->info = value;
	if (l->first == NULL) {
		l->first = temp;
		l->last = temp;
		l->count++;
	}
	else {
		l->last->next = temp;
		l->last = temp;
		l->count++;
	}
}

void PrintList(LinkedList *l) {
	Node *p = new Node;
	p = l->first;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->next;
	}

}
void ReadList(LinkedList *&l) {
	int element;
	cout << "Input sequence of 10 elements:" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> element;
		Add(element, l);
	}
}

void ToList(List *root, LinkedList *&list)
{
	if (root != nullptr)
	{
		ToList(root->left, list);
		Add(root->info, list);
		ToList(root->right, list);
	}
}
void TreeToList(Tree *tree, LinkedList *&list) {
	ToList(tree->root, list);
}
int main()
{
	Tree *tree;
	Create(tree);
	LinkedList *list = new LinkedList;
	ReadTree(tree);
	TreeToList(tree, list);
	cout << "List: ";
	PrintList(list);
	system("pause");
	return 0;
}