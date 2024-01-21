#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grossSale,sal[9]={0,0,0,0,0,0,0,0,0};
    int count=0,j,salary,min,max;

    while (1)
    {
        printf("Enter Employee gross sale (-1 to end) : ");
        scanf("%d", &grossSale);
        salary = 200 + (grossSale*9/100);
        if (grossSale == -1)
        {
            printf("Total %d Employees Reported\n",count);
            printf("Employees in the range:\n");
            printf("200 299: %d\n",sal[0]);
            printf("300 399: %d\n",sal[1]);
            printf("400 499: %d\n",sal[2]);
            printf("500 599: %d\n",sal[3]);
            printf("600 699: %d\n",sal[4]);
            printf("700 799: %d\n",sal[5]);
            printf("800 899: %d\n",sal[6]);
            printf("900 999: %d\n",sal[7]);
            printf("Over 1000: %d\n",sal[8]);
            break;
        }
        printf("Employee salary is $%d\n",salary);
        min = 200;
        max = 299;
        for (j=0;j<8;j++)
        {
         if (salary >= min && salary <= max) sal[j]++;
         else if (salary > 999)
         {
             sal[8]++;
             break;
         }
         min+=100;
         max+=100;
        }
        count++;
    }
    return 0;
}
