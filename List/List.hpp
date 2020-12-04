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

template <typename T>
class List {
public:
    /// Length of the list
    int getLength() {
        return length;
    }

    /// True is empty, false if not empty
    bool isEmpty() {
        return length == 0;
    }

    /// Removes all the elements from the list
    void destroy() {
        length = 0;
        delete head;
        head = nullptr;
    }

    /// Prints all elements of the list
    void printAll() {
        using namespace std;

        Node<T> *current = head;

        while (current != nullptr) {
            cout << current->value << ' ';
            current = current->next;
        }
        cout << endl;
    }

    /// Returns the node at index
    Node<T> *nodeAt(int i) {
        using namespace std;

        int counter = 0;

        // Go to the latest available node
        Node<T> *current = head;

        while (current != nullptr) {
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
        Node<T> *current = head;

        while (current != nullptr) {
            if (current->value == value) return counter;
            current = current->next;
            counter++;
        }

        return -1;
    }

    // MARK: - Insert methoods
    /// Inserts a node at i position
    void insertAt(T value, int i) {
        using namespace std;

        if (i == 0) {
            pushFront(value);
            return;
        }

        length++;

        int counter = 0;

        Node<T> *current = head;
        Node<T> *newNode = new Node<T>(value);

        // Find where to insert
        while (current != nullptr) {
            if (counter + 1 == i) {

                newNode->next = current->next;
                current->next = newNode;
                newNode->prev = current;

                current = nullptr;
            } else {
                current = current->next;
            }
            counter++;
        }
    }

    /// Inserts node after the given node
    void insertAfter(T value, int afterNode) {
        length++;
        using namespace std;

        Node<T> *current = head;
        Node<T> *newNode = new Node<T>(value);

        // Find where to insert
        while (current != nullptr) {
            if (current->value == afterNode) {
                newNode->next = current->next;
                current->next = newNode;
                newNode->prev = current;

                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    /// Inserts node before the given node
    void insertBefore(T value, int beforeNode) {
        using namespace std;

        if (head->value == beforeNode) {
            pushFront(value);
            return;
        }

        length++;
        
        Node<T> *current = head;
        Node<T> *newNode = new Node<T>(value);

        // Find where to insert
        while (current != nullptr) {
            // If next is NULL then insert
            if (current->value == beforeNode) {
                Node<T> *prev = current->prev;

                prev->next = newNode;
                newNode->next = current;
                newNode->prev = prev;

                current = nullptr;
            } else {
                current = current->next;
            }
        }
    }

    /// Inserts node to be the last of all other nodes
    void pushBack(T value) {
        insertAt(value, length - 1);
    }

    /// Inserts node in front of all other nodes
    void pushFront(T value) {
        length++;
        using namespace std;

        Node<T> *newNode = new Node<T>(value);

        Node<T> *headCopy = (Node<int>*) malloc(sizeof(Node<int>));
        memcpy(headCopy, head, sizeof(Node<int>));
        head = newNode;
        headCopy->prev = head;
        head->next = headCopy;
    }

    // MARK: - Remove methods
    /// Removes given node from the list
    void remove(T value) {
        using namespace std;
        Node<T> *current = head;

        if (head->value == value) {
            popFront();
            return;
        }

        length--;

        while (current != nullptr) {
            if (current->value == value) {
                Node<T> *prev = current->prev;
                prev->next = current->next;
                current->next->prev = prev;
                delete current;
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
        Node<T> *current = head;

        while (current != nullptr) {
            if (counter == i - 1) {
                Node<T> *prev = current->prev;
                prev->next = current->next;
                prev->next->prev = prev;
                delete current;
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
        if (length == 0) {
            destroy();
            return;
        }
        
        Node<T> *headCopy = head;
        head = head->next;
        delete headCopy;
        head->prev = nullptr;
    }

    /// Removes element from back
    void popBack() {
        using namespace std;
        if (length == 1) {
            popFront();
            return;
        }

        length--;

        // Go to the latest available node
        Node<T> *current = head;

        while (current != nullptr) {
            if (current->next == nullptr) {
                current->prev->next = nullptr;
                current->prev = nullptr;
                delete current;
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
        head = new Node<T>(value);
        length = 1;
    }
private:
    Node<T> *head;
    int length;
};

#endif /* List_hpp */
