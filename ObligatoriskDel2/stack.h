#ifndef STACK_H
#define STACK_H
#include "charnode.h"

namespace ADS101
{   template<class T>
    class Stack
    {
    private:
        Node<T>* list;
    public:
        Stack(): list{nullptr} {}
        ~Stack();
        void push(T data);
        void pop();
        int size() const;
        bool empty() const;
        T top() const;
        Node<T>* getList();
    };
}

//----------------------------------------------------------------------------------------------
using namespace ADS101;
template<class T>
void Stack<T>::push(T data)
{
    list = new Node<T>(data, list);
}
//----------------------------------------------------------------------------------------------
template<class T>
void Stack<T>::pop()
{
    if(list)
    {
        Node<T>* out = list;
        list = list->getNext();
        delete out;
    }
}
//----------------------------------------------------------------------------------------------
template<class T>
int Stack<T>::size() const
{
    return list ? list->getSize() : 0;
}
//----------------------------------------------------------------------------------------------
template<class T>
bool Stack<T>::empty() const
{
    return !list ? true : false;
}
//----------------------------------------------------------------------------------------------
template<class T>
T Stack<T>::top() const
{
    if(list)
    {
        return list->getData();
    }
    else
    {
        return -1;
    }
}
//----------------------------------------------------------------------------------------------
template<class T>
Node<T>* Stack<T>::getList()
{
    return list;
}
//----------------------------------------------------------------------------------------------
#endif // STACK_H
