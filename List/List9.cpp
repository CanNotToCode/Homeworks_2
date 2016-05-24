// List9(породить список из положительных)
//

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

void Print(LinkedList *newlist) {
	Node *q = newlist->first->next;
	while (q != newlist->last) {
		cout << q->info << " ";
		q = q->next;
	}
}
void FindPos(LinkedList *list, LinkedList *&newlist) {
	Node *p = list->first;
	while (p!= list->last) {
		if (p->info >0)
			Add(p->info, newlist);
		p = p->next;
	}
};

int main()
{
	LinkedList *list = new LinkedList;
	Create(list);

	LinkedList *newlist = new LinkedList;
	Create(newlist);

	cout << " Input the sequense of 15 numbers " << endl;
	Read(list);
	Add(0, list);
    
	bool ordered = true;
	FindPos(list, newlist);
	Add(0, newlist);

	cout << "Positive elements are : ";
	Print(newlist);
	system("pause");
	return 0;
}

