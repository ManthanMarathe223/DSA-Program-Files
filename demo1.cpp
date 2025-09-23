#include<iostream>
using namespace std;

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

int main(){
    int arr[] = {2,4,3,1,5,6};

    shellSort(arr,6);

    return 0;
}