// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdio.h"
#include "stdafx.h"
#include <iostream>
using namespace std;
struct Node {
	double x;
	double y;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
	int count = 0;
};

void Add(double x, double y, LinkedList *&l) {
	Node *temp = new Node;
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
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

void ReadList(LinkedList *&l) {
	double x = 0;
	double y = 0;
	cout << "Input sequence of 5 elements:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		cin >> y;
		Add(x, y, l);
	}
}

bool IsOnCircle(LinkedList *l, double r) {
	bool correct = true;
	Node *temp = l->first;
	while ((temp != NULL) && (correct)) {
	        if((temp->x*temp->x)+(temp->y*temp->y)!=r*r)
			correct = false;
		temp = temp->next;
	}
	return correct;
}
int main()
{
	LinkedList *l = new LinkedList;
	ReadList(l);
	double r;
	cout << "Radius is :" << endl;
	cin >> r;
	bool result = IsOnCircle(l,r);
	if (result)
		cout << "This points are on circle";
	else cout << "This points aren`t on circle";
	cout << endl;
	system("pause");
	return 0;
}