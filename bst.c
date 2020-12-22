#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int bst_insert(BST *bst, int data) {
    /* find the insertion point */
    Node **curr = &bst->root;
    Node *n;
    while ((n = *curr)) {
        if (data > n->data)
            curr = &n->right;
        else if (data < n->data)
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
    node->data = data;
    node->left = node->right = NULL;

    return 0;
}

static void bst_pvt_inorder(Node *node) {
    Node *n;
    if ((n = node->left))
        bst_pvt_inorder(n);

    printf("%d\n", node->data);

    if ((n = node->right))
        bst_pvt_inorder(n);
}

void bst_inorder(BST *bst) {
    if (bst->root)
        bst_pvt_inorder(bst->root);
}
