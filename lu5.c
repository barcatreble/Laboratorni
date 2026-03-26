#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1
    /*int matrix[3][3];
    printf("Vuvedete matrica 3x3:");
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j] );
    
    printf("Glaven diagonal:");
    for (int i = 0; i < 3; i++)
        printf("%d ", matrix[i][i]);

    printf("\nVtorichen diagonal:");
    for (int i = 0; i < 3; i++)
        printf("%d ", matrix[i][3 - 1 - i]);

    printf("\nChislata pod glavniq diagonal sa:");
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(i>j) printf("%d ", matrix[i][j]);

    printf("\nChislata nad glavniq diagonal sa:");
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(i<j) printf("%d ", matrix[i][j]);*/

    //2
    /*int flag = 1;
    int suma_1 = 0;
    for (int i = 0; i < 3; i++)
        suma_1 += matrix[i][0];

    for (int i = 0; i < 3; i++)
    {   
        int suma_red = 0, suma_kolona = 0;
        for(int j = 0; j < 3; j++)
        {
            suma_red += matrix[i][j];
            suma_kolona += matrix[j][i];
        }
        if (suma_red != suma_1 || suma_kolona != suma_1)
        {
            flag = 0;
            break;
        }
    }
    if (flag) printf("Kvadratut e magicheski.");
    else printf("Kvadratut ne e magicheski");*/

    //3
    /*int new_matrix[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new_matrix[j][3 - 1 - i] = matrix[i][j];

    printf("Matricata, poluchena pri zavurtane na 90 gradusa po chasovnikavata strelka, e:")
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%d", new_matrix[i][j]);*/

    //4
    /*int matrix1[3][4];
    for (int i = 0; i < 3; i++)
    {
        if(i % 2 == 1)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", matrix[i][j]);
            }
        }
        else 
        {
            for (int j = 4 - i; j >= 0; j--)
            {
                scanf("%d", matrix[i][j]);
            }
        }
    }*/

    //5
    /*int A[4][3], B[2][2];
    for (int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < 2; i++)
        for(int j = 0; j < 2; i++)
            scanf("%d", &B[i][j]);

    int found = 0;
    for (int i = 0; i < 4 - 2; i++)
    {
        for (int j = 0; j < 3 - 2; j++)
        {
            found = 1;
            for (int k = 0; k < 2; k++)
            {
                for (int m = 0; m < 2; m++)
                {
                    if (A[i + k] != B[j + m]) found = 0;
                }
                if (!found) break;
            }
            if (found) printf("Matricata B se sudurja v A, zapochvaiki ot red %d, kolona %d", i, j);
        }
    }*/

}