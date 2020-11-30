//
//  Node.hpp
//  List
//
//  Created by Roman Esin on 30.11.2020.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <stdio.h>
#include <memory>

template <typename T>
struct Node {
    /// Stored value
    T value;

    /// Pointer to the previous Node
    std::shared_ptr<Node<T>> prev;
    /// Pointer to the next Node
    std::shared_ptr<Node<T>> next;
};
#endif /* Node_hpp */
