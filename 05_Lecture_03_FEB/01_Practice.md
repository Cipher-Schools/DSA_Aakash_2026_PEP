# Class Problems

## Sliding Window Fixed ( K ) sized window

- Count Occurences of Anagrams
    - https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

    ```cpp
    class Solution {
    public:
        int search(string &pat, string &txt) {
            // code here
            unordered_map<char, int> pat_mpp;
            
            for(auto &ch : pat){
                pat_mpp[ch]++;
            }
            
            // window size
            int k = pat.length();
            int size = txt.size();
            
            int i = 0;
            int j = 0;
            int ans = 0;
            
            unordered_map<char, int> window_mpp;
            
            while(j < size){
                window_mpp[txt[j]]++;
                
                if(j-i+1 < k){
                    j++;
                } else if(j-i+1 == k){
                    if(window_mpp == pat_mpp){
                        ans++;
                    }
                    window_mpp[txt[i]]--;
                    if(window_mpp[txt[i]] == 0){
                    window_mpp.erase(txt[i]); 
                    }
                    i++;
                    j++;
                }
            }
            return ans;
        }
    };
    ```

- K Sized Subarray Maximum
    - https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

    - https://leetcode.com/problems/sliding-window-maximum/description/

    ```cpp
    class Solution {
    public:
        vector<int> maxOfSubarrays(vector<int>& arr, int k) {
            // code here
            // k => window Size
            
            // store max elements into the maximum for each subarray
            deque<int> maximum;
            vector<int> result;
            
            int i = 0;
            int j = 0;
            int size = arr.size();
            
            while(j < size){
                
                while(!maximum.empty() && arr[j] > maximum.back()){
                    maximum.pop_back();
                }

                maximum.push_back(arr[j]);

                if(j-i+1 < k){
                    j++;        
                }else if(j-i+1 == k){
                    result.push_back(maximum.front());
                    if(maximum.front() == arr[i]){
                    maximum.pop_front(); 
                    }
                    i++;
                    j++;
                }
                
            }
            return result;
        }
    };
    ```


## Sliding Window : Variable Size

- Longest Subarray with Sum K (Arrays has only positive numbers)
    - https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

    ```cpp
    int longestSubarrayWithSumK(vector<int> arr, long long k) {
        // Write your code here
        int max_len = 0;
        long long sum = 0;
        int i = 0;
        int j = 0;
        int size = arr.size();
        while(j < size){
            sum = sum + arr[j];

            if(sum < k){
                j++;
            } else if(sum == k){
                max_len = max(max_len, j-i+1);
                j++;
            } else if(sum > k){
                while(sum > k){
                    sum = sum - arr[i];
                    i++;
                }
                if (sum == k) {
                    max_len = max(max_len, j - i + 1);
                }
                j++;
            }
        }
        return max_len;
    }
    ```

- Indexes(1 based) of first Subarray whose Sum is equal to the target
    - https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

    ```cpp
    class Solution {
    public:
        vector<int> subarraySum(vector<int> &arr, int target) {
            // code here
            vector<int> result;
            
            int i = 0;
            int j = 0;
            int size = arr.size();
            int sum = 0;
            
            while(j < size){
                sum = sum + arr[j];
                
                if(sum < target){
                    j++;
                } else if(sum == target){
                    result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                } else if(sum > target){
                    while(sum > target){
                        sum = sum - arr[i];
                        i++;
                    }
                    if(sum == target){
                        result.push_back(i+1);
                        result.push_back(j+1);
                        break;
                    }
                    j++;
                }
            }
            if(result.size() > 0){
                return result;
            }
            result.push_back(-1);
            return result;
        }
    };
    ```

- Longest Substring with K Uniques
    - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

    ```cpp
    class Solution {
    public:
        vector<int> subarraySum(vector<int> &arr, int target) {
            // code here
            vector<int> result;
            
            int i = 0;
            int j = 0;
            int size = arr.size();
            int sum = 0;
            
            while(j < size){
                sum = sum + arr[j];
                
                if(sum < target){
                    j++;
                } else if(sum == target){
                    result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                } else if(sum > target){
                    while(sum > target){
                        sum = sum - arr[i];
                        i++;
                    }
                    if(sum == target){
                        result.push_back(i+1);
                        result.push_back(j+1);
                        break;
                    }
                    j++;
                }
            }
            if(result.size() > 0){
                return result;
            }
            result.push_back(-1);
            return result;
        }
    };
    ```

## Prefix Sum

- Count Subarrays whose Sum Equals K (Array has **`-ve numbers`**)
    - https://leetcode.com/problems/subarray-sum-equals-k/description/

    ```cpp
    class Solution {
    public:
        int subarraySum(vector<int>& arr, int k) {
            int count = 0;
            unordered_map<int, int> mpp;
            mpp[0]++;
            int j = 0;
            int size = arr.size();
            int prefix_sum = 0;
            while(j < size){
                prefix_sum = prefix_sum + arr[j];
                auto it = mpp.find(prefix_sum-k);
                if(it != mpp.end()){
                    count = count + it->second;
                }
                mpp[prefix_sum]++;
                j++;
            }

            return count;
        }
    };
    ```

- `kadane / Prefix Sum`: Find subarray whose sum is maximum while array having **`-ve nums`**
    - https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

    - https://leetcode.com/problems/maximum-subarray/

    ```cpp
    class Solution {
    public:
        int maxSubarraySum(vector<int> &arr) {
            // Code here
            int cur_sum = 0;
            int max_sum = INT_MIN;
            
            int size = arr.size();
            for(int i = 0; i <= size-1; i++){
                cur_sum = cur_sum + arr[i];
                if(cur_sum > max_sum){
                    max_sum = cur_sum;
                }
                
                if(cur_sum < 0){
                    cur_sum = 0;
                }
            }
            return max_sum;
        }
    };
    ```

## Practice

- Reverse array in k group
    - https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1

- Smallest subarray with sum greater than x
    - https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

- Minimum Sized Subarray whose sum >= target **Leetcode 209**
    - https://leetcode.com/problems/minimum-size-subarray-sum/description/

- Binary Subarrays With Sum
    - https://leetcode.com/problems/binary-subarrays-with-sum/description/
