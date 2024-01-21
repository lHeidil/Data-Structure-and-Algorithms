#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int main()
{
    char *str;
    str = (char*)malloc(10000*sizeof(char));
    int num1,num2,result,i=0;
    stack *A;
    create(&A);
    scanf("%s", str);
    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
            push(&A,str[i]-'0');

        else if (str[i] == '*')
        {
            num1 = pop(&A);
            num2 = pop(&A);
            push(&A,num1*num2);
        }
        else if (str[i] == '+')
        {
            num1 = pop(&A);
            num2 = pop(&A);
            push(&A,num2+num1);
        }
        else if (str[i] == '-')
        {
            num1 = pop(&A);
            num2 = pop(&A);
            push(&A,(num2-num1));
        }
        else if (str[i] == '/')
        {
            num1 = pop(&A);
            num2 = pop(&A);
            if (num1 == 0)
                {
                printf("Not Valid");
                exit(0);
                }
            push(&A,num2/num1);
        }

        else if (str[i] == '%')
        {
            num1 = pop(&A);
            num2 = pop(&A);
            push(&A,num2%num1);
        }
        else
        {
            printf("Not Valid");
            exit(0);
        }
        i++;
    }
    free(str);
    result = pop(&A);
        if (isempty(A) == 0) //if not empty
        {
            printf("Not Valid");
            exit(0);
        }
    printf("%d", result);

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
       exit(0);
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
      printf ("Not Valid");
      exit(0);
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
int isempty (stack *top)
{
   if (top == NULL)
        return (1);
    else
        return (0);
}

