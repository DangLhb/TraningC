#include "function.h"
// ham khoi tao cong ty voi cac gia tri mac dinh
inf *creat_company(void)
{
	inf *company;
	company = (inf*)malloc(sizeof(inf));
	printf("Khoi tao cong ty voi ID = 0 va thu nhap = 0\n");
	company->ID = 0;
	company->sales = 0;
	printf("Nhap ten cong ty\n");
	scanf("%s", company->name);
	company->superior = NULL;
	for(int i = 0; i < 10; i ++)
	{
		company->staff[i] = NULL;
	}
	return company;
}

// ham tao mot node gom cac thong tin cua nhan vien
inf *creat_new_node(inf *p, inf *company,int id)
{
	inf *new_staff;
	int ID_check;
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
		{
			printf("Nhap thong tin cho thanh vien thu %d cua node cua ID = %d\n",i + 1,id);
			new_staff = (inf*)malloc(sizeof(inf));
				//phai gan cho no mot cai gi do khac NULL
			//if(p->staff[i] == NULL)
				//printf("----------------van = NULL sau khi gan = 1 con tro khac\n");
			do {
				printf("Nhap ID cua node :\n");
				scanf("%d",&ID_check);
				// scanf("%d", &p->staff[i]->ID);
			} while(is_ID_exist(company,ID_check) == 1);
			new_staff->ID = ID_check;
			p->staff[i] = new_staff;
			printf("Nhap ten : \n");
			scanf("%s", &new_staff->name);
			// scanf("%s", p->staff[i]->name);
			
			printf("Nhap thu nhap:\n");
			scanf("%d", &new_staff->sales);
			// scanf("%d", &p->staff[i]->sales);
			
			for(int	i = 0; i < 10 ; i ++)
			{
				new_staff->staff[i] = NULL;	
			}
			// p->staff[i]->superior = p;
			new_staff->superior = p;
			return p;
		}
	}

	printf("This superior have enough 10 staff\n");
	return company;
}
// ham ra soat ID 
//return 1 neui ID trùng
//return 0 neu ID chua trung.
int is_ID_exist(inf *company, int i_d)
{
	//inf p = company;
	//printf("DangLHb DEBUG enter is_ID_exist\n");

	return recusiver_check_ID(company, i_d);
}

// ham de quy so sánh ID :
int recusiver_check_ID(inf *company, int i_d)
{
	//printf("DangLHb DEBUG - enter recusiver_check_ID\n");
	if(company->ID == i_d)
	{
		//printf("ID exist, nhap lai ID :\n");
		return 1;
	}
	for(int i = 0; i < 10; i ++)
	{
		if(company->staff[i] == NULL)
		{
			//printf("DangLHb enter recusiver_check_ID - for i = %d\n", i);
		}
		else
		{
			 if(recusiver_check_ID(company->staff[i], i_d))
			 	return 1;
		}
	}
	printf("ID nhao vao khong trung voi bat ki ID nao\n");
	return 0;
}
//Handle Event ADD
void add_staff (inf *company)
{
	//inf *p = company;
	int ID_superior;
	printf("Nhap ID cua cap tren: \n");
	do{
		//printf("DangLHb debug enter do\n");
		scanf("%d",&ID_superior);
	} while(is_ID_exist(company,ID_superior) == 0);		//ok - neu nhap voi ID khong trung voi ID da ton tai.
	company = add_staff_base_on_ID(company, ID_superior);
	//return p;
}

//ham tim vi tri node co ID tuong ung
inf *find_node_base_on_id (inf *p, int i_d)
{
	//printf("DanglHb debug - enter find_node_base_on_id\n");
	if(p->ID == i_d)
		return p;
	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
		{
			//printf("Node con thu %d cua nodes co ID = %d trong\n",i,i_d);
		}
		else
		{
			printf("DangLHb	DEBUG ----!!!!- i =%d\n",i);
			return find_node_base_on_id(p->staff[i], i_d);
		}
	}
	return p;
}

//ham them nhan vien dua tren ID
inf *add_staff_base_on_ID (inf *company, int i_d)
{
	//printf("DangLHb DEBUG- enter add_staff_base_on_ID \n");
	inf *p = company;
	//kiem tra xem voi ID dau vao thi phai cho con tro P tro toi vi tri node do.
	p = find_node_base_on_id(p,i_d);

	p = creat_new_node(p,company,i_d);
	return company;
}

// ham tinh toan thu nhan dua vao ID cua nhan vien
int caculator_income_base_on_id(inf *company,inf *p,int i_d)
{
	int in_come;
	int extra_income = 0;

	for(int i = 0; i < 10; i ++)
	{
		if(p->staff[i] == NULL)
		{
			//printf("thong tin cua nhan vien thu %d cua node co ID la %d trong\n", i , i_d);
		}
		else{
			extra_income =extra_income + caculator_income_base_on_id(company, p->staff[i], p->staff[i]->ID);
			//printf("extra_income = %d, i = %d, id = %d\n",extra_income,i, p->staff[i]->ID);
		}
	}
	if(p->ID == 0)
		p->income = 30*extra_income/70;
	else
		p->income = 70*(p->sales + 30*extra_income/70)/100;
	//printf("return = %d\n",p->income);
	return p->income;
}

//Handle income event - nhap thong tin ID cua nhan vien can tinh thu nhap
int income_base_on_id(inf *company)
{
	int ID_check;
	int in_come;
	inf *p = company;
	do
	{
		printf("Nhap ID cua nguoi can tinh thu nhap \n");
		scanf("%d",&ID_check);
	}while(is_ID_exist(company,ID_check) == 0);
	p = find_node_base_on_id(p,ID_check);
	in_come = caculator_income_base_on_id(company,p,ID_check);
	printf("in_come = %d\n",in_come);
	return in_come;
}



// ham in thong tin cua toan bo nhan vien trong cong ty
void print_tree(inf *company,inf *p)
{
	//p = company;
	if(p->ID == 0)
		printf("Compaty's name = %s\nCompany's ID = %d\nCompany's sale = %d\nCompany's income = %d\n\n", p->name,p->ID,p->sales,caculator_income_base_on_id(company,p,p->ID));
	else
		printf("Staff's name = %s\nStaff's ID = %d\nStaff's sale = %d\nStaff's income = %d\nID of superior = %d\n\n", p->name,p->ID,p->sales,caculator_income_base_on_id(company,p,p->ID), p->superior->ID);
	for(int i = 0; i < 10; i ++)
		{
			if(p->staff[i] == NULL)
			{
				//printf("thong tin cua nhan vien thu %d trong\n",i);
			}
			else
				print_tree(company,p->staff[i]);
		}
}

