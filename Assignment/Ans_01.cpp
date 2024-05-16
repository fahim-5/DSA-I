#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *head = NULL;
int *arr;
int size;


void insertAtFirst(int v)
{
    Node *t = new Node;
    t->val = v;
    t->next = NULL;


    if (head == NULL)
    {
        head = t;
        return;
    }
    t->next = head;
    head = t;
}


void insertAtLast(int v)
{

    Node *t = new Node;
    t->val = v;
    t->next = NULL;


    if (head == NULL)
    {
        insertAtFirst(v);
        return;
    }

    
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = t;
}


void insertAt_kth_index(int v, int indx)
{
    if (head == NULL || indx <= 1)
    {
        insertAtFirst(v);
        return;
    }


    Node *t = new Node;
    t->val = v;
    t->next = NULL;



    int cnt = 0;
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        cnt++;
        if (cnt + 1 == indx)
            break;
        ptr = ptr->next;
    }
    t->next = ptr->next;
    ptr->next = t;
}


void insertAtMiddle(int v)
{

    int count = 0;
    Node *ptr = head;
    while (ptr != nullptr)
    {
        count++;
        ptr = ptr->next;
    }

    int mid = (count) / 2;

    insertAt_kth_index(v, mid+1);
}


void addArrayToEnd(int array)
{
    int size = sizeof(array) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        insertAtLast(arr[i]);
    }
}

int deleteFrom_kth_index(int indx)
{
    int cnt = 0;
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        cnt++;
        if (cnt + 1 == indx)
            break;
        ptr = ptr->next;
    }
    Node *tmp = ptr->next;
    ptr->next = tmp->next;

    int item = tmp->val;
    delete tmp;
    return item;
}

void replaceLastWithSum()
{
    if (head == nullptr)
    {
        return;
    }

    int sum = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        sum += temp->val;
        temp = temp->next;
    }

    temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->val = sum;
}


void searchEvenNumber(int *&arr, int &size) {
    int sz = 0;
    Node *ptr = head;

    while (ptr != nullptr) {
        if (ptr->val % 2 == 0) {
            sz++;
        }
        ptr = ptr->next;
    }

    arr = new int[sz];
    ptr = head;
    int index = 0;
    while (ptr != nullptr) {
        if (ptr->val % 2 == 0) {
            arr[index++] = ptr->val;
        }
        ptr = ptr->next;
    }
    size = sz;
}

void printList()
{
    if (head == NULL)
    {
        cout << "There is no element" << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);
    
    searchEvenNumber(arr, size); 

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    printList();

    delete[] arr; 

    return 0;
}