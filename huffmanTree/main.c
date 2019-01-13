#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *huffmanTree;
struct treeNode
{
    int weight;
    huffmanTree left, right;
};

typedef  struct heapStruct *minHeap;
struct heapStruct
{
    int * data; // array storing heap elements(data)
    int size; // current element number of heap
    int capacity; // max capacity of heap
};

void buildHeap(huffmanTree h)
{


}

huffmanTree huffman(minHeap h)
{
    // if h->size weights already exist in h->data[]->weight
    int i; huffmanTree t;
    buildMinHeap(h); // adjust h->data[] as a minimum heap base on weights
    for(i=0; i < h->size; i++)
    {// h->size-1 unions
        t = malloc(sizeof(struct treeNode)); // build a new node
        t->left = deleteMin(h); // delete a node from minHeap as the left node of new t
        t->right = deleteMin(h); // delete a node from minHeap as the right node of new t
        t->weight = t->left->weight + t->right->weight; //  calculate new weight
        insert(h,t); // insert the new t into minHeap

    }
    t = deleteMin(h);
    return t;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
