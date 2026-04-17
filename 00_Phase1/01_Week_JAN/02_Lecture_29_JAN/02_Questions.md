# Category B :

- ## Topics :
    - **Programming** :
        - DataTypes
        - Variables
        - Operators
        - Pointers : 
            - Pointers declaration / type
            - Pointers variables access
            - Pointer Airthmatic
        - Functions (Pass by value, pass by reference)
        - Array as pointers
        - new keyword with array

    - **DSA** :
        - Array
            - What is an array & memory layout?
            - Array declaration & initialization
                - with given array size
                - with given elements
            - Array Traversal / access / loops
            - CRUD
        
        - Searching
            - Linear Search
            - Binary search

        - Sorting 
            - Bubble sort
            - Selection sort
            - Insertion sort

## Problems :

## Problem 1 :

***CRUD Operations Using Array in C++***

You are given an empty integer array of fixed size.

Your task is to implement a **menu-driven program** in **C++** that performs the following **CRUD operations** on the array:

1. **Create (Insert)**

   * Insert an element into the array.

2. **Read (Display)**

   * Display all the elements of the array in sequence.

3. **Update**

   * Update the value of an element at a given index.

4. **Delete**

   * Delete an element from a given index.
   * After deletion, shift the remaining elements to maintain array continuity.

---

### Constraints and Rules

* Use a **static array** (no STL containers like `vector`).
* Maintain a variable to track the **current size** of the array.
* Index validation must be performed for **Update** and **Delete** operations.
* The program should continue to run until the user chooses the **Exit** option.

---

### Input Format

* User choices through a menu:

  * 1 → Insert
  * 2 → Display
  * 3 → Update
  * 4 → Delete
  * 5 → Exit
* For Insert and Update operations, the user will enter integer values.
* For Update and Delete operations, the user will enter the index.

---

### Output Format

* Display appropriate messages for each operation.
* Print the array elements after the Read operation.
* Display an error message for invalid index inputs.

---

## Problem 2 :
***Find Minimum and Maximum in an Array***

Given an integer array arr of size n, write a function to find both the minimum and maximum elements in the array.

Constraints

0 ≤ arr[i] ≤ 100

Do not use built-in functions.

Traverse the array only once.

## Problem 3 :
- **Name** : Second Largest in an array
- **Link** : https://www.geeksforgeeks.org/problems/second-largest3735/1

    ```cpp
    class Solution {
    public:
        int getSecondLargest(vector<int> &arr) {
            // code here
            int max = -1;
            int sec_max = -1;
            for(int i = 0; i <= arr.size()-1; i++){
                if(arr[i] > max){
                    sec_max = max;
                    max = arr[i];
                } else if(arr[i] > sec_max && arr[i] != max) {
                    sec_max = arr[i];
                }
            }
            return sec_max;
        }
    };
    ```

## Problem 4 :
- **Name** : Missing Number
- **Link** : https://leetcode.com/problems/missing-number/description/

    ```cpp
    class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int xorAll = 0;
            int xorArray = 0;
            
            for(int i = 0; i <= n; i++) {
                xorAll ^= i;
            }
            
            for(int num : nums) {
                xorArray ^= num;
            }
            
            return xorAll ^ xorArray;
        }
    };
    ```

## Problem 5 :
- **Difficulty** : Easy
- **Name** : Max Consecutive Ones
- **Link** : https://leetcode.com/problems/max-consecutive-ones/submissions/1697796954/

    ```cpp
    class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int size = nums.size();
            int count = 0;
            int maxCount = 0;
            for(int i = 0; i <= size-1; i++){
                if(nums[i] == 1){
                    maxCount++;
                    count = max(maxCount, count);
                } else {
                    maxCount = 0;
                }
            }
            return count;
        }
    };
    ```

## Problem 6 :

Reverse an array
```cpp
function reverseArray(arr):
    left = 0
    right = length(arr) - 1

    while left < right:
        swap arr[left] and arr[right]
        left = left + 1
        right = right - 1
```

## Problem 7 :

Check wheter a array is sorted or not

https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

    ```cpp
    class Solution {
    public:
        bool isSorted(vector<int>& arr) {
            // code here
            int n = arr.size();
            
            for(int i = 1; i < n; i++) {
                if(arr[i] < arr[i - 1]) {
                    return false;
                }
            }
            
            return true;
        }
    };
    ```

## Problem 8 :
- **Name** : Rotate Image
- **Link** : https://leetcode.com/problems/rotate-image/description/
    ```cpp
    class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int rows = matrix.size();
            int column = matrix[0].size();

            // matrix transpose
            for(int i = 0; i < rows; i++){
                for(int j = i; j < column; j++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }

            // reverse each row of matrix
            for(int i = 0; i < rows; i++){
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
    };
    ```

## Problem 9 :
- **Name** :  Find First and Last Position of Element in Sorted Array
- **Link** : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    ```cpp
    class Solution {
    public:

        int first_Occurence(vector<int>& nums, int target){
            int size = nums.size();
            int lower = -1;
            int left = 0;
            int right = size-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target){
                    lower = mid;
                    right = mid-1;
                } else if(nums[mid] > target){
                    // lower = mid;
                    right = mid-1;
                } else if(nums[mid] < target){
                    left = mid+1;
                }
            }
            return lower;
        }

        int last_Occurence(vector<int>& nums, int target){
            int size = nums.size();
            int upper = -1;
            int left = 0;
            int right = size-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target){
                    upper = mid;
                    left = mid +1;
                } else if(nums[mid] > target){
                    right = mid-1;
                } else if(nums[mid] < target){
                    left = mid+1;
                }
            }
            return upper;
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            int first = first_Occurence(nums, target);
            vector<int> result;
            if(first == -1){
                result.push_back(-1);
                result.push_back(-1);
                return result;
            } else {
                int last = last_Occurence(nums, target);
                if(last == -1){
                    result.push_back(first);
                    result.push_back(first);
                    return result;
                } else {
                    result.push_back(first);
                    result.push_back(last);
                    return result;
                }
            }
        }
    };
    ```

## Problem 10 :
- **Name** : count Number of occurrence in sorted array
- **Link** : https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
    ```cpp
    class Solution {
    public:
    
        int first_Occurence(vector<int>& nums, int target){
            int size = nums.size();
            int lower = -1;
            int left = 0;
            int right = size-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target){
                    lower = mid;
                    right = mid-1;
                } else if(nums[mid] > target){
                    // lower = mid;
                    right = mid-1;
                } else if(nums[mid] < target){
                    left = mid+1;
                }
            }
            return lower;
        }

        int last_Occurence(vector<int>& nums, int target){
            int size = nums.size();
            int upper = -1;
            int left = 0;
            int right = size-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target){
                    upper = mid;
                    left = mid +1;
                } else if(nums[mid] > target){
                    right = mid-1;
                } else if(nums[mid] < target){
                    left = mid+1;
                }
            }
            return upper;
        }
    
        int countFreq(vector<int>& nums, int target) {
            // code here
            int first = first_Occurence(nums, target);
            if(first == -1){
                return 0;
            } else {
                int last = last_Occurence(nums, target);
                int ans = last - first + 1;
                return ans;
            }
            
        }
    };
    ```

