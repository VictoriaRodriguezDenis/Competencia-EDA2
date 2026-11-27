#ifndef STACK_IMP
#define STACK_IMP

#include "Stack.h"
#include <cassert>
#include <cstddef>

template <class T>
class StackImp : public Stack<T>
{
private:
    class Node
    {
    public:
        T element;
        Node *next;
        Node(T element, Node *next) : element(element), next(next) {}
    };
    Node *head;
    int size;

public:
    StackImp() : head(NULL), size(0) {}

    void push(T element)
    {
        head = new Node(element, head);
        size++;
    }

    T top()
    {
        assert(!this->isEmpty());
        return head->element;
    }

    T pop()
    {
        assert(!this->isEmpty());
        T element = head->element;
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
        return element;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

#endif
