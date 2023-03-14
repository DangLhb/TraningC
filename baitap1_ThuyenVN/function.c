#include "function.h"

int g_number_of_product = 0;

void add_product(product_t product_ptr_t[])
{	
    printf("Enter add\n");
	// Nhap ma san pham
	printf("Nhap ma san pham :\n");
	// scanf("%d", &(*(product_ptr + g_number_of_product).product_code));
	scanf("%d", &product_ptr_t[g_number_of_product].product_code);

//  Kiểm tra mã sản phầm xem có trùng không?
	for(int i = 0; i < g_number_of_product; i ++)
	{
		if(product_ptr_t[i].product_code == product_ptr_t[g_number_of_product].product_code)
			{
				printf("Trung ma!!!!\n");
				return;
			}
	}

	printf("Nhap ten san pham :\n");
	// scanf("%s", &(*(product_ptr + g_number_of_product).product_name));
	scanf("%s", product_ptr_t[g_number_of_product].product_name);
//	Kiem tra ten san pham co bi trung khong
	for(int i = 0; i < g_number_of_product; i ++)
	{
		if(product_ptr_t[i].product_name == product_ptr_t[g_number_of_product].product_name)
			{
				printf("Trung ten!!!!\n");
				return;
			}
	//		printf("ten ma %d = %s , ten ma vua nhap %s\n",i, product_ptr_t[i].product_name, product_ptr_t[g_number_of_product].product_name);
	}	

	printf("Nhap gia san pham :\n");
	// scanf("%d", &(*(product_ptr + g_number_of_product).product_price));
	scanf("%d", &product_ptr_t[g_number_of_product].product_price);
	printf("Nhap so luong ton kho :\n");
	// scanf("%d", &(*(product_ptr + g_number_of_product).product_remaining_amount));
	scanf("%d", &product_ptr_t[g_number_of_product].product_remaining_amount);
	g_number_of_product += 1; 
	sort_by_price(product_ptr_t);
}


// sap xep theo thu tu tang dan theo gia ban
void sort_by_price(product_t product_ptr_t[])
{
	if(g_number_of_product < 2)
		return;
	// su dung insertsort
	for(int i = 0; i < g_number_of_product; i ++)
	{
		
	}

}

// void delete_product(struct product_ptr_t[])
// {
// 	int product_code_delete;
// 	int is_same_code  = 0;
// 	printf("Nhap ma dien thoai ma ban muon xoa \n");
// 	scanf("%d",&product_code_delete);
// 	for(int i = 0; i < g_number_of_product; i ++)
// 	{
// 		if(product_code_delete == product_ptr_t[i].product_code)
// 		{
// 			delete_product_danglhb(i, product_ptr_t);
// 			is_same_code = 1; 
// 			break;
// 		}
// 		else 
// 		{
// 			is_same_code = 0
// 		}
// 	}
// 	if(!is_same_code)
// 	{
// 		printf("Ma ban nhap khong trung voi bat ki ma nao\n");
// 	}
// }

// void delete_product_danglhb(int stt, struct product_ptr_t[])
// {
// 	for(int i = stt; i < g_number_of_product; i ++)
// 	{
// 		product_ptr_t[i].product_code = product_ptr_t[i + 1].product_code;
// 		product_ptr_t[i].product_name = product_ptr_t[i + 1].product_name;	// chua ro khi gan string cho string thi co duoc khong?
// 		product_ptr_t[i].product_price = product_ptr_t[i + 1].product_price;
// 		product_ptr_t[i].product_remaining_amount = product_ptr_t[i + 1].product_code;
// 		g_number_of_product -= 1;

// 	}
// }