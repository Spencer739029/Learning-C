#include <stdio.h>
#include <stdlib.h>

/* 
 * Node structure definition for a singly linked list
 * - val: stores the integer value in this node
 * - next: pointer to the next node in the list (NULL if this is the last node)
 */
typedef struct node {
    int val;
    struct node * next;
} node_t;

/*
 * print_list: Traverses and prints all values in the linked list
 * Parameter: head - pointer to the first node of the list
 * Concept: We iterate through the list by following the 'next' pointers
 */
void print_list(node_t * head) {
    node_t * current = head;

    // Continue until we reach the end of the list (NULL)
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;  // Move to the next node
    }
}

/*
 * push_end: Adds a new node with the given value at the end of the list
 * Parameters:
 *   - head: pointer to the first node (list must have at least one node)
 *   - val: value to store in the new node
 * Concept: Traverse to the last node, then allocate and link a new node
 */
void push_end(node_t * head, int val) {
    node_t * current = head;
    
    // Traverse to the last node (where next is NULL)
    while (current->next != NULL) {
        current = current->next;
    }

    // Allocate memory for the new node
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;  // This is now the last node
}

/*
 * push_start: Adds a new node at the beginning of the list
 * Parameters:
 *   - head: pointer to pointer (double pointer) to modify the head itself
 *   - val: value to store in the new node
 * Concept: We use double pointer (**head) because we need to change where
 *          the head pointer points (not just the data it points to)
 */
void push_start(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;  // New node points to the old head
    *head = new_node;        // Update head to point to the new node
}

/*
 * pop_remove_first: Removes and returns the first node's value
 * Parameter: head - double pointer to modify the head pointer
 * Returns: value of the removed node, or -1 if list is empty
 * Concept: Save the value, update head to point to second node, free old head
 */
int pop_remove_first(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    // Check if list is empty
    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;  // Save pointer to second node
    retval = (*head)->val;       // Save the value to return
    free(*head);                 // Free the memory of the first node
    *head = next_node;           // Update head to point to second node

    return retval;
}

/*
 * remove_last: Removes and returns the last node's value
 * Parameter: head - pointer to the first node
 * Returns: value of the removed node
 * Concept: Find the second-to-last node, free the last node, update pointers
 * Note: This function has a bug - doesn't handle single-node list properly
 *       (would leave head pointing to freed memory)
 */
int remove_last(node_t * head) {
    int retval = 0;
    
    // Special case: only one node in the list
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    // Traverse to the second-to-last node
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Remove the last node
    retval = current->next->val;
    free(current->next);
    current->next = NULL;  // Second-to-last node is now the last
    return retval;
}

/*
 * remove_by_index: Removes a node at a specific position (0-indexed)
 * Parameters:
 *   - head: double pointer to the list head
 *   - n: index of the node to remove (0 is the first node)
 * Returns: value of the removed node, or -1 if index is out of bounds
 * Concept: Traverse to the node BEFORE the target, then bypass and free target
 */
int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    // Special case: removing the first node
    if (n == 0) {
        return pop_remove_first(head);  // Reuse the pop function
    }

    // Traverse to the (n-1)th node (one before the target)
    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;  // Index out of bounds
        }
        current = current->next;
    }

    // Check if the target node exists
    if (current->next == NULL) {
        return -1;  // Index out of bounds
    }

    // Remove the node at index n
    temp_node = current->next;           // Save pointer to node to delete
    retval = temp_node->val;             // Save its value
    current->next = temp_node->next;     // Bypass the node (link around it)
    free(temp_node);                     // Free the memory

    return retval;
}

/*
 * Main function demonstrating basic linked list creation
 * Creates a simple 2-node list with values 1 and 2
 */
int main() {
    node_t * head = NULL;
    
    // Allocate the first node
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;  // Memory allocation failed
    }

    // Initialize first node
    head->val = 1;
    
    // Allocate and initialize second node
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;  // Mark end of list
    
    // Demonstrate the list operations
    printf("Initial list:\n");
    print_list(head);
    
    // Add to the end
    push_end(head, 3);
    printf("\nAfter push_end(3):\n");
    print_list(head);
    
    // Add to the start
    push_start(&head, 0);
    printf("\nAfter push_start(0):\n");
    print_list(head);
    
    // Remove first element
    int removed = pop_remove_first(&head);
    printf("\nAfter pop_remove_first() [removed %d]:\n", removed);
    print_list(head);
    
    // Remove by index
    removed = remove_by_index(&head, 1);
    printf("\nAfter remove_by_index(1) [removed %d]:\n", removed);
    print_list(head);
    
    // Clean up remaining nodes
    while (head != NULL) {
        pop_remove_first(&head);
    }
    
    printf("\nDone!\n");
    return 0;
}