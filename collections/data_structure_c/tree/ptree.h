

#define MAXSIZE 100

typedef char datatype;

typedef struct node
{
    datatype data;
    int parent;
}node;

typedef struct tree
{
    node treelist[MAXSIZE];
    int length,root;
}tree;


