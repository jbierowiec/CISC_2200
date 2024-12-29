# Project Infix to Postfix Conversion and Evaluation

This program provides a complete implementation for converting mathematical expressions from infix notation to postfix notation and evaluating them. It ensures syntactical correctness of the input expression and supports error handling for invalid inputs, including mismatched parentheses, improper operator placement, and division by zero.

## Features

- **Infix to Postfix Conversion:**
  - Converts an infix expression to postfix notation using a stack.
  - Ensures the correct precedence and associativity of operators.
- **Postfix Expression Evaluation:**
  - Evaluates a postfix expression using a stack.
  - Handles all common arithmetic operators (`+`, `-`, `*`, `/`, `^`).
- **Error Handling:**
  - Detects and handles mismatched parentheses, invalid syntax, and division by zero.
- **Interactive User Input:**
  - Prompts the user to input an infix expression and displays the postfix equivalent and its result.

## Project Structure

```plaintext
├── project
└── project.cpp
```

## Setup Instructions

1. Make sure that you are in the `Project` directory.

2. To run the program, follow these steps:

  - Open a terminal and compile all the `.cpp` files together using a C++ compiler (e.g., `g++`).:
    ```bash
    g++ project.cpp -o project
    ```
  - Execute the compiled program:
    ```bash
    ./project
    ```
