#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // Use greater<int> comparator for min-heap

    pq.push(10);
    pq.push(7);
    pq.push(13);
    pq.push(8);
    pq.push(11);
    

    cout << "Top element: " << pq.top() << endl; // Top element should be 7

    cout << "----------------------------content-----------------------" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
