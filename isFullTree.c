#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
int isFullTree (TreeNodePtr node);
void enqueue(TreeNodePtr node);
TreeNodePtr dequeue();

int main()
{

    TreeNodePtr A = NULL,ptr = NULL,B = NULL,C = NULL;
    int size=0,i;

    scanf("%d",&size);
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

    if (isFullTree(A)) printf("YES");
        else printf("NO");

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
int isFullTree (TreeNodePtr node)
{
    if (node == NULL)
        return 1;

    if (node->left == NULL && node->right == NULL)
        return 1;

    if ((node->left) && (node->right))
        return (isFullTree(node->left) && isFullTree(node->right));

    return 0;
}
