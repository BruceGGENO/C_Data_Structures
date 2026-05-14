#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

TreeNode *create_node(int value)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int main()
{
    // Create a sample BST
    TreeNode *root = create_node(50);
    root->left = create_node(30);
    root->right = create_node(70);
    root->left->left = create_node(20);
    root->left->right = create_node(40);
    root->right->left = create_node(60);
    root->right->right = create_node(80);

    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");

    return 0;
}