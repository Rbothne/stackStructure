#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>{
private:
    int itemCount;
    Node<ItemType>* top;
public:
    LinkedStack();
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
    ~LinkedStack();

};
#include "linkedstack.cpp"
#endif