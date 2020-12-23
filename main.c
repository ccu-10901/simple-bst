#include "bst.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 4096

void rm_newline(char *str);

int main() {
    BST bst;
    bst_init(&bst);

    bst_insert(&bst, "dog", "狗勾");
    bst_insert(&bst, "cat", "貓貓");
    bst_insert(&bst, "apple", "蘋果");
    bst_insert(&bst, "fuck", "法克");
    bst_insert(&bst, "eat", "吃");
    bst_insert(&bst, "bird", "鳥ㄋㄧㄠ");
    bst_insert(&bst, "great", "好唷");

    char key[BUF_SIZE];
    while (fgets(key, BUF_SIZE, stdin)) {
        rm_newline(key);

        char *val;
        if (!bst_get(&bst, key, &val)) {
            printf("meaning of %s: %s\n", key, val);
        } else {
            printf("unknown word :'(\n");
        }
    }

    bst_inorder(&bst);

    /* free the bst */
    bst_destroy(&bst);

    return 0;
}

void rm_newline(char *str) {
    const size_t len = strlen(str);
    if (len && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
