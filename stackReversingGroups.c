#include <stdio.h>
#include <stdlib.h>

struct lifo
{
   int value;
   struct lifo *next;
};
typedef struct lifo stack;

stack *top;

void create (stack **top);
int push (stack **top, long int element);
long int pop (stack **top);

int main()
{
    int S,N,limit,group;
    long int num;
    stack *A;
    create(&A);
    stack *B;
    create(&B);
    stack *C;
    create(&C);
    scanf("%d %d", &S, &N);
    group = S/N;
    for(int i=0;i<S;i++) //take input from user "it's reversed now"
    {
    scanf("%ld",&num);
    push(&A,num);
    }
    for(int i=0;i<S;i++) //reverse to be exactly as entered "it's now unreversed"
        push(&C,pop(&A));
    for(int i=0;i<group;i++) //for number of groups
        {
        for(int i=0;i<N;i++) //for number of elements in each group
            push(&B,pop(&C)); //reverse
        for(int i=0;i<N;i++)
        printf("%ld\n", pop(&B)); //print reversed
        }
    for(int i=0;i<S-(N*group);i++) //print the remaining unreversed
        printf("%ld\n", pop(&C));
    return 0;
}
void create (stack **top)
{
   *top = NULL;
}
int push (stack **top, long int element)
{
    stack *new;

    new = (stack *)malloc (sizeof(stack));
    if (new == NULL)
    {
       return(0);
    }
    else
    {
    new->value = element;
    new->next = *top;
    *top = new;
    return(1);
    }

}
long int pop (stack **top)
{
   long int t;
   stack *p;

   if (*top == NULL)
   {
       printf("Empty\n");
      return;
   }
   else
   {
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
      return t;
   }
}
