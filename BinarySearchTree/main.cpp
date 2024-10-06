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
    bst.isBstInOrder();

    return 0;
}
