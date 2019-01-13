#include <stdio.h>

typedef struct treeNode * binTree;
typedef  binTree position;
struct treeNode
{
    int data;
    binTree left;
    binTree right;
};

// compute the height of binary tree
int postOrderGetHeight(binTree bt)
{
    int hl,hr,maxH;
    if(bt)
    {
        hl = postOrderGetHeight(bt->left);
        hr = postOrderGetHeight(bt->right);
        maxH = (hl>hr)? hl:hr;
        return(maxH+1);
    }
    else
        return 0;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
