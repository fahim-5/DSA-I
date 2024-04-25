#include<bits/stdc++.h>
using namespace std;

int g[10][10];

int main(){
    int V,E,a,b,w;
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        cin>>a>>b>>w;          //this is actually weighted graph
        g[a][b] = w;
        g[b][a] = w;          /// We will comment this line, if it's directed.
    }

    cout<<"---------Graph----"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
5 7
0 1 10
0 2 3
0 3 2
1 2 5
1 3 3
2 4 7
3 4 4
*/
