// recursive.c -- DangLHb
//----------------Function Array-----------------
#include"link_list.h"
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

//--------------------Function link-list-----------------------------
//find max by recursive
int max_link_list(node head, int n)
{
	node p = head;
	if(n == 0)
		return - 1;
	if(n == 1)
		return p->nums;
	printf("----%d\n",get_value_of_node(head,n - 1));
	if(get_value_of_node(head, n - 1) > max_link_list(head, n - 1))
		return get_value_of_node(head, n - 1);
	else return max_link_list(head, n - 1);
}