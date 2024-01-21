#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
   int data;
   struct treenode *left,*right;
}TreeNode, *TreeNodePtr;

TreeNodePtr create (int value);
void visit(TreeNodePtr node);
void preOrder(TreeNodePtr node);
TreeNodePtr BST(int array[], int start, int end);
int ok = 0;

int main()
{
    TreeNodePtr A = NULL;
    int size=0;

    scanf("%d",&size);
    int array[size];

    for (int i=0;i<size;i++)
        scanf("%d",&array[i]);

    A = BST(array, 0, size-1);
    preOrder(A);
}

TreeNodePtr create (int value)
{
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void visit(TreeNodePtr node)
{
    if (ok) printf(",");
    printf("%d", node->data);
    ok=1;
}
void preOrder(TreeNodePtr node)
{
    if (node != NULL)
    {
        visit(node);
        preOrder(node->left);
        preOrder(node-> right);
    }
}
TreeNodePtr BST(int array[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start+end)/2;
    TreeNodePtr ptr = create(array[mid]);
    ptr->left = BST(array, start, mid-1);
    ptr->right = BST(array, mid+1, end);
        return ptr;
}
