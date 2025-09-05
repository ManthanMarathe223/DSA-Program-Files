# 📘 Help Notes – DSA Practice

This file contains important notes and key points that I want to remember while revising my DSA practice codes (Sorting, Linked List, Arrays, etc.).

---

## 🔹 Merge Sort (Divide & Merge)

### 1. Divide Step
- Recursively divide the array into **two halves** until you reach a single element.  
- Example: For `9` elements → you can split into `5 | 4` or `4 | 5`.  
- ⚠️ Keep the splitting method **consistent** throughout.

---

### 2. Merge Step
- While merging two sorted halves, use a temporary array `temp` to store sorted values.  
- After merging, **copy back** into the original array.

👉 Important formula:  
```cpp
for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
}

- [i - low] is used because temp always starts from index 0, but in the original array, the subarray might start at    index low.