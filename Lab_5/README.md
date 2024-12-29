# Lab 5 Directed Weighted Graph Implementation

- **Adjacency Matrix (Array) Version:**
  - Under the `Array` directory, this project implements a directed weighted graph using an adjacency matrix with `arrays`. The `DirectedWeightedGraph` class provides functionality for adding and deleting vertices and edges, marking vertices, and performing breadth-first traversal. The graph operations are demonstrated in the main program (`Lab5.cpp`).
- **Adjacency List (Hash Table) Version:**
  - Under the `Hash_Table` directory, this project implements a directed weighted graph using an adjacency list with `unordered_map`. The `DirectedWeightedGraph` class provides functionality for adding and deleting vertices and edges, marking vertices, and performing breadth-first traversal. The graph operations are demonstrated in the main program (`Lab5.cpp`).

## Differences in Implementation 

| Feature                  | Adjacency Matrix                             | Adjacency List                              |
|--------------------------|----------------------------------------------|---------------------------------------------|
| **Data Structure**       | Fixed-size matrix with edge weights          | Dynamic `unordered_map` of adjacency lists  |
| **Memory Usage**         | Uses `O(V^2)` regardless of edge density     | Efficient for sparse graphs, uses `O(V + E)`|
| **Edge Operations**      | Requires `O(1)` for addition/deletion        | Slightly slower due to mapping overhead     |
| **Traversal Complexity** | Simple access with fixed indices             | More complex access with dynamic mapping    |
| **Scalability**          | Limited by pre-defined size                  | Dynamically scalable with memory            |
| **Code Complexity**      | Easier to implement due to fixed structure   | More complex due to dynamic management      |

## Features
- **Vertex Management:**
   - Add or remove vertices dynamically.
- **Edge Management:**
   - Add or remove directed edges with weights.
- **Traversal:**
   - Perform breadth-first traversal starting from a specific vertex.
- **Graph Inspection:**
   - Retrieve and print graph vertices and edges.
   - Retrieve the weight of a specific edge.

## Project Structure

```plaintext
├── Array
│   ├── DirectedWeightedGraph.cpp
│   ├── DirectedWeightedGraph.h
│   ├── ItemType.h
│   ├── Lab5
│   └── Lab5.cpp
└── Hash_Table
    ├── DirectedWeightedGraph.cpp
    ├── DirectedWeightedGraph.h
    ├── ItemType.h
    ├── Lab5
    └── Lab5.cpp
```

## Setup Instructions

1. Make sure that you are in the `Lab_5` directory.

2. To run either program, change into the Array or Hash_Table directories using `cd Array` or `cd Hash_Table`. Then follow these steps:

  - Open a terminal and compile all the `.cpp` files together using a C++ compiler (e.g., `g++`).:
    ```bash
    g++ DirectedWeightedGraph.cpp Lab5.cpp -o Lab5
    ```
  - Execute the compiled program:
    ```bash
    ./Lab5
    ```
