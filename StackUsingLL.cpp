#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{

    Node *top;

public: 

    Stack(){
        top = nullptr;
    }

    void push(int x){
        Node *newNode = new Node();

        if(!newNode){
            cout << "Heap Overflow..!!" << endl;
            return;
        }

        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " Pushed in Stack..!!" << endl;
    }

    void pop(){

        if(top == nullptr){
            cout << "Stack UnderFlow,,!!" << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        cout << temp->data << " Popped!!" << endl;
        delete temp;
    }

    int peek(){

        if(top == NULL){
            cout << "Stack UnderFlow..!!" << endl;
            return -1;
        }

        return top->data;
    }

    void display(){

        if(top == NULL){
            cout << "Stack UnderFlow..!!" << endl;
            return;
        }

        Node *temp = top;

        cout << "Stack: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();
    s.display();

    cout << "Top Element: " << s.peek() << endl;

    return 0;
}