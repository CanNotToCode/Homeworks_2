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
void IsOrder(LinkedList *list, bool &ordered) {
	Node *p = list->first;
	while ((p->next != list->last) && (ordered)) {
		if (!(p->info <= p->next->info))
			ordered = false;
		p = p->next;
	}
};

int main()
{
	LinkedList *list = new LinkedList;
	Create(list);

	cout << " Input the sequense of 15 numbers " << endl;
	Read(list);
	Add(0, list);

	bool ordered = true;
	IsOrder(list, ordered);

	if (ordered) {
		cout << "List is ordered" << endl;
	}
	else {
		cout << "List is not ordered" << endl;
	}
	system("pause");
	return 0;
}

