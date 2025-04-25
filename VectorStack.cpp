#include "Stack.h"
#include "VectorStack.h"
#include <vector>
#include <stdexcept>


void VectorStack::push(const ValueType& value)
{
    _data.push_back(value);
}

void VectorStack::pop()
{
    if (_data.size() == 0)
    {
        throw std::out_of_range("vector is empty");
    }    
    _data.pop_back();
}

const ValueType& VectorStack::top() const
{
    if (_data.size() == 0)
    {
        throw std::out_of_range("vector is empty");
    }
    return _data.back();
}

bool VectorStack::isEmpty() const
{
    return _data.size() == 0;
}

size_t VectorStack::size() const
{
    return _data.size();
}
