#include<stdio.h>

const unsigned n = 6;

unsigned long fib(unsigned i) {
    if (i < 2) return 1;
    return fib(i - 1) + fib(i - 2);
}

unsigned long fibIter(unsigned n) {
    unsigned long f1 = 0, f2 = 1;
    while (n--) {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    return f2;
}

int main() {
    printf("%u = %lu \n", n, fibIter(n));
}