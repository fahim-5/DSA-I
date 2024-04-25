#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *next;
};
int V,E;
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
void BFS(int s){
    queue<int> Q;
    char c[V];
    int p[V],dist[V];
    for(int i=0;i<V;i++){
        c[i] = 'w';
        p[i] = -1;
        dist[i] = 0;
    }
    c[s] = 'g';
    Q.push(s);
    while(!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();
        if(c[cur_node]=='b')continue;

        Node *vertices = head[cur_node];
        while(vertices){
            int neighbor = vertices->v;
            if(c[neighbor]=='w'){
                c[neighbor] = 'g';
                p[neighbor] = cur_node;
                dist[neighbor] = dist[cur_node]+1;
                Q.push(neighbor);
            }
            vertices = vertices->next;
        }
        c[cur_node]='b';
        cout<<cur_node<<"->";
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
    BFS(2);
    return 0;
}
/*
8 9
0 1
0 2
1 2
1 5
2 5
2 7
2 4
3 6
4 6
*/
