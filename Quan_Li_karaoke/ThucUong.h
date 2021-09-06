#pragma once
#include"main_funsion.h"
node_Thuc_Uong* creatTU(Thuc_uong* a)
{
	node_Thuc_Uong* p = new node_Thuc_Uong;
	p->data = a;
	p->next = NULL;
	return p;
}
void push_TU(List_Thuc_Uong& ds_Thuc_Uong, node_Thuc_Uong* p)
{
	if (ds_Thuc_Uong.uHead == NULL)
		ds_Thuc_Uong.uHead = p;
	else
	{
		p->next = ds_Thuc_Uong.uHead;
		ds_Thuc_Uong.uHead = p;
	}
}
Thuc_uong* findTU(Thuc_uong* u[20], int u_n, string ma)
{
	for (int i = 0; i < u_n; i++)
		if (ma == u[i]->Ma_Thuc_uong)
			return u[i];
	return NULL;
}
int xuat_thuc_uong(List_Thuc_Uong u)
{
	if (u.uHead == NULL)
		return -1;
	while (u.uHead != NULL)
	{
		xuat1_thucuong(u.uHead->data);
		u.uHead = u.uHead->next;
	}
}
long tinhTienDoUong(List_Thuc_Uong u)
{
	if (u.uHead == NULL)
		return 0;
	long resuilt = 0;
	node_Thuc_Uong* p = u.uHead;
	while (p!=NULL)
	{
		resuilt += p->data->soluong * p->data->Gia_tien;
		p = p->next;
	}
	return resuilt;
}