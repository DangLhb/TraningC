#include "function.h"

inf creat_company(void)
{
	inf company;
	company = (inf)malloc(sizeof(struct infor));
	printf("Khoi tao cong ty voi ID = 0 va thu nhap = 0\n");
	company->ID = 0;
	company->income = 0;
	printf("Nhap ten cong ty\n");
	scanf("%s", &company->name);
	company->superior = NULL;
	for(int i = 0; i < 10; i ++)
	{
		company->staff[i] = NULL;
	}
	return company;
}


inf creat_new_node(inf company)
{
	inf p = company;
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
		{
			p = p->staff[i];
			printf("Nhap ID cua node :\n");
			do {
				scanf("%d",&p->ID);
			} while(is_ID_exist(company,p->ID));
			printf("Mhap ten : \n");
			scanf("%s", &p->name);
			printf("Nhap thua nhap:\n");
			scanf("%d", &p->income);
			return company;
		}
	}

	printf("This superior have enough 10 staff\n");
	return company;
}
// ham ra soat ID 
//return 1 neui ID trùng
//return 0 neu ID chua trung.
int is_ID_exist(inf company, int i_d)
{
	inf p = company;
	printf("DangLHb DEBUG enter is_ID_exist\n");

	return recusiver_check_ID(p, i_d);
}

// ham de quy so sánh ID :
int recusiver_check_ID(inf p, int i_d)
{
	if(p->ID == i_d)
	{
		printf("ID exist, nhap lai ID :\n");
		return 1;
	}
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
			break;
		else
		{
			recusiver_check_ID(p->staff[i], i_d);
		}
	}
	return 0;
}
//Handle Event ADD
void add_staff (inf company)
{
	int ID_superior;
	printf("Nhap ID cua cap tren: \n");
	do{
		printf("DangLHb debug enter do\n");
		scanf("%d",ID_superior);
	} while(!is_ID_exist(company,ID_superior));
	company = add_staff_base_on_ID(company, ID_superior);
}

//ham tim vi tri node co ID tuong ung
inf find_node_base_on_id (inf p, int i_d)
{
	if(p->ID == i_d)
		return p;
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
			break;
		else
		{
			find_node_base_on_id(p->staff[i], i_d);
		}
	}
	//return p;
}

//ADD staff to company - base on ID of superior.
inf add_staff_base_on_ID (inf company, int i_d)
{
	inf p = company;
	//kiem tra xem voi ID dau vao thi phai cho con tro P tro toi vi tri node do.
	p = find_node_base_on_id(p,i_d);

	p = creat_new_node(p);
	return company;
}
