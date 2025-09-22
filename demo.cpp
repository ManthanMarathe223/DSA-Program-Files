#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int v){
        data = v;
        next = nullptr;
    }
};

class List{

    Node *head;
    Node *tail;

public:

    List(){
        head = tail = nullptr;
    }

    void push_front(){

        int data;
        cout << "\n Enter Data: ";
        cin >> data;

        Node *newNode = new Node(data);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }

        printLL();
    }

    void printLL(){

        if(head==NULL){
            cout << "LL is empty..!!";
        }
        else{

            Node *temp = head;

            while(temp!=NULL){
                cout<< temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){

    int n;
    List l;

    
    do{
        cout << "\t 1.Push Front \t " << endl;
        cout << "Enter your Choice: ";
        cin >> n;

        switch(n){
            
            case 1: 
            l.push_front();
            break;

            default:
            cout << "Invalid Choice..!!";

        }
    } while(n != 0);

    return 0;
}