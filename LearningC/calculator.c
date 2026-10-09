#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float numbers[100];
int count_of = 0;
int sonuc = 0;
float result_op = 0;
int secim = 0;
int veri_al() // Get the choice of operator from user. 
{
    char islem;
    int secim = 0;
    while (secim==0)
    {
        printf("Choose operator (e.g. + - * / ):");
        scanf(" %c", &islem);
        if (islem == '+')
        {
            secim = 1;
            break;
        }
        if (islem == '-')
        {
            secim = 2;
            break;
        }
        if (islem == '*')
        {
            secim = 3;
            break;
        }
        if (islem == '/')
        {
            secim = 4;
            break;
        }
        else
        {
            secim = 0;
            printf("Invalid input. Please try again.\n");
        }
        
    }
    return secim;
};

void get_numbers()
{
    while (sonuc != 1 || count_of <= 1 || count_of > 100)
    {
        if (secim == 4) { count_of = 2; break; }
        printf("Please enter the number of items to be processed : "); // Get how many number for operate from user
        sonuc = scanf(" %d", &count_of);
        
        if (sonuc != 1 || count_of <= 1 || count_of > 100)
        {
            if (count_of > 100) { printf("it's just a simple calculator bro, pls chill ;)\n"); while (getchar() != '\n');}
            printf("Invalid input. ( 1 < x < 100 ) Please try again.\n");
            while (getchar() != '\n'); // clear memory for clean read
        }
    }
    int i;

    for (i = 0; i < count_of; i++)
    {
        system("cls");
        printf("Please enter number %d.  : \n", i + 1);
        scanf(" %f", &numbers[i]);
    }
    return 0;
}

int do_math(int secim)
{
    result_op = numbers[0];
    for (int i = 0;i < count_of - 1;i++)
    {
        if (secim == 1) {
            result_op = result_op + numbers[i+1];
        }
        if (secim == 2) {
            result_op = result_op - numbers[i+1];
        }
        if (secim == 3) {
            result_op = result_op * numbers[i+1];
        }
        if (secim == 4) {
            result_op = result_op / numbers[i+1];
        }
    }
    printf("Result  : %.2f", result_op);
    return result_op;
}

int main() {
    while (1)
    {
        secim = veri_al(); // Get operators
        system("cls"); // Clear terminal
        get_numbers(); // Get numbers
        system("cls");
        do_math(secim);
        printf("\n\nPress enter for new operation");
        while (getchar() != '\n');
        getchar();
        system("cls");

        count_of = 0;
        sonuc = 0;
        result_op = 0;
        secim = 0;
    }
    
};