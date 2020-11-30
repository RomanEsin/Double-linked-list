//
//  List.hpp
//  List
//
//  Created by Roman Esin on 30.11.2020.
//

#ifndef List_hpp
#define List_hpp

#include "Node.hpp"
#include <stdio.h>
#include <iostream>
#include <memory>

template <typename T>
class List {
public:
    /// Length of the list
    int length = 1;

    /// True is empty, false if not empty
    bool isEmpty() {
        return length == 0;
    }

    /// Removes all the elements from the list
    void destroy() {
        length = 0;
        // shared_ptr makes it easy to remoove stuff from memory
        // so when we set it to NULL all the nodes are
        // removed from memory automatically
        head = nullptr;
    }

    /// Prints all elements of the list
    void printAll() {
        using namespace std;

        shared_ptr<Node<T>> current = head;

        while (current != nullptr) {
            cout << current->value << ' ';
            current = current->next;
        }
        cout << endl;
    }

    /// Returns the node at index
    std::shared_ptr<Node<T>> nodeAt(int i) {
        using namespace std;

        int counter = 0;

        // Go to the latest available node
        shared_ptr<Node<T>> current = head;

        while (current != nullptr) {
            // If next is NULL then insert
            if (counter == i) return current;

            current = current->next;
            counter++;
        }

        return nullptr;
    }

    /// Returnds the index of the node
    int findNode(T value) {
        using namespace std;

        int counter = 0;
        shared_ptr<Node<T>> current = head;

        while (current != nullptr) {
            // If next is NULL then insert
            if (current->value == value) return counter;
            current = current->next;
            counter++;
        }

        return -1;
    }

    // MARK: - Insert methoods
    /// Inserts a node at i position
    void insertAt(T value, int i) {
        length++;
        using namespace std;

        int counter = 0;

        shared_ptr<Node<T>> current = head;
        Node<T> newNode = Node<T>{value};

        // Find where to insert
        while (current != nullptr) {
            // If next is NULL then insert
            if (counter == i) {
                shared_ptr<Node<T>> prev = current->prev;

                newNode.prev = prev;
                newNode.next = current;
                prev->next = make_shared<Node<T>>(newNode);

                current = nullptr;
            } else {
                current = current->next;
            }
            counter++;
        }
    }

    /// Inserts node after the given node
    void insertAfter(T value, Node<T> afterNode) {
        length++;
        using namespace std;

        shared_ptr<Node<T>> current = head;
        Node<T> newNode = Node<T>{value};

        // Find where to insert
        while (current != nullptr) {
            // If next is NULL then insert
            if (current->value == afterNode.value) {
                shared_ptr<Node<T>> newNodePtr = make_shared<Node<T>>(newNode);
                newNodePtr->next = current->next;
                current->next = newNodePtr;
                newNodePtr->prev = current;

                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    /// Inserts node before the given node
    void insertBefore(T value, Node<T> beforeNode) {
        using namespace std;

        if (beforeNode.value == head->value) {
            pushFront(value);
            return;
        }

        length++;
        shared_ptr<Node<T>> current = head;
        Node<T> newNode = Node<T>{value};

        // Find where to insert
        while (current != nullptr) {
            // If next is NULL then insert
            if (current->value == beforeNode.value) {
                shared_ptr<Node<T>> newNodePtr = make_shared<Node<T>>(newNode);
                shared_ptr<Node<T>> prev = current->prev;

                prev->next = newNodePtr;
                newNodePtr->next = current;
                newNodePtr->prev = prev;

                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    /// Inserts node to be the last of all other nodes
    void pushBack(T value) {
        length++;
        using namespace std;

        // Go to the latest available node
        shared_ptr<Node<T>> current = head;
        Node<T> newNode = Node<T>{value};

        while (current != nullptr) {
            // If next is NULL then insert
            if (current->next == nullptr) {
                newNode.prev = current;
                current->next = make_shared<Node<T>>(newNode);
                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    /// Inserts node in front of all other nodes
    void pushFront(T value) {
        length++;
        using namespace std;

        Node<T> newNode = Node<T>{value};
        auto newNodePtr = make_shared<Node<T>>(newNode);

        shared_ptr<Node<T>> headCopy = head;
        headCopy->prev = newNodePtr;

        head = newNodePtr;
        head->next = headCopy;
    }

    // MARK: - Remove methods
    /// Removes given node from the list
    void remove(T value) {
        length--;
        using namespace std;
        shared_ptr<Node<T>> current = head;

        if (head->value == value) {
            popFront();
            return;
        }

        while (current != nullptr) {
            // If next is NULL then insert
            if (current->value == value) {
                shared_ptr<Node<T>> prev = current->prev;
                prev->next = current->next;
                current->next->prev = prev;
                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    /// Removes node at the given iterator
    void eraseAt(int i) {
        using namespace std;

        if (i == 0) {
            popFront();
            return;
        }

        length--;

        int counter = 0;
        shared_ptr<Node<T>> current = head;

        while (current != nullptr) {
            // If next is NULL then insert
            if (counter == i - 1) {
                shared_ptr<Node<T>> prev = current->prev;
                prev->next = current->next;
                prev->next->prev = prev;
                current = nullptr;
            } else {
                current = current->next;
            }

            counter++;
        }
    }

    /// Removes element from front
    void popFront() {
        length--;
        head = head->next;
        head->prev = nullptr;
    }

    /// Removes element from back
    void popBack() {
        length--;
        using namespace std;

        if (length == 0) {
            head = nullptr;
            return;
        }

        // Go to the latest available node
        shared_ptr<Node<T>> current = head;

        while (current != nullptr) {
            // If next is NULL then insert
            if (current->next->next == nullptr) {
                current->next = nullptr;
                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    // MARK: - Init method
    // Init
    List(T value) {
        using namespace std;
        head = make_shared<Node<T>>(Node<T>{value});
        length = 1;
    }
private:
    std::shared_ptr<Node<T>> head;
};

#endif /* List_hpp */
