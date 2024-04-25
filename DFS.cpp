#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *next;
};
int V,E,t;
char c[10];
int p[10],dist[10],start[10],finish[10];
Node *head[10];
void make_graph(int s,int d){
    Node *newNode = new Node;
    newNode->v = d;
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
        cout<<"("<<tmp->v<<")"<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}
void DFS_VISIT(int s){
    t = t + 1;
    start[s] = t;
    c[s] = 'g';

    Node *vertices = head[s];
    while(vertices){
        int neighbor = vertices->v;
        if(c[neighbor]=='w'){
            p[neighbor] = s;
            dist[neighbor] = dist[s] + 1;
            DFS_VISIT(neighbor);
        }
        vertices = vertices->next;
    }
    t= t + 1;
    finish[s] = t;
    c[s] = 'b';
    cout<<s<<"->";

}
void DFS(){
    for(int i=0;i<V;i++){
        c[i] = 'w';
        p[i] = -1;
        dist[i] = 0;
    }
    t = 0;
    for(int i=0;i<V;i++){
        if(c[i]=='w'){
            DFS_VISIT(i);
        }
    }
}

int main(){

    cin>>V>>E;
    int a,b,c;
    for(int i=1;i<=E;i++){
        cin>>a>>b;
        make_graph(a,b);
        make_graph(b,a);

    }
    cout<<"-------Graph-----"<<endl;
    for(int i=0;i<V;i++){
        cout<<"Adjacent of "<<i<<": ";
        Node *ptr = head[i];
        printList(ptr);
    }
    cout<<"--------- Traversing ------"<<endl;
    DFS();
    return 0;
}
/*
10 10
0 1
0 2
1 2
1 5
2 5
2 7
2 4
3 6
4 6
8 9
*/

