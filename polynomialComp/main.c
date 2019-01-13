#include <stdio.h>
#include <stdlib.h>

//struct node
//{
//    int data;
//    struct node *next;
//};

// define a polynomial node
struct polyNode
{
    int coef;
    int expon;
    struct polyNode *link;
};

typedef struct polyNode *polynomial;

void attach(int c, int e, polynomial *pRear)
{
    // c,e are the coefficient and exponantial of the polynomial
    // attach(store) each part of the polynomial ready for forming a polynomial
    polynomial p;
    p = (polynomial)malloc(sizeof (struct polyNode));

    p->coef = c;
    p->expon = e;
    p->link = NULL;
    (*pRear)->link = p;
    *pRear = p;
}

polynomial readPoly()
{
    polynomial p,rear,tmp;
    int c,e,n;

    scanf("%d",&n);
    p = (polynomial)malloc(sizeof (struct polyNode));
    p->link = NULL;
    rear = p;
    while(n--)
    {
        scanf("%d %d",&c,&e);
        attach(c,e,&rear);
    }
    tmp = p; p = p->link; free(tmp);
    return p;
}

void printPoly(polynomial p)
{
    int flag = 0;
    if(!p)
    {
        printf("0 0\n");
        return;
    }
    while(p)
    {
        if(!flag)
            flag = 1;
        else
            printf(" ");

        printf("%d %d",p->coef, p->expon);
        p = p->link;
    }

}

polynomial add(polynomial p1, polynomial p2)
{
    polynomial p,t1,t2,rear;
    t1 = p1; t2 = p2;
    p = (polynomial)malloc(sizeof(struct polyNode));
    p->link = NULL;
    rear = p;
    while(t1 && t2)
    {
        if(t1->expon == t2->expon)
        {

        }
        else if(t1->expon > t2->expon)
        {

        }
        else
        {

        }
    }

    while(t1)
    {

    }

    while(t2)
    {

    }

    return p;
}

polynomial mult(polynomial p1, polynomial p2)
{
    int e,c;
    polynomial p,t1,t2,rear,t;
    t1 = p1; t2 = p2;

    while(t2)
    {// compute p = (first term of p1)*p2;

    }
    t1 = t1->link;
    while(t1)
    {
        t2 = p2;
        rear = p;
        while(t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while(rear->link && rear->link->expon == e)
                rear = rear->link;
            if(rear->link&&rear->link->expon == e)
            {
                if(rear->link->coef + c)
                    rear->link->coef += c;
                else {
                    t = rear->link;
                    rear->link = t->link;
                    free(t);
                }
            }
            else {
                t = (polynomial)malloc(sizeof(struct polyNode));
                t->coef = c;
                t->expon = e;
                t->link = rear->link;
                rear->link = t;
                rear = rear->link;

            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t2 = p; p = p->link; free(t2);
    return p;
}

int main()
{
    polynomial p1,p2,pp,ps;

    p1 = readPoly();
    p2 = readPoly();
    pp = mult(p1, p2);
    printPoly(pp);
    ps = add(p1, p2);
    printPoly(ps);

    return 0;
}
