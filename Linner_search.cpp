#include<bits/stdc++.h>
using namespace std;
int linearSearch(int a[],int n,int item){
    for(int i=0;i<n;i++){
        if(a[i]==item){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {10,5,7,11,15,2,9,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item;
    cout<<"Enter your search item:"<<endl;
    cin>>item;
    int res = linearSearch(arr,n,item);
    if(res!=-1){
        cout<<item<<" is found at index "<<res<<endl;
    }
    else{
        cout<<item<<" is not found"<<endl;
    }
}
