#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXN 10

//compute f = a0 + a1*x + ...an * (x^n)

// normal impletation
double f(int n, double a[], double x)
{
    double p = a[0];
    for(int i=1;i<=n;i++)
        p += (a[i] * pow(x, i));
    return p;
}
// opt
double fOpt(int n, double a[], double x)
{
    double p = a[n];
    for(int i=n;i>0;i--)
        p = a[i-1] + x*p;
    return p;
}


int main()
{
    double a[MAXN];
    for(int i=0; i<MAXN; i++)
        a[i] = (double)i;

    clock_t start, stop;
    double duration;
    start = clock();
    f(MAXN-1, a, 1.1);
//    fOpt(MAXN-1, a, 1.1);
    stop = clock();
    duration = ((double)(stop-start));
    printf("ticks = %f\n", duration);

    return 0;
}
