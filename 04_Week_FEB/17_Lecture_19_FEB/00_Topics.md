## BFS (Breadth First Search)

Also called **Level Order Traversal**.

---

### 1. Naive Recursive BFS (Level Order Traversal)

1. First compute the height of the tree.
2. For each level `i` from 0 to height:

   * Print all nodes at that level.

Because for every level we traverse the tree again,
this method is inefficient.

---

**Step 1: Height Function (Edges Based)**

```cpp
int height(Node* root){
    if(root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}
```

---

**Step 2: Print Nodes at Given Level**

```cpp
void printLevel(Node* root, int level){
    if(root == NULL) return;

    if(level == 0){
        cout << root->data << " ";
    } else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
```

---

**Step 3: Level Order Using Recursion**

```cpp
void levelOrderRecursive(Node* root){
    int h = height(root);

    for(int i = 0; i <= h; i++){
        printLevel(root, i);
    }
}
```

**Why It Is Inefficient**

Because:

* For level 0 → you traverse tree
* For level 1 → you traverse again
* For level 2 → traverse again
* And so on...

---

### 2. Iterative BFS (Using Queue) – Optimal

```cpp
void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->data;

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
```

Time Complexity → O(n)
Space Complexity → O(n)

---

## Time and Space Complexity Comparison

Let:

* n = number of nodes
* h = height of tree

---

## A. DFS (Recursive)

| Case                 | Time | Space    |
| -------------------- | ---- | -------- |
| Best (balanced tree) | O(n) | O(log n) |
| Worst (skewed tree)  | O(n) | O(n)     |

Space due to recursion stack.

---

## B. DFS (Iterative)

| Case     | Time | Space    |
| -------- | ---- | -------- |
| Balanced | O(n) | O(log n) |
| Skewed   | O(n) | O(n)     |

Space used by explicit stack.

---

## C. BFS (Using Queue)

| Case     | Time | Space |
| -------- | ---- | ----- |
| Balanced | O(n) | O(n)  |
| Skewed   | O(n) | O(n)  |

Queue may store up to n/2 nodes at last level.

---

## D. Naive Recursive BFS

| Case     | Time       | Space |
| -------- | ---------- | ----- |
| Balanced | O(n log n) |       |
| Skewed   | O(n²)      |       |

Because height ≈ n.

---

## Problems based on Binary Tree