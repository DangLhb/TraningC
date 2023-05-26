// Trien khai va tao link list , truy suat cac phan tu trong link list
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include<stdio.h>
#include<stdlib.h>
// #include"recursive.h"

struct Node_sigle
{
	int nums;
	struct Node_sigle* next;
};
typedef struct Node_sigle node;

struct Node_double
{
	int data;
	struct Node_double* next_d;
	struct Node_double* prev_d;
};
typedef struct Node_double node_double;	// struct nay dung de mo ta mot node cua link list double gom nhung gi?

typedef struct //Linklist_double
{
	node_double *head;
	node_double *tail;
}ll_double;
// typedef struct LinkedList_double ll_double;	// struct nay de phan loai cac link list double kha nhau : - co the hieu la de xac dinh link list
//single
node *creat_node(int value);
node *add_node_at_the_begin(node *head, int value);
node *add_node_at_the_end(node *head, int value);
node *add_node_at_hope_postion(node *head, int position, int value);
node *del_node_at_begin_of_list(node *head);
node *del_node_at_end_of_list(node *head);
node *del_node_at_hope_position(node *head, int position);
int get_value_of_node(node *head, int position);
void set_value_of_node(node *head, int position, int value);
int find_value_in_list(node *head, int value);
void sort_node_ascending_insert_sort(node *head);
void print_list(node *head);
node *init_head(void);
node *creat_link_list(void);
int count_mount_of_node(node *head);

//double
node_double *creat_node_double(int value);
ll_double add_node_at_the_begin_double(ll_double list_double, int value);
ll_double add_node_at_the_end_double(ll_double list_double, int value);
ll_double add_node_at_hope_postion_double(ll_double list_double, int value, int position);
ll_double del_node_at_begin_of_list_double(ll_double list_double);
ll_double del_node_at_end_of_list_double(ll_double list_double);
ll_double del_node_at_hope_position_double(ll_double list_double, int position);
int get_value_of_node_double(ll_double list_double, int position);
void set_value_of_node_double(ll_double list_double, int position, int value);
int find_value_in_list_double(ll_double list_double, int value);
void sort_node_ascending_insert_sort_double(ll_double list_double);
int count_mount_of_node_double(ll_double list_double);
void print_list_double(ll_double list_double);
ll_double init_head_tail_double(void);
ll_double creat_link_list_double(void);


#endif