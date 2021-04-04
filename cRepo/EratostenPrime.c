#include<stdio.h>

#define MAXN 30000
const unsigned n = 200;
char sieve[MAXN];

int main() {
    unsigned i;
    for (i = 0; i < n; i++)
    {
        sieve[i] = 0;
    }
    eratosten(n);
}

void eratosten(unsigned n) {
    unsigned j, i = 2;
    while (i <= n)
    {
        if (sieve[i] == 0) {
            printf("%5u", i);
            j = i * i;
            while (i <= n)
            {
                sieve[j] = 1;
                j += i;
            }
        }
        i++;
    }
}