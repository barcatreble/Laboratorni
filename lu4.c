#include <stdio.h>
#include <stdlib.h>

//1
int strLength(char str[])
{   
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

//2
int broiDumi(char str[])
{   
    int i = 0, broi = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (str[i+1] == ' ') || (str[i] != ' ' && str[i+1] == '\0')) broi++;
        i++;
    }
    return broi;
}

//5
int broiGlasni(char str[])
{
    int i = 0, broi = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' ||  str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u' || str[i] == 'q') broi++;
        i++;
    }
    return broi;
}

int main() 
{
    //3
    /*char str[200];
    fgets(str, 200, stdin);
    for (char bukva = 'a'; bukva <= 'z'; bukva++)
    {
        int count = 0, i = 0;
        while (str[i] != '\0')
        {
            if(str[i] == bukva) count++;
            i++;
        }
    }*/

    //4
    /*char str1[200], str2[200];
    fgets(str1, 200, stdin);
    fgets(str2, 200, stdin);
    int i = 0, ravni = 1;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i]) 
        {
            ravni = 0; 
            break;
        }
        i++;
    }

    if(ravni) printf("Dvata niza sa ednakvi");
    else printf("Dvata niza sa razlichni");*/

    //6
    /*char str[200];
    fgets(str, 200, stdin);
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 97 && str[i] <= 122) str[i] -= 32;
        i++;
    }*/

    //7 i 9
    int nums[7];
    int sum = 0;
    /*printf("Napishete 7 chisla v intervala (-5000, 5000)");
    for (int i = 0; i < 7; i++) 
    {   
        scanf("%d", &nums[i]);
        while (nums[i] < -5000 || nums[i] > 5000)
        {   
            printf("Chisloto %d ne e v intervala. Vuvedete otnovo!", nums[i]);
            scanf("%d", &nums[i]);
        }
        sum += nums[i];
    }
    float avg = sum / 7.0;*/
   
    //8
    /*int max = 0;
    printf("Napishete 7 chisla v intervala (-5000, 5000)");
    for (int i = 0; i < 7; i++) 
    {   
        scanf("%d", &nums[i]);
        while (nums[i] < -5000 || nums[i] > 5000)
        {   
            printf("Chisloto %d ne e v intervala. Vuvedete otnovo!", nums[i]);
            scanf("%d", &nums[i]);
        }
        if (nums[i] > max) max = nums[i];
    }*/

    //10
    /*printf("Napishete 7 chisla v intervala (-5000, 5000)");
    for (int i = 0; i < 7; i++) 
    {   
        scanf("%d", &nums[i]);
        while (nums[i] < -5000 || nums[i] > 5000)
        {   
            printf("Chisloto %d ne e v intervala. Vuvedete otnovo!", nums[i]);
            scanf("%d", &nums[i]);
        }
        sum += nums[i];
    }
    int naiBlizko = nums[0];
    float avg = sum / 7.0;
    for (int i = 1; i < 7; i++)
    {
        if(abs(nums[i] - avg) > abs(naiBlizko - avg)) naiBlizko = nums[i];
    }*/
}