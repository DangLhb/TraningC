/*Bai 2:


1. Cài đặt lại thuật toán Insertion Sort với CTDL là double linked list.
2. Cài đặt 1 số thuật toán đơn giản sau bằng đệ quy:
- Tìm max trong mảng
- Tính tổng các số trong mảng
3. Vẫn tìm max / tổng bằng đệ quy nhưng cho cấu trúc dữ liệu là linked list
*/
#include "link_list.h"

int main()
{
	printf("Create a link list\n");
	node head = creat_link_list();
	sort_node_ascending_insert_sort(head);
	print_list(head);


	int arr[10] = {0,1,1,1,1,1,1,1,1,1};
	int result_max = *(arr + 9);
	int max = max_arr_danglhb(arr, 10, result_max);
	printf("max =  %d\n", max);
	// int sum = sum_arr_danglhb(arr, 10, 0);
	int sum = sum_arr_danglhb_2(arr, 10);
	printf("sum = %d\n", sum);


	return 0;
}