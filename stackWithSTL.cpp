#include<bits/stdc++.h>
using namespace std;

int main(){

    vector <int> stck;
    /*
        1.push_back()
        2.pop_back();
        3. size()
        4. back();
        5. empty();
    */
    stck.push_back(10);
    stck.push_back(15);
    stck.push_back(7);
    for(int i=0;i<stck.size();i++){
        cout<<stck[i]<<" ";
    }
    cout<<endl;
    cout<<stck.back()<<endl;
    stck.pop_back();
    for(int a:stck){
        cout<<a<<" ";
    }

    return 0;
}
