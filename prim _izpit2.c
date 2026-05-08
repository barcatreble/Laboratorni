#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[31];
    char expiry_date[8];
    long long id;
    float price;
    int quantity;
} Medicine;

int main(){
    FILE* fp;
    if((fp = fopen("medicines.txt", "r")) == NULL)
    {
        printf("Cannot open file.");
        return 1;
    }

    Medicine* medicines = malloc(sizeof(Medicine));
    int n = 0;

    while(fscanf(fp, " %30[^;];%7[^;];%lld;%f;%d", 
        medicines[n].name, medicines[n].expiry_date, &medicines[n].id, &medicines[n].price, &medicines[n].quantity) == 5)
    {
        n++;
        Medicine* temp = realloc(medicines, sizeof(Medicine) * (n+1));
        if (temp == NULL)
        {
            printf("Memory allocation error.");
            free(medicines);
            fclose(fp);
            return 1;
        }
        medicines = temp;
    }

    free(medicines);
    fclose(fp);
    return 0;
}

//2
void priceDecrease(Medicine* arr, int n, char date[])
{
    int target_m = (date[0] - '0') * 10 + (date[1] - '0');
    int target_y = (date[3] - '0') * 1000 + (date[4] - '0') * 100 + (date[5] - '0') * 10 + (date[6] - '0');

    int found = 0;
    for(int i = 0; i < n; i++)
    {
        int m = (arr[i].expiry_date[0] - '0') * 10 + (arr[i].expiry_date[1] - '0');
        int y = (arr[i].expiry_date[3] - '0') * 1000 + (arr[i].expiry_date[4] - '0') * 100 + (arr[i].expiry_date[5] - '0') * 10 + (arr[i].expiry_date[6] - '0');
        if(y < target_y || (y == target_y && m < target_m) )
        {   
            float new_price = 0.8 * arr[i].price;
            printf("%s - %s - %f - %.2f\n", arr[i].name, arr[i].expiry_date, arr[i].price, new_price);
            found = 1;
        }
    }
    if(found == 0) printf("Nqma otkrito suvpadenie!");
}

//3
void binaryFile(Medicine* arr, int n, int quantity1)
{
    FILE *fp;
    if((fp = fopen("offer.bin", "wb")) == NULL)
    {
        printf("Cannot open file");
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(quantity1 < arr[i].quantity)
        {
            int name_len = strlen(arr[i].name);
            if(fwrite(&name_len, sizeof(int), 1, fp) != 1 ||
            fwrite(arr[i].name, sizeof(char), name_len, fp) != name_len ||
            fwrite(arr[i].expiry_date, sizeof(char), 8, fp) != 8 ||
            fwrite(&arr[i].id, sizeof(long long), 1, fp) != 1 ||
            fwrite(&arr[i].price, sizeof(float), 1, fp) != 1 ||
            fwrite(&arr[i].quantity, sizeof(int), 1, fp) != 1)
            {
                printf("Writing error");
                fclose(fp);
                return;
            }
        }
    }
    fclose(fp);
}

//4
void deleteMedicine(Medicine** arr, int *n, long long code)
{
    for(int i = 0; i < *n; i++)
    {
        if((*arr)[i].id == code)
        {
            for(int j = i; j < *n - 1; j++)
            {
                (*arr)[j] = (*arr)[j+1];
            }
            (*n)--;
            return;
        }
    }
    printf("Nqma otkrito suvpadenie!\n");
}