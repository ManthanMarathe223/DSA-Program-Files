#include<iostream>
using namespace std;

int pivotValue(int arr[], int st, int end){

    int idx = st-1;
    int pivot = arr[end];

    for(int j=st; j<end; j++){
    
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);

    return idx;
}

void quickSort(int arr[], int st, int end){

    if(st<end){
        int piv = pivotValue(arr, st, end);
        quickSort(arr, st, piv-1);
        quickSort(arr,piv+1,end);
    }
}

int main(){

    int arr[] = {3,2,4,1,3};
    quickSort(arr, 0, 4);

    for (int val: arr){
        cout << val << " ";
    }

    return 0;
}