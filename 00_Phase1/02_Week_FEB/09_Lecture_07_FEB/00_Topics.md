# Recursion

---

### 1. What is Recursion?

Recursion is a programming and mathematical technique where a function calls itsel
- to solve a problem by breaking it down into smaller sub-problems.

- It requires a base case to terminate the recursion and avoid infinite loops, alongside a recursive case that moves closer to the solution. 


Key Aspects of Recursion

- Base Case: The condition that stops the function from calling itself, preventing infinite recursion.

- Recursive Case: The part of the function where it calls itself with a modified, smaller input.

- Call Stack: Recursive functions use the stack memory, where each call is added, and it unwinds once the base case is reached.
---

### 2. Structure of a Recursive Function

#### a) Base Case

* Stopping condition
* Prevents infinite recursion
* Must guarantee termination

#### b) Recursive Case

* The part where function calls itself
* Moves toward base case

---

### 3. Decision Making in Recursion

* Identifying choices at each step
* Making a decision before recursive call
* OR making a decision after recursive call
* Understanding single recursive call vs multiple recursive calls

---

### 4. Input Size Reduction Logic

* How input shrinks in every call
* `n → n-1` pattern
* `n → n/2` pattern

> After every recursive call, problem size must move closer to base case.

---

### 5. Normal Function Call Stack

* How functions are pushed into stack
* LIFO execution model
* Stack frame creation and destruction

---

### 6. Recursive Function Call Stack

* Multiple stack frames of the same function
* Each call has its own:
  * Local variables
  * Parameters
  * Return address
* Memory growth during deep recursion

---

### 7. Recursive Execution Flow

* Forward phase (going deeper)
* When code runs:

  * Before recursive call
  * After recursive call

---

### 8. Recursive Tree (Visualization Method)

* Representing recursive calls as tree
* Single-branch recursion (linear recursion)
* Two-branch recursion (binary recursion)

---

### 9. Dry Run Techniques

* Stack simulation method
* Tree drawing method
* Tracing return values bottom-up

---

### 10. Common Recursion Patterns Introduced

* Printing numbers (1 to N, N to 1)
* Sum of first N numbers
* Fibonacci (for tree understanding, not for optimal solution)

---

### 11. Common Mistakes Explained

* Missing base case
* Wrong base condition
* Infinite recursion
* Stack overflow
* Not reducing input size properly

---