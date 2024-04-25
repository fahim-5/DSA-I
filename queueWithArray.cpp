#include <bits/stdc++.h>
using namespace std;

#define SIZE 5 // first decler a size for the queue

int Q[SIZE], f = -1, r = -1;     // intializog the quue.with front and rare.



bool isEmpty()
{
    if (f == -1 && r == -1)   //if front and rare both are -1 then it is empty
    {
        return true;
    }
    else
    {
        return false;
    }
}




bool isFull()
{
    if (r + 1 == SIZE)    // rare always enter at the last.so if rare is at position r+1 then the queue is full
        return true;
    else
        return false;
}



void enqueue(int x)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
        return;
    }
    if (isEmpty())
    {
        f = r = 0;   // this is the rare case where the f and r are both at -1.then we have to 
    }                // increase both togther.
    else
    {
        r = r + 1;
    }
    Q[r] = x;          //entering element at the rare postiotion of the queue.
}


int dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return -1;
    }

    int x = Q[f];    //in dequeue the front element will get out. so we are taknig this in to a temp var.

    if (f == r)
    {
        f = r = -1;     //this case will happen when there is one element in the queue
    }
    else
    {
        f = f + 1;     //hrer the front is moving to the next element
    }
    return x;         //dequeue element
}


int top()
{
    return Q[f];     //this is front
}


void print()
{
    if (!isEmpty())     //if is not empty
    {
        cout << "Current Queue" << endl;
        for (int i = f; i <= r; i++)     // startinf from font and ending where not equal to rare.
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}



int main()
{

    dequeue();
    enqueue(10);
    enqueue(13);
    enqueue(7);
    cout << dequeue() << endl;
    enqueue(5);
    enqueue(2);
    enqueue(8);
    enqueue(12);
    cout << top() << endl;
    enqueue(15);
    print();
    return 0;
}
