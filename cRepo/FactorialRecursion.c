#include<stdio.h>

const unsigned n = 20;

unsigned long fact(unsigned i) {
    if (i < 2) return 1;
    return i * fact(i - 1);
}

int main() {
    printf("%u! = %lu \n", n, fact(n));
}