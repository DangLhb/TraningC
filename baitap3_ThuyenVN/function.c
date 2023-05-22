#include "function.h"

inf creat_company(void)
{
	inf company;
	company = (inf)malloc(sizeof(struct infor));
	printf("Khoi tao cong ty voi ID = 0 va thu nhap = 0\n");
	company->ID = 0;
	company->income = 0;
	printf("Nhap ten cong ty\n");
	scanf("%s", company->name);
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
	inf new_staff;
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
		{
			new_staff = (inf)malloc(sizeof(struct infor));
			p->staff[i] = new_staff;	
			do {
				printf("Nhap ID cua node :\n");
				scanf("%d",&new_staff->ID);
			} while(is_ID_exist(company,new_staff->ID));
			printf("Nhap ten : \n");
			scanf("%s", new_staff->name);
			printf("Nhap thu nhap:\n");
			scanf("%d", &new_staff->income);
			new_staff->superior = p;
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
	//inf p = company;
	printf("DangLHb DEBUG enter is_ID_exist\n");

	return recusiver_check_ID(company, i_d);
}

// ham de quy so sánh ID :
int recusiver_check_ID(inf company, int i_d)
{
	printf("DangLHb DEBUG - enter recusiver_check_ID\n");
	if(company->ID == i_d)
	{
		//printf("ID exist, nhap lai ID :\n");
		return 1;
	}
	for(int i = 0; i < 10; i ++)
	{
		if(company->staff[i] == NULL)
		{
			printf("DangLHb enter recusiver_check_ID - for i = %d\n", i);
		}
		else
		{
			recusiver_check_ID(company->staff[i], i_d);
		}
	}
	printf("ID nhao vao khong trung voi bat ki ID nao\n");
	return 0;
}
//Handle Event ADD
void add_staff (inf company)
{
	//inf p = company;
	int ID_superior;
	printf("Nhap ID cua cap tren: \n");
	do{
		//printf("DangLHb debug enter do\n");
		scanf("%d",&ID_superior);
	} while(is_ID_exist(company,ID_superior) == 0);
	company = add_staff_base_on_ID(company, ID_superior);
	//return p;
}

//ham tim vi tri node co ID tuong ung
inf find_node_base_on_id (inf p, int i_d)
{
	//printf("DanglHb debug - enter find_node_base_on_id\n");
	if(p->ID == i_d)
		return p;
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
		{
			
		}
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
	printf("DangLHb DEBUG- enter add_staff_base_on_ID \n");
	inf p = company;
	//kiem tra xem voi ID dau vao thi phai cho con tro P tro toi vi tri node do.
	p = find_node_base_on_id(p,i_d);

	p = creat_new_node(company);
	return company;
}
