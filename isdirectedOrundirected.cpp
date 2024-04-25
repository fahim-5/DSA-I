#include<bits/stdc++.h>
using namespace std;



int main(){
    int V;
    cin>>V;
    int g[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>g[i][j];
        }
    }

    cout<<"---------Graph----"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    int directed = 0;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(g[i][j]!=g[j][i]){
                directed = 1;
                break;
            }
        }

    }
    if(directed==1){
        cout<<"Directed Graph"<<endl;
    }
    else{
        cout<<"Undirected Graph"<<endl;
    }
    return 0;
}
/*
4
0 7 5 1
7 0 4 6
5 4 0 10
1 6 10 0

*/

