#pragma once

#include <iostream>
#include <ostream>
#include <string>

// Defines MAX
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif

enum NodeColor {RED, BLACK};
// Underlying class which will be used to implement the RBTree class.
// I.E. RBTree is made up of RBTNode
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

// Public versions: accept a single parameter so the usage of the class is neat.
// Private version: implement the functions recursively
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
    void remove(int data);
    LLRBTNode* getRoot();
    int height();
    void preorder(std::ostream& os = std::cout);
    void inorder(std::ostream& os = std::cout);
    void postorder(std::ostream& os = std::cout);

    bool search(int data);
    void clear();
};
