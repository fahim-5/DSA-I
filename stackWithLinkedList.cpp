#include <bits/stdc++.h>
using namespace std;



struct Student
{
    int ID;
    string name;
    float cgpa;
};


struct Node
{
    Student s;
    Node *next;
};


Node *top = NULL;


bool isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}



void push(Student s1)
{
    Node *newNode = new Node;
    newNode->s = s1;
    newNode->next = NULL;

    if (top == NULL)
    {
        top = newNode;
        return;
    }
    newNode->next = top; // previous top will be at the curent top node next.
    top = newNode;
}

/*In a stack implementation using a linked list, each node typically points to the node below it.
 When you add a new node to the top of the stack, you want this new node to point to the previous
 top node (the one that was previously at the top of the stack). This is because in a stack, you
 add and remove elements from the top, and you want the top node to always point to the node below it.
*/



Student pop()
{
    if (isEmpty())
    {
        cout <<"Underflow"<<endl;
    }
    else
    {
        Node *tmp = top;
        Student s1 = tmp->s;

        top = top->next;

        
        delete tmp;
        return s1;
    }
}



Student peek()
{
    return top->s;
}



void printStack()
{
    Node *ptr = top;
    while (ptr)
    {
        cout << ptr->s.ID << " " << ptr->s.name << " " << ptr->s.cgpa << endl;
        ptr = ptr->next;
    }
}



int main()
{

    push({1, "Rahad", 3.95});
    push({2, "Mohai", 3.97});
    push({3, "Partho", 4});
    push({4, "Netu", 3.5});

    printStack();
    cout << pop().name << endl;
    printStack();
    return 0;
}
