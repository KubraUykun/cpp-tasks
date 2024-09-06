# cpp-tasks
## Overview
This repository contains solutions to several programming tasks. Each task focuses on different aspects of coding, including performance optimization, linked list manipulation, template functions, file handling, and directory processing. The tasks are implemented in C++ and aim to test skills in algorithm design, data structures, and system programming.

Note: For some of the dependencies and features used, you should compile with C++17 or above.


## Task 1: Update Function
### Objective: 
Implement a function update that performs the following operations on two integers, a and b:
- Set a to the sum of a and b.
- Set b to the absolute difference between a and b.


## Task 2: Delete Node in Linked List
### Objective: 
Write a function delete_with_position that deletes the node at a specific position in a linked list.

### Linked List Definition:
```
struct Node {
    int data;
    struct Node *next;
};
```
### Instructions:
- Implement void delete_with_position(struct Node **head, int position).
- Ensure that the function handles edge cases, such as deleting the head node or handling invalid positions.


## Task 3: Find the Smallest Element
### Objective: 
Write a template function ```smallest``` to find the index of the smallest element in an array.
### Instructions:
- Implement a template function template <typename T> int smallest(const T* array, int length).
- The function should work with arrays of any data type.


## Task 4: Count Total Lines in Directory
### Objective: 
Implement a C++ program that counts the total number of lines in all text files within a given directory.

### Instructions:
- The program should efficiently utilize multiple CPU cores for processing.
- Handle text files within a specified directory and compute the total line count.


## Task 5: Find the Longest Word in a File
### Objective: 
Write a C++ program to find the longest word in a text file.

### Instructions:
- The program should take the path to the text file as a command-line argument.
- Output the longest word along with its length.
- The text file contains only alphabetical words separated by spaces and should be case-insensitive.
- How to Run:
  - Provide the input file path as a command-line argument when executing the program.

### Example:
```
./task5 sample.txt
```





