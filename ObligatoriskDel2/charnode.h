#ifndef CHARNODE_H
#define CHARNODE_H
#include <iostream>

template <class T>
class Node
{
private:
    T m_data;
    Node<T>* m_next;
    static int s_size;
public:
    Node();
    Node(char data, Node<T>* next) : m_data{data}, m_next{next} {s_size++;}
    ~Node();
    void print(Node<T> *list);
    void printBackwards();
    Node<T> *getNext() const;
    int getSize() const;
    char getData() const;
    friend std::ostream& operator<< (std::ostream &out, const Node<T> *node);

};



//Static variable
template<class T>
int Node<T>::s_size;
//----------------------------------------------------------------------------------------------
template<class T>
Node<T>::Node()
{
    //Default constructor
}
//----------------------------------------------------------------------------------------------
template<class T>
Node<T>::~Node()
{
    s_size--;
}

//----------------------------------------------------------------------------------------------
template<class T>
void Node<T>::print(Node<T> *list)
{
    while(list)
        {
            std::cout << list->m_data << "\n";
            list = list->m_next;
        }
}
//----------------------------------------------------------------------------------------------
template<class T>
void Node<T>::printBackwards()
{
    if(m_next)
    {
        m_next->printBackwards();
    }
    std::cout << m_data <<" | ";
}

//----------------------------------------------------------------------------------------------

//GETTERS
template<class T>
Node<T> *Node<T>::getNext() const
{
    return m_next;
}
//----------------------------------------------------------------------------------------------
template<class T>
char Node<T>::getData() const
{
    return m_data;
}
//----------------------------------------------------------------------------------------------
template<class T>
int Node<T>::getSize() const
{
    return s_size;
}
//----------------------------------------------------------------------------------------------
//Operator overload
template<class T>
std::ostream& operator<< (std::ostream &out, const Node<T> *node)
{
    out << node->m_data;
    return out;
}
//----------------------------------------------------------------------------------------------
#endif // CHARNODE_H
