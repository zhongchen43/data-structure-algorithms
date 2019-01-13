#include <stdio.h>

// use struct array to define a binary tree
#define maxTree 10
#define elementType char
#define tree int
#define Null -1

struct treeNode
{
    elementType Element;
    tree left;
    tree right;
};

struct treeNode t1[maxTree],t2[maxTree];

tree buildTree(struct treeNode t[])
{
    scanf("%d\n",&n);
    if(n)
    {
        for(int i=0;i<n;++i)
            check[i] = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%c %c %c\n",&t[i].Element,&cl,&cr);
            if(cl!='-')
            {
                t[i].left = cl-'0';
                check[t[i].left] = 1;

            }
            else {
                t[i].left = Null;
            }
        }
        for(int i = 0;i<n;++i)
            if(!check[i])
                break;
        root = i;
    }
    return root;
}

int isomorphic(tree r1, tree r2)
{
    if((r1 == Null) && (r2==Null))
            return 1;
    if(((r1 == Null) && (r2!=Null)) || ((r1 != Null) && (r2==Null)))
        return 0;
    if((t1[r1].left==Null) && (t2[r2].left == Null))
        return isomorphic(t1[r1].right, t2[r2].right);
    ....
}

int main()
{
    tree r1, r2;
    r1 = buildTree(t1);
    r2 = buildTree(t2);

    if (isOmorphic(r1,r2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
