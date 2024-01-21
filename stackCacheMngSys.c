#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int ik=0;
struct TheStack
{
    int key;
    int value;
    struct TheStack *prev,*next;
}*head=NULL,*tail=NULL;
void PushToStack(int key,int value)
{
    struct TheStack *newnode=malloc(sizeof(struct TheStack));
    newnode->key=key;
    newnode->value=value;
    if(ik==0)
    {
        newnode->prev=newnode->next=NULL;
        head=tail=newnode;
        ik++;
        return;
    }
    else
    {
        newnode->prev=tail;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
        ik++;
    }
}
void printit()
{
    struct TheStack *tmp=head;
    while(tmp!=NULL)
    {
        printf("%d\t%d\n",tmp->key,tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    return;
}
void ModifiyToStack(struct TheStack* del)
{
    /* base case */
    if (head == NULL || del == NULL)
        return;
    /* If node to be deleted is head node */
    if (head == del)
    {

        if(head->next!=NULL)
        {
            head=head->next;
            head->prev=NULL;
            ik--;
        }
        else if(head->next==NULL)
        {
            head=NULL;
            tail=NULL;
            ik=0;
        }
        return;
    }
    if(del->next==NULL)
    {
        tail=tail->prev;
        tail->next=NULL;
        ik--;
        return;
    }
    else
    {
        /* Change next only if node to be deleted is NOT the last node */
        if (del->next != NULL)
            del->next->prev = del->prev;
        if (del->prev != NULL)
            del->prev->next = del->next;
        free(del);
        ik--;
        return;
    }
}
void SearchForKey(int key,int check,int value,int C)
{
    struct TheStack *tmp=head;
    if(check ==0)
    {
            while(tmp!=NULL)
        {
            if(tmp->key==key)
            {
                ModifiyToStack(tmp);
                break;
            }
            tmp=tmp->next;
        }
    }
    else if(check == 1)
    {
        while(tmp!=NULL)
        {
            if(tmp->key==key)
            {
                ModifiyToStack(tmp);
                break;
            }
            tmp=tmp->next;
        }
        while(ik>=C)
        {
            head=head->next;
            ik--;
        }
        PushToStack(key,value);
        return;
    }
    else if(check == 2)
    {
        while(tmp!=NULL)
        {
            if(tmp->key==key)
            {
                int v;
                v=tmp->value;
                printf("%d\n",v);
                ModifiyToStack(tmp);
                PushToStack(key,v);
                return;
            }
            tmp=tmp->next;
        }
        printf("Not Found\n");
        return;
    }
}
int main()
{
    //printf("Enter The Two Values Of P & C:\n");
    int P,C,i;
    scanf("%d %d",&P,&C);
    for(i=0;i<P;i++)
    {
        int task;
        scanf("%d",&task);
        if(task==1)
        {
            int key,value;
            //printf("Enter The Key & The Value:\n");
            scanf("%d %d",&key,&value);
            if(C!=0)
            {
                SearchForKey(key,1,value,C);
                if(value<1)
                {
                    printf("Error\n");
                    SearchForKey(key,0,value,C);
                    continue;
                }
            }
            else printf("Error\n");

        }
        else if(task==2)
        {
            int key;
            //printf("Enter The Key:\n");
            scanf("%d",&key);
            if(C!=0)
                SearchForKey(key,2,0,C);
            else
                printf("Not Found\n");
        }
    }
    return 0;
}
