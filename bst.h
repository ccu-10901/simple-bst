#ifndef BST_H
#define BST_H

#include <stddef.h>

#define BST_ERR_MALLOC -1
#define BST_ERR_NOT_FOUND -2

typedef struct node Node;

struct node {
    char *key;
    char *val;
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

int bst_insert(BST *bst, const char *key, const char *val);

/**
 * 根據給定的 key，尋找對應的 val。
 * @param key - 欲尋找的鍵
 * @param val - 將找到的值，指派至 val 所指向的 char * 中
 * @return 0 表示成功，小於 0 表示失敗
 */
int bst_get(BST *bst, const char *key, char **val);

void bst_inorder(BST *bst);

void bst_destroy(BST *bst);

#endif //BST_H
