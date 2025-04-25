#pragma once 
#include "StackImplementation.h"
#include <list>


class ListStack:public IStackImplementation
{
    private:
        std::list<ValueType> _data;
    public:
        void push(const ValueType& value) override;
        void pop() override;
        
	const ValueType& top() const override;
        
	bool isEmpty() const override;
        
	size_t size() const override;
};
