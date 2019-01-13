#include <stdio.h>

void printN(int N)
{
    for (int i=0; i<N; ++i)
    {
        printf("%d\n",i);
    }
}
void printNRecursive(int N)
{
    if(N)
    {
        printNRecursive(N-1);
        printf("%d\n",N);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
//    printN(N);
    printNRecursive(N);
    return 0;
}
