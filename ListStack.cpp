#include "Stack.h"
#include "ListStack.h"
#include <list>
#include <stdexcept>



void ListStack::push(const ValueType& value)
{
    _data.push_back(value);
}

void ListStack::pop()
{
    if (_data.size() == 0)
    {
        throw std::out_of_range("list is empty");
    }   
    _data.pop_back();
}

const ValueType& ListStack::top() const
{
    if (_data.size() == 0)
    {
        throw std::out_of_range("list is empty");
    }
    return _data.back();
}

bool ListStack::isEmpty() const
{
    return _data.size() == 0;
}

size_t ListStack::size() const
{
    return _data.size();
}
