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

	for(int i = 0; i < g_number_of_product; i ++)
	{
		printf("co tong cong %d loai san pham \n",g_number_of_product);
		printf("San pham thu %d \n", i);
		printf("code = %d\n", product_ptr_t[i].product_code);
		printf("name = %s\n", product_ptr_t[i].product_name);
		printf("price = %d\n", product_ptr_t[i].product_price);
		printf("amount = %d\n", product_ptr_t[i].product_remaining_amount);
	}
}


// sap xep theo thu tu tang dan theo gia ban
void sort_by_price(product_t product_ptr_t[])
{
	int i , j;
	int last_code, last_price, last_amount;
	char last_name[50];
	for(i = 1; i < g_number_of_product; i ++)
	{
		last_price = product_ptr_t[i].product_price;
		last_code = product_ptr_t[i].product_code;
		strcpy(last_name, product_ptr_t[i].product_name);
		last_amount = product_ptr_t[i].product_remaining_amount;
		j = i;
		while(j > 0, product_ptr_t[j - 1].product_price > last_price)
		{
			product_ptr_t[j].product_price = product_ptr_t[j - 1].product_price;
			product_ptr_t[j].product_code = product_ptr_t[j - 1].product_code;
			strcpy(product_ptr_t[j].product_name, product_ptr_t[j - 1].product_name);			
			product_ptr_t[j].product_remaining_amount = product_ptr_t[j - 1].product_remaining_amount;			
			j -= 1;
		}
		product_ptr_t[j].product_price = last_price;
		product_ptr_t[j].product_code = last_code;
		strcpy(product_ptr_t[j].product_name, last_name);			
		product_ptr_t[j].product_remaining_amount = last_amount;	
	}

}

void delete_product(product_t product_ptr_t[])
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
			is_same_code = 0;
		}
	}
	if(!is_same_code)
	{
		printf("Ma ban nhap khong trung voi bat ki ma nao\n");
	}

	for(int i = 0; i < g_number_of_product; i ++)
	{
		printf("co tong cong %d loai san pham \n",g_number_of_product);
		printf("San pham thu %d \n", i);
		printf("code = %d\n", product_ptr_t[i].product_code);
		printf("name = %s\n", product_ptr_t[i].product_name);
		printf("price = %d\n", product_ptr_t[i].product_price);
		printf("amount = %d\n", product_ptr_t[i].product_remaining_amount);
	}

}

void delete_product_danglhb(int stt, product_t product_ptr_t[])
{
	for(int i = stt; i < g_number_of_product; i ++)
	{
		product_ptr_t[i].product_code = product_ptr_t[i + 1].product_code;
		// product_ptr_t[i].product_name = product_ptr_t[i + 1].product_name;	// chua ro khi gan string cho string thi co duoc khong?
		strcpy(product_ptr_t[i].product_name, product_ptr_t[i + 1].product_name);
		product_ptr_t[i].product_price = product_ptr_t[i + 1].product_price;
		product_ptr_t[i].product_remaining_amount = product_ptr_t[i + 1].product_code;
		g_number_of_product -= 1;
	}
}