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
void push (stack **top, int element);
int pop (stack **top);
int isempty (stack *top);
void recursion(stack **top, unsigned long x, int N);

int main() {
    unsigned long x;
    int N,num;
    stack *A;
    create(&A);
    scanf("%lu %d",&x,&N);
    recursion(&A,x,N);
    while(!isempty(&A))
    {
        num = pop(&A);
        if (num<10)
            printf("%d",num);
        else
            printf("%c",num);
    }

    return 0;
}

void recursion(stack **top, unsigned long x, int N)
{
    unsigned long div;
    int mod;
    div = x/N;
    mod = x%N;
    if (mod < 10) push(top,mod);
    else push(top,(mod+55));
    if (div != 0)
    recursion(top,div,N);

}
void create (stack **top)
{
   *top = NULL;
}
void push (stack **top, int element)
{
    stack *new;

    new = (stack *)malloc (sizeof(stack));
    if (new == NULL)
       exit(0);

    new->value = element;
    new->next = *top;
    *top = new;
}
int pop (stack **top)
{
   int t;
   stack *p;

   if (*top == NULL)
      exit(0);
   else
   {
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
      return t;
   }
}
int isempty (stack *top)
{
   if (top == NULL)
        return (1);
    else
        return (0);
}
