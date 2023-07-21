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
    int arr[10]{5,2,9,15,23,1,2,8,2,5};
    bubbleSort(arr, 10);
    for (int n : arr)
        std::cout << n << " ";

    std::cout <<"\n";
}

constexpr size_t Columns = 3;
constexpr size_t Rows = 3;
enum class SortingDirection { ByRows, ByColumn };

void print2DArray(int **arr, int numRows, int numColumns)
{
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numColumns; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void sort(int **arr2d, int rows, SortingDirection direction) 
{

    if (direction == SortingDirection::ByRows) 
    {
        int *arr1d = new int[Rows ];
        for (int i = 0; i < Rows; ++i)
        {
            for (int j = 0; j < Columns; ++j)
                arr1d[j] = arr2d[i][j];

            std::sort(arr1d, arr1d +  Columns);

            for (int j = 0; j < Columns; ++j)
                arr2d[i][j] = arr1d[j];
        }
        
        delete[] arr1d;
    }
       
    else
    {
        //I could  not even compile with static 2d array here, code was different with function comparators, even with auto parameters in lambda it didm't compile
        std::cout << "I'm your huckleberry.\nThat's just my game\n";
        for (size_t i{}; i < Rows; ++i)
        {
            int *arr1d = new int[Columns];

            for (size_t j{}; j < Columns; ++j)
                arr1d[j] = arr2d[j][i];

            std::sort(arr1d, arr1d + Columns);

            for (size_t j{}; j < Columns; ++j)
                arr2d[j][i] = arr1d[j];

            delete[] arr1d;
        }
       
    }
      
}

void task2() 
{
    
    int **arr = new int *[Rows];
    for (int i = 0; i < Rows; ++i)
        arr[i] = new int[Columns];

    arr[0][0] = 3; arr[0][1] = 2; arr[0][2] = 5;
    arr[1][0] = 1; arr[1][1] = 4; arr[1][2] = 6;
    arr[2][0] = 7; arr[2][1] = 0; arr[2][2] = 2;

    print2DArray(arr, Rows, Columns);

    sort(arr, 3, SortingDirection::ByRows);
    std::cout << "\n";

    print2DArray(arr, Rows, Columns);

    for (int i = 0; i < Rows; ++i)
        delete[] arr[i];
    delete[] arr;

}
