# Category A :
## Topics : Array, Searching

## Problem 1 :
- **Name** : Rotate Image
- **Link** : https://leetcode.com/problems/rotate-image/description/
- **Hint** :
    ```cpp
    Take transpose
    reverse each row
    ```

## Problem 2 :
- **Name** : Best time to buy and sell stock
- **Link** : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1704896293/
- **Hint** :
    ```cpp
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int minimum = 10000;
        int maxProf = 0;
        for(auto price : prices){
            minimum = min(minimum, price);
            maxProf = max(maxProf, price-minimum );
        }

        return maxProf;
    }
    ```

## Problem 3 :
- **Name** : Majority element in an array
- **Link** : https://leetcode.com/problems/majority-element/description/
    ```cpp
    #include<bits/stdc++.h>

    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int result;
            for(int i = 0; i <= n - n/2 -1; i++){
                if(nums[i] == nums[i + n/2]){
                    result = nums[i];
                    break;
                }
            }
            return result;
        }
    };
    ```

## Problem 4 :
- **Name** : Intersaction of two arrays
- **Link** : https://leetcode.com/problems/intersection-of-two-arrays/submissions/1697294736/
    ```cpp
    #include<bits/stdc++.h>

    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            int n1 = nums1.size();
            int n2 = nums2.size();
            int i = 0;
            int j = 0;
            int lastElement = -1;
            vector<int> resultArray;
            while(i <= n1-1 && j <= n2-1){
                if(nums1[i] == nums2[j]){
                    if(lastElement == nums1[i]){
                        i++;
                        j++;
                    } else{
                        resultArray.push_back(nums1[i]);
                        lastElement = nums1[i];
                        i++;
                        j++;
                    }
                } else if(nums1[i] < nums2[j]){
                    i++;
                } else if(nums1[i] > nums2[j]){
                    j++;
                }
            }
            return resultArray;
        }
    };
    ```

## Problem 5 :
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

## Problem 6 :
- **Name** : Search in roated sorted array
- **Link** : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
    ```cpp
    class Solution {
    public:

        // find minimum element indix in rotated array
        int find_pivot(vector<int>& nums){
            int size = nums.size();
            int left = 0;
            int right = size-1;
            while(left < right){
                int mid = (left + right) /2;
                if(nums[mid] > nums[right]){
                    left = mid+1;
                } else if(nums[mid] < nums[right]){
                    right = mid;
                }
            }
            return right;
        }

        int binary_search(vector<int>& nums, int target, int start, int end){
            int size = nums.size();
            int ans = -1;
            while(start <= end){
                int mid = (start + end) / 2;
                if(nums[mid] == target){
                    ans = mid;
                    break;
                } else if(nums[mid] < target){
                    start = mid+1;
                } else if(nums[mid] > target){
                    end = mid-1;
                }
            }
            return ans;
        }

        int search(vector<int>& nums, int target) {
            int size = nums.size();
            int pivot_index = find_pivot(nums);
            int index = binary_search(nums, target, 0, pivot_index-1);
            if(index != -1){
                return index;
            } else {
                index = binary_search(nums, target, pivot_index, size-1);
            }
            return index;

        }
    };
    ```