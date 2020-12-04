//
//  Node.hpp
//  List
//
//  Created by Roman Esin on 30.11.2020.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>

template <typename T>
struct Node {
    /// Stored value
    T value;

    /// Pointer to the previous Node
    Node<T> *prev;
    /// Pointer to the next Node
    Node<T> *next;

    Node<T>(int val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};
#endif /* Node_hpp */
