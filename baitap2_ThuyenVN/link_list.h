// Trien khai va tao link list , truy suat cac phan tu trong link list
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include<stdio.h>
#include<stdlib.h>
// #include"recursive.h"

struct LinkedList
{
	int nums;
	struct LinkedList* next;
};
typedef struct LinkedList *node;


node creat_node(int value);
node add_node_at_the_begin(node head, int value);
node add_node_at_the_end(node head, int value);
node add_node_at_hope_postion(node head, int position, int value);
node del_node_at_begin_of_list(node head);
node del_node_at_end_of_list(node head);
node del_node_at_hope_position(node head, int position);
int get_value_of_node(node head, int position);
void set_value_of_node(node head, int position, int value);
int find_value_in_list(node head, int value);
void sort_node_ascending_insert_sort(node head);
void print_list(node head);
node init_head();
node creat_link_list();
int count_mount_of_node(node head);


#endif