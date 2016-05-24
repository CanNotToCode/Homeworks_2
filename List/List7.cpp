// List7(добавить новый перед каждым заданным)
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

void Read(LinkedList *text) {
	double info;
	int i = 0;
	while (i<15) {
		cin >> info;
		Add(info, text);
		i++;
	}
};
void Print(LinkedList *list) {
	Node *p = list->first->next;
	while (p != list->last) {
		cout << p->info<< ' ';
		p = p->next;
	}
}; 

void InsertBefore(int element, int newelement, LinkedList *&list) {
	Node *p = list->first;
	Node *q = p;

	while (p != list->last) {
		q = p;
		p = p->next;
		if (p->info == element) {
			Node *newel = new Node;
			newel->info = newelement;
			newel->next = NULL;

			newel->next = p;
			q->next = newel;
		}
	}
};

int main()
{
	LinkedList *list = new LinkedList;
	Create(list);


	cout << " Input the sequense of 15 numbers " << endl;
	Read(list);
	Add(0, list);

	int element = 0;
	cout << " Input the element" << endl;
	cin >> element;
	cout << endl;

	int newelement = 0;
	cout << " Input the new element" << endl;
	cin >> newelement;
	cout << endl;

	InsertBefore(element,newelement, list);

	cout << "Result:  " << endl;

	Print(list);
	cout << endl;

	system("pause");
	return 0;
}

