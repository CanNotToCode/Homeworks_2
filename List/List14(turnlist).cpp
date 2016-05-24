

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	double info;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
};

void Create(LinkedList *&text) {//первый и последний узел списка хранят нули
	Node *temp = new Node;
	temp->info = 0;
	temp->next = NULL;
	text->first = temp;
	text->last = temp;
}

void Add(double info, LinkedList *&text) {
	Node *temp = new Node;
	temp->info = info;
	temp->next = NULL;

	text->last->next = temp;
	text->last = temp;
};

void Read(LinkedList *&text) {
	double info;
	int i = 0;
	while (i<15) {
		cin >> info;
		Add(info, text);
		i++;
	}
};

void Print(LinkedList *list) {
	Node *q = list->first;
	int i = 0;
	while (i<15) {
		cout << q->info << " ";
		q = q->next;
		i++;
	}
}

void Turn(LinkedList *list) {
	Node *node = list->first;
	Node *PNode = NULL;
	Node *NNode = NULL;
	while (node != NULL) {
		PNode = node;
		node = node->next;
		PNode->next = NNode;
		NNode = PNode;
	}
	list->first = PNode;

}


int main()
{
	LinkedList *list = new LinkedList;
	Create(list);

	cout << " Input the sequense of 15 numbers " << endl;
	Read(list);

	Turn(list);

	Print(list);
	system("pause");
	return 0;
}

