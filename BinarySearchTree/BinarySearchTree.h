#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include "Node.h"

class BinarySearchTree{
private:
    Node* root;
    Node* insert(Node* node, int value);
    void destroyTree(Node* node);
    bool search(Node* node, int value) const;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    bool search(int value) const;
};

#endif