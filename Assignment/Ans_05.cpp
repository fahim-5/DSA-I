#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include<math.h>

using namespace std;

stack<int> topo;
const int INF = INT_MAX;
int g[10][10];
bool visited[10];
int longestPath[10];

void zeroing()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            g[i][j] = 0;
        }
    }
}



void DFS(int v, int V)
{
    visited[v] = true;
    for (int i = 0; i < V; ++i)
    {
        if (g[v][i] && !visited[i])
        {
            DFS(i, V);
        }
    }
    topo.push(v);
}



void topologicalSort(int V)
{
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            DFS(i, V);
        }
    }
}



bool hasCycle(int V, int vertex, bool visited[], bool recursionStack[], int g[][10]) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        recursionStack[vertex] = true;

        for (int i = 0; i < V; ++i) {
            if (g[vertex][i] != 0) {
                if (!visited[i] && hasCycle(V, i, visited, recursionStack, g))
                    return true;
                else if (recursionStack[i]) 
                    return true;
            }
        }
    }
    recursionStack[vertex] = false; 
    return false;
}



bool isAcyclic(int V, int g[][10]) {
    bool visited[10] = {false};
    bool recursionStack[10] = {false};

    for (int i = 0; i < V; ++i) {
        if (hasCycle(V, i, visited, recursionStack, g))
            return false;
    }
    return true;
}


void longestPathDirection(int source, int V)
{

    for (int i = 0; i < V; ++i)
    {
        longestPath[i] = (i == source) ? 0 : -INF;
    }

    topologicalSort(V);

    while (!topo.empty())
    {
        int u = topo.top();
        topo.pop();

        for (int v = 0; v < V; ++v)
        {
            if (g[u][v] != 0)
            {
                if (longestPath[u] != -INF && longestPath[v] < longestPath[u] + g[u][v])
                {
                    longestPath[v] = longestPath[u] + g[u][v];
                }
            }
        }
    }
}

void printPaths(int source, int V)
{
    cout << "Longest paths from source vertex " << source << " to every other vertex are:" << endl;
    for (int i = 0; i < V; ++i)
    {
        if (i == source) continue; 
        cout << "dist(" << source << ", " << i << ") = ";
        if (longestPath[i] == -INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << longestPath[i] << " (";
            if (longestPath[i] != 0)
            {
                vector<int> path;
                int current = i;
                path.push_back(current);
                while (current != source)
                {
                    for (int j = 0; j < V; ++j)
                    {
                        if (g[j][current] != 0 && longestPath[current] == longestPath[j] + g[j][current])
                        {
                            current = j;
                            path.push_back(current);
                            break;
                        }
                    }
                }
                for (int k = path.size() - 1; k >= 0; --k)
                {
                    cout << path[k];
                    if (k != 0)
                    {
                        cout << " --> ";
                    }
                }
            }
            cout << ")";
            cout << endl;
        }
    }
}



int main()
{
    int V, E;
    cout << "Enter the number of vertices of the graph: ";
    cin >> V;
    cout << "Enter the number of edges of the graph: ";
    cin >> E;

    zeroing();

    for (int i = 0; i < V; ++i)
    {
        visited[i] = false;
    }

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    int a, b, w;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> w;
        g[a][b] = w;
    }

    cout << "Enter the source vertex for finding the longest path: ";
    int s;
    cin >> s;

    if (!isAcyclic(V, g)) {
        cout << "The graph contains a cycle. Longest path cannot be computed." << endl;
        return 0;
    }

    longestPathDirection(s, V);

    printPaths(s, V);

    return 0;
}


/*
8
11


0 6 2
1 6 8
1 4 1
1 2 4
3 0 3
3 4 5
5 1 2
7 1 -1
7 0 6
7 3 4
7 5 -4


7 

my outpout :

dist(7, 0) = 7 (7 --> 3 --> 0)
dist(7, 1) = -1 (7 --> 1)
dist(7, 2) = 3 (7 --> 1 --> 2)
dist(7, 3) = 4 (7 --> 3)
dist(7, 4) = 9 (7 --> 3 --> 4)
dist(7, 5) = -4 (7 --> 5)
dist(7, 6) = 9 (7 --> 3 --> 0 --> 6)

*/