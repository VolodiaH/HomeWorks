#pragma once
#include <cstdlib>

class DynamicIntArray
{
public:
    //default c-tor
    DynamicIntArray();

    //c-tor with size
    explicit DynamicIntArray(std::size_t size);

    //copy c-tor
    DynamicIntArray(const DynamicIntArray& other);

    //free allocated memory
    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other);

    // fast access
    int& operator[](std::size_t index) const;

    // slow access, but with check
    int& at(std::size_t index) const;

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize);
    std::size_t getSize() const { return m_size; }

    //Clear internal memory, set size to 0
    void clear();


    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(int element);

private:
    int *m_data;
    size_t m_capacity;
    size_t m_size;
    
};