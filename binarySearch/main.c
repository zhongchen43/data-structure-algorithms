#include <stdio.h>
#include <stdlib.h>

// implemation with non-recursive
int binarySearch(int arr[10], int e)
{
    int low = 0;
    int high = 9;
    while(low <= high)
    {
        int mid = (low+high)/2;

        if(e > arr[mid])
            low = mid+1;
        else if(e < arr[mid])
            high = mid-1;
        else
            return mid;
    }
    return -1;

}


// implemation with recursive
int binarySearchRecursive(int arr[10], int low, int high, int e)
{
    int mid = (low+high)/2;
    if(e > arr[mid])
        return binarySearchRecursive(arr, mid+1,high, e);
    else if (e<arr[mid])
        return binarySearchRecursive(arr, low,mid-1, e);
    else
        return mid;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
