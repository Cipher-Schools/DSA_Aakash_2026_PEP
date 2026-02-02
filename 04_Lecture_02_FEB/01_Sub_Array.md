# SubArray

- **Generate All Subarrays of an array**
    - Brute Force
    ```cpp
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> subarray;
            for (int k = i; k <= j; k++) {
                subarray.push_back(arr[k]);
            }
            result.push_back(subarray);
        }
    }
    ```

    - Optimal
    ```cpp
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        vector<int> subarray;
        for (int j = i; j < n; j++) {
            subarray.push_back(arr[j]);
            result.push_back(subarray);
        }
    }
    ```

- **Return Sum of all subArrays**
    - Brute Force
    ```cpp
    vector<<int> sum_result;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum = sum + arr[k];
            }
            sum_result.push_back(sum);
        }
    }
    ```

    - Optimal
    ```cpp
    vector<<int> sum_result;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + arr[j];
            sum_result.push_back(sum);
        }
    }
    ```
