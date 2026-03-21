#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1
int NOD(int a, int b)
{
    while (b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//2
int prosto_neprosto(int a)
{
    if (a <= 1) return 0;
    for(int i = 2; i * i <= a;i++)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}

//3
int broi_cifri(int num)
{
    int count = 0;
    if (num<0) num = -num;
    while (num>0)
    {
        num /=10;
        count++;
    }
    return count;
}

//4
long conv_dvoichno(int num)
{
    long dvoichno = 0;
    int ostatuk = 0, mnoj = 1;
    while (num>0)
    {   
        ostatuk = num % 2;
        dvoichno += ostatuk * mnoj;
        num /= 2;
        mnoj *= 10;
    }
    return dvoichno;
}

//5
int sbor_cifri(int num)
{
    int sum = 0; 
    if (num<0) num = -num;
    while (num > 0)
    {
        sum += num %10;
        num /=10;
    }
    return sum;
}

//6
void matSmetki(int A, int B, int *sum, int *razlika, int *proizvedenie, int *delenie)
{
    *sum = A + B;
    *razlika = A - B;
    *proizvedenie = A * B;
    *delenie = A / B;
}

//7
int special (int num)
{
    if (num == 0) return 0;
    int cifri_sum = 0, cifri_proizv = 1;
    while (num > 0)
    {
        cifri_sum += num % 10;
        cifri_proizv *= num % 10;
        num /= 10;
    }
    if (cifri_sum % 2 == 0 &&  cifri_proizv > 35) return 1;
    return 0;
}

int neSpecial (int *num)
{
    if(special(*num) == 0) 
    {
        int max = 0, cifra = 0, temp = *num;
        while (temp > 0)
        {
            cifra = temp % 10;
            if (cifra > max) max = cifra;
            temp /= 10;
        }
        *num += max;
    }
}

//8
int narastvashto (int num)
{
    int posl_cifra = 10, temp = num;
    while (temp>0)
    {
        int posl_cifra1= temp % 10;
        if (posl_cifra1 > posl_cifra) return 0;
        posl_cifra = posl_cifra1;
        temp/=10;
    }
    return 1;
}

void promqna_narastvashto(int *num)
{
    if (narastvashto(*num) == 0) *num = 5 * (*num); 
}

//9
int palindrom (int num)
{
    int num1 = num;int obratno = 0;
    while (num > 0)
    {
        obratno = (obratno * 10) + (num % 10);
        num /= 10;
    }
    return obratno == num1;
}

void doPalindrom(int *num)
{
    while (palindrom(*num) == 0)
    {
        (*num)++;
    }
}

int main()
{
    int a = NOD(43,86);
    printf("%d", a);
}