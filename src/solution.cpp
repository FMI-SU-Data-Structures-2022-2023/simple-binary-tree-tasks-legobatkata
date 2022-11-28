#include "solution.h"
#include <iostream>

int countElements(Node* tree) {
    if(tree == nullptr) return 0;
    return countElements(tree->left) + countElements(tree->right) + 1;
}

int countLeafs(Node* tree) {
    if(tree == nullptr) return 0;
    if(tree->left == nullptr && tree->right == nullptr) return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    if(tree == nullptr) return 0;
    return std::max(height(tree->left), height(tree->right)) + 1;
}

int sumElements(Node* tree) {
    return -1;
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    return -1;
}

bool isSymmetric(Node* tree) {
    return false;
}

bool checkLeftRight(Node* tree){
    if(tree->left == nullptr && tree->right == nullptr) return true;
    if(tree->left == nullptr && tree->right != nullptr){
        return tree->key <= tree->right->key;
    }
    if(tree->left != nullptr && tree->right == nullptr){
        return tree->left->key < tree->key;
    }
    if(tree->left != nullptr && tree->right != nullptr){
        return (tree->left->key < tree->key) && (tree->key <= tree->right->key);
    }
}
bool isBST(Node* tree) {
    if(tree == nullptr) return true;
    return checkLeftRight(tree) && isBST(tree->left) && isBST(tree->right);
}