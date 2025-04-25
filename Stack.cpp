#include "Stack.h"
#include "VectorStack.h"
#include "ListStack.h"
#include "StackImplementation.h"
#include <stdexcept>
#include <cstdlib>

Stack::Stack(StackContainer container): _containerType(container)
{
    if (container != StackContainer::Vector && container != StackContainer::List)
    {
        throw std::invalid_argument("invalid container type");
    }
    if (container == StackContainer::Vector)
    {
        _pimpl = new VectorStack();
    }
    if(container == StackContainer::List)
    {
        _pimpl = new ListStack();
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container): 
  _containerType(container) 
    {
    if (valueArray == nullptr) 
    {
        throw std::invalid_argument("valueArray is nullptr");
    }
    if (container != StackContainer::Vector && container != StackContainer::List)
    {
        throw std::invalid_argument("invalid container type");
    }
    if (container == StackContainer::Vector)
    {
        _pimpl = new VectorStack();
    }
    if(container == StackContainer::List)
    {
        _pimpl = new ListStack();
    }
    for (size_t i = 0; i != arraySize; ++i) 
    {
        _pimpl->push(valueArray[i]);
    }
}

Stack::Stack(const Stack& copyStack)
{
    *this=copyStack;
}


Stack& Stack::operator=(const Stack& copyStack) 
{
    if (copyStack.isEmpty())
    {
        throw std::invalid_argument("copyStack is nullptr");
    }
    _containerType = copyStack._containerType;
    if (copyStack._containerType == StackContainer::Vector) 
    {
        _pimpl = new VectorStack(*dynamic_cast<VectorStack*>(copyStack._pimpl));
    }
    if (copyStack._containerType == StackContainer::List) 
    {
        _pimpl = new ListStack(*dynamic_cast<ListStack*>(copyStack._pimpl));
    }
    return *this;
}


Stack::Stack(Stack&& moveStack) noexcept
{
    *this=std::move(moveStack);
}


Stack& Stack::operator=(Stack&& moveStack) noexcept 
{
    _pimpl = moveStack._pimpl;
    _containerType = moveStack._containerType;
    moveStack._pimpl = nullptr;
    return *this;
}

Stack::~Stack() 
{
    delete _pimpl;
}

void Stack:: push(const ValueType& value)
{
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack:: top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Stack::size() const
{
   return _pimpl->size();
}













