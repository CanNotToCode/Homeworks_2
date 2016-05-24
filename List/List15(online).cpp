// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdio.h"
#include "stdafx.h"
#include <iostream>
using namespace std;
struct Line {
	int k;
	int b;
};
struct Node {
	double r;
	double fi;
	double x;
	double y;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
	int count = 0;
};

void Add(double r, double fi, LinkedList *&l) {
	Node *temp = new Node;
	temp->r = r;
	temp->fi = fi;
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

void ToDecart(LinkedList *&l) {
	Node *temp = l->first;
	while (temp != NULL) {
		temp->x = temp->r*(cos(temp->fi*3.14 / 180));
		temp->y = temp->r*(sin(temp->fi*3.14 / 180));
		temp = temp->next;
	}
}

void ReadList(LinkedList *&l) {
	double r = 0;
	double fi = 0;
	cout << "Input sequence of 5 elements:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> r;
		cin >> fi;
		Add(r, fi, l);
	}
}

bool IsOnline(LinkedList *l, Line line) {
	bool correct = true;
	Node *temp = l->first;
	int f = 0;
	while ((temp != NULL) && (correct)) {
		f = line.k * temp->x + line.b;
		if (f != temp->y)
			correct = false;
		temp = temp->next;
	}
	return correct;
}
int main()
{
	LinkedList *l = new LinkedList;
	ReadList(l);
	ToDecart(l);
	Line line;
	cout << "Coef of line:"<<endl;
	cin >> line.k;
	cin >> line.b;
	bool result = IsOnline(l, line);
	if (result)
		cout << "This points are on line";
	else cout << "This points aren`t on line";
	cout << endl;
	system("pause");
	return 0;
}