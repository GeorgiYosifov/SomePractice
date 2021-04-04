#include<stdio.h>
#include<stdlib.h>

typedef char *data;
typedef int keyType;

struct tree {
    keyType key;
    data info;
    struct tree *left;
    struct tree *right;
};

struct tree *search(keyType key, struct tree *T) {
    if (NULL == T) {
        return NULL;
    }
    else if (key < T->key) {
        return search(key, T->left);
    }
    else if (key > T->key) {
        return search(key, T->right);
    }
    else {
        return T;
    }
}

void insertKey(keyType key, data x, struct tree **T) {
    if (NULL == *T) {
        *T = (struct tree *) malloc(sizeof(**T));
        (*T)->key = key;
        (*T)->info = x;
        (*T)->left = NULL;
        (*T)->right = NULL;
    }
    else if (key < (*T)->key) {
        insertKey(key, x, &(*T)->left);
    }
    else if (key > (*T)->key) {
        insertKey(key, x, &(*T)->right);
    }
    else {
        fprintf(stderr, "This element already exists in the tree!\n");
    }
}

struct tree *findMin(struct tree *T) {
    while (NULL != T->left)
        T = T->left;
    return T;
}

void deleteKey(keyType key, struct tree **T) {
    if (NULL == *T) {
        fprintf(stderr, "The element that has to be removed doesnt exist!\n");
    }
    else {
        if (key < (*T)->key) {
            deleteKey(key, &(*T)->left);
        }
        else if (key > (*T)->key) {
            deleteKey(key, &(*T)->right);
        }
        else {
            if ((*T)->left && (*T)->right) {
                struct tree *replace = findMin((*T)->right);
                (*T)->key = replace->key;
                (*T)->info = replace->info;
                deleteKey((*T)->key, &(*T)->right);
            }
            else {
                struct tree *temp = *T;
                if ((*T)->left) {
                    *T = (*T)->left;
                }
                else {
                    *T = (*T)->right;
                }
                free(temp);
            }
        }
    }
}

void printTree(struct tree *T, int shift) {
    if (NULL == T) 
        return;
    for(int i = 0; i < shift; i++) 
        printf(" ");
    printf("%d\n", T->key);
    printTree(T->left, shift + 1);
    printTree(T->right, shift + 1);
}

int main() {
    struct tree *T = NULL, *result;
    int nodes[] = { 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13 };
    int i;
    for(i = 0; i < sizeof(nodes)/sizeof(int); i++) {
        //int ikey = (rand() % 20) + 1;
        printf("Insert an element with key %d \n", nodes[i]);
        insertKey(nodes[i], "someInfo", &T);
    }

    printf("Tree:\n");
    printTree(T, 0);
    printf("\n");

    // result = search(5 ,T);
    // printf("Found element: %s\n", result->info);

    // for(i = 0; i < 10; i++) {
    //     int ikey = (rand() % 20) + 1;
    //     printf("Delete element with key %d \n", ikey);
    //     deleteKey(ikey, &T);
    // }

    // printf("Tree:\n");
    // printTree(T, 0);
    // printf("\n");
}