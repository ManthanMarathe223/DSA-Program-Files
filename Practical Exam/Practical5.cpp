/*Implement a navigation system for a delivery service using a circular linked list to represent
routes. The navigation system should support the following functionalities:
a. Add route
b. Remove route
c. Display route*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int n){
        data = n;
        next = nullptr;
    }
};

class List {

    Node *head;

public:

    List(){
        head = nullptr;
    }

    void addRoute(){
        int num;

        cout << "Enter Data: ";
        cin >> num;

        Node *newNode = new Node(num);

        if(!head){
            head = newNode;
            newNode->next = head;
        }
        else{
            Node *temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;            
        }

        cout << "Added: " << num << endl;
    }

    void removeRoute(){

        if(!head){
            cout << "List is Empty..!!";
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;
        int n;

        cout << "Enter node Data to Delete: ";
        cin >> n;

        do{
            if(temp->data == n) break;
            prev = temp;
            temp = temp->next;
        }while(temp != head);

        if(temp->data != n){
            cout << "Route not Found...!!!";
            return;
        }

        if(temp->next == temp){
            head = nullptr;
        }
        else if(temp == head){
            Node *last = head;

            while(last->next != head) last = last->next;

            head = head->next;
            last->next = head;

        }
        else{
            prev->next = temp->next;
        }

        delete temp;
        cout << "Removed: " << n << endl;
    }

    void displayRoute(){

        if(!head){
            cout << "List is Empty..!!!";
            return;
        }

        Node *temp = head;
        cout << "List Data: \n" ;

        do{
            cout << temp->data << endl;
            temp = temp->next;
        }while(temp != head);
    }
};


int main(){

    List l;
    int ch;

    do{

        cout << "\n\t 1.Add Route \t 2. Remove Route \t 3. Display Route \t 0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            l.addRoute();
            break;

        case 2: 
            l.removeRoute();
            break;

        case 3: 
            l.displayRoute();
            break;

        case 0:
            cout << "Exiting...";
            break;
        
        default:
            cout << "Invalid choice..!!!";
            break;
        }
        
    }while(ch != 0);

    return 0;
}