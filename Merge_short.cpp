#include<bits/stdc++.h>
using namespace std;
void conquer(int a[],int l,int m,int h){
    int nL = m-l+1;
    int nR = h - m;

    int Left[nL+1],Right[nR+1];
    for(int i=0;i<=nL;i++){
        Left[i] = a[l+i];
    }
    for(int i=0;i<=nR;i++){
        Right[i] = a[m+1+i];
    }
    Left[nL] = Right[nR] = INT_MAX;
    int i=0,j=0,k;
    for(k=l;k<=h;k++){
        if(Left[i]<=Right[j]){
            a[k] = Left[i];
            i++;
        }
        else{
            a[k] = Right[j];
            j++;
        }
    }
}
void mergeSort(int a[],int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        conquer(a,low,mid,high);
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
    mergeSort(a,0,5);
    cout<<"-------After swap-------"<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

