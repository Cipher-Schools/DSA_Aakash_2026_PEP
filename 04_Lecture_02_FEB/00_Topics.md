# Topics 

- ## 👉🏻 Subarrays

    ```cpp
    Total no. of Subarrays = n(n+1)/2;
    n : size of array

    length of the subArray : j-i+1
    i : starting index of subarray
    j : ending index of subarray
    ```

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


- ## 👉🏻 Sliding Window

    - **Template Fixed Size Sliding Window**
    
    ```cpp
    // choose appropiate data structure according to the problem
    int size = size of array
    int k = window_size
    int i = 0;
    int j = 0;
    while(j < size){
        // Prior calculation at each : j

        // reach to the window size
        if(j-i+1 < k){
            j++;
        } 
        // once reached the window size
        else if(j-i+1 == k){
            do calculation to get eligible candidate for answer

            remove calculation for i^th element
            //Slide the window
            i++;
            j++;
        }
    }
    ```