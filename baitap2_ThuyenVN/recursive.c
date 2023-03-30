// recursive.c -- DangLHb
//----------------Function Array-----------------
#include"recursive.h"

int max_2(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
// Ham tinh max se tinh max cua 2 phan tu dau tien trong mang, duoc ket qua bao nhieu so sanh voi phan tu tiep theo trong mang
int max_arr_danglhb(int arr[], int sum, int result_max)
{
	if(sum == 0)
		return -1;
	if(sum == 1)
		return result_max;

	result_max = max_2(result_max, *(arr + sum - 2));

	return max_arr_danglhb(arr, sum - 1, result_max);
}

// Ham max tren mang
int max_arr_internet(int arr[], int sum)
{
	if(sum == 0)
		return -1;
	if(sum == 1)
		return *arr;
	else
	{
		if(arr[sum - 1] > max_arr_internet(arr, sum - 1))
			return arr[sum - 1];
		else 
			return max_arr_internet(arr, sum - 1);
	}
}

int cal_lt (int n)
{
	if(n = 1)
	{
		return 1;
	}
	else 
		return n*cal_lt(n - 1);
}

int sum_2(int a, int b)
{
	return a + b;
}

int sum_arr_danglhb(int arr[], int n, int result_sum)
{
	if(n == 0)
		return -1;
	if(n == 1)
		return *arr;
	else
	{
		result_sum = *(arr + n -1) + sum_arr_danglhb(arr, n - 1, result_sum);
		return result_sum;
	}
}


int sum_arr_danglhb_2(int arr[], int n)
{
	if(n == 0)
		return -1;
	if(n == 1)
		return *arr;
	else
		return *(arr+ n - 1) + sum_arr_danglhb_2(arr, n - 1);
}

// int main()
// {
// 	int arr[10] = {0,1,1,1,1,1,1,1,1,1};
// 	int result_max = *(arr + 9);
// 	int max = max_arr_danglhb(arr, 10, result_max);
// 	printf("max =  %d\n", max);
// 	// int sum = sum_arr_danglhb(arr, 10, 0);
// 	int sum = sum_arr_danglhb_2(arr, 10);
// 	printf("sum = %d\n", sum);
// 	return 0;
// }
//--------------------Function link-list-----------------------------