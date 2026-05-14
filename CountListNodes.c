#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int count_nodes(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    // Create linked list: 10 -> 20 -> 30 -> 40
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 10;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->data = 30;
    head->next->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    int count = count_nodes(head);
    printf("Number of nodes in linked list: %d\n", count);

    // Free memory
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}