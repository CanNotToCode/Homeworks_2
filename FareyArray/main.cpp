#include <stdio.h>
//Ряд Фарея - упорядоченная последовательность несократимых дробей

struct Fraction {
    int a;
    int b;
};
void Calc(int n){
    struct Fraction Fraction_list[200];
    int h = 2;
    Fraction_list[0].a = 0;
    Fraction_list[0].b = 1;
    Fraction_list[1].a = 1;
    Fraction_list[1].b = 1;
    for (int i = 0; i<=n; i++){
        int j = 0;
        while ( j<h-1){
            if(Fraction_list[j].b + Fraction_list[j+1].b == i) {
                int k;
                for (k = h+1; k >=j+1; k--){
                    Fraction_list[k] = Fraction_list[k-1];
                }
                Fraction_list[j+1].a = Fraction_list[j].a + Fraction_list[j+2].a;
                Fraction_list[j+1].b = Fraction_list[j].b + Fraction_list[j+2].b;
                j++;
                h++;
            }
            j++;

        }
    }
    int m=0;
    while ( (Fraction_list[m].b!=0)&&(m<h)){
        printf("%d/%d, ", Fraction_list[m].a, Fraction_list[m].b );
        m++;
    }

}
int main() {
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    Calc(n);
    return 0;
}
