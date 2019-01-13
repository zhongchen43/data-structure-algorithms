#include <stdio.h>

// use linked list to store binary tree
typedef struct treeNode * binTree;
typedef  binTree position;
struct treeNode
{
    int data;
    binTree left;
    binTree right;
};

// traversal implementation with recursive
// preorder: root(data)->left->right
void preOrderTraversalRecursive(binTree bt)
{
    if(bt)
    {
        printf("%d",bt->data);
        preOrderTraversalRecursive(bt->left);
        preOrderTraversalRecursive(bt->right);
    }
}

//in-order: left->root->right
void inOrderTraversalRecursive(binTree bt)
{
    if(bt)
    {
        inOrderTraversalRecursive(bt->left);
        printf("%d", bt->data);
        inOrderTraversalRecursive(bt->right);
    }
}

//post-order: left->right->right
void postOrderTraversalRecursive(binTree bt)
{
    if(bt)
    {
        postOrderTraversalRecursive(bt->left);
        postOrderTraversalRecursive(bt->right);
        printf("%d", bt->data);
    }
}

// traversal implementation with stack (linked list) instead of recursive
//pre-order
void preOrderTraversalStack(binTree bt)
{
    binTree t = bt;
    Stack s = creatStack(maxSize);
    while(t || !isEmpty(s))
    {
        while(t) // always left and push data into stack
        {
            push(s,t);
            printf("%5d", t->data);//print root data
            t = t->left;
        }
        if(!isEmpty(s))
        {
            t = pop(s); //root data pop
            t = t->right; // turn to right child tree
        }
    }
}
// in-order
void inOrderTraversalStack(binTree bt)
{
    binTree t = bt;
    Stack s = creatStack(maxSize);
    while(t || !isEmpty(s))
    {
        while(t) // always left and push data into stack
        {
            push(s,t);
            t = t->left;
        }
        if(!isEmpty(s))
        {
            t = pop(s); //root data pop
            printf("%5d", t->data);//print root data
            t = t->right; // turn to right child tree
        }
    }
}

// level-order traversal
void levelOrderTraversal(binTree bt)
{
    Queue q;
    binTree t;
    if(!bt) return;
    q = createQueue(maxSize);
    addQ(q,bt);
    while(!isEmpty(q))
    {
        t = deleteQ(q);
        printf("%d\n",t->data);
        if(t->left) addQ(q,t->left);
        if(t->right) addQ(q,t->right);
    }
}
int main()
{
    printf("Hello World!\n");
    return 0;
}
