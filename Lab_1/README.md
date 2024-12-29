# Lab 1 Unsorted List Implementation Using Arrays

This lab demonstrates the implementation of an unsorted list using arrays in C++. It includes creating, managing, and manipulating a collection of items stored in an array. The implementation supports operations such as insertion, deletion, splitting, and retrieving items.

## Features

- **ItemType Class:** Represents an individual item in the list with functionality to compare, print, and initialize values.
- **UnsortedListByArray Class:** Manages the list of ItemType objects with various operations, including:
  - Insert items.
  - Delete individual or all occurrences of an item.
  - Retrieve items.
  - Split the list into two based on a comparison value.
- **User Interaction:** Allows the user to input and manage a sequence of strings, showcasing various functionalities.

## Project Structure

```plaintext
├── ItemType.h
├── Lab1
├── Lab1.cpp
├── UnsortedListByArray.cpp
└── UnsortedListByArray.h
```

## Setup Instructions

1. Make sure that you are in the `Lab_1` directory.

2. To run the program, follow these steps:

  - Open a terminal and compile all the `.cpp` files together using a C++ compiler (e.g., `g++`).:
    ```bash
    g++ UnsortedListByArray.cpp Lab1.cpp -o Lab1
    ```
  - Execute the compiled program:
    ```bash
    ./Lab1
    ```
