#include <stdio.h>
#include <stdlib.h>
struct node *MinValue(struct node *node);

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("%d Cannot be inserted in bst", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node *BSTSearch(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    else if (root->data > key)
        return BSTSearch(root->left, key);

    else
        return BSTSearch(root->right, key);
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value > root->data)
        root->right = deleteNode(root->right, value);

    else if (value < root->data)
        root->left = deleteNode(root->left, value);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return root;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return root;
        }

        struct node *temp = MinValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct node *MinValue(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

int main()
{


    /* Let us create following BST
          50
       /     \
      30      70
     /  \    /  \
   20   40  60   80 */


    struct node *p = createNode(50);
    struct node *p1 = createNode(30);
    struct node *p2 = createNode(70);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(40);
    struct node *p5 = createNode(60);
    struct node *p6 = createNode(80);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    printf("Inorder traversal of the given tree \n");
    inorder(p);

    printf("\nDelete 20\n");
    p = deleteNode(p, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(p);

    struct node *n = BSTSearch(p, 80);
    if (n != NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("Element not found");
    }

    printf("\nInsert 20\n");
    insert(p, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(p);

    return 0;
}