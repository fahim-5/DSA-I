#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[],int n){
    int cnt=0,flag;
    for(int j=0;j<n;j++){
        flag = 0;
        for(int i=0;i<n-1-j;i++){
            cnt++;
            if(a[i]>a[i+1]){
                flag = 1;
                swap(a[i],a[i+1]);
            }
        }
        if(flag==0)break;
    }
    cout<<cnt<<endl;
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
    bubbleSort(a,6);
    cout<<"-------After swap-------"<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
