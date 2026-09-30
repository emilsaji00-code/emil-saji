# Complexity Analysis

## 1. Tree Representation

The organisational hierarchy is represented using a General Tree with the Child-Sibling representation.

Each node contains:
- Department name
- Pointer to its first child
- Pointer to its next sibling

This representation allows a node to have any number of children.

---

## 2. Tree Height

The organisational hierarchy contains four levels:

Level 1: CEO

Level 2: HR, Finance, IT

Level 3: Development, Testing

Level 4: Frontend, Backend

Therefore:

- Number of levels = 4
- Tree height = 3 edges

The height is calculated as the maximum number of edges from the root node to a leaf node.

---

## 3. Level-Order Traversal

Level-order traversal visits the nodes level by level from top to bottom.

Traversal obtained:

CEO HR Finance IT Development Testing Frontend Backend

A queue is used to store nodes that have to be visited.

### Time Complexity

For n nodes, every node is visited once.

Time complexity = O(n)

For this organisation:

n = 8

Therefore, all 8 nodes are visited once.

### Space Complexity

A queue is used during traversal.

Worst-case space complexity = O(n)

---

## 4. Linear Search

The department names are stored in an array.

Linear Search checks each department sequentially until the required department is found.

### Time Complexity

Best case = O(1)

Average case = O(n)

Worst case = O(n)

### Space Complexity

No additional data structure is required.

Space complexity = O(1)

---

## 5. Binary Search

The department names are stored in sorted alphabetical order:

Backend, CEO, Development, Finance, Frontend, HR, IT, Testing

Binary Search repeatedly divides the search range into two halves.

### Time Complexity

Best case = O(1)

Average case = O(log n)

Worst case = O(log n)

### Space Complexity

The iterative implementation does not use recursion.

Space complexity = O(1)

---

## 6. Search Comparison

| Department | Linear Search Comparisons | Binary Search Comparisons |
|------------|---------------------------|---------------------------|
| IT         | 7                         | 3                         |
| Backend    | 1                         | 3                         |
| Testing    | 8                         | 4                         |

The number of comparisons depends on the position of the department in the array and the search method used.

Linear Search can locate an item immediately if it occurs near the beginning, but it may require checking many elements if the item occurs near the end.

Binary Search requires the data to be sorted, but it reduces the search range by half at every step.

---

## 7. Comparison of Operations

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Tree Construction | O(n) | O(n) |
| Level-Order Traversal | O(n) | O(n) |
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |

---

## 8. Suitability of the Representation

The General Tree using Child-Sibling representation is suitable for representing the organisational hierarchy because departments can have different numbers of sub-departments.

Level-order traversal is suitable for organisational reporting because it displays the hierarchy level by level, making the structure easy to understand.

For department searching, an alphabetically sorted array with Binary Search is suitable when searches are frequent and the department list does not change frequently.

If departments are frequently added or removed, maintaining the sorted array may require additional work. In such cases, other data structures may be considered.

---

## 9. Conclusion

The organisational hierarchy can be effectively represented using a General Tree with Child-Sibling representation. Level-order traversal provides a systematic way to display departments according to their organisational levels.

For searching departments, Linear Search has O(n) worst-case time complexity, while Binary Search has O(log n) worst-case time complexity when the data is sorted.

Therefore, the selected tree representation is suitable for organisational reporting, while a sorted array with Binary Search provides efficient department searching for a relatively stable list of departments.
