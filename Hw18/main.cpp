#include <iostream>
#include <memory>
#include <boost/algorithm/string.hpp>

//CASE 1
class A
{
public:
    A()
    {
        std::cout << "A()" << '\n';
    }

    virtual ~A()
    {
        std::cout << "~A()" << '\n';
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B()" << '\n';
    }

    ~B()
    {
        std::cout << "~B()" << '\n';
    }

    void print() const
    {
        std::cout << "B::print()" << '\n';
    }

    void print(const std::string &text) const
    {
        std::cout << text << '\n';
    }
};


//CASE 2
class Base {
public:
    virtual void print()  {
        std::cout << "Base" << '\n';
    }
};

class Derived1 : public Base {
public:
    void print() override {
        std::cout << "Derived1" << '\n';
    }
};

class Derived2 : public Base {
public:
    void print() override {
        std::cout << "Derived2" << '\n';
    }
};



//CASE 3
class Animal
{
public:
    virtual ~Animal() = default;

    virtual void eat() const {}

    virtual void sleep()
    {
        std::cout << "Animal sleep method\n";
    }
};

class Dog : public Animal
{
public:
    void eat() const override
    {
        std::cout << "Dog eating" << ++m_eatCallsCounter << '\n';
    }

private:
    mutable int m_eatCallsCounter = 0;
};

class Cat : public Animal
{
public:
    void eat() const override
    {
        std::cout << "Cat eating\n";
    }
};

std::unique_ptr<Animal> createAnimal(std::string &pet)
{
    boost::algorithm::to_lower(pet);

    // That was a lot of memory leaks!
    if (pet == "dog")  return std::make_unique<Dog>();
    if (pet == "cat") return std::make_unique<Cat>();

    return std::make_unique<Animal>();
}

int main()
{
    //CASE 1
    const std::unique_ptr<A> a = std::make_unique<B>();

    if(const B *b = dynamic_cast<B *>(a.get()))
    {
        b->print("sdf");
        b->print();
    }


    //CASE 2
    const std::unique_ptr<Base> b1 = std::make_unique<Base>();
    const std::unique_ptr<Base> d1 = std::make_unique<Derived1>();
    const std::unique_ptr<Base> d2 = std::make_unique<Derived2>();

    b1->print();
    d1->print();
    d2->print();


    //CASE 3
    std::string petChoice;
    std::cout << "Choose your pet:(Dog/Cat):";
    std::cin >> petChoice;
   

    std::unique_ptr<Animal> animal = createAnimal(petChoice);
    animal->eat();
  
}

