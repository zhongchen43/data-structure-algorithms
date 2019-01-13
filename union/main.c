#include <stdio.h>

#define maxSize 100;

/*
// use array and tree to represent the union
// slowly
typedef struct Union
{
    int data;
    int parent;

}SetType;

int find (SetType s[], int x)
{// find the union of x in array s
    // maxSize is length of array
    int i;
    for(i=0; (i < maxSize) && (s[i].data!=x); i++)
        if(i >= maxSize) return -1; // return -1 if not find x
    for(;s[i].parent >= 0; i = s[i].parent)
        return i; // return all sets of x, and return root node subscript of the array

}

*/

// Simplify
typedef int ElementType;
typedef  int setName;
typedef ElementType SetType[maxSize];



int main()
{
    printf("Hello World!\n");
    return 0;
}
