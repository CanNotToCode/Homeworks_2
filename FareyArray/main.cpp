#include <stdio.h>
//Ряд Фарея - упорядоченная последовательность несократимых дробей

int main() {
    struct Fraction {
        int a;
        int b;
        int next;
    };
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    struct Fraction Fraction_list[200];
    Fraction_list[0].a = 0;
    Fraction_list[0].b = 1;
    Fraction_list[1].a = 1;
    Fraction_list[1].b = 1;
    Fraction_list[0].next = 1;
    Fraction_list[1].next = 0;
    int m = 2;
    for (int i = 2; i<=n; i++){
        int j1 = 0;
        int j2 = Fraction_list[j1].next;
        while ( j2!=0){
            if(Fraction_list[j1].b + Fraction_list[j2].b == i) {
                Fraction_list[m].a = Fraction_list[j1].a + Fraction_list[j2].a;
                Fraction_list[m].b = i;
                Fraction_list[m].next = j2;
                Fraction_list[j1].next = m;
                m++;
            }
            j1 = j2;
            j2 = Fraction_list[j1].next;
        }
    }
    int i=0;
    while ((Fraction_list[i].b!=0)&&(Fraction_list[i].b<=n)){
        printf("%d/%d, ", Fraction_list[i].a, Fraction_list[i].b );
        i++;
    }

    return 0;
}