#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using namespace std;

struct Emp {
    string name;
    int id;
    string position;
    Emp* next;
};

Emp* head = nullptr;
stack<string> stk;

Emp* createNode(string name, int id, string position) {
    Emp* newNode = new Emp;
    newNode->name = name;
    newNode->id = id;
    newNode->position = position;
    newNode->next = nullptr;
    return newNode;
}

void printEmployeeList(Emp* head) {
    cout << "Employee List:" << endl;
    int count = 1;
    Emp* temp = head;
    while (temp != nullptr) {
        cout << "Employee " << count++ << ":\n";
        cout << "Name: " << temp->name << endl;
        cout << "ID: " << temp->id << endl;
        cout << "Position: " << temp->position << endl;
        cout << endl;
        temp = temp->next;
    }
}

int Check_Consecutive(const string& name1, const string& name2) {
    Emp* temp = head;
    bool foundName1 = false;

    while (temp != nullptr && temp->next != nullptr) {
        if (temp->name == name1) {
            foundName1 = true;
            if (temp->next->name == name2) {
                stk.push(name1);
                stk.push(name2);
                return 1;
            }
        } else {
            foundName1 = false;
        }
        temp = temp->next;
    }

    return 0;
}


void printStack() {
    while (!stk.empty()) {
        std::cout << stk.top();
        stk.pop();
        if (!stk.empty()) {
            std::cout << ", ";
        }
    }
    
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string name;
        int id;
        string position;

        cout << "Enter information of Employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, name); 
        cout << "ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Position: ";
        getline(cin, position); 

       
        if (head == nullptr) {
            head = createNode(name, id, position);
        } else {
            Emp* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = createNode(name, id, position);
        }
    }


    int m;
    cout << "Enter the number of names to search for: ";
    cin >> m;
    cin.ignore(); 

    string* names = new string[m];

    cout << "Enter the names to search for:" << endl;
    for (int i = 0; i < m; ++i) {
        getline(cin, names[i]); 
    } 

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            count += Check_Consecutive(names[i], names[j]);
            count += Check_Consecutive(names[j], names[i]);
        }
    }

    cout << count << " [";
     printStack();
    cout << "]" << endl;

    delete[] names;

    return 0;
}


/*

Rana, 11023, Software-Tester
Salman, 12045, Designer
Jacob, 21055, FrontEnd-Developer
Rasel, 22134, BackEnd-Developer

[Rana, Jacob, Rasel]


*/
