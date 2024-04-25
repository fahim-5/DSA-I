#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;

void insertAtFirst(int d){
    Node *t = new Node;
    t->data = d;
    t->next = t->prev = NULL;

    if(head==NULL){
        head = t;
        return;
    }
    head->prev = t;
    t->next = head;
    head = t;
}
void insertAt(int d,int indx){
    if(head==NULL || indx<=1)
    {
        insertAtFirst(d);
        return;
    }

    Node *t = new Node;
    t->data = d;
    t->next = NULL;
    t->prev = NULL;

    int cnt=0;
    Node *ptr=head;
    while(ptr->next!=NULL){
        cnt++;
        if(cnt==indx)break;
        ptr = ptr->next;
    }
    t->next = ptr;
    ptr->prev->next = t;
    t->prev = ptr->prev;
    ptr->prev = t;
}

int deleteFrom(int indx){
    int cnt=0;
    Node *ptr=head;
    while(ptr->next!=NULL){
        cnt++;
        if(cnt==indx)break;
        ptr = ptr->next;
    }
    Node *tmp = ptr;
    ptr = ptr->prev;
    ptr->next = tmp->next;
    tmp->next->prev = ptr;
    int item = tmp->data;
    delete tmp;
    return item;
}

void printList(){
    Node *ptr = head;
    while(ptr){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    insertAtFirst(3);
    insertAtFirst(5);
    insertAtFirst(10);
    insertAtFirst(7);
    printList();
    insertAt(13,3);
    printList();
    cout<<deleteFrom(4)<<endl;
    printList();
    return 0;
}
