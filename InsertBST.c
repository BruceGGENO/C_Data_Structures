#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *bst_insert_node(TreeNode *root, int value)
{
    if (root == NULL)
    {
        TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (value < root->data)
    {
        root->left = bst_insert_node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = bst_insert_node(root->right, value);
    }
    return root;
}

void inorder_print(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

int main()
{
    TreeNode *root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting values: ");
    for (int i = 0; i < n; i++)
    {
        root = bst_insert_node(root, values[i]);
        printf("%d ", values[i]);
    }

    printf("\nInorder traversal of BST: ");
    inorder_print(root);
    printf("\n");

    // Free memory (simplified - would need full traversal in practice)
    return 0;
}