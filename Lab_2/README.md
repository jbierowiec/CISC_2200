# Lab 2 Sorted and Unsorted Lists with Arrays

This project implements data structures for managing collections of items using arrays. The code includes functionality for both sorted and unsorted lists, allowing insertion, deletion, retrieval, and merging operations. It provides a hands-on demonstration of managing data with manual array manipulations.

## Features

- **Item Management:**
  - Insert, delete, and retrieve items efficiently.
  - Support for maintaining sorted order.
- **List Operations:**
  - Merge unsorted lists into a sorted list.
  - Split lists based on comparison criteria.
  - Remove duplicate items from lists.
- **Iteration:**
  - Supports sequential access to items through `ResetList` and `GetNextItem`.

## Project Structure

```plaintext
├── ItemType.h
├── Lab2
├── Lab2.cpp
├── SortedListByArray.cpp
├── SortedListByArray.h
├── UnsortedListByArray.cpp
└── UnsortedListByArray.h
```

## Setup Instructions

1. Make sure that you are in the `Lab_2` directory.

2. To run the program, follow these steps:

  - Open a terminal and compile all the `.cpp` files together using a C++ compiler (e.g., `g++`).:
    ```bash
    g++ SortedListByArray.cpp UnsortedListByArray.cpp Lab2.cpp -o Lab2
    ```
  - Execute the compiled program:
    ```bash
    ./Lab2
    ```
