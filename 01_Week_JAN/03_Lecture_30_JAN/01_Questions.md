## 👉🏻 Topic : Array

### Problem 1 : 
- **PlatForm** : Leetcode 442
- **Name** : Find All Duplicates in an Array without using extra space and sorting in O(n)
- **Link** : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

    ```cpp
    class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> result;
            int size = nums.size();
            for(int i = 0; i <= size-1; i++){
                int num = abs(nums[i]);
                int visit_index = num-1;
                if(nums[visit_index] < 0){
                    result.push_back(num);
                } else {
                    nums[visit_index] = -nums[visit_index];
                }
            }
            return result;
        }
    };
    ```


## 👉🏻 Topic : Binary Search - Pattern 1

### Problem 2 : 
- **PlatForm** : GFG
- **Name** : Count Occurences of Target Element
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


### Problem 3 : 
- **PlatForm** : Leetcode 153
- **Name** : Find Minimum in Rotated Sorted Array
- **Link** : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

    ```cpp
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int size = nums.size();
            int left = 0;
            int right = size-1;
            while(left < right){
                int mid = (left + right) / 2;
                if(nums[mid] > nums[right]){
                    left = mid+1;
                } else if(nums[mid] < nums[right]){
                    right = mid;
                }
            }
            return nums[right];
        }
    };
    ```


## 👉🏻 Topic : Two pointers

### Problem 4 : 
- **PlatForm** : GFG
- **Name** : Common in 3 Sorted Arrays
- **Link** : https://www.geeksforgeeks.org/problems/common-elements1132/1

    ```cpp
    class Solution {
    public:
        // Function to find common elements in three arrays.
        vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                                vector<int> &arr3) {
            // Code Here
            vector<int> result;
            int i = 0;
            int j = 0;
            int k = 0;
            int num1 = arr1.size();
            int num2 = arr2.size();
            int num3 = arr3.size();
            while(i < num1 && j < num2 && k < num3){
                if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
                    if (result.empty() || result.back() != arr1[i])
                        result.push_back(arr1[i]);
                    i++;
                    j++;
                    k++;
                } else if(arr1[i] < arr2[j]){
                    i++;
                } else if(arr2[j] < arr3[k]){
                    j++;
                } else {
                    k++;
                }
            }
            return result;
            
        }
    };
    ```


### Problem 5 : 
- **PlatForm** : LeetCode 26
- **Name** : Remove Duplicates from Sorted Array
- **Link** : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

    ```cpp
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int unique = 0;
            int i = 0;
            int j = 1;
            int size = nums.size();
            if(size == 1){
                return 1;
            }
            while(j < size){
                if(nums[i] == nums[j]){
                    j++;
                } else {
                    i = i+1;
                    nums[i] = nums[j];
                }
            }
            return i+1;
        }
    };
    ```


### Problem 6 : 
- **PlatForm** : Leetcode 1877
- **Name** : Minimize Maximum Pair Sum in Array
- **Link** : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/

    ```cpp
    class Solution {
    public:
        int minPairSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int i = 0;
            int j = nums.size()-1;
            int pair_Sum = 0;
            while(i < j){
                int sum = nums[i] + nums[j];
                pair_Sum = max(pair_Sum, sum);
                i++;
                j--;
            }
            return pair_Sum;
        }
    };
    ```


**Example** :
Edge cases where **Smallest + Largest** approch could be fail for Problem 6.**

```
nums = [4,1,5,1,2,5,1,5,5,4]

Sorted :

[1, 1, 1, 2, 4, 4, 5, 5, 5, 5]

```

```

nums = [1, 2, 100, 101, 102, 103]

```

```
nums = [2, 3, 50, 60, 61, 62]

```

```

Let's suppose, tumhare paas kuch log hain jinki heights different hain(in even numbers).

Tumhe unhe pairs me khada karna hai.
Har pair ki total height niklegi.
Your goal is:
    - “Mujhe sabse lamba pair jitna ho sake utna chhota chahiye.”

```

```
Let’s suppose you have some people with different heights(in even numbers).

You need to arrange them into pairs.
For each pair, you calculate the total height.

Your goal is:
You want the tallest pair to be as short as possible.
```