#ifndef BST_H
#define BST_H

class BSTNode {
private:
    int data;
    BSTNode* left;
    BSTNode* right;
public:
    explicit BSTNode(int val);
    ~BSTNode();
    friend class BSTree;
};

class BSTree {
private:
    BSTNode* root;
    void destroy(BSTNode* node);
    BSTNode* insert(BSTNode* node, int val);
    void preorder(BSTNode* node);
    void inorder(BSTNode* node);
    void postorder(BSTNode* node);
    BSTNode* remove(BSTNode* node, int val);
    BSTNode* minValueNode(BSTNode* node);
public:
    BSTree();
    ~BSTree();
    void insert(int val);
    void remove(int val);
    void preorder();
    void inorder();
    void postorder();
};
#endif