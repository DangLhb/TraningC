#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

struct infor
{
	int ID;
	char name[30];
	int sales;
	int income;
	struct infor *superior;
	struct infor *staff [10];
};
typedef struct infor *inf;

typedef enum
{
	none = 0,
	add = 1,
	income = 2,
	print = 3
}action;

inf creat_company(void);
inf creat_new_node(inf p, inf company,int id);
int is_ID_exist(inf company, int i_d);
int recusiver_check_ID(inf p, int i_d);
void add_staff (inf company);
inf find_node_base_on_id (inf p, int i_d);
inf add_staff_base_on_ID (inf company, int i_d);

//2
int caculator_income_base_on_id(inf company,inf p,int i_d);
void income_base_on_id(inf company);


void print_tree(inf company);


#endif