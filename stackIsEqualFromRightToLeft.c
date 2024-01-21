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
void push (stack **top, int element);
int pop (stack **top);

int main()
{
    int input_digits,num,reversed=0,count=0;
    stack *A;
    create(&A);
    scanf("%d" , &input_digits );
    num = input_digits;
    while (input_digits != 0)
    {
    push(&A,input_digits%10);
    input_digits /= 10;
    count +=1;
    }
    for(int i=0;i<count;i++)
        reversed += (pop(&A)* pow(10,i));
    if (num == reversed)
        printf("YES");
    else
        printf("NO");
    return 0;
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
    {
       printf ("\n Stack is full");
       exit(-1);
    }

    new->value = element;
    new->next = *top;
    *top = new;
}
int pop (stack **top)
{
   int t;
   stack *p;

   if (*top == NULL)
   {
      printf ("\n Stack is empty");
      exit(-1);
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
