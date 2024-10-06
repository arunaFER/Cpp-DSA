#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include <vector>

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
    
    // printing
    void preOrderTraversal(Node* node) const;
    void inOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;

    // check bst naive method
    bool isSubTreeLesser(Node* root, int value) const;
    bool isSubTreeGreater(Node* root, int value) const;
    bool isBinarySearchTree(Node* root) const;

    // check bst min max or range based
    bool isBSTUtilRangeBased(Node* root, int minValue, int maxValue) const;

    // check if bst using inOrder
    // void isBstInOrderTraversal(Node* node, std::vector<int> &vector);
    // bool isBstInOrderUtil();

    bool isBstInOrderTraversal(Node* node, int &prev); // in place validation

    Node* findMinNode(Node* node);
    Node* deleteNodeHelper(Node* root, int data);
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
    void isBstRangeBased() const;
    void isBstInOrder();

    void deleteNode(int data);
};

#endif