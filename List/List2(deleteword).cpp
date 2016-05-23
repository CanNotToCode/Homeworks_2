#include "stdafx.h" 
#include <stdio.h> 
#include <iostream> 
using namespace std;
//Удаление слова из текста 
struct Node {
	char symbol;
	Node* next;
};

struct TextList {

	Node* first;
	Node* last;

	TextList() {
		first = NULL;
		last = NULL;
	}
};


void AddNew(char c, TextList *text) {

	Node* node = new Node;

	(*node).symbol = c;
	(*node).next = NULL;

	if ((*text).first == NULL)
	{
		(*text).first = node;
		(*text).last = node;
	}
	else
	{
		(*(*text).last).next = node;
		(*text).last = node;
	}
}


void Read(TextList *text) {
	char symbol;
	while ((symbol = getchar()) != '\n') {
		AddNew(symbol, text);
	}

}

void Show(TextList *text) {
	Node *temp = (*text).first;
	while (temp != NULL) {
		cout << (*temp).symbol;
		temp = (*temp).next;
	}
	cout << ("\n");
}

void Delete(TextList *text, TextList *word) {
	Node *temp = (*text).first; //символ текста
	Node *wtemp = (*word).first; // word symbol
	Node *end = NULL;// last sym of prev word
	bool p = true; ///a quant

	while (temp != NULL) { // цикл по тексту

		p = true;

		while (temp != NULL && (*temp).symbol != ' ' && p) {//цикл по каждому слову в тексте
			if ((*temp).symbol != (*wtemp).symbol) {
				p = false;
			}
			temp = (*temp).next;

			if (wtemp != NULL)//если короче
				wtemp = wtemp->next;
			else if (temp->symbol != ' ')
				p = false;
		}
		if (wtemp != NULL)//если длинее
			p = false;

		if (p) {
			end->next = temp;
			temp = end;
		}
		end = temp; //запоминаем последний символ проверенного слова
		wtemp = word->first;
		if (temp != NULL)
			temp = (*temp).next;
	}
}


int main() {
	TextList *text = new TextList;
	cout << "Input the text \n";
	AddNew(' ', text);
	Read(text);
	TextList *word = new TextList;
	cout << "Input the word \n";
	Read(word);
	Show(text);
	Delete(text, word);
	Show(text);
	system("pause");
}