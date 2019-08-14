

#define m 3

typedef char datatype;

typedef struct node
{
    datatype data;
    struct node *child[m];
}node,*tree;

tree root;