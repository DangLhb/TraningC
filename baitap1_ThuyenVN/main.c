       /*******************************************
bai 1
Viết chương trình quản lý sản phẩm là điện thoại di động. Dữ liệu về sản phẩm gồm các thông tin: mã sản phẩm, tên sản phẩm, giá bán, số lượng tồn kho.

Cài đặt các chức năng sau:

1. Thêm mới một điện thoại vào danh sách. Khi thêm sản phẩm phải đảm bảo điện thoại được sắp xếp theo thứ tự tăng của giá bán.
2. Xóa một điện thoại khỏi danh sách theo mã.
3. Sửa thông tin số lượng tồn kho một sản phẩm trong danh sách theo mã.
4. Tìm kiếm sản phẩm theo giá gần đúng và 2 sản phẩm cận trên và cận dưới. Ví dụ danh sách gồm các sản phẩm có giá là 100 - 150 - 210 - 300 mà nhập vào giá 200 thì sẽ tìm ra sản phẩm là 210 và in thêm 2 sản phẩm giá 150 (cận dưới), 300 (cận trên). Nếu không có cận dưới / cận trên thì in là không có.
5. In ra tất cả các sản phẩm trong danh sách với 1 trong 2 lựa chọn giá tăng dần hoặc giảm dần)

Note : 
Để làm bài toán này cần lên lưu đồ thuật toán.
hàm main sẽ là một vòng lòng while. 
đợi nhập lệnh từ phía người dùng.
******************************************/
#include<stdio.h>


typedef struct
{
	int product_code;
	char product_name[50];
	int product_price;
	int product_remaining_amount;	
}product_t;
void add(struct product_t product)
{
	// Nhap ma san pham
	printf("Nhap ma san pham :");
	scanf("%d", &p);
}
int main()
{
	
}