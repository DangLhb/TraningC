// Trien khai va tao link list , truy suat cac phan tu trong link list
// #include"recursive.h"
#include"link_list.h"

/********creat node*************/

//single
node creat_node(int value)
{
	node danglhb;
	danglhb = (node)malloc(sizeof(struct Node_sigle));
	danglhb->nums = value;
	danglhb->next = NULL;
	return danglhb;	
}

//double
node_double creat_node_double(int value)
{
	node_double danglhb;
	danglhb = (node_double)malloc(sizeof(struct Node_double));
	danglhb->data = value;
	danglhb->next_d = NULL;
	danglhb->prev_d = NULL;
	return danglhb;
}
/******add at begin**********/

//single
node add_node_at_the_begin(node head, int value)
{
	node temp = creat_node(value);
	if(head == NULL)
	{
		printf("DAngLHb debug - head = NUll list empty\n");
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	printf("DangLHb -debub create a node at begin with value = %d\n",value);
	return head;
}

//double
ll_double add_node_at_the_begin_double(ll_double list_double, int value)
{
	node_double node_begin = creat_node_double(value);
	if(list_double.head == NULL)
	{
		printf("DanglHb debug - add node at begin - node empty - value = %d \n",value);
		list_double.head = node_begin;
		list_double.tail = node_begin;
	}
	else
	{
		printf("DanglHb debug -- add node at begin with value = %d\n",value);
		list_double.head->prev_d = node_begin;
		node_begin->next_d = list_double.head;
		list_double.head = node_begin;
	}
	return list_double;
}

/********add node at the end*****************/

//single
node add_node_at_the_end(node head, int value)
{
	node temp = creat_node(value);
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		node p = head;
		while(p->next !=NULL)
		{
			p = p->next;
		}
		p->next = temp;	
	}
	return head;
}

//double
ll_double add_node_at_the_end_double(ll_double list_double, int value)
{
	node_double node_end = creat_node_double(value);
	if(list_double.head == NULL)
	{
		list_double.head = node_end;
		list_double.tail = node_end;	
	}
	else
	{
		list_double.tail->next_d = node_end;
		node_end->prev_d = list_double.tail;
		list_double.tail = node_end;
	}

	return list_double;
}
/**********add node at hope postion***********/

