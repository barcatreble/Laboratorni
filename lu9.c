#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

typedef struct{
    char brand[30];
    char model[5];
    float fuel_capacity;
    float price;
    char registered;
} Car;

void CarInput(Car *c) {
    printf("Marka: ");
    scanf("%s", c->brand);

    printf("Model: "); 
    scanf("%s", c->model);

    printf("Obem na dvigatelq: ");  
    scanf("%f", &c->fuel_capacity);

    printf("Cena: ");  
    scanf("%f", &c->price);
    
    printf("Registraciq (Y/N): "); 
    scanf(" %c", &c->registered);
}

int main()
{
    // 1 a)
    /*FILE *fp;
    int n, num;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr[i] = num;
    }

    if ((fp = fopen("file1", "wb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 2;
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1)
    {
        printf("Writing error.\n");
        return 3;
    }

    if (fwrite(arr, sizeof(int), n, fp) != n)
    {
        printf("Writing error.\n");
        return 4;
    }
    fclose(fp);

    // 1 b)
    int even_count = 0, odd_count = 0;
    if ((fp = fopen("file1", "rb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 5;
    }

    if((fread(&n, sizeof(int), 1, fp) == NULL)
    {
        printf("Reading error.\n");
        return 6;
    };
    for (int i = 0; i < n; i++)
    {
        if (fread(&num, sizeof(int), 1, fp) != 1)
        {
            printf("Reading error.\n");
            return 7;
        }

        int temp = num;
        do {
            if ((temp % 10) % 2 == 0) even_count++;
            else odd_count++;
            temp /= 10;
        } while (temp > 0);
    }

    printf("Broqt na chetnite cifri e %d.\nBroqt na nechetnite cifri e %d\n", even_count, odd_count);
    fclose(fp);

    // 1 v)
    if ((fp = fopen("file1", "rb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 8;
    }

    fread(&n, sizeof(int), 1, fp);

    FILE* fp2;
    if ((fp2 = fopen("file2", "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return 9;
    }

    int arr2[100];
    for (int i = 0; i < n; i++)
    {
        if(fread(&arr2[i], sizeof(int), 1, fp) != 1)
        {
            printf("Reading error.\n");
            return 10;
        };
    }

    BubbleSort(arr2, n);

    for (int i = 0; i < n; i++)
    {
        fprintf(fp2, "%d ", arr2[i]); 
    }

    fclose(fp);
    fclose(fp2);
    free(arr);*/

    //2 a)
    /*FILE* fp;
    int num;

    if((fp = fopen("binfile", "wb")) == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }

    printf("Vuvedete chisla(0 za krai):");
    while(1)
    {
        scanf("%d", &num);
        if(num != 0) break;

        if(fwrite(&num, sizeof(int), 1, fp) != 1)
        {
            printf("Writing error.\n");
            return 2;
        }
    }
    fclose(fp);

    //2 b)
    int even_count = 0, odd_count = 0;
    if ((fp = fopen("binfile", "rb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 3;
    }

    while(fread(&num, sizeof(int), 1, fp) == 1)
    {
        int temp = num;
        do {
            if ((temp % 10) % 2 == 0) even_count++;
            else odd_count++;
            temp /= 10;
        } while (temp > 0);
    }

    printf("Broqt na chetnite cifri e %d.\nBroqt na nechetnite cifri e %d\n", even_count, odd_count);
    fclose(fp);

    //2 v)
    FILE* fp2;
    int n = 0;
    if ((fp = fopen("binfile", "rb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 4;
    }

    if ((fp2 = fopen("txtfile", "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return 5;
    }

    int* arr = NULL;
    while(fread(&num, sizeof(int), 1, fp) == 1)
    {   
        int *temp = realloc(arr, (n + 1) * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory error.\n");
            free(arr);
            fclose(fp);
            fclose(fp2);
            return 6;
        }
        arr = temp;
        arr[n] = num;
        n++;
    }

    BubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        fprintf(fp2, "%d ", arr[i]); 
    }

    free(arr);
    fclose(fp);
    fclose(fp2);*/

    //3
    FILE *bin, *txt;

    if((bin = fopen("binfile", "wb")) == NULL)
    {
        printf("Cannot open binary file!\n");
        return 1;
    }

    if((txt = fopen("txtfile", "w")) == NULL)
    {
        printf("Cannot open text file!\n");
        return 2;
    }

    Car car;
    printf("Vuvedete danni za kola. END za krai na vuvejdaneto.\n");

    while(1)
    {
        CarInput(&car);
        if (strcmp(car.brand, "END") == 0) break;

        if(fwrite(&car, sizeof(Car), 1, bin) != 1)
        {
            printf("Writing error.\n");
            return 3;
        }

        fprintf(txt, "%s %s %.2f %.2f %c", car.brand, car.model, car.fuel_capacity, car.price, car.registered);
    }
    fclose(bin);
    fclose(txt);

    char choice;
    while(1)
    {
        printf("Iskate li da dobavite nov avtomobil?(Y/N):");
        scanf(" %c", &choice);

        if(choice == 'N' || choice == 'n') break; 

        if(choice == 'Y' || choice == 'y')
        {
            if((bin = fopen("binfile", "ab")) == NULL)
            {
                printf("Cannot open binary file!\n");
                return 4;
            }

            if((txt = fopen("txtfile", "a")) == NULL)
            {
                printf("Cannot open text file!\n");
                return 5;
            }

            CarInput(&car);
            if(fwrite(&car, sizeof(Car), 1, bin) != 1)
            {
                printf("Writing error.\n");
                return 6;
            }
            fprintf(txt, "%s %s %.2f %.2f %c\n", car.brand, car.model, car.fuel_capacity, car.price, car.registered);

            fclose(bin);
            fclose(txt);
        }
    }

    if ((bin = fopen("binfile", "rb")) == NULL)
    {
        printf("Cannot open binary file.\n");
        return 7;
    }
    if ((txt = fopen("txtfile", "r")) == NULL)
    {
        printf("Cannot open text file.\n");
        fclose(bin);
        return 8;
    }

    printf("Danni v binarniq file:\n");
    while(fread(&car, sizeof(Car), 1, bin) == 1)
    {
        printf("%s %s %.2f %.2f %c\n", car.brand, car.model, car.fuel_capacity, car.price, car.registered);
    }
    printf("\n");

    printf("Danni v tekstoviq file:\n");
    char tekst[100];
    while(fgets(tekst, sizeof(tekst), txt) != NULL)
    {
        printf("%s ", tekst);   
    }
    fclose(bin);
    fclose(txt);

    return 0;
}   