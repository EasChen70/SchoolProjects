#include "bst.h"
#include <iostream>

BSTNode::BSTNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
}

BSTNode::~BSTNode() = default;
BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    destroy(root);
}
void BSTree::destroy(BSTNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BSTree::insert(int val) {
    root = insert(root, val);
}

BSTNode* BSTree::insert(BSTNode* node, int val) {
    if (node == nullptr) {
        node = new BSTNode(val);
    }
    else if (val < node->data) {
        node->left = insert(node->left, val);
    }
    else if (val > node->data) {
        node->right = insert(node->right, val);
    }
    else {
        std::cout << "-1" << std::endl;
    }
    return node;
}

void BSTree::remove(int val) {
    root = remove(root, val);
}

BSTNode* BSTree::remove(BSTNode* node, int val) {
    if (node == nullptr) {
        return nullptr;
    }
    if (val < node->data) {
        node->left = remove(node->left, val);
    }
    else if (val > node->data) {
        node->right = remove(node->right, val);
    }
    else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        BSTNode* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

BSTNode* BSTree::minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void BSTree::preorder() {
    preorder(root);
    std::cout << std::endl;
}

void BSTree::preorder(BSTNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BSTree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BSTree::inorder(BSTNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void BSTree::postorder() {
    postorder(root);
    std::cout << std::endl;
}

void BSTree::postorder(BSTNode* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}