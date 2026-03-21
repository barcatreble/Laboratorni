#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    //1
    /*int a,b;
    printf("Vuvedete purvo chislo:");
    scanf("%d", &a);
    printf("Vuvedete vtoro chislo:");
    scanf("%d", &b);  
    int sum = a + b;
    printf("Sumata na dvete chisla e:%d", sum);*/
    
    //2
    /*int a,b;
    printf("Vuvedete purvo chislo:");
    scanf("%d", &a);
    printf("Vuvedete vtoro chislo:");
    scanf("%d", &b);  
    int sum = a + b;
    int proizv = a * b;
    float chastno = 1.0 * a / b;
    printf("Suma:%d\nProizvedenie:%d\nChastno:%.2f", sum, proizv, chastno);*/

    //3
    /*int num;
    printf("Vuvedete chislo:");
    scanf("%d", &num);
    if (num % 2 == 0) printf("Chisloto e chetno!");
    else printf("Chisloto e nechetno!");*/

    //4
    /*int a, sum;
    printf("Vuvedete chetiricifreno chislo:");
    scanf("%d", &a);
    sum = a % 10;
    sum += (a/10) % 10;
    sum += (a/100) % 10;
    sum+= a / 1000;
    printf("Sumata ot cifrite na chisloto e:%d", sum);*/

    //5
    /*int year;
    printf("Vuvedete godina:");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) printf("Visokosna!");
    else printf("Ne e visokosna!");*/

    //6
    /*int num;
    printf("Vuvedete chetiricifreno chislo:");
    scanf("%d", &num);
    int cifra1 = num % 10;
    int cifra2 = (num/10) % 10;
    int cifra3 = (num/100) % 10;
    int cifra4 = num / 1000;
    printf("Chisloto v obraden red e:%d%d%d%d", cifra1, cifra2, cifra3, cifra4);*/

    //7
    /*int a,b,c;
    printf("Vuvedete 3 chisla:");
    scanf("%d%d%d", &a, &b, &c);
    int max = a;
    if (b>max) max=b;
    if (c>max) max=c;
    printf("Nai-golqmoto chislo mejdu trite e %d", max);*/
}