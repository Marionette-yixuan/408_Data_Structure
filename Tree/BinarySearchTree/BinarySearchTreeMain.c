//
// Created by マリオネット on 2021/7/22.
//

#include "BinarySearchTree.h"

int main() {
    int keys[9] = {50, 66, 60, 26, 21, 30, 35, 70, 68};
    BSTree bsTree;
    Create(&bsTree, keys, 9);
    Delete(bsTree, 30);

    return 0;
}