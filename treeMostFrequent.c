#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
   int data;
   struct treenode *left,*right;
}TreeNode, *TreeNodePtr;

struct node
{
    TreeNodePtr data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

TreeNodePtr create ();
void visit(TreeNodePtr node,int array[]);
void inOrder(TreeNodePtr node,int array[]);
void enqueue(TreeNodePtr node);
void Sort(int array[], int n);
TreeNodePtr dequeue();

int j=0,count=0,Most=0;
int main()
{

    TreeNodePtr A = NULL,ptr = NULL,B = NULL,C = NULL,x = NULL;
    int size=0,i,count=0,z=0;

    scanf("%d",&size);
    int array[size],arr[size];
    if (size != 0)
    A = create();
    if (A!=NULL)
    {
        for (i=0;i<size/2;i++)
        {
        B = create();
        C = create();
        ptr = dequeue();
        ptr->left = B;
        ptr->right = C;
        }
    }
    inOrder(A,array);
    Sort(array,j);

    if (array[0] == array[1]) count++;
    else count=1;
    for (i=1;i<j;i++)
    {
        if (array[i] == array[i-1]) count++;
        else count=1;
            if(Most<=count)
                 {
                    if (Most < count && i!=1)
                    {
                      z=0;
                    }
                Most=count;
                arr[z]=array[i];
                z++;
                }
    }
    for (i=0;i<z;i++)
    {
        printf("%d\n",arr[i]);
    }
}

TreeNodePtr create ()
{
    int value;
    scanf("%d",&value);
    if (value == -1) return NULL;
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    enqueue(p);
    return p;
}
void visit(TreeNodePtr node,int array[])
{
    //printf("--%d ", node->data);
    array[j]=node->data;
    j++;

}
void inOrder(TreeNodePtr node,int array[])
{
    if (node != NULL)
    {
        inOrder(node->left,array);
        visit(node,array);
        inOrder(node-> right,array);
    }
}
void enqueue(TreeNodePtr val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (newNode == NULL)
    {
       exit(0);
    }
    else if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }

    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
TreeNodePtr dequeue()
{
    TreeNodePtr val;
    struct node *temp;

    if(front != NULL)
    {
        val = front->data;
        temp = front;
        front = front->next;
        free(temp);
        return val;
    }
    else
    {
        rear = NULL;
        return NULL;
    }
}
void Sort(int array[], int n)
{
    int i, j,temp;
    for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
        if (array[j] > array[j+1])
        {
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
}
