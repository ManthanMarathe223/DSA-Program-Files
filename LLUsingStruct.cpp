#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *next;

    Node(int val): data(val), next(nullptr){};
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

        cout << "\nEnter Data: ";
        cin >> data;

        Node *newNode = new Node(data);

        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }

        printLL();
    }

    void printLL(){

        if(head == nullptr){
            cout << "List is Empty..!!!";
        }
        else{
            Node *temp = head;

            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
};

int main(){

    List ll;

    ll.push_front();
    ll.push_front();

    return 0;
}