# Contact Management System

A simple, console-based mini-project implemented in C using singly linked lists. Developed as part of a Data Structures coursework assignment.

## 📌 Project Objective

The objective of this project is to apply fundamental data structures concepts—specifically dynamic memory allocation and linear linked lists—to create a functional, menu-driven command-line application that manages a directory of contacts.

## 🚀 Features

- **Add Contact:** Dynamically adds a new contact (name and phone number) to the end of the list.
- **Display Contacts:** Iterates through the linked list to display all stored contacts sequentially.
- **Search Contact:** Performs a linear search by name to find and display specific contact details.
- **Delete Contact:** Safely removes a contact node from the list and frees the allocated memory.

## 🧠 Data Structure Used

### Singly Linked List

Unlike fixed-size arrays, a linked list allows the contact list to grow and shrink dynamically at runtime. Each node contains a `struct Contact` holding the user's data (name and phone number) and a pointer (`next`) referencing the memory address of the next contact node.
