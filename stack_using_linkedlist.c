#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*head=NULL;

void push(int x){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("stack overflow");
    }
    else{
    t->data=x;
    t->next=head;
    head=t;
    }
}
void display(struct Node *p){
    printf("THE ELEMENT INSIDE THE STACK:");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int pop(struct Node *p){
    int x=-1;
     if(head==NULL){
        printf("stack is empty");
     }
     x=p->data;
     head=head->next;
     free(p);
     return x;

}
int peek(int pos , struct Node *p){
    int x=-1;
    int i;
    for(i=0;p!=NULL && i<pos-1;i++){
        p=p->next;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        return x;
    }
}
int main(){
    push(5);
    push(6);
    push(7);
    display(head);
    int deleted_item=pop(head);
    printf("the element removed from head:%d\n",deleted_item);
    display(head);
    push(889);
    display(head);
    int ele_data=peek(3,head);
    printf("the data at given position:%d",ele_data);
    return 0;
}