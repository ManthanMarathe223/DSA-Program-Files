/*Implement a job scheduling system for a manufacturing plant using a double-ended queue. The
system needs to efficiently manage the processing of jobs on various machines throughout the
plant. Each job has a Job_priority.
The system should support the following operations:
a. Add Job
b. Remove Job
c. Display Job
d. Search Job*/

#include<iostream>
using namespace std;
#define SIZE 10

struct Job
{
    string name;
    int priority;
};

class Dequeue{

    Job jobs[SIZE];
    int front, rear;

public:
    Dequeue(){
        front = rear = -1;
    }

    bool isFull(){
        return ((front == 0 && rear == SIZE -1) || (rear+1 == front));
    }

    bool isEmpty(){
        return (front == -1);
    }

    void addJob(){

        if(isFull()){
            cout << "Queue is Full ...!!";
            return;
        }

        Job j;

        cout << "Enter Job Name: ";
        cin >> j.name;

        cout << "Enter Job Priority: ";
        cin >> j.priority;

        if(front == -1){
            rear = front = 0;
            jobs[front] = j;
            cout << "Job Added \n";
            return;
        }

        if(j.priority > 5){
            
            front = (front - 1 + SIZE) % SIZE;
            jobs[front] = j;
        }
        else{
            
            rear = (rear + 1) % SIZE;
            jobs[rear] = j;
        }

        cout << "Job Added \n";
    }

    void removeJob(){

        if(isEmpty()){
            cout << "Queue is Empty..!!";
            return;
        }

        if(front == rear){
            front = rear = -1;
        }
        else if(front == SIZE-1){
            front = 0;
        }
        else{
            front++;
        }
    }

    void display(){

        if(isEmpty()){
            cout << "Queue is Empty..!!";
            return;
        }

        cout << "Current Jobs: \n";

        int i = front;

        while(true){
            cout << "Job: " << jobs[i].name << " Priority: " << jobs[i].priority << endl;
            if(i == rear) break;
            i = (i+1) % SIZE;
        }

        cout << endl;
    }

    void searchJob(){

        if(isEmpty()){
            cout << "Queue is Empty..!!";
            return;
        }

        string name;
        cout << "Enter name to search: ";
        cin >> name;

        int i = front;

        while(true){

            if(jobs[i].name == name){
                cout << "Found Job: " << jobs[i].name << " (Priority: " << jobs[i].priority << ")" << endl;
                return;
            }

            if(i==rear) break;

            i = (i+1) % SIZE;
        }

        cout << "Job not Found..!!\n";
    }
};

int main(){

    Dequeue d;
    int n;

    do{

        cout << "1. Add Job 2. Remove Job 3. Search Job 4. Display 0. Exit\n";
        cout << "Enter your choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            d.addJob();
            break;

        case 2:
            d.removeJob();
            break;

        case 3:
            d.searchJob();
            break;

        case 4:
            d.display();
            break;
    
        case 0:
            cout << "Exiting...";
            break;
        
        default:
            cout << "Invalid Choice..!!";
            break;
        }

    }while(n != 0);

    return 0;
}