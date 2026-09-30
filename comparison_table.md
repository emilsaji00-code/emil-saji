# Comparison Table

## 1. Linear Search vs Binary Search

| Department | Linear Search Comparisons | Binary Search Comparisons |
|------------|---------------------------|---------------------------|
| IT         | 7                         | 3                         |
| Backend    | 1                         | 3                         |
| Testing    | 8                         | 4                         |

---

## 2. Operation Complexity Comparison

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Tree Construction | O(n) | O(n) |
| Level-Order Traversal | O(n) | O(n) |
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |

---

## 3. Tree Representation Comparison

| Feature | General Tree - Child-Sibling |
|---------|------------------------------|
| Represents hierarchy | Yes |
| Supports multiple children | Yes |
| Level-order traversal | Yes |
| Suitable for organisation hierarchy | Yes |
| Search department names directly | No |
| Requires separate searchable representation | Yes |

---

## 4. Summary

The General Tree with Child-Sibling representation is used to represent the organisational hierarchy.

Level-order traversal displays all departments level by level.

For department searching, the department names are stored in a sorted array. Linear Search checks elements sequentially, whereas Binary Search repeatedly divides the search range into two halves.

Binary Search has better asymptotic search performance for a sorted and relatively stable department list.
