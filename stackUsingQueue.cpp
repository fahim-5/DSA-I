#include<bits/stdc++.h>
using namespace std;
queue<char> q1,q2;

void push(int x){/// This is for stack
    q1.push(x);
}
char pop(){
    while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
    }
    char x = q1.front();
    q1.pop();
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    return x;
}
int main(){
    push('a');
    push('b');
    push('c');
    push('d');
    cout<<pop();
    push('e');
    cout<<pop();
    cout<<q1.back();
    return 0;
}
