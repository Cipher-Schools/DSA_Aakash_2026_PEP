# Topics : 2D Arrays and Linked List (C++)

## PART 1: 2D ARRAYS

## 1. 2D Array Declaration (C++)

```cpp
int arr[3][4];          // 3 rows, 4 columns
int arr2[2][3] = {
    {1,2,3},
    {4,5,6}
};
````

Memory is continuous in row-major order.

If you declare `int arr[3][4]`, total memory = `3 * 4 = 12 integers`.

---

## 2. Traversing 2D Array

```cpp
for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
```

Outer loop → rows
Inner loop → columns

Time Complexity: `O(n * m)`

---

## 3. 2D Array vs 2D Char Array

### 2D Char Array

```cpp
char names[3][10] = {
    "Ram",
    "Shyam",
    "Mohan"
};
```
Each row must have equal size (10 here).

Even if name is small, memory reserved is fixed.

Problem:

* Wastage of memory
* Cannot store variable-length strings efficiently

```cpp
// column no. are mandatory
char names[][10] = {
    "Ram",
    "Shyam",
    "Mohan"
};
```

```cpp
// error => each nested element has diffrent length : violates 2d array rectangular size property
char names[][] = {
    "Ram",
    "Shyam",
    "Mohan"
};
```

---

## 4. 2D Array vs String Array (C++ string class)

```cpp
string names[3] = {"Ram", "Shyam", "Mohan"};
```

Difference:

| 2D char array         | string array       |
| --------------------- | ------------------ |
| Fixed size            | Dynamic size       |
| Wastage possible      | No wastage         |
| Manual memory control | Managed internally |

If string length varies → string class is better.

Array of strings of Sting class is a 1D array

---

## 5. 2D Array vs Vector

### 2D Array (Fixed size)

```cpp
int arr[3][4];
```

* Size must be known at compile time.
* Cannot resize.

### 2D Vector (Dynamic)

```cpp
vector<vector<int>> v(3, vector<int>(4));
```

* Dynamic size
* Can resize rows
* More flexible

---

## 6. Problem of Different Length Rows

Normal 2D array:

```cpp
int arr[3][4];
```

All rows must have 4 columns.

But what if:

Row 1 → 3 elements
Row 2 → 5 elements
Row 3 → 2 elements

Normal 2D array cannot handle this.

This is where Jagged Array is needed.

---

# 7. Jagged Array

## (A) Jagged Array in Java

```java
int[][] arr = new int[3][];

arr[0] = new int[3];
arr[1] = new int[5];
arr[2] = new int[2];
```

Each row has different size.

---

## (B) Jagged Array using Vector in C++

```cpp
vector<vector<int>> v;

v.push_back({1,2,3});       // 3 elements
v.push_back({4,5,6,7,8});   // 5 elements
v.push_back({9,10});        // 2 elements
```

Each row can have different size.

Traversal:

```cpp
for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i].size(); j++) {
        cout << v[i][j] << " ";
    }
    cout << endl;
}
```

---

## Summary: When to Use What?

| Situation                  | Use               |
| -------------------------- | ----------------- |
| Fixed rows & columns       | 2D Array          |
| Variable row size          | Vector of vectors |
| String storage             | string array      |
| Memory sensitive + C style | 2D char array     |

---

# PART 2: LINKED LIST

---

## 1. Why Not Arrays?

Demerits of Array:

* Fixed size
* Insertion in middle → O(n)
* Deletion in middle → O(n)
* Memory must be continuous

Linked List solves:

* Dynamic size
* No need for continuous memory
* Easy insertion/deletion

---

# 2. Node Structure
```cpp
struct Node {
    int data;
    Node* next;

    // Constructor with value only
    Node(int val) {
        data = val;
        next = NULL;
    }

    // Constructor with value and next pointer
    Node(int val, Node* nextNode) {
        data = val;
        next = nextNode;
    }
};
```
---

# 3. Create Linked List from Array

```cpp
Node* createList(vector<int>& arr) {
    if(arr.size() == 0) return NULL;

    Node* head = new Node{arr[0], NULL};
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new Node{arr[i], NULL};
        temp = temp->next;
    }

    return head;
}
```

---

# 4. Traversal

```cpp
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
```

---

# 5. Insertion Operations

## Insert at Beginning

```cpp
Node* insertAtStart(Node* head, int val) {
    Node* newNode = new Node{val, head};
    return newNode;
}
```

---

## Insert at End

```cpp
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node{val, NULL};

    if(head == NULL) return newNode;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
```

---

## Insert at Position

```cpp
Node* insertAtPos(Node* head, int val, int pos) {
    if(pos == 1)
        return insertAtStart(head, val);

    Node* temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) return head;

    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;

    return head;
}
```

---

# 6. Deletion Operations

## Delete First Node

```cpp
Node* deleteStart(Node* head) {
    if(head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
```

---

## Delete by Value

```cpp
Node* deleteValue(Node* head, int val) {
    if(head == NULL) return NULL;

    if(head->data == val)
        return deleteStart(head);

    Node* temp = head;
    while(temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if(temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    return head;
}
```

---

# 7. Update Operation

```cpp
void update(Node* head, int oldVal, int newVal) {
    while(head != NULL) {
        if(head->data == oldVal) {
            head->data = newVal;
            return;
        }
        head = head->next;
    }
}
```

---

# 8. Doubly Linked List

## Structure

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor with only value
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }

    // Constructor with value, next and prev
    Node(int val, Node* nextNode, Node* prevNode) {
        data = val;
        next = nextNode;
        prev = prevNode;
    }
};
```

---

## Insert at Beginning

```cpp
Node* insertStart(Node* head, int val) {
    Node* newNode = new Node{val, head, NULL};
    if(head != NULL)
        head->prev = newNode;
    return newNode;
}
```

---

## Delete Node

```cpp
Node* deleteNode(Node* head, int val) {
    Node* temp = head;

    while(temp != NULL && temp->data != val)
        temp = temp->next;

    if(temp == NULL) return head;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    return head;
}
```