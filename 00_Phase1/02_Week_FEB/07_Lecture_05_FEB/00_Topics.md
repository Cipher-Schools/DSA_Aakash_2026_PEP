# 📘 Topics

### 1. String Declaration Methods in C++

* String literal initialization

  ```cpp
  char str1[] = "aakash";
  ```
* Character array with explicit null terminator

  ```cpp
  char str2[] = {'a','a','k','a','s','h','\0'};
  ```
* Character array without null terminator (Undefined Behaviour)

  ```cpp
  char str3[] = {'a','a','k','a','s','h'};
  ```

---

### 2. Importance of Null Terminator (`'\0'`)

* How C-style strings end
* Why missing `'\0'` causes undefined behaviour
* How functions like `strlen`, `strcmp`, `strcpy`, `strcat` depend on it

---

### 3. `sizeof` vs `strlen`

* `sizeof()` → total allocated memory
* `strlen()` → number of characters before `'\0'`
* Difference between compile-time size and runtime length

---

### 4. Memory Layout of Character Arrays

* How characters are stored in contiguous memory
* Indexing and accessing last element
* Difference between last character and null character

---

### 5. Standard Library String Functions (`<cstring>`)

* `strlen()` – length calculation
* `strcmp()` – string comparison
* `strcpy()` – string copy
* `strcat()` – string concatenation

---

### 6. Buffer Size & Overflow Concepts

* Why destination array must be large enough
* Risks of overflow in `strcpy` and `strcat`
* Undefined behaviour when buffer size is insufficient

---

### 7. Undefined Behaviour in C-Style Strings

* Printing non-null-terminated arrays
* Using `strlen` on improper strings
* Copying/concatenating unsafe arrays

---

### 8. Transition Concept (Bridge to DSA)

* Why `std::string` is safer than `char[]`
* When low-level character arrays are still important
* Memory-level understanding before string-based problems

---

### Strings based questions