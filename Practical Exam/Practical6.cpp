/*Consider two polynomial expressions of any degree. Design solution to perform addition of these
two polynomials with suitable data structure and display results*/

#include<iostream>
using namespace std;

struct Node{
    float coeff;
    int exp;
    Node *next;
};

Node *insert(struct Node *head, float coeff, int exp){

    struct Node *temp;
    struct Node *newNode = new Node;

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = nullptr;

    if(!head || exp > head->exp){
        newNode->next = head;
        head = newNode;
    }
    else{
        temp = head;

        while(temp->next != NULL && temp->next->exp >= exp){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node *create(struct Node *head){

    int num;
    float coeff;
    int exp;

    cout << "Enter the Number of Terms: ";
    cin >> num;

    for(int i=1; i<=num; i++){

        cout << "Enter the Coefficient for the Term " << i << ": ";
        cin >> coeff;

        cout << "Enter the Exponent for the Term " << i << ": ";
        cin >> exp;

        head = insert(head, coeff, exp);
    }

    return head;
}

void print(struct Node *head){

    if(!head){
        cout << "No Polynomial Found..!!";
        return;
    }

    struct Node *temp = head;

    while(temp){
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;

        if(temp){
            cout << " + ";
        }
        else{
            cout << endl;
        }
    }
}

void polyAdd(struct Node *head1, struct Node *head2){

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    struct Node *head3 = nullptr;

    while(ptr1 && ptr2){

        if(ptr1->exp == ptr2->exp){
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp){
            head3 = insert(head3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else{
            head3 = insert(head3, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }

    while (ptr2)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    cout << "\n Added Polynomials: ";
    print(head3);
}

int main(){

    Node *head1 = nullptr;
    Node *head2 = nullptr;

    cout << "Enter 1st Polynomial: " << endl;
    head1 = create(head1);

    cout << "Enter 2nd Polynomial: " << endl;
    head2 = create(head2);

    polyAdd(head1, head2);

    return 0;
}