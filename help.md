# 📘 Help Notes – DSA Practice

---

## 🔹 Merge Sort (Divide & Merge)

### 1. Divide Step
- Recursively divide the array into **two halves** until you reach a single element.  
- Example: For `9` elements → you can split into `5 | 4` or `4 | 5`.  
- ⚠️ Keep the splitting method **consistent** throughout.

### 2. Merge Step
- While merging two sorted halves, use a temporary array `temp` to store sorted values.  
- After merging, **copy back** into the original array.

👉 Important formula:  
```cpp
for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
}
```
- [i - low] is used because temp always starts from index 0, but in the original array, the subarray might start at    index low.

#### Time & Space Complexity
- Time Complexity : O(nlogn) Best for Less Time

- Space Complexity : O(n)       
                  - Merge Sort requires extra memory for temp arr so O(n).

---

## 🔹 Shell Sort

### Shell Sort means Gap.
- Calculate gap using index or using number of elements, which is divided by 2.
- Gap is calculated till its not equal to 1.

### 3 nested for loops
- 1st for Gap.
- 2nd for j.
    - j will be gap and inc by 1

- 3rd for i.
    - Which is i=j-gap.
    - Firstly, will check in forward manner means i and i+gap( which is j).
    - Then, will check in backward direction as i-=gap.
    - We campare it as 
    ```cpp
    if(a[i]>a[i+gap])
    ```
    Because we check j value only once and after that only backward
    comparison is done with i-=gap(i). 
    - 

---

## 🔹 Quick Sort

### Consider Last element is 'Pivot':
- Firstly, find pivot and place lesser value to left and greater to right.
- Recursion for Left partition and Right as well.
- Continue recursion till (start < end).

### Pivot Finding Logic:
- Initially 'idx' variable initialize to -1.
- Pivot is last element of the array.
- for loop of 'j' from start to < end. 
- Compare every 'j' value with pivot. 
``` if(arr[j]<pivot) ``` 
- Increment 'idx' and swap with j
- Lastly, inc. 'idx' and swap with pivot, to place it at correct position. Ret 'idx'

### Doubt clearing:
```cpp
idx++;
swap(arr[end], arr[idx]);
```
why not
```cpp
idx++;
swap(pivot, arr[idx]);
```
-Becoz, it will swap the value with local variable and not with the array index.


#### Time & Space Complexity
- Time Complexity : Avg/Practical Case => O(nlogn)
                  -   Worst Case => O(n^2) 
                  If, pivot value is either largest or smallest.

- Space Complexity : O(1)       Best for Less Memory
                  -  As no extra space is required
                  - That's why QS is used over Merge Sort as when less memory is req QS is best.
                  - Merge Sort requires extra memory for temp arr so O(n).

---

## 🔹 Insertion Sort 

- Start from 1st index as 0th index is initially sorted.
- After storing the current var we do the shifting (overwriting to the next index).
- Lastly when all index is compared we add the current variable to its sorted place.

---

## 🔹 Vector

- [Variable Sized Array](https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true)

- 2D Vector: 
```cpp
vector<vector<int>> v;
```
- Means we create a Vector inside which we will store various vectors which in turn will have int values.
- v is vector without any size so should add elements using 
```cpp
v.push_back(element);
```


