#include<bits/stdc++.h>
using namespace std;


//here we are delcering the struct fro link list
struct Node{
    int d;
    Node *next;
};



Node *Front = NULL;  
Node *Rear=NULL;             //same as array just here we used node.




bool isEmpty(){
    if(Front == NULL && Rear==NULL)      //same as array
        return true;
    else
        return false;
}


//we no need the isFull function bcz it dynamic memory aclocation


void enqueue(int x){     
    Node *newNode = new Node;   //for enqueue we need a new node
    newNode->d = x;      // and in the newnode data we puting the data
    newNode->next = NULL;   //and we are making the next of the newnode null cs it is linner linklist 
    //so rare will alayas the last element.


    if(Front==NULL){
        Front=Rear=newNode;  //if the linklist is empty
        return;
    }

    Rear->next = newNode;   //we are puting the new node in the next of rear.
    Rear = newNode;        // now we are updating the new node

}


int dequeue(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return -1;
    }

    int x;
    if(Front==Rear){      // if there is only one node
        x = Front->d;
        Front=Rear=NULL;  //are vanising the linklist
    }
    else{
        x = Front->d;   // bcz the front have to out so we are taking the data of the frot node
        Front = Front->next;  //updating the front 
    }
    return x;
}
int main(){
    enqueue(10);
    enqueue(13);
    enqueue(7);
    enqueue(11);
    cout<<Front->d<<endl;
    cout<<dequeue()<<endl;
    cout<<Front->d<<endl;
}
