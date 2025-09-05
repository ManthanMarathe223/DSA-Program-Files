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


