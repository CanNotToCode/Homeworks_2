#include <stdio.h>
bool IsNumber ( char Liter){
    int k = (int)Liter;
    if ((k >= (int)'0')&&(k <= (int)'9')) {
        return true;
    }
    else {
        return false;
    }

}

int TryParse(char Liter)
{
    int k = (int)Liter;
    if(IsNumber(Liter)) {
        return k-(int)'0';
    }
    else {
        return (-1);}
}

int TryParse(char Str[]){
    int MyNumber = 0;
    int l = 1;
    for (int i = 0; i < 5; i++)
    {
        char Liter = Str[i];
        if (TryParse(Liter)==-1) {
            return (-1);
        }
        MyNumber+=TryParse(Liter);
        MyNumber*=10;
    }
    return MyNumber/10;
}
int main() {
    char MyString[5];
    printf("Enter array [5] of char\n");
    scanf("%s", &MyString);
    if (TryParse(MyString)!=-1) {
        printf("Number: %d", TryParse(MyString));
    }
    else {
        printf("Not a number");
    }

    return 0;
}