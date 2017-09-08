#include <iostream>
#include "charnode.h"
#include "stack.h"
#include <stack>
int main()
{

    ADS101::Stack<char>* stackTest = new ADS101::Stack<char>;
    std::cout << "Stack Size: " <<stackTest->size() << "\n";
    if(stackTest->empty())
    {
        std::cout << "Stack is empty\n";
    }
    else
    {
        std::cout << "Stack has " << stackTest->size() << " elements\n";
    }

    stackTest->push('a');
    std::cout << "Added one new element to stack. Top is now: " << stackTest->top() << "\n";
    stackTest->push('c');
    std::cout << "Added two elements to stack. Top is now: " << stackTest->top() << "\n";
    std::cout << "Stack Size: " <<stackTest->size() << "\n";
    stackTest->pop();
    std::cout << "Removed one element from stack\n";

    if(stackTest->empty())
    {
        std::cout << "Stack is empty\n";
    }
    else
    {
        std::cout << "Stack has " << stackTest->size() << " elements\n";
    }
    for(int i{0}; i <= stackTest->size(); i++)
    {
        stackTest->pop();
    }
    std::cout << "Remove whole stack. Stacksize is now: " << stackTest->size() << "(empty)\n";


    //Testing if new template function is working
    ADS101::Stack<int>* intStack = new ADS101::Stack<int>;
    std::cout << "Added new element to intStack:\n";
    intStack->push(2);
    std::cout << "Added new element to intStack:\n";
    intStack->push(4);
    std::cout << "Top is now: " <<intStack->top();
    std::cout << "\nPrinting out list:\n";
    intStack->getList()->print(intStack->getList());

    for(int i{0}; i <= intStack->size(); i++)
    {
        intStack->pop();
    }
    std::cout << "Remove whole stack. Stacksize is now: " << intStack->size() << "(empty)\n";



    //-----------------std::stack--------------------


    std::cout << "std::stack:\nCreating new object..\n";
    std::stack<int> stdStackTest;
    if(stdStackTest.empty())
    {
        std::cout << "Stack is empty\n";
    }
    else
    {
         std::cout << "Stack has " << stdStackTest.size() << " elements\n";
    }
    stdStackTest.push(5);
    stdStackTest.push(10);
   if(stdStackTest.empty())
   {
       std::cout << "Stack is empty\n";
   }
   else
   {
        std::cout << "Stack has " << stdStackTest.size() << " elements\n";
   }
    stdStackTest.pop();
    std::cout << "Remove top element from stack\n";
    std::cout << "Stack size: " << stdStackTest.size() << "\n";

    for(int i{0}; i < stdStackTest.size() ; i++)
    {
        stdStackTest.pop();
    }
    std::cout << "Remove whole stack. Stacksize is now: " << stdStackTest.size() << "(empty)\n";

    return 0;
}
