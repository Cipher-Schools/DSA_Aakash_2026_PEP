## Class Problems

### 1. Insert into a Sorted Circular Linked List – LeetCode
* Link : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

### 2. Deletion in Circular Linked List
* Link : https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

### 3. Split a Circular Linked List into Two Halves
* Link : https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1


## Singly list

### 4. Reverse Nodes in k-Group
* Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/
```cpp
class Solution {
public:
    int len_list(ListNode* head){
        ListNode* cur_node = head;
        int count = 0;
        while(cur_node != NULL){
            count++;
            cur_node = cur_node->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int length = len_list(head);
        if(length < k){
            return head;
        }
        int total_reverse = length/k;
 
        ListNode* prev_tail = NULL;
        ListNode* new_head = NULL;
        ListNode* cur_node = head;
        
        while(total_reverse){
            ListNode* prev = NULL;
            ListNode* new_tail = cur_node;

            for(int i = 0; i < k; i++){
                ListNode * nextNode = cur_node->next;
                cur_node->next = prev;
                prev = cur_node;
                cur_node = nextNode;
            }
            if(new_head == NULL){
                new_head = prev;
            }
            if(prev_tail != NULL) {
                prev_tail->next = prev;
            }

            prev_tail = new_tail;

            total_reverse--;
        }

        prev_tail->next = cur_node;
        return new_head;
    }
};
```

### 5. LRU Cache
* Link : https://leetcode.com/problems/lru-cache/description/

* **Using Vector** : TLE for Edge cases

```cpp
class LRUCache {
public:
    vector<pair<int, int>> cache;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        int value = -1;
        int cache_size = cache.size();
        for(int i = 0;  cache_size != 0 && i < cache_size; i++){
            if(key == cache[i].first){
                value = cache[i].second;
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                break;
            }
        }
        return value;
    }
    
    void put(int key, int value) {
        int cache_size = cache.size();
        for(int i = 0; i < cache_size; i++){
            if(key == cache[i].first){
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() == size){
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else if(cache.size() < size){
            cache.push_back({key, value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```


* Using **Doubley Linked List**

```cpp
class LRUCache {
public:
    int LRU_size;

    struct DLL_List{
        int val;
        DLL_List * next;
        DLL_List * back;
        DLL_List(int value){
            val = value;
            next = nullptr;
            back = nullptr;
        }
    };

    DLL_List * head;
    DLL_List * tail;

    //<key, <node_address, value>>
    unordered_map<int, pair<DLL_List*, int>> mpp;

    LRUCache(int capacity) {
        LRU_size = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void moveTohead(DLL_List* node){
        if(node == head){
            return;
        }

        if(node->back){
            node->back->next = node->next;
        }

        if(node->next){
            node->next->back = node->back;
        }

        if(node == tail){
            tail = node->back;
        }

        node->next = head;
        node->back = nullptr;

        if(head){
            head->back = node;
        }

        head = node;

        if(tail == nullptr){
            tail = head;
        }

    }

    int get(int key) {
        int value = -1;
        if(mpp.find(key) != mpp.end()){
            value = mpp[key].second;
            DLL_List* node_add = mpp[key].first;
            moveTohead(node_add);
        }
        return value;
    }
    
    void put(int key, int value) {

        if(mpp.find(key) != mpp.end()){
            mpp[key].second = value;
            DLL_List* node_add = mpp[key].first;
            moveTohead(node_add);
            return;
        }

        if(mpp.size() == LRU_size){
            // erase from map
            mpp.erase(tail->val);

            // delete tail from Lru
            DLL_List * prev = tail->back;

            if(prev){
                prev->next = nullptr;
            }
            delete tail;
            tail = prev;

            if(tail == nullptr){
                head = nullptr;
            }
        }

        DLL_List * new_node = new DLL_List(key);

        if(head == NULL){
            head = new_node;
            tail = new_node;
        } else if(head != NULL){
            new_node->next = head;
            head->back = new_node;
            head = new_node;
        }
        mpp[key] = {new_node, value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

```