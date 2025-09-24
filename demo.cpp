#include<iostream>
#include<vector>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n){

    for (int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

// Merge Sort
void merge(int arr[], int low, int mid, int high){

    int left = low;
    int right = mid+1;

    vector<int> temp;

    while(left<=mid && right<=high){

        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high){

    if(low == high) return;

    int mid = (low+high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int arr[] = {2,4,3,1,5,6};

    mergeSort(arr, 0, 5);

    for(int val: arr){
        cout << val << " ";
    }

    return 0;
}