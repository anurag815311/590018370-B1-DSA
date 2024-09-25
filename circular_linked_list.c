#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct Node{
    int data;
    struct Node* next;
}*head;

void create(int a[],int len){
    int i;
    struct Node *last,*t;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=a[0];
    head->next=head;
    last=head;
    for(i=1;i<len;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}
void recur_display(struct Node *p){
    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d ",p->data);
        recur_display(p->next);
    } 
    flag=0;
}
void insert(int pos,int value,struct Node *p){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if(pos==0){
        t->data=value;
    if(head==NULL){
         head=t;
         head->next=head;
    }
    else{
        while(p->next!=head){
            p=p->next;
        }
        p->next=t;
        t->next=head;
        head=t;
    }
    }
    else{
        t->data=value;
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int Delete(struct Node *p,int index){
    struct Node *q;
    int i,x;
    if(index==1){
        while(p->next!=head)p=p->next;
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    
    }
    else{
        for( i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main(){
    int arr[]={1,2,3,4,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    create(arr,n);
    //Display(head);
   // recur_display(head);
   insert(3,10,head);
   Display(head);
   Delete(head,3);
   printf("\n");
   Display(head);
    return 0;
}