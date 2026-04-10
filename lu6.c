#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1
    /*int n = 5, m = 4;
    int sum1 = 0, sum2 = 0;
    float avg1 = 0, avg2 = 0;
    int* arr1 = (int*)malloc(n * sizeof(int));
    printf("Vuvedete %d chisla za purviq masiv:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        sum1 += arr1[i];
    }
    avg1 = (float)sum1 / n;
    printf("Sumata na chislata e:%n\nSrednoaritmetichnoto na chislata e:%.2f", sum1, avg1);

    int* arr2 = (int*)malloc(m * sizeof(int));
    printf("Vuvedete %d chisla za vtoriq masiv:", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
        sum2 += arr2[i];
    }
    avg2 = (float)sum2 / m;
    printf("Sumata na chislata e:%d\nSrednoaritmetichnoto na chislata e:%.2f", sum2, avg2);
    free(arr1);
    free(arr2);*/

    //2
    /*int n = 5;
    char izbor;
    int* arr1 = (int*)malloc(n * sizeof(int));
    if (arr1 == NULL) return 1;
    printf("Vuvedete chisla za masiva:");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr1[i]);

    printf("Jelaete li da dobavite oshte elementi? (y/n)");
    scanf(" %c", &izbor);
    if(izbor == 'y')
    {
        int m = 3;
        arr1 = (int*)realloc(arr1, (m + n) * sizeof(int));
        if(arr1 == NULL) return 1;
        printf("Vuvedete oshte %d chisla:", m);
        for(int i = n; i < m + n; i++)
        {
            scanf("%d", &arr1[i]);
        }
        n+=m;
    }

    printf("Vsichki chisla v masiva:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
        free(arr1);*/

    //3
    /*int n = 5;
    int num;
    int* arr1 = (int*)malloc(n * sizeof(int));
    if (arr1 == NULL) return 1;
    printf("Vuvedete chisla za masiva:");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr1[i]);

    printf("Vuvedete chislo, koeto da se premahne, ako sushtestvuva v masiva:");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        if(arr1[i] == num)
        {
            for(int j = i; j < n - 1; j++)
            {
                arr1[j] = arr1[j+1];
            }
            n--;
            i--;
        }
    }

    printf("Noviqt masiv e:");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr1[i]);
    }
    free(arr1);*/

    //4
    /*int n = 5, m = 4;
    int* arr1 = (int*)malloc(n * sizeof(int));
    printf("Vuvedete %d chisla za purviq masiv:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    int* arr2 = (int*)malloc(m * sizeof(int));
    printf("Vuvedete %d chisla za vtoriq masiv:", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    if (arr1 == NULL || arr2 == NULL) return 1;

    int total = n + m;
    int* arr3 = (int*)malloc(total * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for(int i = 0; i < m; i++)
    {
        arr3[n+i] = arr2[i];
    }

    for(int i = 0; i < total - 1; i++)
    {
        for(int j = 0; j < total - 1- i; j++)
        {
            if(arr3[j] > arr3[j+1])
            {
                int temp = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = temp;
            }
        }
    }

    printf("Obshtiqt masiv ot dvata, sortiran vuv vuzhodqsht red e:");
    for(int i = 0; i < total; i++)
    {
        printf("%d ", arr3[i]);
    }

    free(arr1);
    free(arr2);
    free(arr3);*/

    //5 Pascal
    int n = 4;
    int** arr = (int**)malloc(n * sizeof(int*));
    if (arr == NULL) return 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc((i+1) * sizeof(int));
        if(arr[i] == NULL) return 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("/n");
    }

    for(int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}