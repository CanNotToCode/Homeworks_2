
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	int info;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
};

void Create(LinkedList *&text) {//ïåðâûé è ïîñëåäíèé óçåë ñïèñêà õðàíÿò íóëè
	Node *temp = new Node;
	temp->info = 0;
	temp->next = NULL;
	text->first = temp;
	text->last = temp;
}

struct DoubleNode {
	int info;
	DoubleNode *next = NULL;
	DoubleNode *prev = NULL;
};

struct DoubleLinkedList {
	DoubleNode *first = NULL;
	DoubleNode *last = NULL;
};

void Add(int info, LinkedList *&text) {
	Node *temp = new Node;
	temp->info = info;
	temp->next = NULL;

	text->last->next = temp;
	text->last = temp;
};

void AddToDouble(int element, DoubleLinkedList *&list) {
	DoubleNode *temp = new DoubleNode;
	temp->info = element;

	list->last->next = temp;
	temp->prev = list->last;
	list->last = temp;

}

void Read(LinkedList *&text) {
	int info;
	int i = 0;
	while (i<5) {
		cin >> info;
		Add(info, text);
		i++;
	}
};

void ReadDoubleList(DoubleLinkedList *&list) {
	DoubleNode *temp = new DoubleNode;
	temp->info = 0;
	temp->next = NULL;
	temp->prev = NULL;

	list->first = temp;
	list->last = temp;

	int i = 0;
	int element = 0;
	while ( i < 10) {
		cin >> element;
		AddToDouble(element, list);
		i++;
	}

}
void Print(LinkedList *newlist) {
	Node *q = newlist->first->next;
	while (q != newlist->last) {
		cout << q->info << " ";
		q = q->next;
	}
}

void PrintDoubleList(DoubleLinkedList *list) {
	DoubleNode *q = list->first->next;
	int i = 0;
	while (i<15) {
		cout << q->info << " ";
		q = q->next;
		i++;
	}
}

void Assoñiation(DoubleLinkedList *&list, LinkedList *&newlist) {
	Node *p = newlist->first->next;
	DoubleNode *q = list->first->next;
	while ((p != newlist->last) && (q != list->last) && (q != list->last)) {

		if (p->info < list->first->next->info) {
			DoubleNode *temp = new DoubleNode;
			temp->info = p->info;
			temp->next = list->first->next;
			list->first->next->prev = temp;
			list->first->next = temp;
			temp->prev = list->first;
			p = p->next;

		}

		else 
			if (p->info > list->last->prev->info) {
			DoubleNode *temp = new DoubleNode;
			temp->info = p->info;
			temp->next = list->last;
			temp->prev = list->last->prev;
			list->last->prev->next = temp;
			list->last->prev = temp;
			p=p->next;

		}

		else {
			while (!((p->info >= q->info) && (p->info <= q->next->info))&&(q->next->next!=list->last)) {
				q = q->next;
			}
			DoubleNode *temp = new DoubleNode;
			temp->info = p->info;
			temp->next = q->next;
			q->next->prev = temp;
			q->next = temp;
			temp->prev = q;

			p = p->next;
			q = list->first->next;
		}
	}
}
int main()
{
	DoubleLinkedList *list = new DoubleLinkedList;
	cout << "Input elements of the doubly linked ordered list (10 elements) \n";
	ReadDoubleList(list);
	AddToDouble(0, list);

	LinkedList *newlist = new LinkedList;
	cout << "Input elements of the linked not ordered list (5 elements) \n";
	Create(newlist);
	Read(newlist);
	Add(0, newlist);
	
	Assoñiation(list, newlist);

	cout << "Result ";
	PrintDoubleList(list);
	cout << "\n";

	system("pause");
	return 0;
}

