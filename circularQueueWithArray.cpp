#include<bits/stdc++.h>
using namespace std;


#define SIZE 5    // taking size



int Q[SIZE],f=-1,r=-1;   //intializing Q,f,r



bool isEmpty(){              //it similer as lineer queue
    if(f==-1 && r==-1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if((r+1)%SIZE==f)       //important    5***
        return true;
    else
        return false;
}


void enqueue(int x){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }
    if(isEmpty()){   // mena f and r are at -1
        f = r = 0;   //now they are in 0 index
    }
    else{
        r = (r+1)%SIZE;  // we are iterrating the rare in circuler motion
    }
    Q[r] = x;
}


int dequeue(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int x = Q[f];
    if(f==r){               //when there was only one element
        f = r = -1;
    }
    else{
        f = (f+1)%SIZE;   //other we pass the front to his next index in circuler way
    }
    return x;

}



int top(){
    return Q[f];      //similer as lineer queue
}


//using while loop 

void printQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    int i = f;
    cout << "Circular Queue: ";
    do {
        cout << Q[i] << " ";
        i = (i + 1) % SIZE;
    } while (i != (r + 1) % SIZE);    //it menas it will print rare but it will not print after rare
    cout << endl;
}


int main(){

    dequeue();
    enqueue(10);
    enqueue(13);
    enqueue(7);
    cout<<dequeue()<<endl;
    cout<<top()<<endl;
    enqueue(15);
    enqueue(5);
    enqueue(4);
    cout<<top()<<endl;
    enqueue(8);
    return 0;
}
