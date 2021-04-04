#include<stdio.h>
#include<string.h>

#define MAXN 1000

char getChar(char n) {
    return (n < 10) ? n + '0' : n + 'A' - 10;
}

void reverse(char *pch) {
    char *pEnd;
    for(pEnd = pch + strlen(pch) - 1; pch < pEnd; pch++, pEnd--) {
        char c = *pch;
        *pch = *pEnd;
        *pEnd = c;
    }
}

void convert(char *rslt, unsigned long n, unsigned char base) {
    char *saveRslt = rslt;
    while (n > 0) {
        *rslt++ = getChar((char) (n % base));
        n /= base;
    }
    *rslt = '\0';
    reverse(saveRslt);
}

int main() {
    char result[MAXN];
    convert(result, 180, 10);
    for(int i = 0; i < strlen(result); i++) {
        printf("%c", result[i]);
    }
    printf("\n");
}