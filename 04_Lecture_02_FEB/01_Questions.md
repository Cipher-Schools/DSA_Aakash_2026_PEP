# Sliding Window Fixed ( K ) sized window

## Class Problems

- Maximum sum of subarray of size K
    - https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
    ```cpp
    class Solution {
    public:
        int maxSubarraySum(vector<int>& arr, int k) {
            // code here
            int max_sum = -1;
            int size = arr.size();
            int i = 0;
            int j = 0;
            int sum = 0;
            while(j < size){
                sum = sum + arr[j];
                if(j-i+1 < k){
                    j++;
                } else if((j-i+1) == k) {
                    max_sum = max(max_sum, sum);
                    sum = sum - arr[i];
                    i++;
                    j++;
                }
            }
            return max_sum;
        }
    };
    ```

- First negative in every window of size k
    - https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
    ```cpp
    class Solution {
    public:
        vector<int> firstNegInt(vector<int>& arr, int k) {
            // write code here
            vector<int> result;
            queue<int> negatives;
            int size = arr.size();
            int i = 0;
            int j = 0;
            while(j < size){
                if(arr[j] < 0){
                    negatives.push(arr[j]);
                }
                
                if(j-i+1 < k){
                    j++;
                } else if(j-i+1 == k){
                    if(!negatives.empty()){
                        int neg = negatives.front();
                        result.push_back(neg);
                        if(arr[i] == negatives.front()){
                            negatives.pop();
                        }
                        i++;
                        j++;
                    } else {
                        result.push_back(0);
                        i++;
                        j++;
                    }
                }
            }
            return result;
        }
    };
    ```

- Minimum swaps to make `(elements <= K)` together
    - https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
    ```cpp
    // Final function implementation
    class Solution {
    public:
        int minSwap(vector<int>& arr, int k) {
            // code here
            int size = arr.size();
            int window = 0;
            for(int i = 0; i <= size-1; i++){
                if(arr[i] <= k){
                    window++;
                }
            }
            if (window == 0 || window == 1) return 0;
            
            int greater_count = 0;
            int swaps = INT_MAX;
            
            int i = 0;
            int j = 0;
            
            while(j < size){
                if(arr[j] > k){
                    greater_count++;
                }
                if(j-i+1 < window){
                    j++;
                } else if(j-i+1 == window){
                    swaps = min(swaps, greater_count);
                    if(arr[i] > k){
                        greater_count--;
                    }
                    i++;
                    j++;
                }
            }
            return swaps;
            
        }
    };
    ```

## Practise

- Minimum Swaps to Group All 1's Together
    - https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

- Count Occurences of Anagrams
    - https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

- Find All Anagrams in a String (return indecies array)
    - https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/1902942294/