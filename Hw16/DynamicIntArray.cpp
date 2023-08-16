#include "DynamicIntArray.h"

#include <algorithm>
#include <new>

static constexpr int VecDefaultSize = 100;

DynamicIntArray::DynamicIntArray:
m_data{ new int[VecDefaultSize] },
m_capacity{ VecDefaultSize },
m_size{ 0 }
{
}

DynamicIntArray::DynamicIntArray(std::size_t size):
m_data{ new int[(size > 0) ? size : VecDefaultSize ] },
m_capacity{ (size > 0) ? size : VecDefaultSize },
m_size{ (size > 0) ? size : VecDefaultSize }
{

	std::fill_n(m_data, m_capacity, 0);
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other):
m_data{ new int[other.m_size] },
m_capacity{ other.m_capacity },
m_size{ other.m_size }
{
	std::memcpy(m_data, other.m_data, m_size * sizeof(int));
}

DynamicIntArray::~DynamicIntArray()
{
	delete[] m_data;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if(&other == this)
		return *this;

	m_size = other.m_size;
	m_capacity = other.m_capacity;

	delete[]m_data;

	m_data = new int[m_capacity];

	memcpy(m_data, other.m_data, m_size * sizeof(int));
	std::fill(m_data + m_size, m_data + m_capacity, 0);

	return *this;
}

int& DynamicIntArray::operator[](std::size_t index) const
{
	return m_data[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	if(newSize == m_size || m_size <= 0)
		return;

	const size_t copyCount = std::min(newSize, m_size);
	
	int *tmpArray = new int[newSize];

	memcpy(tmpArray, m_data, copyCount * sizeof(int));

	delete[] m_data;

	m_data = tmpArray;

	m_capacity = newSize;
	std::fill(m_data + copyCount, m_data + m_capacity, 0);
}

void DynamicIntArray::clear()
{
	std::fill_n(m_data, m_size, 0);
	m_size = 0;
}

void DynamicIntArray::push_back(int element)
{
	if(m_capacity == m_size)
	{
		if(!m_capacity)
			setSize(VecDefaultSize);
		else
			setSize(m_capacity * 1.5);
	}

	m_data[m_size++] = element;
}


