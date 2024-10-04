#include <iostream>

#include "BinarySearchTree.h"

void displayMenu() {
    std::cout << "Binary Search Tree Menu:\n";
    std::cout << "1. Insert a value\n";
    std::cout << "2. Search for a value\n";
    std::cout << "3. Find minimum value\n";
    std::cout << "4. Find maximum value\n";
    std::cout << "0. Exit\n";
}

int main() {
    BinarySearchTree bst;
    int choice;
    int value;

    do { 
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Insert a value
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                bst.insert(value);
                std::cout << "Inserted " << value << " into the tree.\n";
                break;

            case 2: // Search for a value
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (bst.search(value)) {
                    std::cout << value << " found in the tree.\n";
                } else {
                    std::cout << value << " not found in the tree.\n";
                }
                break;

            case 3: // find min value
                try {
                        const int& minValue = bst.findMin();
                        std::cout << "Minimum value: " << minValue << "\n";
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << "\n";
                    }
                break;

            case 4: // find max value
                try {
                        const int& maxValue = bst.findMax();
                        std::cout << "Maximum value: " << maxValue << "\n";
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << "\n";
                    }
                break;

            case 0: // Exit
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
