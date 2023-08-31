#pragma once

#include <algorithm>
#include <memory>
#include <stdexcept>


template <typename T, int Size>
class InplaceArray
{
public:
    InplaceArray() = default;

    //c-tor with size
    explicit InplaceArray(std::size_t size);

    //copy c-tor
    InplaceArray(const InplaceArray &other);

    //free allocated memory
    ~InplaceArray(){ delete[] m_dynamicData; }

    InplaceArray &operator=(const InplaceArray &other);

    // fast access, no check
    T &operator[](std::size_t index);

    // slow access, with check
    T &at(std::size_t index) const;

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize)
    {
        if (newSize <= Size)
            m_size = newSize;
        else
        {
            if (m_size < Size)
            {
                std::fill(&m_data[m_size], m_data + Size, T{});
                m_size = Size;
            }
               

            resize(newSize - Size, true);
        }
            
    }
    std::size_t getSize() const { return m_size + m_dynamicSize; }

    //Clear internal memory, set size to 0
    void clear() { m_size = m_dynamicSize = 0;}

    void reserve(size_t capacity);
    std::size_t getCapacity() const { return m_capacity; }

    T back() const ;

    // I've got interesting error, implementing it due spaceship operator
    bool operator==(const InplaceArray &other) const
    {
        if (m_size != other.m_size || 
            m_dynamicSize != other.m_dynamicSize)
            return false;

        return std::equal(m_dynamicData, m_dynamicData + m_dynamicSize, other.m_dynamicData, other.m_dynamicData + other.m_dynamicSize) &&
            std::equal(m_data, m_data + m_dynamicSize, other.m_data, other.m_data + other.m_data);
    }
    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void pushBack(const T &element);

    void popBack();
    
private:
    void allocateMemory(size_t size);
    void resize(size_t size, bool saveSize = false);

    void copyData(T *destination, const T *source, size_t count)
    {
        if (std::is_trivially_copyable_v<T>)
            memcpy(destination, source, count * sizeof(T));
        else
            std::uninitialized_copy(source, source + count, destination);
    }
    T m_data[Size]{};
    T *m_dynamicData {nullptr};
    size_t m_capacity{};
    size_t m_size{};
    size_t m_dynamicSize{ };

};



static constexpr int ArrayDefaultSize = 5;

template<typename T, int Size>
InplaceArray<T, Size>::InplaceArray(std::size_t size) :
    m_dynamicSize{ size > 0 ? size : ArrayDefaultSize }
{
    if(size >= Size)
        std::fill(m_data, m_data + size, T{}), m_size = Size;

    if (size > Size)
        allocateMemory(size - Size);
}

template<typename T, int Size>
InplaceArray<T, Size>::InplaceArray(const InplaceArray &other) :
m_dynamicData{ new T[other.m_dynamicSize]},
m_capacity{ other.m_capacity },
m_size{ other.m_size },
m_dynamicSize{other.m_dynamicSize}
{
    copyData(m_dynamicData, other.m_dynamicData, m_dynamicSize);
    copyData(m_data, other.m_data, m_size);
}

template<typename T, int Size>
InplaceArray<T,Size> &InplaceArray<T,Size>::operator=(const InplaceArray &other)
{
    if (&other == this)
        return *this;

    delete[]m_dynamicData;

    m_dynamicData = new T[other.m_capacity];

    copyData(m_dynamicData, other.m_dynamicData, other.m_dynamicSize);
    copyData(m_data, other.m_data, other.m_size);

    m_size = other.m_size;
    m_capacity = other.m_capacity;

    return *this;
}


template<typename T, int Size>
T &InplaceArray<T,Size>::operator[](std::size_t index)
{
    if (index < Size)
        return m_data[index];

    return m_dynamicData[index - Size];
}

template<typename T, int Size>
T &InplaceArray<T,Size>::at(std::size_t index) const
{
    if(index < Size)
        return m_data[index];

    if (index < m_size)
        return m_dynamicData[index - Size];

    throw std::out_of_range("Index is out of range");
}

template<typename T, int Size>
void InplaceArray<T,Size>::resize(std::size_t newSize, bool saveSize)
{
    if (newSize == m_dynamicSize)
        return;

    const size_t copyCount = std::min(newSize, m_dynamicSize);

    T *tmpArray = new T[newSize];

    copyData(tmpArray, m_dynamicData, copyCount);

    std::fill(tmpArray + copyCount, tmpArray + newSize, T{});

    delete[] m_dynamicData;

    m_dynamicData = tmpArray;
    if (saveSize)
        m_dynamicSize = newSize;
    m_capacity = newSize;
}

template<typename T, int Size>
void InplaceArray<T,Size>::reserve(size_t capacity)
{
    if (m_capacity >= capacity)
        return;

    T *tmpArray = new T[capacity];

    copyData(tmpArray, m_dynamicData, m_size);

    delete[] m_dynamicData;

    m_dynamicData = tmpArray;
    m_capacity = capacity;
}

template<typename T, int Size>
void InplaceArray<T,Size>::pushBack(const T &element)
{
    if(m_size < Size)
    {
        m_data[m_size++] = element;
        return;
    }

    if (m_capacity == m_dynamicSize)
    {
        if (!m_capacity)
            resize(ArrayDefaultSize);
        else
            resize(m_capacity * 1.5);
    }
        

    m_dynamicData[m_dynamicSize++] = element;
}

template<typename T, int Size>
void InplaceArray<T, Size>::allocateMemory(size_t size)
{
    m_dynamicSize = size;
    m_dynamicData = new T[size];
    std::fill(m_dynamicData, m_dynamicData + size, T{});
}

template <typename T, int Size>
T InplaceArray<T, Size>::back() const
{
    if(m_size)
        return m_data[m_size - 1];

    if(m_dynamicSize)
        return m_dynamicData[m_dynamicSize - 1];

    throw std::exception("back() called on empty vector");
}

template <typename T, int Size>
void InplaceArray<T, Size>::popBack()
{
    if(m_dynamicSize)
    {
        --m_dynamicSize;
        return;
    }

    if (m_size)
    {
        --m_size;
        return;
    }

    throw std::exception("popBack() called on empty vector");
}

