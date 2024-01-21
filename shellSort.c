#include <stdio.h>

void shellSort(int array[], int n);
int N,K;

int main()
{
    scanf("%d %d", &N, &K);
    int array[N];
    for(int i=0;i<N;i++)
        scanf("%d",&array[i]);
    shellSort(array, N);
}

void shellSort(int array[], int n)
{
    for (int i = n / 2; i > 0; i /= 2)
    {
        for (int j = i; j < n; j += 1)
        {
            int temp = array[j];
            int z;
            for (z = j; z >= i && array[z - i] > temp; z -= i)
            {
                array[z] = array[z - i];
            }
            array[z] = temp;
        }
    }
    printf("%d", array[N-K]);
}
