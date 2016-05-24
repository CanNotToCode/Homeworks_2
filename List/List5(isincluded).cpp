// List5(isincluded)
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	char info;
	Node *next = NULL;
};

struct LinkedList {
	Node *first = NULL;
	Node *last = NULL;
};

void Create(LinkedList *&text) {//первый и последний узел списка хранят пробелы
	Node *temp = new Node;
	temp->info = ' ';
	temp->next = NULL;
	text->first = temp;
	text->last = temp;
}

void Add(char liter, LinkedList *&text) {
	Node *temp = new Node;
	temp->info = liter;
	temp->next = NULL;

	text->last->next = temp;
	text->last = temp;
};

void Read(LinkedList *text) {
	char symbol;
	while ((symbol = getchar()) != '\n') {
		Add(symbol, text);
	}
};

void FindWord(Node *&p, Node *q, bool &IsEqual) {
	while ((p->info != ' ') && (q->info != ' ')) {
		if ((p->info) != (q->info)) {
			IsEqual = false;
			p = p->next;
			q = q->next;
		}
		p = p->next;
		q = q->next;
	}

	if (p->info != q->info)
		IsEqual = false;
}

bool FindAndDeleteWord(LinkedList *word, LinkedList *&text) {
	Node *p = text->first->next;
	Node *q = word->first->next;
	bool IsEqual = true;
	bool IsIncluded = false;
	while ((p != text->last)&&(!IsIncluded)) {
		q = word->first->next;

		FindWord( p, q, IsEqual);

		if (IsEqual)
			IsIncluded = true;
			
		else
			IsEqual = true;
		p = p->next;
	}
	return IsIncluded;
};

int main()
{
	LinkedList *text = new LinkedList;
	Create(text);
	LinkedList *word = new LinkedList;
	Create(word);


	cout << " Input the text " << endl;
	Read(text);
	Add(' ', text);

	cout << " Input the word " << endl;
	Read(word);
	Add(' ', word);

	bool result = FindAndDeleteWord(word, text);
	if (result)
		cout << "Word is included  " << endl;
	else
		cout << "Word isn`t included ";
	cout << endl;

	system("pause");
	return 0;
}

