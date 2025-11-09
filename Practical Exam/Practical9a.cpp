/*a. Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist
provide following facility:
a. Add Party to Waitlist
b. Seat Party
c. Display Waitlist*/

#include<iostream>
using namespace std;

class Node{
public:

    string name;
    Node *next;

    Node(string p){
        name = p;
        next = nullptr;
    }
};

class PartyWaitList{

    Node *front, *rear;

public: 

    PartyWaitList(){
        front = rear = nullptr;
    }

    void addParty(){

        string nm;

        cout << "\n Enter Party Name: \n";
        cin >> nm;

        Node *newNode = new Node(nm);

        if(front == NULL){
            front = rear = newNode;
            return;
        }

        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;

        cout << "\n Party added to WaitList...!! \n";
    }

    void seatParty(){

        if(front == NULL){
            cout << "\n List is empty..!! \n";
            return ;
        }

        Node *temp = front;
        front = front->next;

        cout << "\n Seating Party: " << temp->name << endl;

        delete temp;
    }

    void display(){

        if(front == NULL){
            cout << "\n List is empty..!! \n";
            return ;
        }

        Node *temp = front; 

        while(temp){
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main(){

    PartyWaitList l;
    int n;

    do{

        cout << "\n 1. Add Party 2. Seat Party 3. Display Party 0. Exit \n";
        cout << "Enter your choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            l.addParty();
            break;

        case 2:
            l.seatParty();
            break;

        case 3:
            l.display();
            break;

        case 0:
            cout << "Exiting ....";
            break;
        
        default:
            break;
        }

    }while(n != 0);

    return 0;
}