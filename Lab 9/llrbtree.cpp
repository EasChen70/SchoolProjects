#include "llrbtree.h"

/*
 * Node Class Functions
*/

LLRBTNode::LLRBTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->color = RED;
}

LLRBTNode::~LLRBTNode(){

}

bool LLRBTree::isRed(LLRBTNode* node){
    if (node == nullptr) {
        return false;
    }
    return (node->color == RED);
}
/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

void LLRBTree::rotateLeft(LLRBTNode*& node){
    LLRBTNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    temp->color = node->color;
    node->color = RED;
    node = temp;
}

void LLRBTree::rotateRight(LLRBTNode*& node){
    LLRBTNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->color = node->color;
    node->color = RED;
    node = temp;
}

void LLRBTree::flipColors(LLRBTNode* node){
    node->color = (node->color == RED) ? BLACK : RED;
    node->left->color = (node->left->color == RED) ? BLACK : RED;
    node->right->color = (node->right->color == RED) ? BLACK : RED;
}

LLRBTNode* LLRBTree::insert(LLRBTNode* node, int data){
    if(node == nullptr){
        return new LLRBTNode(data);
    }
    if(data < node->data){
        node->left = insert(node->left, data);
    }else if(data > node->data){
        node->right = insert(node->right, data);
    }else{
        return node;
    }
    if(isRed(node->right) && !isRed(node->left)){
        rotateLeft(node);
    }
    if(isRed(node->left) && isRed(node->left->left)){
        rotateRight(node);
    }
    if(isRed(node->left) && isRed(node->right)){
        flipColors(node);
    }

    return node;
}

int LLRBTree::height(LLRBTNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

void LLRBTree::preorder(LLRBTNode* root, std::ostream& os){
    if(!root) return;

    os << root->data << ":" << (root->color == BLACK ? "0" : "1") << " ";
    preorder(root->left, os);
    preorder(root->right, os);
}

void LLRBTree::inorder(LLRBTNode* root, std::ostream& os){
    if(!root) return;

    inorder(root->left, os);
    os << root->data << ":" << (root->color == BLACK ? "0" : "1") << " ";
    inorder(root->right, os);
}

void LLRBTree::postorder(LLRBTNode* root, std::ostream& os){
    if(!root) return;

    postorder(root->left, os);
    postorder(root->right, os);
    os << root->data << ":" << (root->color == BLACK ? "0" : "1") << " ";
}



bool LLRBTree::search(int data, LLRBTNode* root){
    if(!root){
        return false;
    }
    if(data == root->data){
        return true;
    }
    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

/*
 * Public Functions
*/

LLRBTree::LLRBTree(){
    this->_root = nullptr;
}

LLRBTree::~LLRBTree(){
    delete this->_root;
}

void LLRBTree::insert(int data){
    _root = insert(_root, data);
    _root->color = BLACK;
}


int LLRBTree::height(){
    return this->height(this->_root);
}

void LLRBTree::preorder(std::ostream& os){
    this->preorder(this->_root, os);
    os << "\n";
}

void LLRBTree::inorder(std::ostream& os){
    this->inorder(this->_root, os);
    os << "\n";
}

void LLRBTree::postorder(std::ostream& os){
    this->postorder(this->_root, os);
    os << "\n";
}

bool LLRBTree::search(int data){
    return this->search(data, this->_root);
}