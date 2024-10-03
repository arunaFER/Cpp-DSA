#include <iostream>

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
