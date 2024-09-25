#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
     struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Memory not available\n");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue(){
    int x=-1;
    struct Node *p;
    if(rear==NULL){
        printf("Queue is empty\n");
    }
    else{
        x=front->data;
        p=front;
        front=front->next;
        free(p);
    }
    return x;
}
void Display(struct Node *q){
    while(q){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}
int main(){
     enqueue(10);
     enqueue(20);
     enqueue(30);
     Display(front);
     dequeue();
     Display(front);

    return 0;
}