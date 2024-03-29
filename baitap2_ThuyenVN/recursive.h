#ifndef _RECURSIVE_H_
#define _RECURSIVE_H_
// #include <stdio.h>
#include "link_list.h"




int max_2(int a, int b);
int max_arr_danglhb(int arr[], int sum, int result_max);
int max_arr_danglhb_2(int arr[], int sum);
int sum_arr_danglhb(int arr[], int n, int result_sum);
int sum_arr_danglhb_2(int arr[], int n);

//single
int max_link_list(node head, int n);
int max_link_list_danglhb(node head, int n, int result_max);
int sum_link_list(node head, int n);

//double
int max_link_list_double(ll_double list_double, int n);
int max_link_list_double_danglhb(ll_double list_double, int n, int result_max);
int sum_link_list_double(ll_double list_double, int n);

#endif