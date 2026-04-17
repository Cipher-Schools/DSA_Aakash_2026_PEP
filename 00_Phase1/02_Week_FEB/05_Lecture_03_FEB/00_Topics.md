# Topics 

- ## 👉🏻 Sliding Window
    - **Fixed Size Sliding Window**
    
    - **Variable Size Size Sliding Window**
        - Template : variable Size Sliding Window
        ```cpp
        int size = arr.size();
        int i = 0;
        int j = 0;

        while (j < size) {

            // Include arr[j] into calculation / DS

            if (window condition is still VALID) {
                // Window can expand
                // Example: sum < k, distinct <= k, no duplicate, etc.
                j++;
            } 
            else if (window condition is EXACTLY what problem asks) {
                // We found an eligible candidate
                // Update answer here (min length / max length / count etc.)

                j++;  // still try expanding for better answer (problem dependent)
            } 
            else if (window condition is INVALID / OVERFLOWED) {
                // Window violated constraint → must shrink

                while (window condition is INVALID) {
                    // Remove arr[i] from calculation / DS
                    i++;
                }

                // check once here also to hit the condition if needed

                j++;  // After fixing window, expand again
            }
        }
        ```

- ## 👉🏻 Prefix Sum


```
p[i] = p[i-1] + arr[i-1]
```

If we take : `p[0] = 0`

`p[i]` = sum of **first i elements**

---

Array:

```
Index:   0   1   2   3   4
arr =   [2,  4,  6,  8, 10]
```

Build prefix:

| i | p[i] meaning         | value |
| - | -------------------- | ----- |
| 0 | sum of 0 elements    | 0     |
| 1 | arr[0]               | 2     |
| 2 | arr[0]+arr[1]        | 6     |
| 3 | arr[0]+arr[1]+arr[2] | 12    |
| 4 | …                    | 20    |
| 5 | …                    | 30    |

- Get Sum of a Range L → R : Sum(L→R)

```
Sum(L→R)=p[R+1]−p[L]
```

Sum from **L=1 to R=3**

Subarray = `[4,6,8]` → sum = **18**

Using formula:

```
p[R+1] - p[L] = p[4] - p[1] = 20 - 2 = 18
```

```cpp
int n = arr.size();
vector<long long> p(n + 1, 0);

// Build prefix
for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + arr[i - 1];
}

// Range sum L to R (0-indexed)
long long range_sum(int L, int R) {
    return p[R + 1] - p[L];
}
```