## Class Room

### Problem 1:

* **Platform** : Sorting Algorithms (Concept Practice)
* **Name** : Sort a String using Count Sort
* **Link** : N/A
    - using sorting algoritms
    ```cpp
    string s = "sortingalgoritms";

      // Compare each character with every other character
      for(int i = 0; i < s.length(); i++) {
         for(int j = i + 1; j < s.length(); j++) {
               // If characters are not in order, swap them
               if(s[i] > s[j]) {
                  swap(s[i], s[j]);
               }
         }
      }
    ```
    
    - using count sort (in O(n))
    ```cpp
    string s = "sortingalgoritms";

    // Array to store frequency of characters
    int count[26] = {0};

    // Count each character
    for(char ch : s) {
        count[ch - 'a']++;
    }

    // Build the sorted string
    int index = 0;
    for(int i = 0; i < 26; i++) {
        while(count[i] > 0) {
            s[index++] = char(i + 'a');
            count[i]--;
        }
    }
    ```

### Problem 2:

* **Platform** : Concept Practice
* **Name** : Reverse a String
* **Link** : N/A
    ```cpp
    void reverseStringOptimal(string &s) {
        int left = 0;
        int right = s.length() - 1;

        // Keep swapping until pointers meet
        while(left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
    ```


### Problem 3:

* **Platform** : Concept Practice
* **Name** : Count Vowels and Consonants
* **Link** : N/A


### Problem 4:

* **Platform** : LeetCode
* **Name** : Valid Anagram
* **Link** : https://leetcode.com/problems/valid-anagram/description/
    - Sortng
        ```cpp
        bool isAnagramSorting(string s, string t) {
            // If length is different, not an anagram
            if(s.length() != t.length())
                return false;

            // Sort both strings
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            // Compare sorted strings
            if(s == t)
                return true;
            else
                return false;
        }
        ```

    - Map Hashing
        ```cpp
        bool isAnagramMap(string s, string t) {
            if(s.length() != t.length())
                return false;

            unordered_map<char, int> mp;

            // Count characters of s
            for(int i = 0; i < s.length(); i++) {
                mp[s[i]]++;
            }

            // Decrease count using t
            for(int i = 0; i < t.length(); i++) {
                mp[t[i]]--;

                if(mp[t[i]] < 0)
                    return false;
            }

            return true;
        }
        ```

    - Array 26 Hashing - Using 2 arrays : freq[str[i] - 'a']++;
    ```cpp
    bool isAnagramTwoArrays(string s, string t) {
        if(s.length() != t.length())
            return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Count both strings
        for(int i = 0; i < s.length(); i++) {
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }

        // Compare frequency arrays
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
    ```
    
    - Array 26 Hashing - Using 1 array using one loop
    ```cpp
    bool isAnagramOneArray(string s, string t) {
        if(s.length() != t.length())
            return false;

        int freq[26] = {0};

        // One loop for both strings
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // Check if all values are zero
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0)
                return false;
        }

        return true;
    }
    ```


### Problem 5:

* **Platform** : LeetCode
* **Name** : Valid Palindrome
* **Link** : https://leetcode.com/problems/valid-palindrome/description/
    ```cpp
    class Solution {
    public:
        bool isPalindrome(string s) {
            int left = 0;
            int right = s.length() - 1;

            while (left < right) {
                while (left < right && !isalnum(s[left])) left++;
                while (left < right && !isalnum(s[right])) right--;
                if (tolower(s[left]) != tolower(s[right])) 
                    return false;

                left++;
                right--;
            }
            return true;
        }
    };
    ```


## Practice

### Problem 6 :

* **Platform** : LeetCode
* **Name** : Is Subsequence
* **Link** : [https://leetcode.com/problems/is-subsequence/description/](https://leetcode.com/problems/is-subsequence/description/)

### Problem 7 :

* **Platform** : GeeksforGeeks
* **Name** : First Repeated Character
* **Link** : [https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1](https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1)

### Problem 8 :

* **Platform** : LeetCode
* **Name** : First Unique Character in a String
* **Link** : [https://leetcode.com/problems/first-unique-character-in-a-string/description/](https://leetcode.com/problems/first-unique-character-in-a-string/description/)
