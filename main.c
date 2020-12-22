#include "bst.h"

int main() {
    BST bst;
    bst_init(&bst);

    bst_insert(&bst, 20);
    bst_insert(&bst, 40);
    bst_insert(&bst, 10);
    bst_insert(&bst, 30);
    bst_insert(&bst, 50);

    bst_inorder(&bst);

    return 0;
}
