#include <stdio.h>
#include <stdlib.h>

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;

    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = top->data;
    struct node *temp;
    temp = top;
    top = top->next;
    free(temp);
    return data;
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display()
{
    struct node *temp;
    temp = top;
    printf("The stack elements are: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




void sort()
{
    int tempStack[MAX_SIZE]; 
    int tempTop = -1;        

    while (!isEmpty())
    {
        int temp = pop(); 

        while (tempTop != -1 && tempStack[tempTop] < temp)
        {
            push(tempStack[tempTop--]);
        }

        tempStack[++tempTop] = temp;
    }

    
    while (tempTop != -1)
    {
        push(tempStack[tempTop--]);
    }
}


int main()
{
    
    push(4);
    push(2);
    push(1);
    push(3);
    push(60);
    push(55);

    sort(); 

    int poped=pop();
    cout<<poped<<endl;
    display(); 


    int top=peek();
    cout<<top<<endl;

    return 0;
}
