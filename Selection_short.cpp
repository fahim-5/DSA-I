#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int minIDX = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minIDX]){
                minIDX = j;
            }
        }
        swap(a[i],a[minIDX]);
    }
}
int main(){
    int a[10];
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    cout<<"-------Before swap-------"<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    selectionSort(a,6);
    cout<<"-------After swap-------"<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

