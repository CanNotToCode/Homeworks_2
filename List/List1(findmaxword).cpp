// List1(findmaxword).cpp: определяет точку входа для консольного приложения.
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

void Add(char liter, LinkedList *&text){
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

void SaveWord(Node *wordbegin, LinkedList *&maxword) {//сохранение максимального слова
	maxword->first->next = wordbegin;
	wordbegin = wordbegin->next;
	Node *c = maxword->first;
	c = c->next;
	while (wordbegin->info != ' ') {
		wordbegin = wordbegin->next;
		c = c->next;
	};
	maxword->last=c;
	Add(' ', maxword);
};

void FindMaxWord(int &max, LinkedList *&maxword, LinkedList *text) {//поиск максимального по длине
	Node *q = text->first->next;
	int length=0;
	while ((q != NULL)&&(q != text->last)) {
		Node *wordbegin = q;
		while ((q!=NULL)&&(q->info != ' ')&& (q != text->last)) {
			length++;
			q = q->next;
		}
		if (length > max) {
			max = length;
			SaveWord(wordbegin, maxword);
		}
		length = 0;
		q = q->next;
	}
};

int main()
{
	LinkedList *text = new LinkedList;
	Create(text);
	LinkedList *maxword = new LinkedList;
	Create(maxword);
	int max = 0;

	cout << " Input the text "<<endl;
	Read(text);
	Add(' ', text);

	FindMaxWord(max, maxword, text);

	cout << "Length of max word is: " << max<<" " <<endl;
	cout << "Max word is:  ";
	Print(maxword);
	cout << endl;

	system("pause");
    return 0;
}

