/*program to implement stack using linked list*/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
typedef struct node
{
    int data;
    struct node *next;
}node;

void push(node**,int);
int pop(node **s);
void display(node*);
int count(node*);

int main(){
    node *top;
    int ch,num;
    top=NULL;
    while (1)
    {
        printf("\n\n What do you want to do?\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.count\n");
        printf("5.press any key to exit...\n");
        printf("Enter your choice : ");

        scanf("%d",&ch);

        switch (ch)
        {
        case 1:{
            printf("Enter the value you want to push onto the stack:");
            scanf("%d",&num);
            push(&top,num);
        }
            break;
        case 2:{
            printf("The popped element is %d",pop(&top));
        }
            break;
        case 3:{
            printf("Element in the stack are :");
            display(top);
        }
            break;
        case 4:{
            printf("The number of element = %d",count(top));
        }
            break;
        default:{
            printf("THANK YOU!!!");
            exit(0);
        }
    }
    
  }
}

void push(node **s, int num)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data = num;
    p->next = *s;
    *s = p;
}

int pop(node **s){
    node *temp;
    int item;
    if(*s == NULL){
        printf("\n Stack Underflow!!!");
        exit(0);
    }
    else
    {
        temp = *s;
        item = temp->data;
        *s = temp->next;
        free(temp);
    }
    return item;
}

void display(node *s){
    node *temp;
    temp = s;
    printf("\n\n Top-> ");
    while ((temp)!=NULL)
    {
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int count(node *s){
    int count = 0;
    while ((s)!= NULL)
    {
        s = s->next;
        count++;
    }
    return count;
}

