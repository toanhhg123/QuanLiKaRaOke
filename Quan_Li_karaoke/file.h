#pragma once
#include"main_funsion.h"
void doc_dsPhong(phong *p[30], int &n)
{
	fstream f("Quanli//DS_PHONG.txt");
	if (!f.is_open())
		cout << "\nKhong mo duoc file";
	else
	{
		n = 0;
		while (!f.eof())
		{
			f.ignore();
			p[n] = new phong;
			getline(f, p[n]->Ma_Phong, ',');
			f >> p[n]->SL_Nhan_Vien;
			f.seekg(1, 1);
			getline(f, p[n]->Loai_Phong,',');
			f >> p[n]->Gia;
			n++;
		}
		f.close();
	}
}
void xuat1_phong(phong* p)
{
	cout << "\n" << p->Ma_Phong << "\t\t" << p->SL_Nhan_Vien << "\t\t" << p->Gia << "\t\t" << p->Loai_Phong;

}
void Xuatds_phong(phong *p[30],int& n)
{
	cout << "\nMa" << "\t\tSL_NV" << "\t\tGIA" << "\t\tloai phong";

	for (int i = 0; i < n; i++)
		cout << "\n" << p[i]->Ma_Phong << "\t\t" << p[i]->SL_Nhan_Vien  << "\t\t" << p[i]->Gia << "\t\t" << p[i]->Loai_Phong;
}
void docfile_Thuc_uong(Thuc_uong* u[20], int& n)
{
	fstream f("Quanli//THUC_UONG.txt");
	if (!f.is_open())
		cout << "\nKhong mo duoc file";
	else
	{
		n = 0;
		while (!f.eof())
		{
			f.ignore();
			u[n] = new Thuc_uong;
			getline(f, u[n]->Ma_Thuc_uong, ',');
			getline(f, u[n]->Ten_thuc_uong, ',');
			f >> u[n]->Gia_tien;
			f.seekg(1, 1);
			f >> u[n]->soluong;
			n++;
		}
		f.close();
	}
}
void xuat1_thucuong(Thuc_uong* u)
{
	cout << "\n" << u->Ma_Thuc_uong << "\t" << u->Ten_thuc_uong << "\t\t" << size_t (u->Gia_tien) << "\t\t" << u->soluong;
}
void xuatMenuThucUong(Thuc_uong* u[20], int n)
{
	system("cls");
	setTextColor(12);
	cout << "\nMa_TU" << "\tTen Thuc uong" << "\t\tGia tien" << "\tSo Luong";
	for (int i = 0; i < n; i++)
		xuat1_thucuong(u[i]);
}
void docFileThucAn(Thuc_An* a[31], int& n)
{
	fstream f("Quanli//THUC_AN.txt");
	if (!f.is_open())
		cout << "\nKhong mo duoc file";
	else
	{
		n = 0;
		while (!f.eof())
		{
			f.ignore();
			a[n] = new Thuc_An;
			getline(f, a[n]->Ma_Thuc_An, ',');
			getline(f, a[n]->Ten_Mon_An, ',');
			f >> a[n]->Gia_Tien;
			f.seekg(1, 1);
			f >> a[n]->soluong;
			n++;
		}
		f.close();
	}
}
void Xuat1_MonAn(Thuc_An* a)
{
	cout << "\n" << a->Ma_Thuc_An << "\t" <<a->Ten_Mon_An << "\t\t" << size_t(a->Gia_Tien) << "\t\t" <<a->soluong;
}
void XuatMenuMonan(Thuc_An* a[32], int n)
{
	system("cls");
	setTextColor(12);
	cout << "\nMa_TA" << "\tTen Thuc An" << "\t\tGia tien" << "\tSo Luong";
	for (int i = 0; i < n; i++)
		Xuat1_MonAn(a[i]);
}
void backgrout()
{
	setTextColor(12);
	fstream f("Quanli//backgr.txt");
	if (!f.is_open())
		cout << "\nKhong mo duoc file";
	else
	{
		string str;
		while (!f.eof())
		{
			getline(f, str);
			cout << "\n\t\t\t\t\t\t\t" << str;
		}
		f.close();
	}
}