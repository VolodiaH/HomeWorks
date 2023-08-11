#include <iostream>
#include <numeric>
#include <algorithm>
#include <span> 

constexpr size_t MarksCount{ 4 };

struct Student
{
    const char* name;
    int marks[MarksCount];
};

std::ostream &operator<<(std::ostream &os, const Student &st)
{
    os << "Age: " << st.name << "\n";

    os << "Marks: ";
    for (const auto& n : st.marks)
        os << n << " ";

    os << "\n";
    return os;
}

void task1();
void task2();
void task3();

int main() 
{
    task1();
    task2();
    task3();
}

double calcStudentAverage(const Student &student) 
{
    return std::reduce(student.marks, student.marks + MarksCount, 0.0) / MarksCount;
}

void task1() 
{
    constexpr Student st{ "Leon",{1,2,3,4}};
    std::cout << "Average mark is: " << calcStudentAverage(st) << "\n";
}

bool compareStudents(const Student &left, const Student &right)
{
    return calcStudentAverage(left) > calcStudentAverage(right);
}

void task2() 
{
    Student students[3]{  {"Chris",{3,5,6,7}}, {"Albert",{1,2,3,4}},{"Jill",{34,12,67,56}}};

    std::sort(students, students + 3, compareStudents);

    for (const auto &st : students)
        std::cout << st;
}

// Sonar: S6188 Replace these two parameters(const Student& students, const size_t size) with a more generic std::span object
Student &bestStudent(const std::span<Student> &students)
{
    Student *st = students.data();
    for (size_t i{ 1 }; i < students.size(); ++i) 
    {
        if (calcStudentAverage(*st) < calcStudentAverage(students[i]))
            st = &students[i];
    }

    return *st;
}

size_t countGoodStudents(const std::span<Student> &students)
{
    size_t res{};

    for (auto &student : students)
    {
        if (calcStudentAverage(student) >= 75)
            ++res;
    }

    return res;
}

void task3() 
{
    Student students[5]{ {"Chris",{3,5,6,7}}, {"Leon",{1,2,3,4}},{"Ada",{34,12,67,56}}, {"Claire", {78,75,90,100}}, {"Carlos",{100,56,92,88}}};

    std::cout << bestStudent(students);

    std::cout << "Count of best students: " << countGoodStudents(students) << "\n";
}

