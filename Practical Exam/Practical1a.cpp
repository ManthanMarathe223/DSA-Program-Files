/*Consider a student database of SY COMP class (at least 15 records). Database contains different
fields of every student like Roll No, Name and SGPA.
a. Design a roll call list, arrange list of students according to roll numbers in ascending order
using Insertion Sort*/

#include<iostream>
using namespace std;

struct stud{
    int rollno;
    string name;
    float sgpa;
}s[15];

void display(){

    for(int i=1; i<=5; i++){
        cout << "Roll No. " << s[i].rollno << " Name: " << s[i].name << " SGPA: " << s[i].sgpa << endl;
    }
}

void SortRollNo(){

    for(int i=1; i<=5; i++){
        stud temp = s[i];
        int j = i-1;

        while(j >= 0 && s[j].rollno > temp.rollno){
            s[j+1] = s[j];
            j--;
        }

        s[j+1] = temp;
    }

    display();
}

void takeInput(){

    for(int i=1; i<=5; i++){
        cout << "Enter Student Roll NO. " << i << ": " ;
        cin >> s[i].rollno ;

        cout << "Enter Student Name " << i << ": " ;
        cin >> s[i].name ;

        cout << "Enter Student SBPA " << i << ": " ;
        cin >> s[i].sgpa ;
    }

    SortRollNo();
}

int main(){

    takeInput();

    return 0;
}