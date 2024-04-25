#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v,w;
    Node *next;
};

Node *head[10];
void make_graph(int s,int d,int w){
    Node *newNode = new Node;
    newNode->v = d;
    newNode->w = w;
    newNode->next = NULL;

    if(head[s]==NULL){
        head[s] = newNode;
        return;
    }
    newNode->next = head[s];
    head[s] = newNode;
}
void printList(Node *tmp){
    while(tmp){
        cout<<"("<<tmp->v<<", "<<tmp->w<<")"<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main(){
    int V,E;
    cin>>V>>E;
    int a,b,c;
    for(int i=1;i<=E;i++){
        cin>>a>>b>>c;
        make_graph(a,b,c);
        make_graph(b,a,c);

    }
    cout<<"-------Graph-----"<<endl;
    for(int i=0;i<V;i++){
        cout<<"Adjacent of "<<i<<": ";
        Node *ptr = head[i];
        printList(ptr);
    }
    return 0;
}
/*
5 7
0 1 10
0 2 3
0 3 2
1 2 5
1 3 3
2 4 7
3 4 4
*/
