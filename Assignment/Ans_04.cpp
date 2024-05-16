#include <bits/stdc++.h>
using namespace std;


using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int g[10][10] = {0}; 

    
    for (int i = 1; i <= E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = w;
        g[b][a] = w; 
    }

    

    
    int max= 0;
    int Ans_vertex = -1;
    for (int i = 0; i < V; i++) {
        int count = 0;
        for (int j = 0; j < V; j++) {
            if (g[i][j] != 0) { 
                count++;
            }
        }
        if (count > max) {
            max = count;
            Ans_vertex= i;
        }
    }

    
    cout << "Vertex with the highest number of adjacent nodes: " << Ans_vertex << endl;

    return 0;
}
