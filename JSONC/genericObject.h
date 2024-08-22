
#pragma once

#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>

#include "generic.h"

class GenericObject : public Generic
{
private:
    std::shared_ptr<std::unordered_map<std::string, std::shared_ptr<void>>> attributes;

public:
    GenericObject()
    {
        this->attributes = std::make_shared<std::unordered_map<std::string, std::shared_ptr<void>>>();
    }

    virtual ~GenericObject() {}

    template <typename Type> void set(const std::string key, const Type& value)
    {
        if (key == "")
        {
            throw std::runtime_error("Error");
        }

        (*this->attributes)[key] = std::make_shared<Type>(value);
    }

    template <typename Type> Type get(const std::string key)
    {
        if (key == "")
        {
            throw std::runtime_error("Error");
        }

        return *((Type*)((*this->attributes)[key].get()));
    }

    void remove(const std::string key)
    {
        if (key == "")
        {
            throw std::runtime_error("Error");
        }

        (*this->attributes).erase(key);
    }

    void clear()
    {
        (*this->attributes).clear();
    }

    const unsigned long long int size()
    {
        return (*this->attributes).size();
    }

    const bool isFound(const std::string key)
    {
        return (*this->attributes).contains(key);
    }

    const bool isEmpty()
    {
        return (*this->attributes).empty();
    }
};
