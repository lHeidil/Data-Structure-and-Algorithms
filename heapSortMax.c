#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(long *a, long *b);
void heapify(long arr[], int n, int i);
void heapSort(long arr[], int n);

int main()
{
    int size,i,interval,max=0;
    scanf("%d",&size);
    long arr[size];
    for(i=0;i<size;i++)
        scanf("%ld",&arr[i]);
    heapSort(arr, size);
    for(i=0;i<size-1;i++)
    {
        interval = arr[i+1]-arr[i];
        if (interval>max)
            max=interval;
    }
    printf("%d",max);
    return 0;
}

void swap(long *a, long *b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(long arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(long arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
