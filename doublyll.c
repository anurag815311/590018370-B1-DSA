#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;

}*first=NULL;

void Create(int a[],int len){
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(int i=1;i<len;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
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
int len(struct Node *p){
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct Node *p,int pos,int x){
    struct Node *t;
    int i ;
    if(pos<0 || pos>len(p)){
        return;
    }
    if(pos==0){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}
int Delete(struct Node *p,int index){
    int x,i;
    struct Node *q;
    if(index<1||index>len(p)){
     return -1;
    }
    if(index==0){
      first=first->next;
      if(first)first->prev=NULL;
      x=p->data;
      free(p);
    }
    else{
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}
void rev_dll(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}

int main(){
    int a[]={1,23,3,2,2,4};
    int n=sizeof(a)/sizeof(a[0]);
     Create(a,n);
     Display(first);
    //  int length=len(first);
    //  printf("\nthe length of linked list: %d",length);
    int del_ele=Delete(first,3);
    printf("\n deleted element is: %d",del_ele);
    printf("\n");
    Display(first);
    return 0;
}