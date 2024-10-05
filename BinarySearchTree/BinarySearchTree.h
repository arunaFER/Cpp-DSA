#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include "Node.h"

class BinarySearchTree{
private:
    Node* root;
    Node* insert(Node* node, int value);
    void destroyTree(Node* node);
    bool search(Node* node, int value) const;
    const int& findMin(Node* node) const;
    const int& findMax(Node* node) const;
    int findHeight(Node* node) const;
    
    void preOrderTraversal(Node* node) const;
    void inOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;

    bool isSubTreeLesser(Node* root, int value) const;
    bool isSubTreeGreater(Node* root, int value) const;
    bool isBinarySearchTree(Node* root) const;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    bool search(int value) const;
    const int& findMin() const;
    const int& findMax() const;
    int findHeight() const;
    
    void levelOrderTraversal() const;
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;

    void isBinarySearchTree() const;
};

#endif