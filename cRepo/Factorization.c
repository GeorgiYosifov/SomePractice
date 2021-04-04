#include<stdio.h>

unsigned n = 436;

int main() {
    unsigned how, i, j;
    printf("%u = ", n);
    i = 1;
    while (n != 1)
    {
        i++;
        how = 0;
        while (0 == n % i)
        {
            how++;
            n = n / i;
        }
        for (j = 0; j < how; j++)
        {
            printf("%u ", i);
        }
    }
    printf("\n");    
}