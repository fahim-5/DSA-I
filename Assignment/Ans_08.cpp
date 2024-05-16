#include <iostream>
#include <string>

using namespace std;

struct Emp
{
    string name;
    int id;
    int workHour;
    Emp *next;
};

Emp *head = nullptr;

void push(Emp *&head, string name, int id, int workHour)
{
    Emp *newNode = new Emp;
    newNode->name = name;
    newNode->id = id;
    newNode->workHour = workHour;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}


void print_One(Emp *tmp)
{
    Emp *temp = tmp;
    cout << "Name: " << temp->name << ", ID: " << temp->id << ", Work Hour: " << temp->workHour << endl;
}

void pop()
{
    if (head == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    Emp *temp = head;
    head = head->next;

    print_One(temp);

    
    delete temp;
}




void print_the_lazy_One(Emp *tmp)
{
    Emp *temp = tmp;
    cout<<"Information of the employee who work less then any other : "<<endl;
    cout << "Name: " << temp->name << ", ID: " << temp->id << ", Work Hour: " << temp->workHour << endl;
}

void top()
{
    if (head == nullptr)
    {
        cout << "Stack is empty." << endl;
    }
    print_One(head);
}

void getMin()
{
    if (head == nullptr)
    {
        cout << "Stack is empty" << endl;
    }

    Emp *target = head;
    Emp *current = head->next;

    while (current != nullptr)
    {
        if (current->workHour < target->workHour)
        {
            target = current;
        }
        current = current->next;
    }

    print_the_lazy_One(target);
}


int main()
{
    int N;
    cout << "Enter the number of Employees: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string name;
        int id;
        int workHour;
        cout << "Enter the name of the " << i + 1 << " Employee: ";
        cin >> name;
        cout << "Enter the ID of the " << i + 1 << " Employee: ";
        cin >> id;
        cout << "Enter the work hour of the " << i + 1 << " Employee: ";
        cin >> workHour;

        push(head, name, id, workHour);
    }

    getMin();

    top();
    pop();

    getMin();

    return 0;
}
