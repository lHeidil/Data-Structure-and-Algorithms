#include <stdio.h>
#include <stdlib.h>

int main()
{
    int positive=0,negative=0,i;
    float negative_sum=0,positive_sum=0;
    float number[5];
    printf("Enter 5 numbers:\n");
    for(i=0;i<5;i++)
    {
        scanf("%f", &number[i]);
        if (number[i] > 0)
        {
            positive ++;
            positive_sum += number[i];
        }
        else if (number[i]<0)
        {
            negative++;
            negative_sum += number[i];
        }
    }
    printf("Number of positive numbers: %d\n", positive);
    printf("Number of Negative numbers: %d\n", negative);
    if (positive==0 && negative!=0)
    {
    printf("Average of positive numbers: %f\n", 0);
    printf("Average of Negative numbers: %f\n", negative_sum/negative);
    }
    else if (positive != 0 && negative==0)
    {
    printf("Average of positive numbers: %f\n", positive_sum/positive);
    printf("Average of Negative numbers: %f\n", 0);
    }
    else if (positive == 0 && negative == 0)
    {
        printf("Average of positive numbers: %f\n", 0);
        printf("Average of Negative numbers: %f\n", 0);
    }
    else
    {
        printf("Average of positive numbers: %f\n", positive_sum/positive);
        printf("Average of Negative numbers: %f\n", negative_sum/negative);
    }
    return 0;
}
