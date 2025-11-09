/*Implement a simple text editor application using a doubly linked list to manage the text buffer.
Text editor should support the following functionalities:
a. Insert text
b. Delete text
c. Display text
d. Search text
e. Print text in reverse*/

#include<iostream>
using namespace std;

class Node{
public:
    string text;
    Node *next;
    Node *prev;

    Node(string s){
        text = s;
        next = prev = nullptr;
    }
};

class TextEditor{
    Node *head;
    Node *tail;

public:

    TextEditor(){
        head = tail = nullptr;
    }

    void insertText(){
        string t;

        cout << "Enter Text: ";
        cin.ignore();
        getline(cin, t);

        Node *newNode = new Node(t);

        if(!head){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Inserted\n";
    }

    void displayText(){

        if(!head){
            cout << "Buffer is empty..!!\n";
            return;
        }

        Node *temp = head;

        cout << "Text: \n";

        while(temp){
            cout << temp->text << endl;
            temp = temp->next;
        }
    }

    void printReverse(){

        if(!head){
            cout << "Buffer is empty..!!\n";
            return;
        }

        Node *temp = tail;

        cout << "Reverse List: \n";

        while (temp)
        {
            cout << temp->text << endl;
            temp = temp->prev;
        }
        
    }

    void deleteText(){

        if(!tail){
            cout << "List is Empty..!!";
            return;
        }

        Node *temp = tail;

        tail = tail->prev;

        if(tail) tail->next = nullptr;
        else head = nullptr;

        delete temp;
    }

    void searchText(){

        if(!head){
            cout << "Buffer is Empty..!!!\n";
            return;
        }

        Node *temp = head;
        string t;

        cout << "Enter Text to be Searched: ";
        cin.ignore();
        getline(cin, t);

        while(temp){

            if(temp->text.find(t) != -1){
                cout << "Found on line: " << temp->text << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Text not Found..!!\n";
    }
};

int main(){

    int ch;
    TextEditor t;

    do{

        cout << "\n1.Insert  2.Delete  3.Display  4.Search  5.Reverse  0.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            t.insertText();
            break;

        case 2:
            t.deleteText();
            break;

        case 3:
            t.displayText();
            break;

        case 4:
            t.searchText();
            break;

        case 5:
            t.printReverse();
            break;

        case 0:
            cout << "Exiting..!!\n";
            break;
        
        default:
            cout << "Invalid..\n";
            break;
        }

    }while(ch != 0);

    return 0;
}