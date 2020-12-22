#ifndef BST_H
#define BST_H

#include <stddef.h>

#define BST_ERR_MALLOC -1

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

typedef struct bst {
    Node *root;
} BST;

static inline int bst_init(BST *bst) {
    bst->root = NULL;
    return 0;
}

int bst_insert(BST *bst, int data);

void bst_inorder(BST *bst);

#endif //BST_H
