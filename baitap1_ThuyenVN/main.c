       /*******************************************
bai 1
Viết chương trình quản lý sản phẩm là điện thoại di động. Dữ liệu về sản phẩm gồm các thông tin: mã sản phẩm, tên sản phẩm, giá bán, số lượng tồn kho.

Cài đặt các chức năng sau:

1. Thêm mới một điện thoại vào danh sách. Khi thêm sản phẩm phải đảm bảo điện thoại được sắp xếp theo thứ tự tăng của giá bán.
2. Xóa một điện thoại khỏi danh sách theo mã.
3. Sửa thông tin số lượng tồn kho một sản phẩm trong danh sách theo mã.
4. Tìm kiếm sản phẩm theo giá gần đúng và 2 sản phẩm cận trên và cận dưới. Ví dụ danh sách gồm các sản phẩm có giá là 100 - 150 - 210 - 300 mà nhập vào giá 200 thì sẽ tìm ra sản phẩm là 210 và in thêm 2 sản phẩm giá 150 (cận dưới), 300 (cận trên). Nếu không có cận dưới / cận trên thì in là không có.
5. In ra tất cả các sản phẩm trong danh sách với 1 trong 2 lựa chọn giá tăng dần hoặc giảm dần)

******************************************/
#include<stdio.h>


typedef struct
{
	int product_code;
	char product_name[50];
	int product_price;
	int product_remaining_amount;	
}product_t;

int g_number_of_product = 0;

void add_product(product_t product_ptr_t[])
{	
    printf("Enter add\n");
	// Nhap ma san pham
	printf("Nhap ma san pham :\n");
	// scanf("%d", &(*(product_ptr + g_number_of_product).product_code));
	scanf("%d", &product_ptr_t[g_number_of_product].product_code);
	printf("Nhap ten san pham :\n");
	// scanf("%s", &(*(product_ptr + g_number_of_product).product_name));
	scanf("%s", product_ptr_t[g_number_of_product].product_name);
	printf("Nhap gia san pham :\n");
	// scanf("%d", &(*(product_ptr + g_number_of_product).product_price));
	scanf("%d", &product_ptr_t[g_number_of_product].product_price);	
	printf("Nhap so luong ton kho :\n");
	// scanf("%d", &(*(product_ptr + g_number_of_product).product_remaining_amount));
	scanf("%d", &product_ptr_t[g_number_of_product].product_remaining_amount);
	sort_by_price(product_ptr_t);
	g_number_of_product += 1; 
}

void sort_by_price(struct product_ptr_t[])
{
	
}

void delete_product(struct product_ptr_t[])
{
	int product_code_delete;
	int is_same_code  = 0;
	printf("Nhap ma dien thoai ma ban muon xoa \n");
	scanf("%d",&product_code_delete);
	for(int i = 0; i < g_number_of_product; i ++)
	{
		if(product_code_delete == product_ptr_t[i].product_code)
		{
			delete_product_danglhb(i, product_ptr_t);
			is_same_code = 1; 
			break;
		}
		else 
		{
			is_same_code = 0
		}
	}
	if(!is_same_code)
	{
		printf("Ma ban nhap khong trung voi bat ki ma nao\n");
	}
}

void delete_product_danglhb(int stt, struct product_ptr_t[])
{
	for(int i = stt; i < g_number_of_product; i ++)
	{
		product_ptr_t[i].product_code = product_ptr_t[i + 1].product_code;
		product_ptr_t[i].product_name = product_ptr_t[i + 1].product_name;	// chua ro khi gan string cho string thi co duoc khong?
		product_ptr_t[i].product_price = product_ptr_t[i + 1].product_price;
		product_ptr_t[i].product_remaining_amount = product_ptr_t[i + 1].product_code;
		g_number_of_product -= 1;

	}
}

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
				//call function delete
			break;
			case 3:
				//call change
			break;
			case 4:
				//call Fine
			break;
			case 5:
				//call printf
			break;

			default:
			    printf("Nhap sai gia tri, nhap lai \n"); 
			break;	
		}
		action = 0;
	}

}