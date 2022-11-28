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
    if(tree == nullptr) return 0;
    return sumElements(tree->left) + sumElements(tree->right) + tree->key;
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if(tree == nullptr) return 0;
    if(level == 0) return tree->key;
    return sumElementsAtLevel(tree->left, level-1) + sumElementsAtLevel(tree->right, level-1);
}

bool areSame(Node* tree1, Node* tree2){
    if(tree1 == nullptr && tree2 == nullptr) return true;
    if(tree1 == nullptr && tree2 != nullptr) return false;
    if(tree1 != nullptr && tree2 == nullptr) return false;
    return areSame(tree1->left, tree2->right) && areSame(tree1->right, tree2->left) && tree1->key == tree2->key;
}
bool isSymmetric(Node* tree) {
    if(tree == nullptr) return true;
    return areSame(tree->left, tree->right);
}

bool checkLeftRight(Node* tree){
    if(tree->left == nullptr && tree->right == nullptr)
        return true;
    if(tree->left == nullptr && tree->right != nullptr)
        return tree->key <= tree->right->key;
    if(tree->left != nullptr && tree->right == nullptr)
        return tree->left->key < tree->key;
    if(tree->left != nullptr && tree->right != nullptr)
        return (tree->left->key < tree->key) && (tree->key <= tree->right->key);
}
bool isBST(Node* tree) {
    if(tree == nullptr) return true;
    return checkLeftRight(tree) && isBST(tree->left) && isBST(tree->right);
}