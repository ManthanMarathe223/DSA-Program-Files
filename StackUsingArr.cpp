#include<iostream>
using namespace std;

#define SIZE 20

class Stack{
    int arr[SIZE];
    int top;

public: 
    Stack(){
        top = -1;
    }

    void push(int x){

        if(top == SIZE-1){
            cout << "Stack Overflow..!!";
            return;
        }

        arr[++top] = x;
        cout << x << "Added to Stack" << endl;
    }

    void pop(){

        if(top == -1){
            cout << "Stack UnderFlow..!!";
            return;
        }

        cout << arr[top--] << " Popped..!!" << endl;
    }

    int peek(){
        if(top == -1){
            cout << "Stack is Empty..!!";
            return -1;
        }
        return arr[top];
    }

    void display(){

        if(top == -1){
            cout << "Stack is Empty..!!";
            return;
        }
        cout << "Stack: ";
        for(int i=0; i<=top; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    cout << "Top element: " << s.peek() << "\n";

    s.pop();
    s.display();

    return 0;
}