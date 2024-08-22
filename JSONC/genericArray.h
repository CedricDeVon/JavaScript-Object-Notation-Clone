
#pragma once

#include <memory>
#include <vector>
#include <stdexcept>

#include "generic.h"

class GenericArray : public Generic
{
private:
    std::shared_ptr<std::vector<std::shared_ptr<void>>> items;

public:
    GenericArray()
    {
        this->items = std::make_shared<std::vector<std::shared_ptr<void>>>();
    }

    virtual ~GenericArray() {}
    
    template <typename Type> Type get(const unsigned long long int index)
    {
        if (index >= this->size())
        {
            throw std::runtime_error("Error");
        }

        return *((Type*)((*this->items)[index].get()));
    }
    
    template <typename Type> void set(const Type& value)
    {
        (*this->items).push_back(std::make_shared<Type>(value));
    }
    
    template <typename Type> void set(const unsigned long long int index, const Type& value)
    {
        if (index >= this->size())
        {
            throw std::runtime_error("Error");
        }

        (*this->items)[index] = std::make_shared<Type>(value);
    }
    
    void remove()
    {
        if (this->size() == 0)
        {
            throw std::runtime_error("Error");
        }

        (*this->items).pop_back();
    }
    
    const bool isEmpty()
    {
        return (*this->items).empty();
    }
    
    const unsigned long long int size()
    {
        return (*this->items).size();
    }
    
    void clear()
    {
        (*this->items).clear();
    }
};
