# Data Structures Assignment 2

## Organisational Hierarchy and Department Searching

### Student
**Name:** Emil Saji

### Assignment Topic

A company has the following organisational hierarchy:

CEO → HR, Finance, IT

IT → Development, Testing

Development → Frontend, Backend

The assignment involves representing the hierarchy using a suitable tree structure and comparing Linear Search and Binary Search for locating departments.

---

## 1. Problem Statement

The organisational hierarchy of a company needs to be represented using a tree data structure.

The program should:

1. Construct the organisational hierarchy.
2. Display the hierarchy using Level-Order Traversal.
3. Store department names in a searchable representation.
4. Compare Linear Search and Binary Search.
5. Record the number of comparisons for at least three searches.
6. Analyse tree height, traversal behaviour, time complexity and space complexity.
7. Determine the suitability of the selected data structures and algorithms.

---

## 2. Tree Representation

A **General Tree using Child-Sibling Representation** is used.

The hierarchy is:

```text
CEO
├── HR
├── Finance
└── IT
    ├── Development
    │   ├── Frontend
    │   └── Backend
    └── Testing
