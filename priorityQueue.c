#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
    struct node* next;

} Node;

Node* newNode(long d, long p);
void enqueue(Node** head, long d, long p);
long dequeue(Node** head,long* max);
int isEmpty(Node** head);

int main()
{
    int n,count=0;
    long d,i, max = 0;
    scanf("%d", &n);
    if (n>=1)
    {
        scanf("%ld %ld", &d,&i);
        Node* pq = newNode(d, i);
        n--;
        while(n!=0)
        {
            scanf("%ld %ld", &d,&i);
            enqueue(&pq, d, i);
            n--;
        }

        while (!isEmpty(&pq))
            if (dequeue(&pq,&max) != 0)
                count++;

        printf("%d" , count);
    }

    return 0;
}

Node* newNode(long d, long p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

long dequeue(Node** head, long* max)
{
    long data = (*head)->data;
    long priority = (*head)->priority;

    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
    *max += data;
    if (*max <= priority)
        return *max;
    else
    {
        *max-=data;
        return 0;
    }
}

void enqueue(Node** head, long d, long p)
{
    Node* start = (*head);
    Node* temp = newNode(d, p);

    if ((*head)->priority > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority < p)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node** head)
{
    return (*head) == NULL;
}

