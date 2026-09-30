#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

/* Node for a General Tree using Child-Sibling Representation */
typedef struct Node {
    char name[30];
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;

/* Create a new node */
Node* createNode(const char *name) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->name, name);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

/* Add a child to a parent node */
void addChild(Node *parent, Node *child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node *temp = parent->firstChild;

        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }

        temp->nextSibling = child;
    }
}

/* Level-order traversal */
void levelOrder(Node *root) {
    if (root == NULL)
        return;

    Node *queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("\nLevel-order traversal:\n");

    while (front < rear) {
        Node *current = queue[front++];

        printf("%s ", current->name);

        Node *child = current->firstChild;

        while (child != NULL) {
            queue[rear++] = child;
            child = child->nextSibling;
        }
    }

    printf("\n");
}

/* Find height of the tree */
int treeHeight(Node *root) {
    if (root == NULL)
        return -1;

    int maxHeight = -1;
    Node *child = root->firstChild;

    while (child != NULL) {
        int h = treeHeight(child);

        if (h > maxHeight)
            maxHeight = h;

        child = child->nextSibling;
    }

    return maxHeight + 1;
}

/* Linear Search */
int linearSearch(char departments[][30], int n, char target[], int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (strcmp(departments[i], target) == 0)
            return i;
    }

    return -1;
}

/* Binary Search */
int binarySearch(char departments[][30], int n, char target[], int *comparisons) {
    int low = 0;
    int high = n - 1;

    *comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        (*comparisons)++;

        int result = strcmp(departments[mid], target);

        if (result == 0)
            return mid;
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {

    /* ------------------------------------------------
       PART A: Construct the Organisation Tree
       ------------------------------------------------ */

    Node *CEO = createNode("CEO");

    Node *HR = createNode("HR");
    Node *Finance = createNode("Finance");
    Node *IT = createNode("IT");

    Node *Development = createNode("Development");
    Node *Testing = createNode("Testing");

    Node *Frontend = createNode("Frontend");
    Node *Backend = createNode("Backend");

    /* CEO -> HR, Finance, IT */
    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);

    /* IT -> Development, Testing */
    addChild(IT, Development);
    addChild(IT, Testing);

    /* Development -> Frontend, Backend */
    addChild(Development, Frontend);
    addChild(Development, Backend);

    /* Display hierarchy */
    printf("ORGANISATIONAL HIERARCHY\n");
    printf("------------------------\n");

    printf("CEO\n");
    printf("|-- HR\n");
    printf("|-- Finance\n");
    printf("|-- IT\n");
    printf("    |-- Development\n");
    printf("    |   |-- Frontend\n");
    printf("    |   |-- Backend\n");
    printf("    |-- Testing\n");

    /* Level-order traversal */
    levelOrder(CEO);

    /* Tree height */
    printf("\nTree height = %d edges\n", treeHeight(CEO));
    printf("Number of levels = %d\n", treeHeight(CEO) + 1);


    /* ------------------------------------------------
       PART B: Linear Search vs Binary Search
       ------------------------------------------------ */

    char departments[][30] = {
        "Backend",
        "CEO",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };

    int n = 8;

    char searches[3][30] = {
        "IT",
        "Backend",
        "Testing"
    };

    printf("\nSEARCH COMPARISON\n");
    printf("-----------------\n");

    printf("\n%-15s %-20s %-20s\n",
           "Department",
           "Linear Comparisons",
           "Binary Comparisons");

    printf("--------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {

        int linearComparisons;
        int binaryComparisons;

        int linearResult = linearSearch(
            departments,
            n,
            searches[i],
            &linearComparisons
        );

        int binaryResult = binarySearch(
            departments,
            n,
            searches[i],
            &binaryComparisons
        );

        printf("%-15s %-20d %-20d\n",
               searches[i],
               linearComparisons,
               binaryComparisons);

        if (linearResult != -1)
            printf("  Linear Search: Department found\n");

        if (binaryResult != -1)
            printf("  Binary Search: Department found\n");
    }

    return 0;
}
