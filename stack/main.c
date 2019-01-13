#include <stdio.h>

// stack implementation with array
#define maxSize 100;
typedef struct sNode *Stack;
struct sNode
{
    int data[maxSize];
    int top;
};

void push(Stack ptrS, int item)
{
    if((ptrS->top) == (maxSize-1))
    {
        printf("Stack full!");
        return;
    }
    else
    {
        ptrS->data[++(ptrS->top)] = item;
        return;
    }
}

int pop(Stack ptrS)
{
    if(ptrS->top == -1)
    {
        printf("Stack empty!");
        return error;
    }
    else {
        return (ptrS->data[(ptrS->top)--]);
    }
}


// stack implementation with linked list

int main()
{
    printf("Hello World!\n");
    return 0;
}
