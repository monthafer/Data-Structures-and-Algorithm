# CSC121: Data Structures and Algorithms (C++ Implementations)

Welcome to my personal implementations of core data structures and algorithms developed as part of the **CSC121: Data Structures and Algorithm** course curriculum. This repository showcases a comprehensive, evolutionary progression from basic models (like Points and Lists) to complex structures (AVL Trees) and interactive terminal applications.

## Repository Structure

The project is structured into modular directories corresponding to the progression of topics, along with a fallback test environment:

| Directory | Description | Key Modules / Files |
| :--- | :--- | :--- |
| **`1. Point`** | 2D Coordinate geometry models and operator overloading. | `Point 1.0` to `Point 1.3` (progressive updates) |
| **`2. List`** | Fixed-capacity and dynamically resizable cursor-based lists. | `List 1.0` (static) & `List 1.1` (dynamic) |
| **`3. String`** | A custom implementation of a string class with dynamic allocation. | `MyString v0.1` to `v2 (Final)` |
| **`4. Linked List`** | Single (SLL) and Double (DLL) Linked Lists. | `LinkedList v1.0` to `v1.2`, list toolkit, sorting & reversing |
| **`5. Stack`** | Array-based and Linked-List-based template stacks. | `arraystack.cpp`, `liststack.cpp`, Hanoi puzzle visualizer |
| **`6. Queue`** | Deque, Priority Queue, and standard circular queue. | Palindrome checker, Washer (laundromat simulation) |
| **`7. Tree`** | Binary Trees and self-balancing AVL Trees. | Standard traversals, Tree printing, Animal Guessing Game |
| **`Run here if doesn't work`** | Consolidated files to test and run programs easily. | Flattened folder containing test programs with absolute inclusions |

---

## Detailed Module Breakdown

### 1. Point (2D Cartesian Coordinates)
*   **Version History:** `Point 1.0` -> `Point 1.3`
*   **Key Features:**
    *   Transitioned coordinates from integer types (`int`) to high-precision double-precision floats (`double`).
    *   Operator overloading for assignment (`=`), incrementation (`++`), scalar multiplication (`*`), and standard stream input/output (`>>` & `<<`).
    *   Distance calculation using the Euclidean distance formula.

### 2. Cursor-Based List
*   **Version History:** `List 0.1 (betas)` -> `List 1.1`
*   **Key Features:**
    *   **List 1.0:** Implements a cursor-driven list with a static `CAPACITY = 20` array. Supported actions include cursor navigation (`start()`, `advance()`), insertion, attachment, and deletion.
    *   **List 1.1:** Upgraded to a dynamically resizable array (`value_type* data`). Includes automatic resizing on overflow (`resize()`).

### 3. Custom String (MyString)
*   **Version History:** `MyString v0.1` -> `MyString v2 (Final)`
*   **Key Features:**
    *   Complete custom alternative to `std::string` utilizing dynamic character array allocation.
    *   Operator overloads for concatenation (`+`, `+=`), equality comparisons (`==`, `!=`, `<`, `>`, `<=`, `>=`), and standard I/O streams.
    *   Rich text manipulation methods: `to_lowercase()`, `to_uppercase()`, `substring()`, `insert()`, search/replace, and delete character operations.
    *   Custom `getline` input processing with configurable delimiters.

### 4. Linked List (Single & Double)
*   **Version History:** `LinkedList v1.0` -> `LinkedList v1.2`
*   **Key Features:**
    *   **SingleLinkedList:** Fully functional singly linked list with structural utilities such as custom list reversal (`reverseList()`) and sorting (`applySort()`).
    *   **DoubleLinkedList:** Doubly linked list tracking both `headPtr` and `tailPtr` supporting bidirectional traversals.
    *   Modular `linkedlisttoolkit` containing boilerplate node management and pointer manipulation tasks.

### 5. Stack
*   **Key Features:**
    *   Template implementations of both Array-based (`ArrayStack`) and Linked-List-based (`ListStack`) stacks.
    *   **Application - Tower of Hanoi:** An interactive CLI game simulating the classic Tower of Hanoi puzzle. Features an ASCII art renderer that visually draws the towers and rings dynamically inside the console.

### 6. Queue
*   **Key Features:**
    *   Circular queues (`Queue`), Double-Ended Queues (`Deque`), and Priority Queues (`PriorityQueue`).
    *   **Application - Laundromat Simulator (Washer):** A discrete-event queuing simulation representing customer arrivals, queue waiting times, and washer occupancy using probabilistic models.
    *   **Application - Palindrome Checkers:** Validates string palindromes using combined stack and queue structures.

### 7. Tree
*   **Key Features:**
    *   **Binary Tree Node (`bnode`):** Recursive utilities for measuring tree sizes, deep copying, and tree cleaning.
    *   **Binary Tree Traversals:** Generic pre-order, in-order, and post-order traversals parameterized by custom processing functions.
    *   **AVL Tree (`AVLTree`):** A self-balancing binary search tree. Automatically performs left/right rotations to maintain the AVL height balance property during insertions and deletions.
    *   **Application - Animal Guessing Game:** A decision-tree guessing game that interacts with the user. If it fails to guess the correct animal, it prompts the user for a distinguishing question and dynamically learns/expands the taxonomy tree at runtime.

---

## Applications & Demos

### 1. Interactive Tower of Hanoi
Located in `5. Stack/hanoi.cpp`. The program displays real-time ASCII illustrations of the rods and rings:
```text
      |            |            |      
     _|_          _|_          _|_     
    __|__        | | |        | | |    
   ___|___       | | |        | | |    
   Tower 1      Tower 2      Tower 3   
```
Run the program, select the number of rings, and enter rod numbers (e.g., from `1` to `3`) to solve the puzzle.

### 2. Akinator-Style Guessing Game
Located in `7. Tree/animal.cpp`. Run the program, think of an animal, and let the binary decision tree guess it. When it makes a mistake, teach it a new question to construct a larger knowledge base.

---

## Compilation & Run Guide

### Standard Compilation
Each folder has corresponding driver/test files (e.g. `stest.cpp`, `avltreetest.cpp`, `testqueue.cpp`). You can compile them using standard `g++` compiler commands:

```bash
# Example: Compiling the AVL Tree test
g++ -std=c++11 -o avltreetest "7. Tree/avltreetest.cpp"
./avltreetest
```

### Fallback Run Directory
If you encounter linking or header path resolution errors due to nested structures, navigate to the **`Run here if doesn't work`** folder. This folder has a flattened structure where source files and test headers are consolidated to simplify compilation:

```bash
cd "Run here if doesn't work/Tree"
g++ -std=c++11 -o avl_test avltreetest.cpp
./avl_test
```

---

## 🎓 Academic Info
*   **Course:** CSC121: Data Structures and Algorithm
*   **Language:** C++ (C++11 or higher recommended)
*   **Implementation Style:** Focuses on standard pointer manipulation, manual memory management (rule of three), template utility, and dynamic array resizing.
