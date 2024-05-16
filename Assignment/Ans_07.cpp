#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

const int MAX = 100;

void findMaxOccurrence(queue<int> &q)
{
    int arr[MAX + 1] = {0};

    while (!q.empty())
    {
        int value = q.front();
        q.pop();
        arr[value]++;
    }

    int maxNum = 0;
    int i;
    for (i = 1; i <= MAX; ++i)
    {
        maxNum = max(maxNum, arr[i]);
    }

    int flag = 1;
    for (int i = 1; i <= MAX; ++i)
    {
        if (arr[i] == maxNum)
        {
            if (flag != 1)
            {
                cout << ", ";
            }
            cout << i << " ";
            flag = 0;
        }
    }
    cout << "Occurred " << maxNum << " times" << endl;
}

int main()
{
    int N;

    cout << "Enter the value of N (0 < N < 1000): ";
    cin >> N;

    if (N <= 0 || N >= 1000)
    {
        cout << "Invalid input of N " << endl;
        return 1;
    }

    queue<int> Q;

    for (int i = 0; i < N; ++i)
    {
        int num = rand() % 100 + 1;
        Q.push(num);
    }

    findMaxOccurrence(Q);

    return 0;
}
