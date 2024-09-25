//USING ARRAY 
#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int top;
    int size;
    int *s;
};

void create(struct Stack *st){
    printf("enter the size of stack:");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}
void Display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d\n",st.s[i]);
    }
    printf("\n");
}
void push(struct Stack *st){
    if(st->top==st->size-1){
        printf("stack is full\n");
    }
    else{
        printf("enter the element to be pushed:");
        scanf("%d",&st->s[++st->top]);
    }
}
int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        printf("stack is empty\n");
    }
    else{
        x=st->s[st->top--];
        return x;
    }

}
int peek(struct Stack st,int index){
    int x=-1;
    if(st.top-index+1<0){
        printf("invalid index\n");
    }
    x=st.s[st.top-index+1];
    return x;
}
int isEmpty(struct Stack st){
    if(st.top==0){
        return 1;
    }
    return 0;
}
int isFull(struct Stack st){
    return st.top==st.size-1;
}
int stackTop(struct Stack st){
    if(!isEmpty(st)){
    return st.s[st.top];}
    return -1;
}
int main(){
    struct Stack st;
    create(&st);
    int choice;
    while(1){
    printf("1.PUSH THE ELEMENT INSIDE STACK \n 2. REMOVE ELEMENT FROM STACK \n 3.DISPLAY ELEMENT IN THE STACK \n4.EXIT\n");
    scanf("%d",&choice);
   
    switch (choice)
    {
        case 1:
            push(&st);
            break;
        case 2:
            printf("poped element is :%d",pop(&st));
            break;
        case 3:
            Display(st);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
    }
    }
    return 0;
}