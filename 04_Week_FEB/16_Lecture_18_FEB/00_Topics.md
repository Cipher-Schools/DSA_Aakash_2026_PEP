## Tree and Binary Tree

- Tree Concepts
    - Terminologies(Node, Edge,Parent, Child, Path,Siblings, Ancesters, Decendents,Subtree, Level, height, Depth)

- What is binary tree?
- Properties of BT, Types of BT
    - On the basis of nodes(0,1,2) with example and definitions
    - on the basis of completion of level with example and definitions

- Tree traversals => recursive + iterative (using explicit stack)
    - DFS 
        - inorder
        - preorder
        - postorder
    - BFS (level order traversal)
        - Naive recursive[ O(n ^ 2)]
        - Ietrative using queue => O(n)

- Time and space complexity comaparision of all at the basis of best and worst case.

--- 

## 1️⃣ Tree Concepts

A **Tree** is a hierarchical data structure consisting of nodes connected by edges. It is a non-linear structure.

### Basic Terminologies

* **Node** – Basic unit of a tree containing data.
* **Edge** – Connection between two nodes.
* **Root** – Top-most node (has no parent).
* **Parent** – A node having child nodes.
* **Child** – A node directly connected below another node.
* **Siblings** – Nodes having the same parent.
* **Path** – Sequence of nodes connected via edges.
* **Ancestors** – All nodes from a given node up to the root.
* **Descendants** – All nodes below a given node.
* **Subtree** – A node and all its descendants.
* **Level** – Number of edges from root to the node.

---

## 2️⃣ What is a Binary Tree?

A **Binary Tree** is a tree where each node has **at most two children**:

* Left child
* Right child

Structure:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

## Height of Node — Two Definitions

Height of a node =

> Length of the longest path from that node to any leaf.

---

### 1. Height Based on Number of Edges (Standard in DSA)

Height = **number of edges** in the longest downward path.

### Rules:

* Height of a **leaf node** = 0
* Height of an empty tree = -1
* Height of root = max number of edges to any leaf

### Example:

```
        1
       / \
      2   3
     /
    4
```

Edges in longest path (1 → 2 → 4):

2 edges

---

### 2. Height Based on Number of Nodes

Height = **number of nodes** in the longest downward path.

### Rules:

* Height of a **leaf node** = 1
* Height of empty tree = 0
* Height of root = total nodes in longest path

Using same example:

Longest path: 1 → 2 → 4
Number of nodes = 3

---

### Height in terms of edges

```cpp
int height(Node* root){
    if(root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}
```

---

### Height in terms of nodes

```cpp
int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

# 3️⃣ Properties of Binary Tree

---

## A. On the Basis of Number of Children (0,1,2)

### 1. Full Binary Tree

Every node has either:

* 0 children (leaf)
* 2 children

- A full binary tree must always have an odd number of total nodes.

---

### 2. Degenerate (or pathological) tree

- A Tree where every internal node has one child.
- Looks like a linked list.
- A degenerate is a tree having a single child either left or right.


### 3. Skewed Binary Tree

- A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes.
- Types of skewed binary tree:
    - Left-skewed binary tree
    - Right-skewed binary tree.

---

## B. On the Basis of Completion of Levels

### 1. Complete Binary Tree

* All levels are completely filled
* Last level filled from left to right

Used in **Heap** implementation.

---

### 2. Perfect Binary Tree

* All internal nodes have 2 children
* All leaves are at same level

Properties:

* Total nodes = 2^(h+1) - 1
* Leaves = 2^h

---

### 3. Balanced Binary Tree

Height is O(log n).

For every node:

```
|height(left) - height(right)| ≤ 1
```

Ensures efficient operations.

---

## 4️⃣ Tree Traversals

Traversal means visiting all nodes exactly once.

---

### A. DFS (Depth First Search)

**Recusrive DFS (Using Explicit Stack)**

---

### 1. Inorder (Left-Root-Right)

```cpp
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
```

In BST → gives sorted order.

---

### 2. Preorder (Root-Left-Right)

Used for:

* Tree copying
* Prefix expression

```cpp
void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
```

---

### 3. Postorder (Left-Right-Root)

Used for:

* Deleting tree
* Evaluating expression tree

```cpp
void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}
```

---

**Iterative DFS (Using Explicit Stack)**

- **Inorder**

```cpp
void inorderIterative(Node* root){
    stack<Node*> st;
    Node* curr = root;

    while(true){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        } else {
            if(st.empty()){
                break;
            } else {
                curr = st.top();
                st.pop();
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
    }
}
```

- **Preorder**
```cpp
void preorderIterative(Node* root){
    if(root == NULL) return;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if(curr->right)
            st.push(curr->right);

        if(curr->left)
            st.push(curr->left);
    }
}
```

- **Postorder**
```cpp
void postorderIterative(Node* root){
    if(root == NULL) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if(curr->left)
            st1.push(curr->left);

        if(curr->right)
            st1.push(curr->right);
    }

    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
}
```

---