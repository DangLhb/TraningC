// Trien khai va tao link list , truy suat cac phan tu trong link list
#include"link_list.h"

node creat_node(int value)
{
	node danglhb;
	danglhb = (node)malloc(sizeof(struct LinkedList));
	danglhb->nums = value;
	danglhb->next = NULL;
	return danglhb;	
}
// De them mot node vao dau thi kiem tra list co 
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
// them node vao cuoi trong list : Kierm tra list co trong khong? Neu khong thi thuc hien tim phan tu cuoi, next cua cuoi tro toi
// node moi
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
// them node vao vi tri mong muon nao do trong list : Kiem tra co phai la list trong k hoac truong hop nay tuong duong voi position = 0.= > chen vao dau hang.
// Neu khong thi thuc hien vòng lặp chạy từ node 0 đến node chỉ định.

node add_node_at_hope_postion(node head, int position, int value)
{
	printf("DangLHb debug - position = %d\n", position);
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
			printf("DanglHb Debug - create a node with value = %d\n", value);
			node temp = creat_node(value);
			temp->next = p->next;
			p->next = temp;
			printf("DanglHb DEBUG - in ra gia tri vua nhap = %d\n", p->nums);
		}
	}
	return head;
}
// Xoa node khoi danh sach lien ket :
// Xoa dau : kiem tra list co empty k ? neu k thi thuc hien

node del_node_at_begin_of_list(node head)
{
	if(head == NULL)
		printf("Nothing to del\n");
	else 
	{
		head = head->next;
	}
}
// Xoa cuoi : kiem tra list co empty k ? neu khong thi thuc hien duyet toi phan tu gan cuoi cung, neu p->next->next = Null thi p->next = NuLL
node del_node_at_end_of_list(node head)
{
	if(head = NULL)
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
	}
	return head;
}

// xoa vi tri bat ki

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

// lay gia tri bat ki trong list

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

// set gia tri moi cho node theo vi tri

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

//Tìm kiem gia tri trong list
// return position
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
// sap xep list theo thu tu tang dan dua theo insert sort
// insert sort : Thuc hien sap xep 1 phan tu vao mot mang da duoc sap xep tu truoc
void sort_node_ascending_insert_sort(node head)
{
	int i = 1;
	int j;
	int last;
	node p;
	for(p = head; p->next != NULL; p = p->next)
	{
		j = i;
		last = p->nums;
		while(j > 0 && get_value_of_node(head, j - 1) > last)
		{
			set_value_of_node(head,j, get_value_of_node(head, j -1));
			j-= 1;
		}
		i ++;
		set_value_of_node(head,j,last);
	}

}

void print_list(node head, int sum)
{
	node p;
	printf("DangLHb DEBUG -- enter print_list\n");
	// for(p = head; p->next != NULL; p = p->next)
	p = head;
	for(int i = 0;i < sum ;i ++)
	{
		printf("Gia tri cua node thu %d trong link list la %d\n",i, p->nums);
		if(p->next != NULL)
		{
			p = p->next;
		}
		else
			break;
	}
}
node init_head()
{
	node head = NULL;
	return head;
}
node creat_link_list()
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
