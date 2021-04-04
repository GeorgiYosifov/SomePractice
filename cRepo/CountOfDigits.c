#include<stdio.h>
#include<math.h> 

const unsigned long n = 123;

int main()  
{ 
    double digits = 0;
    for (unsigned i = 1; i <= n; i++)
    {
        digits += log10(i);
    }
    printf("Count of digits in %lu! is %lu\n", n, (unsigned long)digits + 1);
}