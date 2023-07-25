#include <iostream>
#include <algorithm>

void task1();
void task2();
int main()
{
    task1();
    task2();
}

void bubbleSort(int arr[], int size)
{
    for (size_t i{}; i < size; ++i)
    {
        for (size_t j{}; j < size; ++j)
            if (arr[i] < arr[j])
                std::swap(arr[i], arr[j]);
    }
}

void task1()
{
    int arr[10]{ 5,2,9,15,23,1,2,8,2,5 };
    bubbleSort(arr, 10);
    for (int n : arr)
        std::cout << n << " ";

    std::cout << "\n";
}

constexpr size_t Columns = 3;
constexpr size_t Rows = 3;
enum class SortingDirection { ByRows, ByColumn };

void print2DArray(int **arr, int numRows, int numColumns)
{
    for (size_t i{}; i < numRows; ++i)
    {
        for (size_t j {}; j < numColumns; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void sort(int **arr2d, SortingDirection direction)
{
    if (direction == SortingDirection::ByRows)
    {
        for (size_t i {}; i < Rows; ++i)
            std::sort(arr2d[i], arr2d[i+1]);
    }
    else
    {
        for (size_t i{}; i < Rows; ++i)
        {
            int arr1d[Columns];

            for (size_t j{}; j < Columns; ++j)
                arr1d[j] = arr2d[j][i];

            std::sort(arr1d, arr1d + Columns);

            for (size_t j{}; j < Columns; ++j)
                arr2d[j][i] = arr1d[j];
        }
    }

}

void task2()
{
    int arr[Rows][Columns]{ {3,2,5},
                            {1,4,6},
                            {7,0,2} };

    int *arr2d[]{ arr[0],arr[1], arr[2] };

    print2DArray(arr2d, Rows, Columns);

    sort(arr2d, SortingDirection::ByRows);
    std::cout << "\n";

    print2DArray(arr2d, Rows, Columns);
}
