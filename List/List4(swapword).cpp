// List2(deleteword)
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
void Print(LinkedList *list) {
	Node *p = list->first;
	while (p != NULL) {
		cout << p->info;
		p = p->next;
	}
};

void FindWord(Node *&begin, Node *&end, Node *&p, Node *q, bool &IsEqual) {
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

	end = p;
}

void SwapWord(Node *&begin, Node *&end, LinkedList *&newword) {
	begin->next = newword->first->next;
	newword->last->next = end;
}
void FindAndDeleteWord(LinkedList *word, LinkedList *&text, LinkedList *&newword) {
	Node *p = text->first->next;
	Node *q = word->first->next;
	bool IsEqual = true;
	bool Inserted = false;
	Node *begin = text->first;
	while ((p != text->last) && (!Inserted))  {
		Node *end = NULL;
		q = word->first->next;

		FindWord(begin, end, p, q, IsEqual);

		if (IsEqual) {
			SwapWord(begin, end, newword);
			Inserted = true;
		}
		else
			IsEqual = true;
		begin = p;
		p = p->next;
	}
};

int main()
{
	LinkedList *text = new LinkedList;
	Create(text);
	LinkedList *word = new LinkedList;
	Create(word);
	LinkedList *newword = new LinkedList;
	Create(newword);

	cout << " Input the text " << endl;
	Read(text);
	Add(' ', text);

	cout << " Input the first word " << endl;
	Read(word);
	Add(' ', word);


	cout << " Input the new word " << endl;
	Read(newword);
	Add(' ', newword);
	FindAndDeleteWord(word, text, newword);

	cout << "Result:  " << endl;

	Print(text);
	cout << endl;

	system("pause");
	return 0;
}

