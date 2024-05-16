#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void put(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    if (val < head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;

    while (temp->next != NULL && temp->next->data < val)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int pop()
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    struct node *temp = head;
    int data = head->data;
    head = head->next;
    free(temp);
    return data;
}

void display()
{
    struct node *temp = head;
    printf("The priority Queue is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    put(3);
    put(5);
    put(1);
    put(4);

    display();

    printf("Pop item : ");
    int poped=pop();
    cout<<poped<<endl;

    display();

    return 0;
}
