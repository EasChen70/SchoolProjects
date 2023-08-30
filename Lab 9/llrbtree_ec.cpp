#include "llrbtree_ec.h"

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

LLRBTNode* LLRBTree::remove(int data, LLRBTNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (data < root->data) {
        root->left = remove(data, root->left);
    } else if (data > root->data) {
        root->right = remove(data, root->right);
    } else {
        if (root->left == nullptr) {
            LLRBTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            LLRBTNode* temp = root->left;
            delete root;
            return temp;
        }
        LLRBTNode* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = remove(temp->data, root->right);
    }
    return root;
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
    if(!root){
        return;
    }
    std::string color = root->color == BLACK ? "0" : "1";
    os << root->data << ":" << color << " ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);
    return;
}


void LLRBTree::inorder(LLRBTNode* root, std::ostream& os)
{
    if (root == nullptr)
        return;

    inorder(root->left, os);
    os << root->data << ":" << root->color << " ";
    inorder(root->right, os);
}


void LLRBTree::postorder(LLRBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);

    std::string color = root->color == BLACK ? "0" : "1";
    os << root->data << ":" << color << " ";

    return;
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

LLRBTNode* LLRBTree::getRoot() {
    return _root;
}

void LLRBTree::insert(int data){
    _root = insert(_root, data);
    _root->color = BLACK;
}

void LLRBTree::remove(int data) {
    _root = remove(data, _root);
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
