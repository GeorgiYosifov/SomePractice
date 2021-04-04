#include<stdio.h>
#define MAX 10

typedef int data;
data stack[MAX];
int top;

void init() { top = 0; }

void push(data i) {
    if (MAX == top) {
        //stack[top++] = i;
        fprintf(stderr, "OverFlow\n");
    } else {
        stack[top++] = i;
    }
}

data pop() { 
    if (0 == top) {
        fprintf(stderr, "Empty stack!\n");
        return 0;
    } else {
        return stack[--top]; 
    }
}

int isEmpty() { return (0 == top); }

int main() {
    data p;
    init();

    scanf("%d", &p);
    while (0 != p) {
        push(p);
        scanf("%d", &p); 
    }
    
    while (!isEmpty())
        printf("%d ", pop());
    printf("\n");
}