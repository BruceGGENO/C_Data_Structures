#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insert_at_end(Node *head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    Node **current = &head;
    while (*current != NULL)
    {
        current = &((*current)->next);
    }
    *current = new_node;
    return head;
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    printf("Inserting values at end: ");
    for (int i = 1; i <= 5; i++)
    {
        head = insert_at_end(head, i * 10);
        printf("%d ", i * 10);
    }

    printf("\nFinal linked list: ");
    print_list(head);

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