#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include<stdio.h>
#include<string.h>

typedef struct
{
	int product_code;
	char product_name[50];
	int product_price;
	int product_remaining_amount;	
}product_t;

void add_product(product_t product_ptr_t[]);
void sort_by_price(product_t product_ptr_t[]);
void delete_product(product_t product_ptr_t[]);
void delete_product_danglhb(int stt, product_t product_ptr_t[]);
void change_amount_follow_code_product (product_t product_ptr_t[]);


#endif