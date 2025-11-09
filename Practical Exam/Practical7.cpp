/*Implement a browser history management system using a stack data structure to track the user's
browsing history. The system should support the following functionalities:
a. Add visited page
b. Navigate back
c. View current page
d. Check if history is empty or not
Assume no upper bound on number of pages visited*/

#include<iostream>
using namespace std;

struct Node{
    string data;
    Node *next;
};

struct Node *newNode, *temp, *top =0;

void addPages(){

    int num;

    cout << "Enter Number of Pages: ";
    cin >> num;

    for (int i=0; i<num; i++){
        newNode = new Node;

        cout << "\nEnter Page Name: ";
        cin >> newNode->data;

        newNode->next = top;
        top = newNode;
    }

    cout << "Pages Added to History..!!";
}

void NavigateBack() {
    if (top == 0)
        cout << "No previous page!\n";
    else {
        temp = top;
        top = top->next;
        delete temp;
        cout << "Went back successfully!\n";
    }
}

void viewCurrent(){

    if(top == 0){
        cout << "History is Empty..!!";
        return;
    }

    cout << "Current Page: " << top->data << endl;
}

void checkHistory(){

    if(top == 0){
        cout << "History is Empty..!!";
    }
    else{
        cout << "History is NOT empty";
    }

}

int main(){

    int n;

    do{
        cout << "\n 1. Add Visited Pages 2. Navigate Back 3. View Current Page 4. Check if History is Empty/Not 5.Exit \n";
        cin >> n;

        switch (n)
        {
        case 1:
            addPages();
            break;

        case 2:
            NavigateBack();
            break;

        case 3:
            viewCurrent();
            break;

        case 4:
            checkHistory();
            break;

        case 5:
            cout << "Exiting...\n";
            break;
        
        default:
            cout << "Invalid Choice...!!";
            break;
        }
    }while(n != 5);

    return 0;
}