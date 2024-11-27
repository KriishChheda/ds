#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
// every node of a binary search tree will have three components : 2 pointers and a data field
// one address to the left child , one address to the right child

struct node *insert(struct node *tree);
struct node *search(struct node *tree, int val);
void inorder(struct node *tree);
void postorder(struct node *tree);
void preorder(struct node *tree);
struct node *findingMinValue(struct node *tree);
int findingMaxValue(struct node *tree);
void deleteTree(struct node *tree);
struct node *delete(struct node *root, int val);

void main()
{
    struct node *min;
    int max, val;
    struct node *tree = NULL;
    struct node *searchptr = NULL;
    int choice;
    do
    {
        printf("\n-----BinarySearchTree-----\n");
        printf("\n1]Insert");
        printf("\n2]Search");
        printf("\n3]Max value");
        printf("\n4]Min value");
        printf("\n5]Preorder");
        printf("\n6]Postorder");
        printf("\n7]Inorder");
        printf("\n8]Delete Tree");
        printf("\n9]Delete node");
        printf("\n10]exit");
        printf("\nEnter your choice\n");
        printf("\n-------------------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tree = insert(tree);
            break;

        case 2:
            printf("Enter the data value of the node which you want to find\n");
            scanf("%d", &val);
            searchptr = search(tree, val);
            printf("The address of the node is : %p", searchptr);
            break;

        case 3:
            max = findingMaxValue(tree);
            printf("Max value: %d", max);
            break;

        case 4:

            min = findingMinValue(tree);
            break;

        case 5:
            preorder(tree);
            break;

        case 6:
            postorder(tree);
            break;

        case 7:
            inorder(tree);
            break;

        case 8:
            deleteTree(tree);
            break;

        case 9:
            printf("Enter the data value of the node to be deleted:");
            scanf("%d", &val);
            tree = delete (tree, val);
            break;
        }
    } while (choice != 10);
}

// we will pass the address of the root node of the tree
struct node *insert(struct node *tree)
{

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    int val;
    printf("Enter the data to be stored in the new node\n");
    scanf("%d", &val);

    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    // new node is always inserted as a leaf node
    // our new node is ready to be inserted

    struct node *nodeptr, *parentptr;
    parentptr = NULL;
    nodeptr = tree;

    if (tree == NULL)
    {
        // the tree is empty and has no nodes (FIRST INSERTION)
        tree = ptr;
    }

    // else will run for all insertions except of the first one
    else
    {
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        // after the execution of this while loop nodeptr points to NULL and parentptr points to the node whose child is going to be the new node

        if (val < parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}

// we will pass the address of the root node of the tree and the data value to be searched for
// in further iterations tree will contain the address of the root nodes of subtrees
struct node *search(struct node *tree, int val)
{

    if ((tree == NULL) || (tree->data == val))
    {
        return tree;
    }
    else if (val < tree->data)
    {
        return search(tree->left, val);
    }
    else
    {
        return search(tree->right, val);
    }
}
// the search function returns the address of the node we're trying to find

// will give the address of the root node to tree
void preorder(struct node *tree)
{
    struct node *temp;
    temp = tree;

    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *tree)
{
    struct node *temp;
    temp = tree;

    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void inorder(struct node *tree)
{
    struct node *temp;
    temp = tree;

    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

// preorder , postorder , inorder are three display functions used to display the value of each node once in a systematic manner
struct node *findingMinValue(struct node *tree)
{
    if ((tree == NULL) || (tree->left == NULL))
    {
        return tree;
    }
    else
    {
        return findingMinValue(tree->left);
    }
}
int findingMaxValue(struct node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
    {
        if (tree == NULL)
        {
            printf("tree is empty");
            return 0;
        }
        else
        {
            return tree->data;
        }
    }
    else
    {
        return findingMaxValue(tree->right);
    }
}

void deleteTree(struct node *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}
// first we are deleting the left subtree , then we are deleting the right subtree

struct node *delete(struct node *root, int val)
{
    struct node *temp;
    if (root == NULL)
    {
        printf("Tree is empty");
        return root;
    }
    else if (val < root->data)
    {
        root->left = delete (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete (root->right, val);
    }
    else
    {

        if ((root->left == NULL) && (root->right == NULL))
        {
            free(root);
            return NULL;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            temp = findingMinValue(root->right);
            root->data = temp->data;
            root->right = delete (root->right, root->data);
        }
    }
    return root;
}