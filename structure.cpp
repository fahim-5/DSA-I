#include<bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int ID;
    float cgpa;
};
void increaseCGPA(Student *t){
    if(t->cgpa>3.5){
        t->cgpa += t->cgpa*0.01;
    }
}
int main(){
    /*Student alvi;
    cin>>alvi.name>>alvi.ID>>alvi.cgpa;
    cout<<"Name: "<<alvi.name<<endl;
    cout<<"ID: "<<alvi.ID<<endl;
    cout<<"CGPA: "<<alvi.cgpa<<endl;*/
    Student s[3],tmp;
    for(int i=0;i<3;i++){
        cout<<"Student #"<<i+1<<endl;
        cin>>tmp.name>>tmp.ID>>tmp.cgpa;
        s[i] = tmp;
    }
    increaseCGPA(&s[0]);
    for(int i=0;i<3;i++){
        cout<<"Student #"<<i+1<<"INFO"<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"ID: "<<s[i].ID<<endl;
        cout<<"CGPA: "<<s[i].cgpa<<endl;
    }
    return 0;
}
