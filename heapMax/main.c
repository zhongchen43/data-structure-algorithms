#include <stdio.h>
#include <stdlib.h>

typedef  struct heapStruct *maxHeap;
struct heapStruct
{
    int * data; // array storing heap elements(data)
    int size; // current element number of heap
    int capacity; // max capacity of heap
};

maxHeap create(int maxSize)
{
    int maxData; //  a number great than all of the data in the maxHeap
    maxHeap h = malloc(sizeof (struct heapStruct));
    h->data = malloc((maxSize + 1)* sizeof (int));// "int" here is the heapStruct data type
    h->size = 0;
    h->capacity = maxSize;
    h->data[0] = maxData; // define "sentinal" as what is great than all of the other data
    return h;
}

void insert(maxHeap h, int item)
{
    // insert item into maxHeap, h->data[0] is "sentinal"
    int i;
    if(isFull(h))
    {
        printf("maxHeap is full!");
        return;
    }
    i = ++h->size; // i is the position of the last element after item is inserted
    for (;h->data[i/2] < item; i/=2)
        h->data[i] = h->data[i/2]; // filter the node towards down
    h->data[i] = item; // insert item
}

int deleteMax(maxHeap h)
{
    int parent, child;
    int maxItem, temp;
    if(isEmpty(h))
    {
        printf("maxHeap is empty!");
        return;
    }
    maxItem = h->data[1]; //get the biggest data of root nodes, use the last element in the maxHeap to filter the lower level nodes from root node up
    temp = h->data[h->size--];
    for(parent = 1; parent*2 <= h->size; parent = child)
    {
        child = parent * 2;
        if((child!=h->size) && (h->data[child] < h->data[child + 1]))
            child++;
        if(temp >= h->data[child])
            break;
        else
            h->data[parent] = h->data[child];
    }
    h->data[parent] = temp;
    return maxItem;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
