# Lab 4 Binary Search Tree Implementation

This project implements a binary search tree (BST) using the `TreeType` class. The BST supports insertion, deletion, traversal, swapping, and counting operations. The code provides functionality to test the BST with various operations, including ancestor identification and tree mirroring.

## Features

- **Insertion:**
   - Places new items in the correct position based on their value.
- **Deletion:**
   - Removes a node while maintaining BST properties.
- **Traversal:**
   - Supports in-order, pre-order, and post-order traversals.
- **Tree Mirroring (Swap):**
   - Creates a mirror image of the tree by swapping left and right children.
- **Leaf Counting:**
   - Counts nodes with no children.
- **Ancestor Identification:**
   - Prints all ancestors of a given item.

## Project Structure

```plaintext
├── ItemType.h
├── Lab4.cpp
├── Lab4
├── TreeType.cpp
└── TreeType.h
```

## Setup Instructions

1. Make sure that you are in the `Lab_4` directory.

2. To run the program, follow these steps:

  - Open a terminal and compile all the `.cpp` files together using a C++ compiler (e.g., `g++`).:
    ```bash
    g++ TreeType.cpp Lab4.cpp -o Lab4
    ```
  - Execute the compiled program:
    ```bash
    ./Lab4
    ```
