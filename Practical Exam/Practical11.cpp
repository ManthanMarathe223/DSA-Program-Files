/*Consider an employee database of N employees. Make use of a hash table implementation to
quickly look up the employer's id number.*/

#include<iostream>
using namespace std;
#define SIZE 10

struct Empolyee
{
    int id;
    string name;
};

Empolyee table[SIZE];

int hashFunction(int id){
    return id % SIZE;
}

void insertData(){

    Empolyee e;

    cout << "Enter ID: ";
    cin >> e.id;

    cout << "Enter Name: ";
    cin >> e.name;

    int index = hashFunction(e.id);

    while(table[index].id != 0){
        index = (index+1)%SIZE;
    }

    table[index] = e;

    cout << "Employee inserted\n";
}

void searchData(){
    
    int num;

    cout << "Enter ID to search: ";
    cin >> num;

    int index = hashFunction(num);

    for (int i=0; i<SIZE; i++){

        if(table[index].id == num){
            cout << "Employee Found: " << table[index].name << endl;
            return;
        }

        index = (index+1) % SIZE;
    }

    cout << "Employee NOT found";
}

int main(){

    for (int i=0; i<SIZE; i++){
        table[i].id = 0;
    }

    int n;

    do{
        cout << "\n 1. Add EMP 2. Search EMP 0. Exit \n";
        cout << "Enter your choice: ";
        cin >> n;

        if(n == 1) insertData();
        else if(n == 2) searchData();
        else cout << "Invalid Choice..!!";

    }while(n != 0);
}