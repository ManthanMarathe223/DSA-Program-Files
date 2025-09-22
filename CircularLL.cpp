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
        head=tail=nullptr;
    }

    void push_front(){
        int num;

        cout << "\n Enter Data: ";
        cin >> num;

        Node *newNode = new Node(num);

        if(head==NULL){
            head=tail=newNode;
            newNode->next = head;
        }
        else{
            newNode->next=head;
            head = newNode;
            tail->next=head;
        }

        printLL();
    }

    void pop_front(){

        if(head==NULL){
            cout << "List is Empty";
        }
        else if(head==tail){
            Node *temp = head;
            head = tail = nullptr;
            delete temp;
        }
        else{
            Node *temp = head;
            head = temp->next;
            tail->next = head;
            delete temp;
        }

        printLL();
    }

    void push_back(){

        int num;
        cout << "Enter Data: ";
        cin >> num;

        if(head==NULL){
            Node *newNode = new Node(num);
            head = tail = newNode;
            tail->next=head;
        }
        else{
            Node *newNode = new Node(num);

            newNode->next=tail->next;
            tail->next=newNode;
            tail=newNode;
        }

        printLL();
    }

    void pop_back(){

        if(head==NULL){
            cout << "List is Empty..!!";
        }
        else if(head==tail){
            Node *temp = head;
            head = tail = nullptr;
            delete temp;
        }
        else{
            Node *temp = head;

            while(temp->next->next != head){
                temp = temp->next;
            }

            Node *delNode = temp->next;
            temp->next=head;
            tail=temp;
            delete delNode;
        }

        printLL();
    }

    void insert(){

        int pos;
        int data;

        cout << "\nEnter Position to Insert at: ";
        cin >> pos;

        cout << "\nEnter Data: ";
        cin >> data;

        if(pos<0){
            cout << "Invalid Position..!!";
            return;
        }

        Node *t = head;
        int cnt=0;

        do{
            cnt++;
            t=t->next;
        }while(t!=head);

        if(pos == cnt || pos > cnt){
            push_back();
            return;
        }

        if(pos == 0){
            push_front();
            return;
        }

        t = head;

        for(int i=0; i<pos-1; i++){
            t=t->next;
        }

        Node *newNode = new Node(data);
        newNode->next = t->next;
        t->next = newNode;

        printLL();
    }

    int searchLL(){

        int val;

        cout << "Enter value to be Searched: ";
        cin >> val;

        if(head==NULL){
            cout << "Link is Empty...!!!";
            return -1;
        }

        Node *t = head;
        int idx=0;

        do{
            if(t->data == val) return idx;
            idx++;
            t=t->next;
        }while(t!=head);

        return -1;
    }

    void printLL(){

        if(head==NULL){
            cout << "List is Empty..!!";
        }
        else{
            Node *temp = head;

            do{
                cout << temp->data << " ";
                temp=temp->next;
            }while(temp!=head);
        }
    }
};

int main(){

    int input;
    List ll;
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