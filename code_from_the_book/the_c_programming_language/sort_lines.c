#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max lines to be sorted */
char *lineptr[MAXLINES];    /* pointers to text file */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[],int nlines);


void qsort(char *lineptr[], int left, int right);

/*sort input file */
int 
main()
{
    int nlines;   /*number of input lines read*/

    nlines = readlines(lineptr, MAXLINES);

    if (nlines > 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: input too big to be sorted\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);


/* readlines: read input lines */
int
readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p = alloc(len) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


/* wrielines: write output lines */
void
writelines(char *lineptr[], int nlines)
{
    int i;
    for (i=0; i<nlines; i++) {
        printf("%s\n",lineptr[i]);
    }
}


/* another impl of writelines */
void 
writelines2(char *lineptr[], int nlines) 
{
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}


void
qsort(char *vals[], int left, int right)
{
    int i, last;
    void swap(char *vals[], int i, int j);

    if (left >= right) {
        return;
    }
    
    swap(vals, left, (left + right)/2);
    last = left;
    
    for (i=left+1; i<=right; i++) {
        if (strcmp(vals[i], vals[left]) < 0) {
            swap(vals, ++last, i);
        }
        swap(vals, left, last);
        qsort(vals, left, last-1);
        qsort(vals, last+1, right);
    }
}

void 
swap(char *vals[], int i, int j)
{
    char *tmp;
    
    tmp = vals[i];
    vals[i] =vals[j];
    vals[j] = tmp;
}