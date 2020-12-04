// 1. возможность подключать как библиотеку
// храним int
// 2. уметь создавать список

// функции:

// 3. добавлять элементы в список
// 3.1. в начало // push_front
// 3.2. в конец // push_back
// 3.3. в произвольное место (по индексу, нумерация с нуля) // insert
// 3.10. "вставить после" (принимает Node)
// 3.11. "вставить перед" (принимает Node)

// 4. удалять элементы из списка
// 4.1. по значению // remove
// 4.2. по позиции // erase
// 4.3. из начала // pop_front
// 4.4. из конца // pop_back
// 4.10. "удалить после" (принимает Node)
// 4.11. "удалить перед" (принимает Node)

// обработка ошибок не нужна

// 5. количество эл-в в списке // size
// 5.1. bool -> пустой ли список bool empty()

// 6. возможность удалять весь список: освобождается вся память, занятая этим списком // destroy

// 7. поиск: в какой позиции находится нужный элемент -> возвр. позицию 0..size-1 // find
// 7.1. если не находит: -1 или size

// доп задание: функция сортировки связного списка

#include <iostream>
#include <stdlib.h>
#include <memory>

//#include "Node.hpp"
//#include "List.hpp"

int main() {

    int a[5][3] ={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};



//    // Create nodes
//    int nodes[5] = {
//        4, 2, 6, 0, -10
//    };
//
//    // MARK: - Init
//    // Init list
//    List<int> *list1 = new List<int>(nodes[0]);
//
//    // Insert nodes to the list
//    // MARK: - Push back
//    for (int i = 1; i < 5; i++) {
//        list1->pushBack(nodes[i]);
//    }
//
//    list1->printAll();
//    // Prints: 4 2 6 0 -10
//
//
//    // MARK: - Push Front
//    // Insert in front of list
//    list1->pushFront(23);
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: *23* 4 2 6 0 -10
//
//
//    // MARK: - Insert at
//    list1->insertAt(1, 1);
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 1 23 4 2 6 0 -10
//
//    // MARK: - Node at
//    int n = list1->nodeAt(1)->value;
//    std::cout << (n) << std::endl;
//    // Prints: 2
//
//
//    // MARK: - Insert after
//    list1->insertAfter(42, n);
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 1 23 *42* 4 2 6 0 -10
//
//
//    // MARK: - Insert before
//    list1->insertBefore(41, n);
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: *42* 23 41 4 1 2 6 0 -10
//
//
//    // MARK: - Remove element
//    list1->remove(23);
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 42_41 1 2 42 6 0 -10
//
//
//    // MARK: - Erase element
//    list1->eraseAt(0);
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 42 4 1 2 6 0 -10
//
//    list1->popBack();
//    list1->popBack();
//    list1->popBack();
//
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 42 4 1 2 6 0 -10
//
//    int meaningOfLifeIndex = list1->findNode(42);
//    std::cout << "Index of 42: " << meaningOfLifeIndex << '\n';
//    // Prints: 0
//
//    int number = list1->nodeAt(meaningOfLifeIndex)->value;
//    std::cout << "Meaning of life: " << number << '\n';
//    // Prints: 0
//
//    list1->printAll();
//    // Prints: 42 4 2
//
//
//    list1->popFront();
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 4 2
//
//    list1->popFront();
//    std::cout << "Len:" << list1->length << ", ";
//    list1->printAll();
//    // Prints: 2
//
//    list1->destroy();
//
//    list1->printAll();

    return 0;
}
