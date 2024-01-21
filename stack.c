#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct lifo
{
   int value;
   struct lifo *next;
};
typedef struct lifo stack;

stack *top;

void create (stack **top);
int push (stack **top, long element);
int pop (stack **top);
long print(stack *top);

int main()
{
    int Q,limit,count=0;
    long E,min;
    stack *A;
    create(&A);
    scanf("%d",&limit);
    while (count != limit)
    {
    scanf("%d",&Q);
    if(Q == 1)
    {
        scanf("%ld",&E);
        push(&A,E);
    }
    else if (Q == 2)
        pop(&A);
    else if (Q == 3)
    {
        min = print(A);
        if(min == 0)
            printf("Empty\n");
        else
            printf("%ld\n",min);
    }
    count +=1;
    }
}
void create (stack **top)
{
   *top = NULL;
}

int push (stack **top, long element)
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

int pop (stack **top)
{
   stack *p;

   if (*top == NULL)
   {
      return(0);
   }
   else
   {
      p = *top;
      *top = (*top)->next;
      free (p);
      return (1);
   }
}

long print (stack *top)
{
    long min = 1000000000;
    if (top == NULL)
    {
        return(0);
    }
    else
    {
        while(top != NULL)
        {
            if ((top)->value < min)
                min = (top)->value;
            top = (top)->next;
        }
        return (min);
    }
}
