#include <stdio.h>
//Ряд Фарея - упорядоченная последовательность несократимых дробей

struct Fraction {
    int a;
    int b;
    Fraction *next = NULL;
};
struct FractionList{
    Fraction *first = NULL;
};


FractionList *Result (int n){
    FractionList *Fractions = new FractionList();
     Fraction *begin = new Fraction();
    (*begin).a = 0;
    (*begin).b = 1;
    (*Fractions).first = begin;

    Fraction *end = new Fraction();
    (*end).a = 1;
    (*end).b = 1;
    ((*(*Fractions).first).next) = end;
    for (int i = 0; i<=n; ++i){
        begin = (*Fractions).first;
        end = (*(*Fractions).first).next;
        while ( end != NULL){
            if((*begin).b + (*end).b == i) {
                Fraction *Fraction  = new Fraction();
                (*Fraction).a = (*begin).a +(*end).a;
                (*Fraction).b = (*begin).b +(*end).b;
                (*begin).next = Fraction;
                (*Fraction).next = end;
                begin = end;
                end = (*end).next;

        }
            else{
                begin = (*begin).next;
                end = (*end).next;
            }
        }
    }
    return Fractions;
}

int main() {
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    FractionList *Fractions = Result(n);
    Fraction *Fraction = (*Fractions).first;
    while (Fraction != NULL){
        printf("%d/%d", (*Fraction).a, (*Fraction).b);
        Fraction = (*Fraction).next;

    }
    return 0;
}
