#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef int keyType;

struct list {
    keyType key;
    data info;
    struct list *next;
};

void insertBegin(struct list **L, keyType key, data x) {
    struct list *temp;
    temp = (struct list *) malloc(sizeof(*temp));
    if (NULL == temp) {
        fprintf(stderr, "Doesnt have memory for new elements!\n");
        return;
    }

    temp->next = *L;
    (*L) = temp;
    (*L)->key = key;
    (*L)->info = x;
}

void insertAfter(struct list **L, keyType key, data x) {
    if (NULL == *L) {
        insertBegin(L, key, x);
        return;
    }

    struct list *temp;
    temp = (struct list *) malloc(sizeof(*temp));
    if (NULL == temp) {
        fprintf(stderr, "Doesnt have memory for new elements!\n");
        return;
    }

    temp->key = key;
    temp->info = x;
    temp->next = (*L)->next;
    (*L)->next = temp;
}

void insertBefore(struct list **L, keyType key, data x) {
    if (NULL == *L) {
        insertBegin(L, key, x);
        return;
    }

    struct list *temp;
    temp = (struct list *) malloc(sizeof(*temp));
    if (NULL == temp) {
        fprintf(stderr, "Doesnt have memory for new elements!\n");
        return;
    }

    *temp = **L;
    (*L)->next = temp;
    (*L)->key = key;
    (*L)->info = x;
}

void deleteNode(struct list **L, keyType key) {
    struct list *current = *L;
    struct list *save;
    if ((*L)->key == key) { //need to delete first element
        current = (*L)->next;
        free(*L);
        (*L) = current;
        return;
    }

    //Find element to delete
    while (current->next != NULL && current->next->key != key) {
        current = current->next;
    }

    if (NULL == current->next) {
        fprintf(stderr, "Error: The element for deletion wasnt found!\n");
        return;
    }
    else {
        save = current->next;
        current->next = current->next->next;
        free(save);
    }
}

void print(struct list *L) {
    while(NULL != L) {
        printf("%d(%d) ", L->key, L->info);
        L = L->next;
    }
    printf("\n");
}

struct list* search(struct list *L, keyType key) {
    while(L != NULL) {
        if (L->key == key) return L;
        L = L->next;
    }
    return NULL;
}

int main() {
    struct list *L = NULL;
    int i, edata;
    insertBegin(&L, 0, 42);
    for(i = 1; i < 6; i++) {
        edata = rand() % 100;
        printf("Insert before: %d(%d)\n", i, edata);
        insertBegin(&L, i, edata);
    }

    for(i = 6; i < 10; i++) {
        edata = rand() % 100;
        printf("Insert after: %d(%d)\n", i, edata);
        insertAfter(&L, i, edata);
    }

    print(L);
    deleteNode(&L, 9); print(L);
    deleteNode(&L, 0); print(L);
    deleteNode(&L, 3); print(L);
    deleteNode(&L, 5); print(L);
    deleteNode(&L, 5);
}