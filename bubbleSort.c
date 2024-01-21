#include <stdio.h>
#include <stdlib.h>
void Sort(int array[], int n);
int main()
{
    int i,j,n,m,count=0;
    scanf("%d %d",&n,&m);
    int h[n],t[m];

    for (i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(i=0;i<m;i++)
        scanf("%d",&t[i]);

    Sort(h,n);
    Sort(t,m);

    for (i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(h[i]>=t[j] && t[j] != -1)
            {
                t[j]= -1;
                break;
            }
    for (j=0;j<m;j++)
        if (t[j] == -1)
            count++;
    printf("%d", count);

    return 0;
}

void Sort(int array[], int n)
{
    int i, j,temp;
    for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
        if (array[j] > array[j+1])
        {
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
}
