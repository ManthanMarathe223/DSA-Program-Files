/*b. Implement a checkout system for a supermarket to efficiently manage customer queues during
peak hours. The system should support the following operations using a circular queue data
structure:
a. Customer arrival
b. Customer checkout
c. Close Checkout Counter
d. View customer*/

#include<iostream>
using namespace std;
#define SIZE 5

class CircularQueue{
    string customers[SIZE];
    int front, rear;

public:

    CircularQueue(){
        front = rear = -1;
    }

    bool isFull(){
        return (front == 0 && rear == SIZE-1) || (rear + 1 == front);
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    void arrival(){

        if(isFull()){
            cout << "Queue is Full..!!!";
            return;
        }

        string n;
        cout << "Enter Customer's Name: ";
        cin >> n;

        if(isEmpty()) front = 0;
        rear = (rear+1) % SIZE;
        customers[rear] = n;
        cout << n << " Arrived\n";
    }

    void checkout(){

        if(isEmpty()){
            cout << "No Customer Waiting ...!!";
            return;
        }

        if(front == rear){
            cout << customers[front] << " Checkout";
            front = rear = -1;
        }
        else{
            cout << customers[front] << " Checkout";
            front = (front+1) % SIZE;
        }

    }

    void closeCounter(){

        front = rear = -1;
        cout << "Counter closed. Queue cleared\n";
    }
    
    void view(){

        if(isEmpty()){
            cout << "No Customer Waiting ...!!";
            return;
        }

        int i = front;

        cout << "Customers in Queue: \n";
        while(true){

            cout << customers[i] << endl;
            if(i == rear) break;
            i = (i+1) % SIZE;
        }
    }

};

int main(){

    CircularQueue c;

    int ch;

    do{

        cout << "\n 1. Arrival 2. Checkout 3. Close Counter 4. View 0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            c.arrival();
            break;

        case 2:
            c.checkout();
            break;

        case 3:
            c.closeCounter();
            break;

        case 4:
            c.view();
            break;

        case 0:
            cout << "Exiting  ....";
            break;
        
        default:
            cout << "Invalid Choice..!!";
            break;
        }   

    }while(ch != 0);

    return 0;
}