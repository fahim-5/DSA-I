#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
};
Node *head = NULL;

void insertAtFirst(int v){
    Node *t = new Node;
    t->val = v;
    t->next = NULL;
    if(head==NULL){
       head = t;
       return;
    }
    t->next = head;
    head = t;

}

void insertAtLast(int v){
    if(head==NULL){
        insertAtFirst(v);
        return;
    }
    Node *t = new Node;
    t->val = v;
    t->next = NULL;

    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = t;
}

void printList(){
    if(head==NULL){
        cout<<"There is no element"<<endl;
        return;
    }
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->val<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
}
void insertAt(int v,int indx){
    if(head==NULL || indx<=1)
    {
        insertAtFirst(v);
        return;
    }

    Node *t = new Node;
    t->val = v;
    t->next = NULL;

    int cnt=0;
    Node *ptr=head;
    while(ptr->next!=NULL){
        cnt++;
        if(cnt+1==indx)break;
        ptr = ptr->next;
    }
    t->next = ptr->next;
    ptr->next = t;
}
int deleteFrom(int indx){
    int cnt=0;
    Node *ptr=head;
    while(ptr->next!=NULL){
        cnt++;
        if(cnt+1==indx)break;
        ptr = ptr->next;
    }
    Node *tmp = ptr->next;
    ptr->next = tmp->next;

    int item = tmp->val;
    delete tmp;
    return item;
}
bool linearSearch(int item){
    Node *ptr = head;
    while(ptr){
        if(ptr->val==item)return true;
        ptr = ptr->next;
    }
    return false;
}
int main(){
    insertAtFirst(10);
    insertAtFirst(5);
    insertAtLast(13);
    insertAtFirst(2);
    insertAtFirst(7);
    insertAt(17,4);
    insertAt(20,-1);
    insertAt(23,10);
    printList();
    cout<<"Deleted Item: "<<deleteFrom(4)<<endl;
    printList();
    if(linearSearch(13)){
        cout<<"Item is found"<<endl;
    }
    else{
        cout<<"Item isn't found"<<endl;
    }
    return 0;
}
