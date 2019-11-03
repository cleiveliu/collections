#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* code from stanfordcslib */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return newNode(data);
    else
    {
        if (root->data > data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        return root;
    }
}

struct node *build123()
{
    struct node *root;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    return root;
}

/*  how many items */
int size(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int maxDepth(struct node *root)
{
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    if (left > right)
        return 1 + left;
    else
        return 1 + right;
}

int minValue(struct node *root)
{
    assert(root); /*NULL shouldn't have a value*/
    if (root->left == NULL)
        return root->data;
    else
        return minValue(root->left);
}

int maxValue(struct node *root)
{
    assert(root); /*NULL shouldn't have a value*/
    if (root->right == NULL)
        return root->data;
    else
        return maxValue(root->right);
}

int maxValue_v2(struct node *root)
{
    assert(root); /*NULL shouldn't have a value*/
    for (; root->right != NULL; root = root->right)
        ;
    return root->data;
}

// Ascending order
void printTree(struct node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void printPostorder(struct node *root)
{
    if (root != NULL)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

int hasPathSum(struct node *root, int sum)
{
    if (root == NULL)
        return 0;
    int newSum = sum - root->data;
    if (root->left == NULL && root->right == NULL)
        return (newSum == 0);
    else
        return (hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum));
}

/* exchange nodes */
void mirror(struct node *root)
{
    if (root == NULL)
        return;

    mirror(root->left);
    mirror(root->right);

    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int sameTree(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;
    else if (a == NULL || b == NULL)
        return 0;
    else
        return (sameTree(a->left, b->left) && sameTree(a->right, b->right));
}

int countTrees(int n)
{
    /* 1 to Nth combinations */
    if (n <= 1)
        return 1;
    else
    {
        int sum = 0;
        for (int root = 1; root <= n; root++)
        {
            int right = countTrees(root - 1);
            int left = countTrees(n - root);
            sum += right * left;
        }
        return sum;
    }
}

int isBST(struct node *root)
{
    if (root == 0)
        return 1;
    else if ((root->left == 0 || minValue(root) <= root->data) && (root->right == 0 || maxValue(root) > root->data))
    {
        return isBST(root->left) && isBST(root->right);
    }
    else
        return 0;
}

int isBSTrecur(struct node *node, int min, int max)
{
    if (node == 0)
        return 1;
    else if (min > node->data || node->data > max)
        return 0;
    else
        return isBSTrecur(node->left, min, node->data) && isBSTrecur(node->right, node->data + 1, max); // +1 for root !>= max
}

int isBST2(struct node *root)
{
    return isBSTrecur(root, minValue(root), maxValue(root));
}

void printTill(int *path, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", path[i]);
    }
    puts("");
}

void recurPath(struct node *root, int *path, int currLen)
{
    if (root == NULL)
        return; // Guard

    path[currLen] = root->data, currLen++;

    if (root->left == NULL && root->right == NULL)
    {
        printTill(path, currLen);
    }
    else
    {
        recurPath(root->left, path, currLen);
        recurPath(root->right, path, currLen);
    }
}

#define maxNode 1000
void printPaths(struct node *root)
{
    int initializer[maxNode];
    recurPath(root, initializer, 0);
}

int main()
{
    struct node *test = build123();
    printf("%d ", test->data);
    printPostorder(test);
    return 0;
}