//single
node add_node_at_hope_postion(node head, int position, int value)
{
	if(position == 0 || head == NULL)
	{
		add_node_at_the_begin(head, value);
	}
	else 
	{
		int k = 1;
		node p = head;
		while(k != position && p->next != NULL)
		{
			k +=1;
			p = p->next;
		}
		if(k != position)
		{
			printf("\n");
		}
		else 
		{
			node temp = creat_node(value);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}

//double
ll_double add_node_at_hope_postion_double(ll_double list_double, int value, int position)
{
	if(position == 0 || list_double.head == NULL)
		add_node_at_the_begin_double(list_double, value);
	else
	{
		int k = 1;
		node_double p = list_double.head;
		while(k != position && p->next_d != NULL)
		{
			k += 1;
			p = p->next_d;
		}
		if(k != position)
			printf(" So thu tu > so node cua list\n");
		else
		{
			node_double new_node = creat_node_double(value);
			p->next_d->prev_d = new_node;
			p->next_d = new_node;
			new_node->prev_d = p;
			new_node->next_d = p->next_d; 
		}

	}
	return list_double;
}

/*********delete node at begin of list*************/

//single
node del_node_at_begin_of_list(node head)
{
	if(head == NULL)
		printf("Nothing to del\n");
	else 
	{
		head = head->next;
	}
	return head;
}

//double
ll_double del_node_at_begin_of_list_double(ll_double list_double)
{
	if(list_double.head == NULL)
	{
		printf("Nothing to delete\n");
	}
	else
	{
		list_double.head = list_double.head->next_d;
		list_double.head->prev_d = NULL;
	}
	return list_double;
}

/********delete node at the end of list*************/

//single
node del_node_at_end_of_list(node head)
{	
	if(head == NULL)
	{
		printf("Nothing to del\n");
	}
	else 
	{
		node p = head;
		while(p->next->next !=NULL)	
		{
			p = p->next;
		}
		p->next = NULL;	//hoac co the viet p->next = p->next->nexts
		// p->next = p->next->next;
	}
	return head;
}

//double
ll_double del_node_at_end_of_list_double(ll_double list_double)
{
	if(list_double.head == NULL)
		printf("Nothing to delete\n");
	else
	{
		list_double.tail == list_double.tail->prev_d;

		list_double.tail->next_d = NULL;
	}
	return list_double;
}

/**********delete node at hope position**********/

//single
node del_node_at_hope_position(node head, int position)
{
	if(head == NULL || position == 0 || head->next == NULL)
	{
		head = del_node_at_begin_of_list(head);
	}
	else 
	{
		node p = head;
		int k = 1;
		while(k != position && p->next != NULL)
		{
			p = p->next;
			k ++;
		}
		if(k != position)
		{
			printf("Vi tri xoa vuot qua so phan tu của list\n");
		}
		else
		{
			p->next = p->next->next;
		}
	}
	return head;
}

//double
ll_double del_node_at_hope_position_double(ll_double list_double, int position)
{
	if(position == 0 || list_double.head == NULL || list_double.head->next_d == NULL)
		list_double = del_node_at_begin_of_list_double(list_double);
	else
	{
		int k = 1;
		node_double p = list_double.head;
		while(k != position && p->next_d != NULL)
		{
			k += 1;
			p = p->next_d;
		}
		if(k != position)
			printf("Vi tri xoa > so luong node trong list\n");
		else 
		{
			p->next_d = p->next_d->next_d;
			p->next_d->prev_d = p;
		}
	}
	return list_double;
}

/***********get value of node************/

//single
int get_value_of_node(node head, int position)
{
	int k = 0;
	node p = head;
	while(p->next != NULL && k != position)
	{
		k += 1;
		p = p->next;
	}
	if(k != position)
	{
		printf("Vi tri node yeu cau vuot qua so phan tu cua list - return gia tri cuoi cung\n");
	}
	return p->nums;
}

//double
int get_value_of_node_double(ll_double list_double, int position)
{
	int k = 0;
	node_double p = list_double.head;
	while(k != position && p->next_d != NULL)
	{
		k += 1;
		p = p->next_d;
	}
	if(k != position)
		printf("Vi tri yeu cau > so luong node trong list\n");
	return p->data;
}

/******set value of node ************/

//single
void set_value_of_node(node head, int position, int value)
{
	int k = 0;
	node p = head;
	while(p->next != NULL && k != position)
	{
		p = p->next;
		k ++;
	}
	if(k != position)
	{
		printf("Vi tri vuot qua tong so node trong list\n");
	}
	else
	{
		p->nums = value;
	}
}

//double
void set_value_of_node_double(ll_double list_double, int position, int value)
{
	int k = 0;
	node_double p = list_double.head;
	while(k != position && p->next_d != NULL)
	{
		p = p->next_d;
		k += 1;
	}
	if(k != position)
		printf("Vi tri yeu cau > so luong node cua list\n");
	else
		p->data = value;
}

/***********fine value of node in list************/

//single
int find_value_in_list(node head, int value)
{
	int position = 0;
	node p = head;
	for(p = head; p->next != NULL; p = p->next)
	{
		if(p->nums == value)
			return position;
		position ++;
	}
	return -1;
}

//double
int find_value_in_list_double(ll_double list_double, int value)
{
	int position = 0;
	node_double p = list_double.head;
	for(p = list_double.head; p->next_d != NULL; p = p->next_d)
	{
		if(p->data == value)
			return position;
		position++;
	}
	return -1; 
}

/**********sap sep cac gia tri cua node trong list theo thu tu tang dan bang pp insert sort***********/

//single
void sort_node_ascending_insert_sort(node head)
{
	int i = 1;
	int j;
	int last;
	if(head == NULL)
		return;
	node p;
	for(p = head; p->next != NULL; p = p->next)
	{
		j = i;
		last = p->next->nums;
		while(j > 0 && get_value_of_node(head, j - 1) > last)
		{
			set_value_of_node(head,j, get_value_of_node(head, j -1));
			j-= 1;
		}
		i ++;
		set_value_of_node(head,j,last);
	}
}

//double
void sort_node_ascending_insert_sort_double(ll_double list_double)
{
	int i = 1;
	int j;
	int last;
	if(list_double.head == NULL)
		return;
	node_double p;
	for(p = list_double.head; p->next_d !=NULL; p = p->next_d)
	{
		j = i;
		last = p->next_d->data;
		while(j > 0 && get_value_of_node_double(list_double, j - 1) > last)
		{
			set_value_of_node_double(list_double, j, get_value_of_node_double(list_double, j - 1));
			j -= 1;
		}
		i ++;
		set_value_of_node_double(list_double, j, last);	
	}
}	

/**********tim so luong node trong list******/

//single
int count_mount_of_node(node head)
{
	node p = head;
	int count = 0;
	if(head == NULL)
		return 0;
	// while(p->next != NULL)
	// {
	// 	count ++;
	// 	p = p->next;
	// }
	do {
		count ++;
		p = p->next;
	} while(p != NULL);

	return count;
}

//double
int count_mount_of_node_double(ll_double list_double)
{
	node_double p = list_double.head;
	int count = 0;
	if(list_double.head == NULL)
		return 0;
	do {
		count ++;
		p = p->next_d;
	} while(p != NULL);

	return count;
}

/*******in ra gia tri cua cac node trong list ****************/

//single
void print_list(node head)
{
	node p = head;
	int i = 0;
	printf("DangLHb DEBUG -- enter print_list\n");

	while(p!= NULL)
	{
		printf("Gia tri cua node thu %d trong link list la %d\n",i, p->nums);
		i++;
		p = p->next;
	}
}

//double
void print_list_double(ll_double list_double)
{
	node_double p = list_double.head;
	int i = 0;

	while(p != NULL)
	{
		printf("Gia tri cua node thu %d trong link list la %d\n",i, p->data);
		i ++;
		p = p->next_d;
	}
}

/*************ham khoi tao gia tri cho node dau hoac cuoi***********/

//single
node init_head(void)
{
	node head = NULL;
	return head;
}

//double
ll_double init_head_tail_double(void)
{
	ll_double list_double;
	list_double.head = NULL;
	list_double.tail = NULL;
	return list_double;
}

/*******khoi tao danh sach*************/

//single
node creat_link_list(void)
{
	int value, sum;
	node head = init_head();	 
	printf("Nhap so phan tu cua link list\n");
	scanf("%d",&sum);
	for(int i = 0; i < sum; i ++)
	{
		printf("Nhap gia tri cho node thu %d\n",i);
		scanf("%d", &value);
		head = add_node_at_the_end(head, value);
	}
	return head;
}

//double
ll_double creat_link_list_double(void)
{
	int value, sum;
	ll_double list_double = init_head_tail_double();
	printf("Nhap so phan tu cua link list\n");
	scanf("%d",&sum);
	for(int i = 0; i < sum; i ++)
	{
		printf("Nhap gia tri cho node thu %d\n",i);
		scanf("%d", &value);
		list_double = add_node_at_the_end_double(list_double, value);
	}
	return list_double;
}