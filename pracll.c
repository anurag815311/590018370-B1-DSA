#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int x;
    struct Node *next;
}*first;

void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->x=a[0];
    first->next=NULL;
    last=first;
    for(i=0;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->x=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->x);
        p=p->next;
        }
}
int main(){
    int a[]={5,4,5,4,3,4};
    int length=sizeof(a)/sizeof(a[0]);
    create(a,length);
    Display(first);
    
    return 0;
}