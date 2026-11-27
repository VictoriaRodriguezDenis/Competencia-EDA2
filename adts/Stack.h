#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
    // pre: -
    // post: the element is inserted at the top of the stack
    virtual void push(T element) = 0;

    // pre: the stack is not empty
    // post: returns the element at the top of the stack
    virtual T top() = 0;

    // pre: the stack is not empty
    // post: returns the element at the top of the stack and removes it from the stack
    virtual T pop() = 0;

    // pre: -
    // post: returns if the stack is empty
    virtual bool isEmpty() = 0;
};

#endif
