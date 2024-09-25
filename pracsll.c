#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct Node{
    int data;
    struct Node *next;
}*first;
void create(int a[],int n){
    struct Node *last,*t;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=0;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void insert(struct Node *p,int index,int value){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=value;
    t->next=NULL;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        struct Node *q=first;
        for(int i=0;i<index-1;i++){
            q=q->next;
        }
        t->next=q->next;
        q->next=t;
    }
}
void insert_at_last(struct Node **p,int value){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=value;
    t->next=NULL;
    struct Node *q = *p;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=t;

}
int main(){
    int a[]={12,3,2,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    create(a,n);
    //Display(first);
    //insert(first,4,23);
    //Display(first);
    insert_at_last(&first,30);
    Display(first);
    return 0;
}