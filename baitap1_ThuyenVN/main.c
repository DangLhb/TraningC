       /*******************************************
bai 1
Viết chương trình quản lý sản phẩm là điện thoại di động. Dữ liệu về sản phẩm gồm các thông tin: mã sản phẩm, tên sản phẩm,
 giá bán, số lượng tồn kho.

Cài đặt các chức năng sau:

1. Thêm mới một điện thoại vào danh sách. Khi thêm sản phẩm phải đảm bảo điện thoại được sắp xếp theo thứ tự tăng của giá bán.
2. Xóa một điện thoại khỏi danh sách theo mã.
3. Sửa thông tin số lượng tồn kho một sản phẩm trong danh sách theo mã.
4. Tìm kiếm sản phẩm theo giá gần đúng và 2 sản phẩm cận trên và cận dưới. Ví dụ danh sách gồm các sản phẩm có giá là 
100 - 150 - 210 - 300 mà nhập vào giá 200 thì sẽ tìm ra sản phẩm là 210 và in thêm 2 sản phẩm giá 150 (cận dưới), 300 
(cận trên). Nếu không có cận dưới / cận trên thì in là không có.
5. In ra tất cả các sản phẩm trong danh sách với 1 trong 2 lựa chọn giá tăng dần hoặc giảm dần)

******************************************/
#include"function.h"


//enum action
int main()
{
	int action = 0;
	product_t product_ptr[1000];
	while(1)
	{
		printf("Nhap hanh dong muon thuc hien : \n1 : add\n2 : delete\n3 : change\n4 : Find/Search\n5 : Printf\n ");
// 		do 
// 		{
			scanf("%d", &action);
// 		} while((action > 5 && action < 0));
// 		printf("Out while\n");
		switch(action)
		{
			case 1:
				add_product(product_ptr);
			break;
			case 2:
				delete_product(product_ptr);
			break;
			case 3:
				change_amount_follow_code_product(product_ptr);
			break;
			case 4:
				fine_product_with_nearest_price(product_ptr);
			break;
			case 5:
				print_list_product(product_ptr);
			break;

			default:
			    printf("Nhap sai gia tri, nhap lai \n"); 
			break;	
		}
		action = 0;
	}

}