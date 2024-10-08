#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;

    // Predefined values to insert into the binary search tree
    int valuesToInsert[] = {50, 30, 70, 20, 40, 60, 80};

    // Insert values into the BST
    for (int value : valuesToInsert) {
        bst.insert(value);
        std::cout << "Inserted " << value << " into the tree.\n";
    }

    // Search for specific values
    int valuesToSearch[] = {25, 40, 80, 100};
    for (int value : valuesToSearch) {
        if (bst.search(value)) {
            std::cout << value << " found in the tree.\n";
        } else {
            std::cout << value << " not found in the tree.\n";
        }
    }

    // Find and display the minimum value
    try {
        int minValue = bst.findMin();
        std::cout << "Minimum value: " << minValue << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    // Find and display the maximum value
    try {
        int maxValue = bst.findMax();
        std::cout << "Maximum value: " << maxValue << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    // Display the height of the tree
    std::cout << "Height of the tree: " << bst.findHeight() << "\n";

    // Display BST in level order
    bst.levelOrderTraversal();

    // Display BST in preOrder
    bst.preOrderTraversal();

    // Display BST in inOrder
    bst.inOrderTraversal();

    // Display BST in postOrder
    bst.postOrderTraversal();

    bst.isBinarySearchTree();
    bst.isBstRangeBased();
    bst.isBstInOrder(); // in place in order validation

    // Finding successor and predecessor
    int testValue = 40;
    Node* node = bst.findNode(testValue);
    if (node != nullptr) {
        Node* successor = bst.inOrderSuccessor(node);
        if (successor) {
            std::cout << "In-order Successor of " << testValue << " is: " << successor->data << "\n";
        } else {
            std::cout << "No in-order successor for " << testValue << "\n";
        }

        Node* predecessor = bst.inOrderPredecessor(node);
        if (predecessor) {
            std::cout << "In-order Predecessor of " << testValue << " is: " << predecessor->data << "\n";
        } else {
            std::cout << "No in-order predecessor for " << testValue << "\n";
        }
    } else {
        std::cout << "Node with value " << testValue << " not found in the tree.\n";
    }

    return 0;
}
