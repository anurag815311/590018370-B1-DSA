#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int data;
    struct Node* next;
}*first;

void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
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
    printf("\n");
}

void Display_recurv(struct Node *p){
    
    if(p!=NULL){
        printf("%d ",p->data);
        Display_recurv(p->next);
    }
}
int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
 
void sum(struct Node *p){
    int s=0;
    while(p!=NULL){
        s=s+p->data;
        p=p->next;
    }
    printf("THE SUM OF ELEMENTS:%d",s);
}
void MAX(struct Node *p){
    int max=0;
    while(p!=NULL){
        if(max<p->data){
            max=p->data;
            p=p->next;
        }
    }
    printf("\n");
    printf("THE LARGEST ELEMENT: %d",max);
}
void MIN(struct Node *p){
    int min=p->data; // Initialize min with the first node's data
    while(p!=NULL){
        if(min>p->data){
            min=p->data;
        }
        p=p->next; // Move to the next node
    }
    printf("\n");
    printf("the smallest element %d",min);
}

int Search(struct Node *p,int num){
     while(p!=NULL){
        if(p->data==num){
            return 1;
        }
        p=p->next;
     }
     return -1;
}

void insert_at_beg(struct Node **p,int x){
    struct Node *q;
    
    q=(struct Node* )malloc(sizeof(struct Node));
    
    q->data=x;
    q->next=*p;
    *p=q;
}

void Insert(struct Node *p, int index, int x) {
    // // Check for invalid index
    if (index < 0 || index > count(p)) {
        printf("Invalid index\n");
        return;
    }

    // Create a new node
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    // Handle insertion at the beginning of the list
    if (index == 0) {
        t->next = first;
        first = t;
    } 
    else {
        // Find the node at the (index-1)th position
        struct Node *q = first;
        for (int i = 0; i < index - 1; i++) {
            q = q->next;
        }

        // Insert the new node at the specified position
        t->next = q->next;
        q->next = t;
    }
}
void insert_at_end(struct Node **p,int x){
    struct Node *q=(struct Node*)malloc(sizeof(struct Node));
    q->data=x;
    q->next=NULL;
    struct Node *t=*p;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=q;
}
//inserting element in a sorted linked list
void sortedinsert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
             t->next=q->next;
             q->next=t;
        }
    }
}
int delete_first(struct Node *p){
    int x;
    if(p==NULL){
        return -1;
    }
    else{
        x=p->data;
        first=first->next;
        free(p);
    }
    return x;
}
int Delete(struct Node *p,int pos){
    int x;
    int i;
    struct Node *q=NULL;
    if(first==NULL){
        return -1;
    }
    for(i=0;i<pos-1;i++){
       q=p;
       p=p->next;
    }
    
    q->next=p->next;
    x=p->data;
    free(p);
    
    return x;
}
int delete_last(struct Node *p){
    int x;
    struct Node *q=NULL;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    x=p->data;
    q->next=NULL;
  return x;
}

void reverse(struct Node *p){
  struct Node *q=NULL,*r=NULL;
  while(p!=NULL){
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  first=q;
   
}
void reverse_recur(struct Node *q,struct Node *p){
    if(p!=NULL){
        reverse_recur(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
int sorted(struct Node *p){
    int x=-65536;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}
void remove_duplicate_sorted_linked(struct Node *p){
    struct Node *q = p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }

    }
}

int main(){
    //int a[]={3,5,7,10,15};
    //int length=sizeof(a)/sizeof(a[0]);
   //create(a,length);
   // Display(first);
    //Display_recurv(first);
    //int counting=count(first);
    //printf("%d\n",counting);
    //sum(first);
    //MAX(first);
    //MIN(first);
    // int ele=Search(first,55);
    // if(ele==1){
    //     printf("\nElement Found!!!");
    // }
    // else{
    //     printf("\nElement Not Found!!!");
    // }
    
    // int number,pos;
    // printf("\nenter the number to insert:");
    // scanf("%d",&number);
    // printf("\nenter the position :");
    // scanf("%d",&pos);
    //insert_at_beg(&first,number);
    Insert(first,0,12);
    Insert(first,1,23);
    Insert(first,2,34);
    Insert(first,0,45);

    //insert_at_end(&first,10);
    //Display(first);
    //int deleted_item=delete_first(first);
    //int deleted_item=Delete(first,2);
    // int deleted_item=delete_last(first);
    // printf("\nDeleted item is :%d\n",deleted_item);
    // Display(first);
    reverse(first);
    Display(first);
    return 0;
}

