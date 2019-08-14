

#define MAXSIZE 50

typedef char datatype;

typedef struct chnode
{
    int child;
    struct chnode *next;
}chnode, * chpoint;

typedef struct{
    datatype data;
    chpoint firstchild;
}node;

typedef struct{
    node treelist[MAXSIZE];
    int root,length;
}tree;

