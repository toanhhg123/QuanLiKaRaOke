#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Thuc_uong
{
	string Ma_Thuc_uong;
	string Ten_thuc_uong;
	int soluong;
	float Gia_tien;
};
struct Thuc_An
{
	string Ma_Thuc_An;
	string Ten_Mon_An;
	int soluong;
	float Gia_Tien;
};
struct nodeThucAn
{
	Thuc_An *data;
	nodeThucAn* next;
};
struct node_Thuc_Uong
{
	Thuc_uong *data;
	node_Thuc_Uong* next;
};
struct List_Thuc_An
{
	nodeThucAn* aHead=NULL;
};
struct List_Thuc_Uong
{
	node_Thuc_Uong* uHead = NULL;
};
struct phong
{
	string Ma_Phong;
	int SL_Nhan_Vien;
	float Gia;
	string Loai_Phong;
	List_Thuc_An ds_Thuc_an;
	List_Thuc_Uong ds_thuc_uong;
	bool KT_hoat_dong = false;
	int hours_star;
	int hours_end;
};

