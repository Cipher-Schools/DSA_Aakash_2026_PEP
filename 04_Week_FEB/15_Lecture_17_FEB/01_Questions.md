## Class Problems

### 1. Next Greater Element I

**Platform:** LeetCode
**Link:** [https://leetcode.com/problems/next-greater-element-i/](https://leetcode.com/problems/next-greater-element-i/)


### 2. Reverse a Queue

**Platform:** GeeksforGeeks
**Link:** [https://www.geeksforgeeks.org/problems/queue-reversal/1](https://www.geeksforgeeks.org/problems/queue-reversal/1)


### 3. Reverse K Elements in Queue

**Platform:** GeeksforGeeks
**Link:** [https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)

### 4. Interleave First Half with Second Half of Queue

**Platform:** GeeksforGeeks
**Link:** [https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1)


### 5. Online Stock Span

**Platform:** LeetCode
**Link:** [https://leetcode.com/problems/online-stock-span/](https://leetcode.com/problems/online-stock-span/)

### 6. Largest Rectangle in Histogram

**Platform:** LeetCode
**Link:** [https://leetcode.com/problems/largest-rectangle-in-histogram/](https://leetcode.com/problems/largest-rectangle-in-histogram/)

### 7. Daily tempratures
**Platform:** Leetocde
**link:** - https://leetcode.com/problems/daily-temperatures/description/
```cpp
class Solution {
public:
    vector<int> nsl;
    vector<int> nsr;

    void near_small_left(vector<int>& heights){
        int size = heights.size();
        stack<pair<int, int>> st;

        for(int i = 0; i < size; i++){
            if(st.empty()){
                nsl.push_back(-1);
            } else if(heights[i] > st.top().first){
                nsl.push_back(st.top().second);
            } else if(heights[i] <= st.top().first){
                while(!st.empty() && heights[i] <= st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    nsl.push_back(-1);
                } else {
                    nsl.push_back(st.top().second);
                }
            }
            st.push({heights[i], i});
        }
    }

    void near_small_right(vector<int>& heights){
        int size = heights.size();
        stack<pair<int, int>> st;

        for(int i = size-1; i >= 0; i--){
            if(st.empty()){
                nsr.push_back(size);
            } else if(heights[i] > st.top().first){
                nsr.push_back(st.top().second);
            } else if(heights[i] <= st.top().first){
                while(!st.empty() && heights[i] <= st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    nsr.push_back(size);
                } else {
                    nsr.push_back(st.top().second);
                }
            }
            st.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        near_small_left(heights);
        near_small_right(heights);

        int size = heights.size();
        int maxi = 0;
        for(int i = 0; i < size; i++){
            int width = nsr[i] - nsl[i] - 1;
            int ar = heights[i] * width;
            maxi = max(maxi, ar);
        }
        return maxi;
    }
};
```



## Practice Problem

### 8. Infix to Postfix

**Platform:** GeeksforGeeks
**Link:** [https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1](https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1)