#include <stdio.h>
#include <stdlib.h>

typedef struct sNode *Stack;
struct sNode
{
    int data;
    struct sNode *next;
};

Stack createStack()
{// create a head of stack, and return a pointer
    Stack s;
    s = (Stack)malloc(sizeof(struct sNode));
    s->next = NULL;
    return s;

}
int isEmpty(Stack s)
{
    return (s->next == NULL);
}

void push(int item, Stack s)
{
    struct sNode *tmpCell;
    tmpCell = (struct sNode *)malloc(sizeof(struct sNode));
    tmpCell->data = item;
    tmpCell->next = s->next;
    s->next = tmpCell;
}

int pop(Stack s)
{
    struct sNode *firstCell;
    int topElem;
    if(isEmpty(s))
    {
        printf("Stack empty!");
        return 0;
    }
    else
    {
        firstCell = s->next;
        s->next = firstCell->next;
        topElem = firstCell->data;
        free(firstCell);
        return topElem;
    }
}
int main()
{
    printf("Hello World!\n");
    return 0;
}
