/*Bai 2:


1. Cài đặt lại thuật toán Insertion Sort với CTDL là double linked list.
2. Cài đặt 1 số thuật toán đơn giản sau bằng đệ quy:
- Tìm max trong mảng
- Tính tổng các số trong mảng
3. Vẫn tìm max / tổng bằng đệ quy nhưng cho cấu trúc dữ liệu là linked list
*/
#include "link_list.h"
#include"recursive.h"


int main()
{
	int num_of_arr;
	int arr[100];
	int result;
	printf("Create a link list\n");
	
	//single
	// node head = creat_link_list();
	// sort_node_ascending_insert_sort(head);
	// print_list(head);

	//double
	ll_double list_double_1 = creat_link_list_double();
	sort_node_ascending_insert_sort_double(list_double_1);
	print_list_double(list_double_1);
	printf("Nhap so phan tu cua mang\n");
	scanf("%d", &num_of_arr);
	for(int i = 0; i < num_of_arr; i ++)
	{
		printf("Nhap gia tri cho phan tu thu %d\n", i);
		scanf("%d", &(*(arr + i)));
	}
	// printf("Max in array = %d\n", max_arr_danglhb_2(arr, num_of_arr));
	// printf("Sum of arr= %d\n", sum_arr_danglhb_2(arr, num_of_arr));

	//single
	// printf("Max in link list = %d\n", max_link_list(head, count_mount_of_node(head)));
	// printf("sum of link list= %d\n", sum_link_list(head, count_mount_of_node(head)));

	//double
	printf("Max in link list = %d\n", max_link_list_double(list_double_1, count_mount_of_node_double(list_double_1)));
	printf("sum of link list= %d\n", sum_link_list_double(list_double_1, count_mount_of_node_double(list_double_1)));
	return 0;
}