#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[],int n,int item){
    int LB = 0, UB = n-1,mid;
    while(LB<=UB){
        mid = (LB+UB)/2;
        if(a[mid]==item){
            return mid;
        }
        else if(a[mid]<item){
            LB = mid+1;
        }
        else{
            UB = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {2,4,5,7,9,10,11,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item;
    cin>>item;
    int res = binarySearch(arr,n,item);
    if(res!=-1){
        cout<<item<<" is found at index "<<res<<endl;
    }
    else{
        cout<<item<<" is not found"<<endl;
    }
    return 0;
}
