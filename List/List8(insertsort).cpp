#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next = NULL;
	Node *prev = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
};

void AddToEnd(LinkedList *list, int value) {
	Node *node = new Node;
	node->value = value;
	node->next = NULL;
	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	}
	else {
		node->prev = list->last;
		list->last->next = node;
	}
	list->last = node;
}

void ReadList(LinkedList *list) {
	int value;
	int n = 0;
	cout << "Input amount of numbers"<<endl;
	cin >> n;
	int i = 0;
	cout << "Enter elements of list" << endl;
	while (i<n) {
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

void swap(LinkedList *list, Node *PNode, Node *CNode, Node *NNode) {
	if (NNode == NULL) {
		PNode->next = NULL;
		list->last = PNode;
	}
	else {
		NNode->prev = PNode;
		PNode->next = NNode;
	}
	CNode->next = PNode;
	if (PNode->prev == NULL) {
		CNode->prev = NULL;
		list->first = CNode;
		PNode->prev = CNode;
	}
	else {
		PNode->prev->next = CNode;
		CNode->prev = PNode->prev;
		PNode->prev = CNode;
	}
}

void InsertSort(LinkedList *list) {

	Node *node = list->first->next;
	while (node != NULL) {
		Node *PNode = node->prev;
		Node *CNode = node;
		Node *NNode = node->next;
		while (PNode != NULL && PNode->value > CNode->value) {
			swap(list, PNode, CNode, NNode);

			NNode = PNode;
			PNode = CNode->prev;
		}
		node = node->next;
	}


}

int main() {
	LinkedList *list = new LinkedList;
	ReadList(list);

	InsertSort(list);

	cout << "Result: " << endl;
	PrintList(list);
	system("pause");
	return 0;
}