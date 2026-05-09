#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[51];
    char date[11];
    int lections;
    float price;
} Course;

int main(){
    FILE* fp;
    if((fp = fopen("courses.bin", "rb")) == NULL)
    {
        printf("Cannot open file");
        return 1;
    }

    int n;
    if (fread(&n, sizeof(int), 1, fp) != 1) 
    {
        fclose(fp);
        return 1;
    }

    Course* courses = malloc(sizeof(Course) * n);
    if (courses == NULL) 
    {
        printf("Memory allocation error");
        fclose(fp);
        return 2;
    }

    if (fread(courses, sizeof(Course), n, fp) != n) 
    {
        printf("Reading error");
        free(courses);
        fclose(fp);
        return 3;
    }

    fclose(fp);
    free(courses);
}

//2
void Promo(Course* arr, int n, int index)
{   
    if(index >= n)
    {
        printf("Index out of bounds");
        return;
    }

    arr[index].price = 0.9 * arr[index].price;
    printf("%.2flv - %s - %s", arr[index].price, arr[index].name, arr[index].date);
}

//3
int filterByPrice(Course* arr, int n, float min_price, float max_price)
{
    FILE* fp;
    if((fp = fopen("offer.txt", "w")) == NULL)
    {
        printf("Cannot open file");
        return 1;
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].price > min_price && arr[i].price < max_price)
        {
            fprintf(fp, "Ime: %s\n", arr[i].name);
            fprintf(fp, "Data %s\n", arr[i].date);
            fprintf(fp, "Broi lekcii: %d\n", arr[i].lections);
            fprintf(fp, "Cena: %.2f\n", arr[i].price);
            count++;
        }
    }
    fclose(fp);
    if(count == 0) return 0;
    return count;
}

//4
Course* deleteCourse(Course** arr, int *n, char name[], char date[])
{
    int is_deleted = 0;
    for(int i = 0; i < *n; i++)
    {
        if(strcmp((*arr)[i].name, name) == 0 && strcmp((*arr)[i].date, date) == 0)
        {
            for(int j = i; j < *n - 1; j++)
            {
                (*arr)[j] = (*arr)[j+1];
            }
            (*n)--;
            is_deleted = 1;
            break;
        }
    }
    if(is_deleted == 0)
    {
        printf("Nqma kurs s takova ime i nachalna data");
        return NULL;
    }
    return (*arr);
}