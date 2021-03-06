#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};

int sum_by_rows(int **a, int n, int m)
{
	int sum = 0, i, j;
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			sum += a[i][j];

	return sum;	
}

int main()
{
	Timer t;
	int n = 10000;
	int m = 10000;

	int **a, i ,j;

	a = new int*[n];
	for (i = 0; i < n; i ++)
		a[i] = new int[m];

	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
				 a[i][j] = 2;

	sum_by_rows (a, n ,m);

	for (i = 0; i < n; i ++)
		delete[] a[i];
	delete []a;
	return 0;					
}

