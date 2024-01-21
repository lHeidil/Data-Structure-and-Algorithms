#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue(unsigned long val);
void dequeue();
void printList();

int main()
{
    int Q,limit,count=0;
    long E;
    scanf("%d",&limit);
    while (count != limit)
    {
    scanf("%d",&Q);
    if(Q == 1)
    {
        scanf("%lu",&E);
        enqueue(E);
    }
    else if (Q == 2)
        dequeue();
    else if (Q == 3)
        printList();
    count +=1;
    }
    return 0;
}
void enqueue(unsigned long val)
{
    struct node *newNode = malloc(sizeof(struct node));  //e3ml newnode w 7ot feha l value w tshawr 3la null
    newNode->data = val;
    newNode->next = NULL;
    if (newNode == NULL)
    {
       exit(0);
    }
    else if (front == NULL && rear == NULL) //lw fadya flbdya 5lehom l 2 yshwro 3la awl w7da
    {
        front = newNode;
        rear = newNode;
    }

    else
    {
        rear->next = newNode; //connect lpointer to new node 3shan yb2a gded fl line
        rear = newNode;//n5li  lrear yshwr 3leha
    }
}
void dequeue()
{
    struct node *temp;

    if(front != NULL) //toul mhwa m5lssh lsa
    {
        temp = front;
        front = front->next; //5ali l front yshwr 3lb3dha
        if(front == NULL) //lma ywsl lla5er 5ali lrear bnull
            rear = NULL;
        free(temp);
    }
}
void printList()
{
    struct node *temp = front;
    if (temp == NULL) //lw l front msh byshwr 3la 7ga y3ni hya fdya
        printf("Empty\n");
    else{
    while(temp != NULL) //toul mhya msh fdya etb3 ldata wshwr 3lb3dha
    {
        printf("%d",temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf(",");
    }
    printf("\n");}
}
