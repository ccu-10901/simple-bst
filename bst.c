#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bst_insert(BST *bst, const char *key, const char *val) {
    /* find the insertion point */
    Node **curr = &bst->root;
    Node *n;
    while ((n = *curr)) {
        const int cmp_ret = strcmp(key, n->key);
        if (cmp_ret > 0)
            curr = &n->right;
        else if (cmp_ret < 0)
            curr = &n->left;
        else
            return 0;
    }

    /* invariant: n == NULL */

    /* create a new node */
    Node *const node = *curr = malloc(sizeof(Node));
    if (!node) {
        return BST_ERR_MALLOC;
    }

    /* plus one for null character */
    const size_t len_key = strlen(key);
    char *k = malloc(len_key + 1);
    if (!k) {
        goto free_node;
    }
    memcpy(k, key, len_key + 1);

    const size_t len_val = strlen(val);
    char *v = malloc(len_val + 1);
    if (!v) {
        goto free_k;
    }
    memcpy(v, val, len_val + 1);

    node->key = k;
    node->val = v;
    node->left = node->right = NULL;

    return 0;

    free_k:
    free(k);

    free_node:
    free(node);

    return BST_ERR_MALLOC;
}

int bst_get(BST *bst, const char *key, char **val) {
    Node *curr = bst->root;
    while (curr) {
        const int cmp_ret = strcmp(key, curr->key);
        if (!cmp_ret) {
            *val = curr->val;
            return 0;
        } else if (cmp_ret > 0) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return BST_ERR_NOT_FOUND;
}

static void bst_pvt_inorder(Node *node) {
    Node *n;
    if ((n = node->left))
        bst_pvt_inorder(n);

    printf("<%s, %s>\n", node->key, node->val);

    if ((n = node->right))
        bst_pvt_inorder(n);
}

void bst_inorder(BST *bst) {
    if (bst->root)
        bst_pvt_inorder(bst->root);
}

static void bst_pvt_postorder_free(Node *node) {
    Node *n;
    if ((n = node->left))
        bst_pvt_postorder_free(n);

    if ((n = node->right))
        bst_pvt_postorder_free(n);

    free(node->key);
    node->key = NULL;

    free(node->val);
    node->val = NULL;

    free(node);
    node = NULL;
}

void bst_destroy(BST *bst) {
    if (bst->root)
        bst_pvt_postorder_free(bst->root);
}
