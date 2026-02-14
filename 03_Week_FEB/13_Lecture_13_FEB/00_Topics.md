# Stack and Queue

---

## Stack

### Stack LIFO operations

* `push()`
* `pop()`
* `top()`
* `size()`

---

### Stack operations using in CPP STL

```cpp
#include <iostream>
#include <stack>
using namespace std;

void stackSTL() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;   // 30
    cout << "Size: " << st.size() << endl; // 3

    st.pop();

    cout << "Top after pop: " << st.top() << endl; // 20
}
```

---

### Implementation of Stack using Array

**(Array size fixed to 10, size = top + 1)**

```cpp
#include <iostream>
using namespace std;

class StackArray {
    static const int capacity = 10;
    int arr[capacity];
    int topIndex;

public:
    StackArray() {
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == 9) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[topIndex] << '\n';
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    int size() {
        return topIndex + 1;
    }
};
```

---

### Implementation of Stack using Linked List

**(top = NULL initially)**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class StackLinkedList {

    Node* topNode;
    int st_size;

public:
    StackLinkedList() {
        topNode = NULL;
        st_size = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        st_size++;
    }

    void pop() {
        if (topNode == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        st_size--;
    }

    int top() {
        if (topNode == NULL) {
            cout << "Stack Empty\n";
            return -1;
        }
        return topNode->data;
    }

    int size() {
        return st_size;
    }
};
```

---

# Queue

---

## Queue FIFO operations

* `push()`
* `pop()`
* `front()`
* `size()`

---

### Queue operations using in CPP STL

```cpp
#include <iostream>
#include <queue>
using namespace std;

void queueSTL() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Size: " << q.size() << endl;   // 3

    q.pop();

    cout << "Front after pop: " << q.front() << endl; // 20
}
```

---

### Implementation of Queue using Array

**(front and end start at -1, size variable used)**

```cpp
#include <iostream>
using namespace std;

class QueueArray {
    static const int capacity = 10;
    int arr[capacity];
    int frontIndex, rearIndex;
    int Q_size;

public:
    QueueArray() {
        frontIndex = -1;
        rearIndex = -1;
        Q_size = 0;
    }

    void push(int x) {
        if (Q_size == capacity) {
            cout << "Queue Overflow\n";
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;

        rearIndex = (rearIndex +1) % size;
        arr[rearIndex] = x;
        Q_size++;
    }

    void pop() {
        if (Q_size == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        frontIndex = (frontIndex +1) % size;
        Q_size--;

        if (Q_size == 0) {
            frontIndex = rearIndex = -1;
        }
    }

    int front() {
        if (Q_size == 0) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    int size() {
        return Q_size;
    }
};
```

---

### Implementation of Queue using Linked List

**(front and end initially NULL)**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
};

class QueueLinkedList {
    Node* frontNode;
    Node* rearNode;
    int Q_size;

public:
    QueueLinkedList() {
        frontNode = NULL;
        rearNode = NULL;
        Q_size = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        Q_size++;
    }

    void pop() {
        if (frontNode == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        Q_size--;

        if (frontNode == NULL)
            rearNode = NULL;
    }

    int front() {
        if (frontNode == NULL) {
            cout << "Queue Empty\n";
            return -1;
        }
        return frontNode->data;
    }

    int size() {
        return Q_size;
    }
};
```

---

# Implementation of Stack using Queue

**(Use only ONE queue)**

```cpp
#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
    queue<int> q;
    int st_size;

public:
    StackUsingQueue() {
        st_size = 0;
    }

    void push(int x) {
        q.push(x);
        st_size++;

        // Rotate previous elements
        for (int i = 0; i < st_size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
        st_size--;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return q.front();
    }

    int size() {
        return st_size;
    }
};
```

---

# Implementation of Queue using Stack

**(Use 2 stacks: s1 and s2)**

```cpp
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
    stack<int> s1, s2;
    int st_size;

public:
    QueueUsingStack() {
        st_size = 0;
    }

    // O(n)
    void push(int x) {
        // Move all elements to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element
        s1.push(x);

        // Move back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        st_size++;
    }

    // O(1)
    void pop() {
        if (st_size == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        s1.pop();
        st_size--;
    }

    // O(1)
    int front() {
        if (st_size == 0) {
            cout << "Queue Empty\n";
            return -1;
        }

        return s1.top();
    }

    int size() {
        return st_size;
    }
};
```