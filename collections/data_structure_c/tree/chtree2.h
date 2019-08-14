

#define m 3
#define MAXSIZE 20

typedef char datatype;

typedef struct node
{
    datatype data;
    int child[m];
}treenode;

treenode tree[MAXSIZE];
int root;
int length;