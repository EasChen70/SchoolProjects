#pragma once

#include <iostream>
#include <string>

enum NodeColor {RED, BLACK};

class LLRBTNode
{
private:
    int data;
    LLRBTNode* left;
    LLRBTNode* right;
    NodeColor color;
public:
    LLRBTNode(int data);
    ~LLRBTNode();

    friend class LLRBTree;
};

class LLRBTree
{
private:
    LLRBTNode* _root;
    LLRBTNode* insert(LLRBTNode* root, int data);
    LLRBTNode* remove(int data, LLRBTNode* root);
    
    int height(LLRBTNode* root);
    void preorder(LLRBTNode* root, std::ostream& os);
    void inorder(LLRBTNode* root, std::ostream& os);
    void postorder(LLRBTNode* root, std::ostream& os);
    void rotateLeft(LLRBTNode*& node);
    void rotateRight(LLRBTNode*& node);
    void flipColors(LLRBTNode* node);
    bool search(int data, LLRBTNode* root);
    bool isRed(LLRBTNode* node);

public:
    LLRBTree();
    ~LLRBTree();
    void insert(int data);
   
    int height();
    void preorder(std::ostream& os);
    void inorder(std::ostream& os);
    void postorder(std::ostream& os);

    bool search(int data);
    void clear();
};
