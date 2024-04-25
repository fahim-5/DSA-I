#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int> Q;     //Q here variable name

    /*
        1.push()
        2.pop()
        3.front()
        4.back()
        5.empty()
        6.size()
    */

    Q.push(10);
    Q.push(7);
    Q.push(13);
    Q.push(8);
    Q.push(11);

    cout<<Q.front()<<endl;
    Q.pop();

    cout<<Q.front()<<endl;
    cout<<Q.back()<<endl;


    // Make a copy of the queue// other wise it will lost for the while loop.cz there is opo fucntion.

    queue<int> Q_copy = Q;
    

    cout<<"-----content----"<<endl;
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();   //this will help to get the front elemt evry time in iterating style.
    }

    return 0;
}
