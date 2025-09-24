#include<iostream>
using namespace std;

// Shell Sort
void shellSort(int arr[], int n){

    for(int gap=n/2; gap>=1; gap=gap/2){

        for(int j=gap; j<n; j++){

            for(int i=j-gap; i>=0; i=i-gap){

                if(arr[i]>arr[i+gap]){
                    swap(arr[i], arr[i+gap]);
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

// Quick Sort

int findPivot(int arr[], int st, int end){

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
        int pivot = findPivot(arr,st,end);
        quickSort(arr, st, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

int main(){
    int arr[] = {2,4,3,1,5,6};

    quickSort(arr, 0, 5);
    for(int i=0; i<=5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}