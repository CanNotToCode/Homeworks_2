// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdio.h"
#include "stdafx.h"
#include <iostream>
using namespace std;

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
	cout << "Elements of sequence:" << endl;
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
LinkedList *Merge(LinkedList *&l1, LinkedList *l2) {
	LinkedList *l3 = new LinkedList;
	Node *p;
	Node *q;
	p = l1->first;
	q = l2->first;
	while ((p != NULL) && (q != NULL)) {
		if (p->info <= q->info) {
			Add(p->info, l3);
			p = p->next;
		}
		else {
			Add(q->info, l3);
			q = q->next;
		}
	}
	while (p != NULL) {
		Add(p->info, l3);
		p = p->next;
	}
	while (q != NULL) {
		Add(q->info, l3);
		q = q->next;
	}
	return l3;
}
int main()
{
	LinkedList *l1 = new LinkedList;
	LinkedList *l2 = new LinkedList;
	LinkedList *l3 = new LinkedList;
	ReadList(l1);
	ReadList(l2);
	l3 = Merge(l1, l2);
	PrintList(l3);
	cout << endl;
	system("pause");
	return 0;
}