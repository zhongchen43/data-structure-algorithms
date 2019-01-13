#include <stdio.h>

// bubble sort
//original
void bubbleSort(ElementType a[], int n)
{
    for(p = n-1; p>=0; p--)
    {
        int flag = 0;
        for(int i=0;i<p;i++) // traversal one time
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                flag = 1; // note have an exchange
            }
        }
        if (flag == 0) // no exchange
            break;
    }

}

// insert sort
void insertionSort(ElementType a[], int n)
{
    for(int p=1; p<n;p++)
    {
        tmp = a[p]; //take next element
        for(i=p; i>0 && a[i-1]>tmp; i--)
            a[i] = a[i-1]; // 移出空位
        a[i] = tmp; // 新牌落位
    }
}



int main()
{
    printf("Hello World!\n");
    return 0;
}
