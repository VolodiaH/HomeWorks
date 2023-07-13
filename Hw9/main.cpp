#include <iostream>

void task1();
void task2();
void task3();

int main()
{
	task1();
	task2();
	task3();
}

void swap(int &left, int &right) noexcept
{
	const int tmp{ left };
	left = right;
	right = tmp;
}
void swap(int *left, int *right) noexcept
{
	const int tmp{ *left };
	*left = *right;
	*right = tmp;
}

void task1()
{
	int a{ 5 };
	int b{ 3 };
	int c{ 4 };
	int d{ 9 };

	swap(a, b);
	swap(&c, &d);
}

bool calculateSum(const double *arr, int arrSize, double &sum) 
{
	if (arrSize < 0)
		return false;

	for (; arrSize; --arrSize, ++arr)
		sum += *arr;

	return true;

}

void task2() 
{
	double arr[] = { 2.5,2,6.7,5.6 };

	double sum{};
	bool res = calculateSum(arr, sizeof(arr) / sizeof(double), sum);
}

bool find(const int *arr, int arrSize, int elem) 
{

	for (; arrSize; ++arr, --arrSize)
	{
		if (*arr == elem)
			return true;
	}
	return false;
}

void task3() 
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	bool res = find(arr, sizeof(arr) / sizeof(int), 4);
	std::cout << std::boolalpha << res;
}
