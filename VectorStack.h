#include "StackImplementation.h"
#include <vector>
#pragma once 


class VectorStack:public IStackImplementation
{
    private:
        std::vector<ValueType> _data;
    public:
        void push(const ValueType& value) override;
        void pop() override;

        const ValueType& top() const override;
        
	bool isEmpty() const override;
        size_t size() const override;
};
