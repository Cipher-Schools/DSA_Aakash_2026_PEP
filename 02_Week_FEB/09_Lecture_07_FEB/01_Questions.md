### Problem :
- **PlatForm** : Leetcode
- **Name** : Sort an Array
- **Link** : https://leetcode.com/problems/sort-an-array/description/?envType=problem-list-v2&envId=merge-sort

    ```cpp
    class Solution {
    public:

    void MergeArray(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if(arr[left]  <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
    }

    void MergeSort(vector<int>& arr, int low, int high){
        if(low >= high){
            return;
        }
        int mid = ( low + high ) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        MergeArray(arr, low, mid, high);
    }

        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            MergeSort(nums, 0, n-1);
            return nums;
        }
    };
    ```

