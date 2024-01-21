#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M1[3][3],M2[3][3],i,j,sum[3][3];
    printf("Input matrix1 of size 3x3:\n");
    for (i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",(*( M1 +i )+j));

    printf("Input matrix2 of size 3x3:\n");
    for (i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",(*( M2 +i )+j));

    printf("Sum of both matrices: \n");
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            *(*( sum +i )+j) = *(*( M1 +i )+j) + *(*( M2 +i )+j);
            printf("%d ", *(*( sum +i )+j));
        }
        printf("\n");
    }
    return 0;
}
