## Instructions :
- Pick your pen and paper
- Write pseudo code
- Dry run
- Code at your Device

## Easy :

1. **Array** : Max Consecutive Ones in an Array : https://leetcode.com/problems/max-consecutive-ones/description/

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


2. **Array** : Two Sum Problem on Array : https://leetcode.com/problems/two-sum/description/

    ```cpp
    #include<bits/stdc++.h>
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int, int>> temp;
            vector<int> result;
            int size = nums.size();
            for(int i = 0; i <= size-1; i++){
                temp.push_back({nums[i], i});
            }
            
            sort(temp.begin(), temp.end());
            int left = 0;
            int right = size-1;
            while(left < right){
                pair<int,int> p1 = temp[left];
                pair<int,int> p2 = temp[right];
                if(p1.first + p2.first == target){
                    result.push_back(p1.second);
                    result.push_back(p2.second);
                    break;
                } else if(p1.first + p2.first > target){
                    right--;
                } else if(p1.first + p2.first < target){
                    left++;
                }
            }
            return result;
        }
    };
    ```


3. **Linked List** : Merge Two Sorted Linked List in Sorted Order : https://leetcode.com/problems/merge-two-sorted-lists/description/

    ```cpp
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* head = nullptr;
            ListNode* current_node;
            while(list1 != NULL && list2 != NULL){
                if(list1->val <= list2->val){
                    ListNode *temp = new ListNode(list1->val);
                    if(head == NULL){
                        head = temp;
                        current_node = temp;
                        list1 = list1->next; 
                    } else {
                        current_node->next = temp;
                        current_node = temp;
                        list1 = list1->next; 
                    }
                } else if(list1->val > list2->val){
                    ListNode *temp = new ListNode(list2->val);
                    if(head == NULL){
                        head = temp;
                        current_node = temp;
                        list2 = list2->next; 
                    } else {
                        current_node->next = temp;
                        current_node = temp;
                        list2 = list2->next; 
                    }
                }
            }
            while(list1 != NULL){
                ListNode *temp = new ListNode(list1->val);
                if(head == NULL){
                    head = temp;
                    current_node = temp;
                    list1 = list1->next; 
                } else {
                    current_node->next = temp;
                    current_node = temp;
                    list1 = list1->next; 
                }
            }
            while(list2 != NULL){
                ListNode *temp = new ListNode(list2->val);
                if(head == NULL){
                    head = temp;
                    current_node = temp;
                    list2 = list2->next; 
                } else {
                    current_node->next = temp;
                    current_node = temp;
                    list2 = list2->next; 
                }
            }
        return head;
        }
    };
    ```

4. **Binary Search** : Floor in a Sorted Array : https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
    - Using Linear Search
    - using Binary Search
    ```cpp
    class Solution {
    public:
        int findFloor(vector<int>& arr, int x) {
            // code here
            int size = arr.size();
            int low = 0;
            int high = size-1;
            int ans = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(arr[mid] == x){
                    ans = mid;
                    low = mid+1;
                } else if(arr[mid] < x){
                    ans = mid;
                    low = mid+1;
                } else if(arr[mid] > x){
                    high = mid-1;
                }
            }
            return ans;
        }
    };
    ```

5. **Array** : Left Rotate an  array by k places
    - using extra temp vector
    - using reverse the array from 0 to k-1 and then k to size-1
        ```cpp
        class Solution {
        public:
            // Function to rotate an array by d elements in counter-clockwise direction.

            void reverseArray(vector<int> &arr, int start, int end){
                for(int i = start; i <= (start + end) / 2; i++){
                    int temp = arr[i];
                    arr[i] = arr[end-i+start];
                    arr[end-i+start] = temp;
                }
            }

            void rotateArr(vector<int>& arr, int d) {
                // code here
                int size = arr.size();
                if(size <= 1 || d % size == 0){
                    return;
                }
                d = d % size;
                reverseArray(arr, 0, d-1);
                reverseArray(arr, d, size-1);
                reverseArray(arr, 0, size-1);
            }
        };
        ```

6. **Array** : Right Rotate an array by k places
    - using temp vector space
    - same reverse logic
    - calling
        ```cpp
        class Solution {
        public:

        void reverseTheArray(vector<int>& arr, int start, int end){
            for(int i = start; i <= (start + end) / 2; i++){
                int temp = arr[i];
                arr[i] = arr[end-i+start];
                arr[end-i+start] = temp;
            }
        }
            void rotate(vector<int>& nums, int k) {
                int size = nums.size();
                if(size <= 1){
                    return;
                }
                k = k % size;
                reverseTheArray(nums, 0, size-1-k);
                reverseTheArray(nums, size-k, size-1);
                reverseTheArray(nums, 0, size-1);
            }
        };
        ```

## Medium :

1. **Sorting** : Implement MERGE SORT : https://leetcode.com/problems/sort-an-array/description/?envType=problem-list-v2&envId=merge-sort

2. **Dutch national flag** : Sort Colors 0 1 2 : https://leetcode.com/problems/sort-colors/description/
    - using count 0 , 1 and 2  and then rewrite values in array
        - use while loop three times to 
    
    or 
    
    - Use DNF
    ````cpp
    class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int size = nums.size();
            int i = 0; // for 0
            int j = 0; // for 1
            int k = size-1; // for 2
            while(j <= k){
                if(nums[j] == 2){
                    swap(nums[j], nums[k]);
                    k--;
                } else if(nums[j] == 0){
                    swap(nums[j], nums[i]);
                    i++;
                    j++;
                }
                else {
                    j++;
                }
            }
        }
    };
    ```

4. **Singly Linked List** : Reverse a Singly Linked List : https://leetcode.com/problems/reverse-linked-list/description/

6. **Binary Search** : Find Peak Element in the Array : https://leetcode.com/problems/find-peak-element/

    - using Linear Search
    - Binary search 
        ```cpp
        class Solution {
        public:
            int findPeakElement(vector<int>& nums) {
                int left = 0;
                int right = nums.size() - 1;

                while (left < right) {
                    int mid = left + (right - left) / 2;

                    if (nums[mid] > nums[mid + 1]) {
                        - descending → peak is at mid or to the left
                        right = mid;
                    } else {
                        - ascending → peak must be to the right
                        left = mid + 1;
                    }
                }

                return left;  - or right (both same)
            }
        };
        ```

## Hard:

1. **Tree** : Implement DFS on Tree using explicitly Stack data Structure (Using Iteration)
    - Predorder
        - https://leetcode.com/problems/binary-tree-preorder-traversal/description/
    - Indorer
        - https://leetcode.com/problems/binary-tree-inorder-traversal/description/
    - PostOrder
        - https://leetcode.com/problems/binary-tree-postorder-traversal/description/
