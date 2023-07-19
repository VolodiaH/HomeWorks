#include <iostream>
#include <format>

void task1();
void task2();
void task3();

int main() 
{
    task1();
    task2();
    task3();
}

constexpr size_t Rows = 3;
constexpr size_t Columns = 4;

bool find(const int arr[Rows][Columns],  int value)
{
    for (size_t i{}; i < Rows; ++i)
    {
        for (size_t j{}; j < Columns; ++j)
            if (arr[i][j] == value)
                return true;
    }
    return false;
}

void task1() 
{
    int arr[3][4]{ {1,2,3,123},
                   {4,5,6,456},
                   {7,8,9,789}};
    bool found = find(arr, 5);

    std::cout <<  std::format("Found: {}\n", found);
}

enum class SortingDirection 
{
    ascending,
    descending
};

constexpr size_t ArrSize = 10;

bool isSorted(const int *arr, int size, SortingDirection direction) 
{
    for (int i{}; i < size - 1; ++i)
    {
        if (direction == SortingDirection::ascending)
        {
            if (!(arr[i] < arr[i + 1]))
                return false;
        }  
        else
        {
            if (!(arr[i] > arr[i + 1]))
                return false;
        }
    }

    return true;
}

void task2() 
{
    int arrAscending[ArrSize]{ 1,2,3,4,5,6,7,8,9,10 };
    int arrDescending[ArrSize]{ 10,9,8,7,6,5,4,3,2,1 };
   
    bool orderAscending = isSorted(arrAscending, ArrSize, SortingDirection::ascending);
    bool orderDescending = isSorted(arrDescending, ArrSize, SortingDirection::descending);

    std::cout << std::format("Order is ascending: {}\n", orderAscending);
    std::cout << std::format("Order is descending: {}\n", orderDescending);
}

void traverseSnakeByRows(const int arr[Rows][Columns])
{
    bool fromBegining = true;
    for (int i{ Rows - 1}; i >= 0; --i)
    {
        int j{};

        if (!fromBegining)
            j = Columns - 1;

        while (j < Columns) 
        {
            // decided to add if (j < 0) because on my machine... it works fine without this if and without infinite loop
            // do not quite understand why it is not an infinite loop on my machine... strange...

            if (j < 0)
                break;
            
            std::cout << arr[i][j] << " ";

            if (fromBegining)
                ++j;
            else
                --j;  
        }
        std::cout << "\n";

        fromBegining = !fromBegining;        
    }
}

void traverseTopToBottom(const int arr[Rows][Columns]) 
{
    for (int i{ Columns - 1 }; i >= 0; --i)
    {
        for (size_t j{}; j < Rows; ++j)
            std::cout << arr[j][i] << " ";
        std::cout << "\n";
    }
}

void task3() 
{
    int arr[3][4]{ {1,2,3,123},
                  {4,5,6,456},
                  {7,8,9,789} };

    traverseTopToBottom(arr);
    traverseSnakeByRows(arr);
}
