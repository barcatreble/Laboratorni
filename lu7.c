#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int *row, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(row[j] > row[j+1])
            {
                int temp = row[j];
                row[j] = row[j+1];
                row[j+1] = temp;
            }
        }
    }
}

int main()
{
    //1
    /*int n = 5;
    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) return 1;

    int sum = 0;
    float avg = 0;

    printf("Vuvedete %d chisla v masiva: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0];
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    avg = (float) sum / n;
    printf("Srednoaritmetichnoto na chislata v masiva e: %.2f", avg);

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < avg)
        {
            for(int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j+1];  
            }
            n--;
            i--; 
            arr = (int*)realloc(arr, n * sizeof(int));
        }
    }
    BubbleSort(arr, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    //2
    int k;
    printf("\nVuvedete broi na elementi za dobavane kum masiva: ");
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        int num, poz;
        printf("Vuvedete element nomer %d: ", i+1);
        scanf("%d", &num);
        printf("Vuvedete pozicia na koyto da bude dobaven: ");
        scanf("%d", &poz);
        n++;
        arr = (int*)realloc(arr, n * sizeof(int));
        for(int j = n - 1; j > poz; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[poz] = num;
    }

    printf("Masivut sled dobavqne (Zad 2): ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    //3
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int l = j; l < n - 1; l++)
                {
                    arr[l] = arr[l+1];
                }
                n--;
                j--;
                arr = (int*)realloc(arr, n * sizeof(int));
            }
        }
    }

    printf("Masivut bez povtarqshti se chisla (Zad 3): ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    free(arr);*/

    //4
    int n = 3;
    int m = 2; 
    int** arr2D = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        arr2D[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Vuvedete elementite na masiv s %d reda i %d koloni:\n", n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr2D[i][j]);
        }
    }

    int max_sum = 0, max_index = 0; 
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < m; j++) sum += arr2D[i][j];
        if(i == 0 || sum > max_sum)
        {
            max_sum = sum;
            max_index = i;
        }
    }

    int min_sum = 0, min_index = 0;
    for(int j = 0; j < m; j++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr2D[i][j];
        if(j == 0 || sum < min_sum)
        {
            min_sum = sum;
            min_index = j;
        }
    }

    printf("Red nomer %d e s nai-golyama suma: %d\n", max_index, max_sum);
    printf("Kolona nomer %d e s nai-malka suma: %d\n", min_index, min_sum);

    //5
    for(int i = 0; i < n; i++)
    {
        BubbleSort(arr2D[i], m);
    }

    int *maxArr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        maxArr[i] = arr2D[i][m-1];
    }

    printf("Masivut s maksimalnite elementi ot vseki red e: ");
    for(int i = 0; i < n; i++) printf("%d ", maxArr[i]);

    for(int i = 0; i < n; i++) free(arr2D[i]);
    free(arr2D);
    free(maxArr);

    return 0;
}