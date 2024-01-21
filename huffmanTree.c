#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_IN 10001
int pu = 0;

struct Node
{
    int freq;
    char val;
    struct Node *next,*l,*r;

};


struct Node *create(char val,int f)
{
    struct Node * temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val  = val;
    temp->freq =f;
    temp->next = NULL;
    temp->l = NULL;
    temp->r = NULL;
    return temp;

}
struct Node *subTree (struct Node *n1,struct Node *n2){

   struct Node * temp = (struct Node*) malloc(sizeof(struct Node));
    temp->freq =n1->freq + n2->freq;
    temp->val='_';
    temp->next = NULL;
    if ((n1-> freq > n2-> freq)||((n1->freq== n2->freq)&&(n1->val<n2->val))){
        struct Node *sw =n1;
        n1 = n2 ;
        n2 = sw;
    }
    temp->l = n1;
    temp->r = n2;
    return temp;
}
void put (struct Node **ls,struct Node *node)
{
    struct Node *temp= *ls,*pre=*ls;
    if (temp == NULL || pre == node) return;
    if (temp->freq ==0){
        temp = node;
        *ls = temp;
        return;
    }
    while (temp->next !=NULL && node->freq >temp->freq ){
        pre= temp;
        temp = temp->next;
    }
    if (temp->next == NULL && node->freq > temp->freq){
        temp->next = node;
        return;
    }

    while (temp->val >= node->val&& temp-> freq == node->freq){
            if(temp->next == NULL){
                temp->next = node;
                return;
            }
            pre= temp;
            temp = temp->next;

    }
    if (pre == temp) {
        node->next = temp;
        *ls = node;
    }
    else {
        pre->next = node;
        node->next = temp;
    }


}

int main() {

    struct Node * lis = (struct Node*) malloc (sizeof(struct Node));
    lis->freq =0;
    lis->next = NULL;
    char s[MAX_IN],e[MAX_IN];

    scanf("%[^\n]",s);
    scanf("%s",e);


    int ls =strlen(s), le = strlen(e);
    if(ls<2 || le<1)return 0;

    int y[ls],f,count=0,z;
    char x[ls];
    for (int i=0; i< ls; i++){
        f=0;
        char c = s[i];
        for ( z=0; z<count; z++){
            if(c==x[z]){
                f=1;
                break;
            }
        }
        if (f){
            y[z]++;
            continue;
        }
        x[count]= c;
        y[count++]=1;

    }


    for (int i=0; i<count ; i++){
        put(&lis,create(x[i],y[i]));
    }
    struct Node* t = lis;
    while(count >1){
        put(&lis->next,subTree(lis,lis->next));
        if(lis->next !=NULL){
            if(lis==t &&lis->next->next != NULL){
            lis = lis->next->next;
            t= lis;
        }
        else  lis = lis->next;
        }

        count--;
    }

     int i = 0;
    while (i<le){
        struct Node * tm = lis;

        while(tm->l) {
            if(e[i++]=='1')tm= tm->r;
            else tm= tm-> l;

        }
        if(i<=le)printf("%c",tm->val);
    }

}
