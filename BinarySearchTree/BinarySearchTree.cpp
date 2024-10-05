#include <iostream>
#include <queue>

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


// Private functions

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