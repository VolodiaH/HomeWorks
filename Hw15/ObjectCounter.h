#pragma once

template<class T>
class ObjectCounter
{
public: 
	ObjectCounter() { ++m_createdObjects; }
	ObjectCounter(const ObjectCounter&) { ++m_createdObjects; }
	~ObjectCounter(){ --m_createdObjects; }

	static size_t CreatedObjects() { return  m_createdObjects;  }

private:
	static size_t m_createdObjects;
};


