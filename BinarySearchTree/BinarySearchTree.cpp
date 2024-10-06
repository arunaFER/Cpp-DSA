#include <iostream>
#include <queue>
#include <climits>
#include <vector>

#include "Node.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
    :root{nullptr}{
}

BinarySearchTree::~BinarySearchTree(){
    destroyTree(root);
}

void BinarySearchTree::insert(int value){
    root = insert(root, value);
}

bool BinarySearchTree::search(int value) const{
    return search(root, value);
}

int BinarySearchTree::findHeight() const{
    return findHeight(root);
}

// check out optional in c++17
const int& BinarySearchTree::findMin() const{
   if (root == nullptr){
        throw std::runtime_error("Binary search tree is empty");
   } else {
        return findMin(root);
   }
}

const int& BinarySearchTree::findMax() const{
   if (root == nullptr){
        throw std::runtime_error("Binary search tree is empty");
   } else {
        return findMax(root);
   }
}

void BinarySearchTree::levelOrderTraversal() const{
    if (root == nullptr){
        std::cout << "LevelOrderTraversal: Empty tree!" << std::endl;
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    std::cout << "LevelOrderTraversal: ";

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        
        std::cout << current->data << " ";

        if (current->left != nullptr){
            q.push(current->left);
        }

        if (current->right != nullptr){
            q.push(current->right);
        }
    }
    
    std::cout << std::endl;
}

void BinarySearchTree::preOrderTraversal() const{
    if (root == nullptr){
        std::cout << "PreOrderTraversal: Empty tree!" << std::endl;
        return;
    }

    std::cout << "PreOrderTraversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;
}

void BinarySearchTree::inOrderTraversal() const{
    if (root == nullptr){
        std::cout << "inOrderTraversal: Empty tree!" << std::endl;
        return;
    }

    std::cout << "inOrderTraversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;
}

void BinarySearchTree::postOrderTraversal() const{
    if (root == nullptr){
        std::cout << "postOrderTraversal: Empty tree!" << std::endl;
        return;
    }

    std::cout << "postOrderTraversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;
}

void BinarySearchTree::isBinarySearchTree() const{
    if (root == nullptr){
            std::cout << "isBinarySearchTree: Empty tree!" << std::endl;
            return;
    }

    if (isBinarySearchTree(root)){
        std::cout << "isBinarySearchTree: true!" << std::endl;
    } else {
        std::cout << "isBinarySearchTree: false!" << std::endl;
    }
}

void BinarySearchTree::isBstRangeBased() const{
    if (root == nullptr){
            std::cout << "isBinarySearchTree: Empty tree!" << std::endl;
            return;
    }

    if (isBSTUtilRangeBased(root, INT_MIN, INT_MAX)){
        std::cout << "isBinarySearchTree: true!" << std::endl;
    } else {
        std::cout << "isBinarySearchTree: false!" << std::endl;
    }
}

// void BinarySearchTree::isBstInOrder(){
//     if (isBstInOrderUtil()){
//         std::cout << "isBinarySearchTree: true!" << std::endl;
//     } else {
//         std::cout << "isBinarySearchTree: false!" << std::endl;
//     }
// }

void BinarySearchTree::isBstInOrder(){
    if (root == nullptr){
            std::cout << "isBinarySearchTree: Empty tree!" << std::endl;
            return;
    }

    int prev = INT_MIN;
    if (isBstInOrderTraversal(root, prev)){
        std::cout << "isBinarySearchTree: true!" << std::endl;
    } else {
        std::cout << "isBinarySearchTree: false!" << std::endl;
    }
}

/*
################### Private functions ###################
*/

Node* BinarySearchTree::insert(Node* node, int value){
    if (node == nullptr){
        return new Node(value); // create the new Node
    }

    if (value < node->data){
        node->left = insert(node->left, value);
    } else if (value > node->data){
        node->right = insert(node->right, value);
    } 

    return node;
}

void BinarySearchTree::destroyTree(Node* node){
    if (node != nullptr){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

bool BinarySearchTree::search(Node* node, int value) const{
    if (node == nullptr){
        return false;
    }
    if (value == node->data){
        return true;
    }
    if (value < node->data){
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

const int& BinarySearchTree::findMin(Node* node) const{
    if (node->left == nullptr){
        return node->data;
    }
    return findMin(node->left);
}

const int& BinarySearchTree::findMax(Node* node) const{
    if (node->right == nullptr){
        return node->data;
    }
    return findMax(node->right);
}

int BinarySearchTree::findHeight(Node* node) const{
    if (node == nullptr){
        return -1;
    }

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}

void BinarySearchTree::preOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void BinarySearchTree::inOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;

    inOrderTraversal(node->left);
    std::cout << node->data << " ";
    inOrderTraversal(node->right);
}

void BinarySearchTree::postOrderTraversal(Node* node) const{
    if (node == nullptr)
        return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << " ";
}

bool BinarySearchTree::isSubTreeLesser(Node* root, int value) const{
    if (root == nullptr){
        return true;
    }

    if (root->data < value
        && isSubTreeLesser(root->left, value)
        && isSubTreeLesser(root->right, value)){
            return true;
    } else {
        return false;
    }
}

bool BinarySearchTree::isSubTreeGreater(Node* root, int value) const{
    if (root == nullptr){
        return true;
    }

    if (root->data > value
        && isSubTreeGreater(root->left, value)
        && isSubTreeGreater(root->right, value)){
            return true;
    } else {
        return false;
    }
}

bool BinarySearchTree::isBinarySearchTree(Node* root) const{
    if (root == nullptr)
        return true;

    if (isSubTreeLesser(root->left, root->data)
        && isSubTreeGreater(root->right, root->data)
        && isBinarySearchTree(root->left)
        && isBinarySearchTree(root->right)){
            return true;
    } else {
        return false;
    }
}

bool BinarySearchTree::isBSTUtilRangeBased(Node* root, int minValue, int maxValue) const{
    if (root == nullptr)
        return true;

    if (root->data > minValue 
        && root->data < maxValue
        && isBSTUtilRangeBased(root->left, minValue, root->data)
        && isBSTUtilRangeBased(root->right, root->data, maxValue)){
            return true;
    } else {
        return false;
    }
}

// in order bst check but using additional vector

// void BinarySearchTree::isBstInOrderTraversal(Node* node, std::vector<int> &vector){
//     if (node == nullptr)
//         return;

//     isBstInOrderTraversal(node->left, vector);
//     vector.push_back(node->data);
//     isBstInOrderTraversal(node->right, vector);
// }

// bool BinarySearchTree::isBstInOrderUtil(){
//     if (root == nullptr){
//             std::cout << "isBinarySearchTree: Empty tree!" << std::endl;
//             return false;
//     }

//     std::vector<int> sortedVector;
//     isBstInOrderTraversal(root, sortedVector);

//     for (size_t i {1}; i < sortedVector.size(); ++i){
//         if (sortedVector.at(i) < sortedVector.at(i - 1))
//             return false;
//     }

//     return true;
// }

// in order IN_PLACE bst check
// left, root, right
bool BinarySearchTree::isBstInOrderTraversal(Node* node, int &prev){
    if (node == nullptr)
        return true;

    // check for left node first
    if (!isBstInOrderTraversal(node->left, prev)){
        return false;
    }

    // check root
    if (node->data <= prev)
        return false;

    // Before we go to right, now prev value
    // is current node value.
    // ie. all right node values must be greater
    prev = node->data;

    // check right node finally
    return isBstInOrderTraversal(node->right, prev);
}