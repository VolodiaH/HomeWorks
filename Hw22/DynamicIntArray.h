#pragma once

#include <algorithm>
#include <memory>
#include <stdexcept>


template <typename T>
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
    ~DynamicIntArray() {delete[] m_data;}

    DynamicIntArray& operator=(const DynamicIntArray& other);

    // fast access, no check
    T & operator[](std::size_t index) const { return m_data[index]; }

    // slow access, with check
    T & at(std::size_t index) const;

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize) { resize(newSize, true); }
    std::size_t getSize() const { return m_size; }

    //Clear internal memory, set size to 0
    void clear() { m_size = 0; }

    T* begin() {return m_data;}
    T* end() {return m_data + m_size;}

    void reserve(size_t capacity);
    std::size_t getCapacity() const { return m_capacity; }
    
    T back() const { return m_data[m_size-1]; }

    // I've got interesting error, implementing it due spaceship operator
    bool operator==(const DynamicIntArray &other) const
    {
        if(m_size != other.m_size)
            return false;
        return std::equal(m_data, m_data + m_size , other.m_data, other.m_data + other.m_size);
    }
    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void pushBack(const T &element);

    void popBack() { --m_size; }

private:
    void resize(size_t size, bool saveSize = false);

    void copyData(T* destination, const T* source, size_t count)
    {
        if (std::is_trivially_copyable_v<T>)
            memcpy(destination, source, count * sizeof(T));
        else
            std::uninitialized_copy(source, source + count, destination);
    }

    T *m_data;
    size_t m_capacity;
    size_t m_size;
    
};

static constexpr int VecDefaultSize = 100;

template<typename T>
DynamicIntArray<T>::DynamicIntArray() :
    m_data{ new T[VecDefaultSize] },
    m_capacity{ VecDefaultSize },
    m_size{ 0 }
{
}
template<typename T>
DynamicIntArray<T>::DynamicIntArray(std::size_t size) :
    m_data{ new T[(size > 0) ? size : VecDefaultSize] },
    m_capacity{ (size > 0) ? size : VecDefaultSize },
    m_size{ size }
{
    std::fill(m_data, m_data + size, T{});
}

template<typename T>
DynamicIntArray<T>::DynamicIntArray(const DynamicIntArray &other) :
    m_data{ new T[other.m_size] },
    m_capacity{ other.m_capacity },
    m_size{ other.m_size }
{
    copyData(m_data, other.m_data, other.m_size);
}

template<typename T>
DynamicIntArray<T> &DynamicIntArray<T>::operator=(const DynamicIntArray &other)
{
    if (&other == this)
        return *this;

    delete[]m_data;

    m_data = new T[other.m_capacity];

    copyData(m_data, other.m_data, other.m_size);

    m_size = other.m_size;
    m_capacity = other.m_capacity;

    return *this;
}

template<typename T>
T &DynamicIntArray<T>::at(std::size_t index) const
{
    if (index < m_size)
        return m_data[index];

    throw std::out_of_range("Index is out of range");
}

template<typename T>
void DynamicIntArray<T>::resize(std::size_t newSize, bool saveSize)
{
    if (newSize == m_size)
        return;

    const size_t copyCount = std::min(newSize, m_size);

    T *tmpArray = new T[newSize];

    copyData(tmpArray, m_data, copyCount);

    std::fill(tmpArray + copyCount, tmpArray + newSize, T{});

    delete[] m_data;

    m_data = tmpArray;
    if(saveSize)
        m_size = newSize;
    m_capacity = newSize;
}

template <typename T>
void DynamicIntArray<T>::reserve(size_t capacity)
{
    if(m_capacity >= capacity)
        return;

    T *tmpArray = new T[capacity];

    copyData(tmpArray, m_data, m_size);

    delete[] m_data;

    m_data = tmpArray;
    m_capacity = capacity;
}

template<typename T>
void DynamicIntArray<T>::pushBack(const T &element)
{
    if (m_capacity == m_size)
        resize(m_capacity * 1.5);

    m_data[m_size++] = element;
}


