# Product ID Tracker

This project is a C implementation of a **Product ID Tracking System** using a **Binary Search Tree (BST)** and a **Hash Table**.
It supports insertion, deletion, and neighbor querying of product IDs through a command-based input system.

---

## 📁 Files Included

| File Name         | Description |
|-------------------|-------------|
| `main.c`          | Main program: reads input operations and handles insertion, deletion, and querying |
| `myBST.c/h`       | BST implementation: contains logic for insert, delete, find, predecessor/successor |
| `myHashTable.c/h` | Hash Table implementation using separate chaining for quick lookup |

---

## 🛠️ Features

- **Insert** a new product ID (`I`)
- **Delete** a product ID (`D`)
- **Check and find neighbors** (`C`): if an ID exists, prints up to `K=5` predecessors and successors
- Efficient lookup using a hash table
- Ordered traversal support using a BST

---

## 📦 Compilation

gcc main.c myBST.c myHashTable.c -o product_tracker

▶️ Usage
You can run the program and provide input in the format:

<ID>,<Operation>

Example Input:

10,I
20,I
15,I
10,C
15,D
15,C

Meaning:

Insert 10

Insert 20

Insert 15

Check if 10 exists and print neighbors

Delete 15

Check if 15 exists (should return "N")

✅ Sample Output:

Y
15,20
Y
N

📚 Requirements
GCC (GNU Compiler Collection)

Compatible with Windows/Linux

Course Information:

Course: Data Structures & Applications

Program: B.Tech in Computational Engineering

Institute: Indian Institute of Technology Hyderabad

Student ID: CO23BTECH11008

This project is part of academic coursework and is intended for educational and learning purposes.