#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int> pq;
    /*
        1.push()
        2.pop()
        3.top()
        5.empty()
        6.size()
    */

    // this prority queue is the decending order enqueue

    pq.push(10);
    pq.push(7);
    pq.push(13);
    pq.push(8);
    pq.push(11);

    cout << pq.top() << endl; /// top=13
    pq.pop();                 // 13 has poped
    cout << pq.top() << endl; // top=11

    cout << "----------------------------content-----------------------" << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
