#pragma once
#include"main_funsion.h"
nodeThucAn* creatTA(Thuc_An* a)
{
	nodeThucAn* p = new nodeThucAn;
	p->data = a;
	p->next = NULL;
	return p;
}
void push_TA(List_Thuc_An& ds_Thuc_an, nodeThucAn* p)
{
	if (ds_Thuc_an.aHead == NULL)
		ds_Thuc_an.aHead = p;
	else
	{
		p->next = ds_Thuc_an.aHead;
		ds_Thuc_an.aHead = p;
	}
}
Thuc_An* findTA(Thuc_An* a[32], int n_a, string ma)
{
	for (int i = 0; i < n_a; i++)
		if (ma == a[i]->Ma_Thuc_An)
			return a[i];
	return NULL;
}
int xuat_thuc_an(List_Thuc_An a)
{
	if (a.aHead == NULL)
		return -1;
	while (a.aHead!=NULL)
	{
		Xuat1_MonAn(a.aHead->data);
		a.aHead = a.aHead->next;
	}
	return 1;
}
long tinhTienMonAn(List_Thuc_An a)
{
	if (a.aHead == NULL)
		return 0;
	long resuilt = 0;
	nodeThucAn* p = a.aHead;
	while (p!=NULL)
	{
		resuilt += p->data->soluong * p->data->Gia_Tien;
		p = p->next;
	}
	return resuilt;
}
