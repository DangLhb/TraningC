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
	print_list(head, 5);
	return 0;
}