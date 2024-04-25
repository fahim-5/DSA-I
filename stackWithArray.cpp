#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

//eassy

int stck[SIZE],top=-1;



bool isFull(){
    if (top+1==SIZE)
        return true;
    else
        return false;
}



bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}




void push(int item){
    if(isFull())
    {
        cout<<"Overflow"<<endl;
        return;
    }

    top = top + 1;
    stck[top] = item;
}






int pop(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return -1;
    }

    int item = stck[top];
    top = top - 1;
    return item;
}



int peek(){
    return stck[top];
}




int main(){
    for(int i=1;i<=99;i++){
        push(10+i);
        cout<<"Top: "<<top<<" | stack["<<top<<"]: "<<stck[top]<<endl;
    }
    cout<<peek()<<endl;
    push(0);
    cout<<"Top: "<<top<<" | stack["<<top<<"]: "<<stck[top]<<endl;
    push(1);
    cout<<"Top: "<<top<<" | stack["<<top<<"]: "<<stck[top]<<endl;
    cout<<peek()<<endl;
    cout<<pop()<<endl;
    cout<<"Top: "<<top<<" | stack["<<top<<"]: "<<stck[top]<<endl;
    return 0;
}
