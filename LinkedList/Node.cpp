#include <iostream>

#include "Node.h"

Node::Node(int value)
    :data{value}, next{nullptr}{
        // std::cout << "---Using Node Constructor---" << std::endl;
}