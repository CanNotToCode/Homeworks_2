// List11(intersection).cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
	double value;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
};

void AddToEnd(LinkedList *list, double value) {
	Node *node = new Node;
	node->value = value;
	node->next = NULL;
	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	}
	else {
		list->last->next = node;
		list->last = node;
	}
}

void ReadList(LinkedList *list) {
	double value;
	int length = 0;
	int i = 0;
	cout << "Input length of list" << endl;
	cin >> length;
	cout << "Input elements" << endl;
	while (i <length) {
		cin >> value;
		AddToEnd(list, value);
		i++;
	}
}

void PrintList(LinkedList *list) {
	Node *node = list->first;
	while (node != NULL) {
		cout << node->value << ' ';
		node = node->next;
	}
}

void Intersection (LinkedList *list1, LinkedList *list2, LinkedList *&list) {
	Node *node1 = list1->first;
	Node *node2 = list2->first;
	while (node1 != NULL && node2 != NULL) {
		if (node1->value > node2->value) {
			node2 = node2->next;
		}
		else if (node1->value < node2->value) {
			node1 = node1->next;
		}
		else {
			AddToEnd(list, node1->value);
			node1 = node1->next;
			node2 = node2->next;
		}
	}
}

int main() {
	LinkedList *list1 = new LinkedList;
	cout << "Input elements of first list" << endl;
	ReadList(list1);

	LinkedList *list2 = new LinkedList;
	cout << "Input elements of second list" << endl;
	ReadList(list2);

	LinkedList *list = new LinkedList;

	Intersection(list1, list2, list);

	cout << "Elements of intersection:" << endl;
	PrintList(list);
	cout << endl;
	system("pause");
	return 0;
}


