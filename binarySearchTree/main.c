#include <stdio.h>
#include <stdlib.h>

// use linked list to store binary tree
typedef struct treeNode * binTree;
typedef  binTree position;
struct treeNode
{
    int data;
    binTree left;
    binTree right;
};

// implementation with recursive
position Find(int x, binTree bst)
{
    if(!bst)
         return NULL;
    if(x > bst->data)
        return Find(x,bst->right);
    else if(x < bst->data)
        return Find(x, bst->left);
    else
        return bst;
}

// implementation with iteration
position iteFind(int x, binTree bst)
{
    while(bst)
    {
        if(x > bst->data)
            bst = bst->right;
        else if(x < bst->data)
            bst = bst->left;
        else
            return bst;
    }
    return NULL;
}

// implementation with recursive
position findMin(binTree bst)
{
    if(!bst) return NULL;
    else if(!bst->left)
        return bst;
    else
        return findMin(bst->left);
}

// find the max
position findMax(binTree bst)
{
    if(bst)
        while(bst->right)
            bst = bst->right;
    return bst;
}

// insert data
binTree insert(int x, binTree bst)
{
    if(!bst)
    {
        bst = malloc(sizeof(struct treeNode));
        bst->data = x;
        bst->left = bst->right = NULL;
    }
    else if(x < bst->data)
        bst->left = insert(x, bst->left);
    else if(x > bst->data)
        bst->right = insert(x, bst->right);
    return  bst;
}

// delete
binTree delete(int x, binTree bst)
{
    position tmp;
    if(!bst)
        printf("not find the element to delete");
    else if(x < bst->data)
        bst->left = delete(x, bst->left);
    else if(x > bst->data)
        bst->right = delete(x, bst->right);
    else if(bst->left && bst->right)
    {
        tmp = findMin(bst->right);
        bst->data = tmp->data;
        bst->right = delete(bst->data, bst->right);
    }
    else
    {
        tmp = bst;
        if(!bst->left)
            bst = bst->right;
        else if(!bst->right)
            bst = bst->right;
        free(tmp);
    }
    return bst;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
