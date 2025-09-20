#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    int data ;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List{

    Node *head;
    Node *tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(){

        int val;

        cout << "Enter Numeric Data: ";
        cin >> val;

        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }

        printLL();
    }

    void push_back(){

        int val;

        cout << "Enter Numeric Data: ";
        cin >> val;

        Node *newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

        printLL();
    }

    void pop_front(){

        if(head == NULL){
            cout << "Nothing to be Deleted..!! \n";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        printLL();
    }

    void pop_back(){

        if(head == NULL){
            cout << "Nothing to be Deleted..!! \n";
            return;
        }

        Node *temp = head;

        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;

        printLL();
    }

    void insert(){

        int val, pos;

        cout << "Enter Numeric Data: ";
        cin >> val ;
        cout << endl;

        cout << "Enter Numeric Position: ";
        cin >> pos;
        cout << endl;

        if(pos<0){
            cout << "Invalid Position";
            return;
        }

        Node *t = head;
        int len = 0;

        while(t){
            len++;
            t = t->next ;
        }

        if(pos>len || pos == len){
            cout << "Inserted at last..\n";
            push_back();
        }
       
        if(pos == 0){
            push_front();
        }

        Node *temp = head;

        for(int i=0; i<pos-1; i++){
            temp = temp->next ;
        }

        Node *newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        printLL();
    }

    int searchLL(){

        int v;

        cout << "\nEnter Value to be Searched: ";
        cin >> v;

        if(head == NULL){
            cout << "LL is empty..!\n";
            return -1;
        }

        Node *temp = head;
        int idx = 0;

        while(temp != NULL){

            if(temp->data == v) return idx;

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    void printLL(){

       if(head == NULL){
        cout << "List Empty..!!!";
       }
       else{
         Node *temp = head;

         cout << "\n------------Your List------------\n\n";

         while(temp != NULL){

            cout << temp->data << "->";
            temp = temp->next;

        }

        cout << "NULL" <<endl;
        cout << "\n------------Your List------------\n\n";

       }
    }
};

int main(){

    List ll;
    int input ;
    int i;

    do{
        cout << "\n---------------------------------------------Linked List Operations Started--------------------------------------------\n\n";
        cout << "Choices -> \n\n\t 1.Push Front \t 2.Push Back \t 3.Insert \t 4.Pop Front \t 5.Pop Back \t 6.Search \t 0.Exit\n\n";
        cout << "Enter Your Choice: ";
        cin >> input;

        switch(input){

            case 1:
            ll.push_front();
            break;

            case 2:
            ll.push_back();
            break;

            case 3: 
            ll.insert();
            break;

            case 4:
            ll.pop_front();
            break;

            case 5:
            ll.pop_back();
            break;

            case 6: 
            i = ll.searchLL();
            cout << "Value is at Index: " << i << endl;
            break;

            case 0:
            cout << "\n\n--------------------------------------------------Operations Ended--------------------------------------------------------------------\n";
            exit(0);

            default:
            cout <<"\n\n\t\t<><><><><><>\tInvalid Input...!!!!\t<><><><><><>";
            cout << "\n\n--------------------------------------------------Operations Ended---------------------------------------------------------------------\n";
            break;
        }

    }while(input != 0);

    return 0;
}