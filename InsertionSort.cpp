#include<iostream>
using namespace std;

void insertionSort(int a[]){

    int n = 5;

    for (int i=1; i<n; i++){

        int curr = a[i];
        int prev = i-1;

        while(prev >=0 && a[prev] > curr){
            a[prev+1] = a[prev];
            prev--;
        }

        a[prev+1] = curr;
    }

    cout << "Sorted Array : \n";

    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

int main(){

    int arr[] = {4,1,5,2,3};

    insertionSort(arr);
}