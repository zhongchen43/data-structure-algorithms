#include <stdio.h>
#include <stdlib.h>

//Compare if two binary trees are the same

typedef struct treeNode * binTree;
typedef  binTree position;
struct treeNode
{
    int data;
    binTree left;
    binTree right;
    int flag;
};

binTree newNode(int data)
{
    binTree t = (binTree)malloc(sizeof(struct treeNode));
    t->data = data;
    t->left = t->right =NULL;
    t->flag = 0;
    return t;
}

binTree insert(binTree t, int data)
{
    if(!t) t = newNode(data);
    else
    {
        if(data > t->data)
            t->right = insert(t->right, data);
        else
            t->left = insert(t->left, data);
    }
    return t;
}

binTree makeTree(int n)
{
    binTree t;
    int i, data;
    scanf("%d",&data);
    for(i = 1;i<n;i++)
    {
        scanf("%d",&data);
        t = insert(t, data);
    }
    return t;
}

int check(binTree t, int data)
{
    if(t->flag)
    {
        if(data< t->data)
            return check(t->left, data);
        else if (data > t->data)
            return check(t->right,data);
        else
            return 0;
    }
    else
    {
        if(data == t->data)
        {
            t->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

int judge(binTree t, int n)
{
    int i, data, flag = 0; //"flag=0" means it is same right now, "flag=1" means it is not the same
    scanf("%d",&data);
    if(data!=t->data)
        flag = 1;
    else
        t->flag = 1;

    for (i = 1;i<n;i++)
    {
        scanf("%d",&data);
        if((!flag) && (!check(t,data)))
            flag = 1;
    }
    if(flag)
        return 0;
    else
        return 1;
}

// reset removes all of the flags in the node of t
void resetT(binTree t)
{
    if(t->left) resetT(t->left);
    if(t->right) resetT(t->right);
    t->flag = 0;

}

//free the space of t
void freeTree(binTree t)
{
    if(t->left) freeTree(t->left);
    if(t->right) freeTree(t->right);
    free(t);
}
int main()
{
    int n, l, i;
    binTree t;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&l);
        t = makeTree(n);
        for(i = 0;i<l;i++)
        {
            if(judge(t,n))
                printf("Yes\n");
            else
                printf("No\n");
            resetT(t);
        }
        freeTree(t);
        scanf("%d",&n);
    }

    return 0;
}
