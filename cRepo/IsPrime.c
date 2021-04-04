#include<stdio.h>
#include<math.h> 

const unsigned long n = 123;

int main()  
{ 
    if (isPrime(n)) {
        printf("Number %u is prime.\n", n);
    } else {
        printf("Number %u is composite.\n", n);
    }
}

char isPrime(unsigned n) {
    unsigned i = 2;
    if (n == 2) return 1;
    while (i <= sqrt(n))
    {
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}