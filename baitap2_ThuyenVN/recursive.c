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
		return *arr;

	result_max = max_2(result_max, *(arr + sum - 2));

	return max_arr_danglhb(arr, sum - 1, result_max);
}

// Ham max tren mang
int max_arr_danglhb_2(int arr[], int sum)
{
	if(sum == 0)
		return -1;
	if(sum == 1)
		return *arr;
	else
	{
		if(arr[sum - 1] > max_arr_danglhb_2(arr, sum - 1))
			return arr[sum - 1];
		else 
			return max_arr_danglhb_2(arr, sum - 1);
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
//single
int max_link_list(node *head, int n)
{
	node *p = head;
	if(n == 0)
		return - 1;
	if(n == 1)
		return p->nums;
	// printf("----%d\n",get_value_of_node(head,n - 1));
	if(get_value_of_node(head, n - 1) > max_link_list(head, n - 1))
		return get_value_of_node(head, n - 1);
	else return max_link_list(head, n - 1);
}

// dau vao n la tong so node trong list , result_max gia tri cua node cuoi cung
int max_link_list_danglhb(node *head, int n, int result_max)
{
	node *p = head;
	if(n == 0)
		return -1;
	if(n == 1)
		return p->nums;
	result_max = max_2(result_max,get_value_of_node(head, n - 2));
	return max_link_list_danglhb(head, n - 1, result_max);
}

//ham tinh tong
int sum_link_list(node *head, int n)
{
	node *p = head;

	if(n == 0)
		return - 1;
	if(n == 1)
		return p->nums;
	
	return get_value_of_node(head,n - 1) + sum_link_list(head, n - 1);
}

//double
//ham tim max trong double link list
int max_link_list_double(ll_double list_double, int n)
{
	node_double *p = list_double.head;
	if(n == 0)
		return - 1;
	if(n == 1)
		return p->data;
	if(get_value_of_node_double(list_double, n - 1) > max_link_list_double(list_double, n - 1))
		return get_value_of_node_double(list_double, n - 1);
	else
		return max_link_list_double(list_double, n - 1);
}
//n la tong so node trong list
//result_max la gia tri cua node cuoi cung trong list.
int max_link_list_double_danglhb(ll_double list_double, int n, int result_max)
{
	node_double *p = list_double.head;
	if (n == 0)
	{
		return -1;
	}
	if (n == 1)
	{
		return p->data;
	}
	result_max = max_2(result_max, get_value_of_node_double(list_double, n - 2));
	return max_link_list_double_danglhb(list_double, n - 1, result_max);
}

// ham tinh tong gia tri cac node trong double
// n la tong so node trong list
int sum_link_list_double(ll_double list_double, int n)
{
	node_double *p = list_double.head;
	if(n == 0)
		return -1;
	if (n == 1)
	{
		return p->data;
	}
	return get_value_of_node_double(list_double, n - 1) + sum_link_list_double(list_double, n - 1);
}