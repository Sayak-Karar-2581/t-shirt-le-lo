#include <stdio.h>
#include <stdlib.h>

/* a node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

/* A utility function to swap two elements */
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// A utility function to find last node of linked list
struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

/* Considers the last element as pivot, places the pivot element at its
   correct position in a sorted array, and places all smaller (smaller than
   pivot) to the left of the pivot and all greater elements to right of pivot */
Node *partition(Node *l, Node *h)
{
    // set pivot as h element
    int x = h->data;

    // similar to i = l-1 for array implementation
    Node *i = l->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            // Similar to i++ for array
            i = (i == NULL) ? l : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}

/* A recursive implementation of quicksort for linked list */
void _quickSort(struct Node *l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

// The main function is to sort a linked list. It mainly calls _quickSort()
void quickSort(struct Node *head)
{
    // Find last node
    struct Node *h = lastNode(head);

    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(struct Node *head)
{
    while (head)
    {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = malloc(sizeof(Node)); // new Node;     /* allocate node */
    new_node->data = new_data;

    /* since we are adding at the begining, prev is always NULL */
    new_node->prev = NULL;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int main()
{
    struct Node *a = NULL;
    int data;
    char ch;
    /*  Performing tree operations  */
    do
    {
        printf("\nSelect one of the operations::");
        printf("\n1. To insert a new node in the Doubly Linked List.");
        printf("\n2. To display the nodes of the Doubly Linked List.");
        printf("\n3. To perform Quicksort on the Doubly Linked List.\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value of the node to be inserted\n");
            scanf("%d", &data);
            push(&a, data);
            break;
        case 2:
            printf("\nContents of the Doubly Linked List are::\n");
            printList(a);
            break;
        case 3:
            printf("\nQuicksort applied sucessfully on the Doubly Linked List.\n");
            quickSort(a);
            break;
        default:
            printf("Wrong Entry\n");
            break;
        }

        printf("\nDo you want to continue (Type y or n)\n");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    return 0;
}