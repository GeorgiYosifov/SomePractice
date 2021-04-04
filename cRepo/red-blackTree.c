#include<stdio.h>
#include<stdlib.h>

enum color_t { BLACK, RED };

struct Node {
  struct Node* parent;
  struct Node* left;
  struct Node* right;
  enum color_t color;
  int key;
};

struct Node* GetParent(struct Node* n) {
  // Note that parent is set to null for the root node.
  return n == NULL ? NULL : n->parent;
}

struct Node* GetGrandParent(struct Node* n) {
  // Note that it will return null if this is root or child of root
  return GetParent(GetParent(n));
}

struct Node* GetSibling(struct Node* n) {
  struct Node* p = GetParent(n);

  // No parent means no sibling.
  if (p == NULL) {
    return NULL;
  }

  if (n == p->left) {
    return p->right;
  } else {
    return p->left;
  }
}

struct Node* GetUncle(struct Node* n) {
  struct Node* p = GetParent(n);

  // No parent means no uncle
  return GetSibling(p);
}

void RotateLeft(struct Node* n) {
  struct Node* nnew = n->right;
  struct Node* p = GetParent(n);
  assert(nnew != NULL); // Since the leaves of a red-black tree are empty,
                        // they cannot become internal nodes.
  n->right = nnew->left;
  nnew->left = n;
  n->parent = nnew;
  // Handle other child/parent pointers.
  if (n->right != NULL) {
    n->right->parent = n;
  }

  // Initially n could be the root.
  if (p != NULL) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

void RotateRight(struct Node* n) {
  struct Node* nnew = n->left;
  struct Node* p = GetParent(n);
  assert(nnew != NULL);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->left = nnew->right;
  nnew->right = n;
  n->parent = nnew;

  // Handle other child/parent pointers.
  if (n->left != NULL) {
    n->left->parent = n;
  }

  // Initially n could be the root.
  if (p != NULL) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}