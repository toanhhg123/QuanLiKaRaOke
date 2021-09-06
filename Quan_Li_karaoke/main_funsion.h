#pragma once
#include"Quan_li.h"
#include"design.h"
#include"design.h"
#include"fstream"
#include"file.h"
#include"ctime"
#include"ThucUong.h"
#include"ThucAn.h"

void out_toando(int x, int y, string str)
{
	gotoXY(x, y);
	cout << str;
}
void vetuong()
{
	setTextColor(9);
	for (int i = Tuong_Trai; i <= Tuong_phai; i++)
	{
		gotoXY(i, Tuong_tren);
		cout << (char)220;
	}
	for (int i = Tuong_tren+1; i <Tuong_duoi; i++)
	{
		gotoXY(Tuong_phai, i);
		cout << (char)222;
	}
	for (int i = Tuong_phai; i >=Tuong_Trai; i--)
	{
		gotoXY(i, Tuong_duoi);
		cout << (char)223;
	}
	for (int i = Tuong_duoi-1; i > Tuong_tren; i--)
	{
		gotoXY(Tuong_Trai, i);
		cout << (char)221;
	}
}
void vetuongGT()
{
	setTextColor(9);
	for (int i = Tuong_Trai; i <= Tuong_phai; i++)
	{
		gotoXY(i, 0);
		cout << (char)220;
	}
	for (int i = 0+1; i < Tuong_tren+1; i++)
	{
		gotoXY(Tuong_phai, i);
		cout << (char)222;
	}
	for (int i = Tuong_tren ; i > 0; i--)
	{
		gotoXY(Tuong_Trai, i);
		cout << (char)221;
	}
}
void VEBienbr()
{
	for (int i = Tuong_phai; i <= Bien_Ben; i++)
	{
		gotoXY(i, 0);
		cout << (char)220;
	}
	for (int i = 1; i <= Tuong_duoi; i++)
	{
		gotoXY(Bien_Ben, i);
		cout << (char)222;
	}
	for (int i = Bien_Ben; i >= Tuong_phai; i--)
	{
		gotoXY(i, Tuong_duoi);
		cout << (char)223;
	}
}
void opption()
{
	int biengiua = Tuong_duoi - 8;
	for (int i = Tuong_Trai + 1; i < Tuong_phai; i++)
	{
		gotoXY(i, biengiua);
		cout << (char)220;
	}
	setTextColor(10);
	out_toando(Tuong_Trai + 1, ++biengiua, "\t\t\tHuong Dan");
	out_toando(Tuong_Trai + 1, ++biengiua+1, "Dung 4 phim mui ten");
	out_toando(Tuong_Trai + 1, biengiua+1, "\t\t\t\t  Enter: Chon");
	out_toando(Tuong_Trai + 1, ++biengiua+2, "\t\tNhan ESC: KET_THUC");
}

int batsukien(int bien)
{
	setTextColor(4);
	toado T;
	T.x = Tuong_Trai + 1;
	T.y = Tuong_tren + 1;
	
	out_toando(T.x, T.y, "->");
	while (true)
	{
		toado cu = T;
		char key = _getch();
		if (key == 13)
			return T.y - Tuong_tren;
		else if (key == 27)
		{
			system("cls");
			cout << "\n\tChuong trinh ket thuc";
			return 0;
		}
		else if (key == -32)
			key = _getch();
		switch (key)
		{
		case 80:
			T.y++;
			if (T.y == bien)
				T.y = Tuong_tren + 1;
			out_toando(cu.x, cu.y, "  ");
			out_toando(T.x, T.y, "->");
			break;
		case 72:
			T.y--;
			if (T.y == Tuong_tren)
				T.y = bien - 1;
			out_toando(cu.x, cu.y, "  ");
			out_toando(T.x, T.y, "->");
			break;
		}
	}

}

int xuatDsPhongTrong(phong* p[30], int n);
void orderPhong(phong* p[30], int n);
bool kt_Phonghoatdong(phong* p);
bool KT_phong_Ma(phong* p[30], int n, string mp);
nodeThucAn* creatTA(Thuc_An* a);
void push_TA(List_Thuc_An& ds_Thuc_an, nodeThucAn* p);
phong* find(phong* p[30], int n, string mp);
nodeThucAn* creatTA(Thuc_An* a);
void push_TA(List_Thuc_An& ds_Thuc_an, nodeThucAn* p);
int xuat_ds_phong_on(phong* p[30], int n);
void xuatDoUong_Phong(phong* p[30], int n);
void oder_douong(phong* p[30], int n);
void tinhTienThucUong_phong(phong* p[30], int n);
void oder_thucAn(phong* p[30], int n);
void xuatTA_phong(phong* p[30], int n);
void tinhTienThucAn_phong(phong* p[30], int n);
long tinhtien_phong(phong* p[30], int n);
void menu()
{
	
	int luachon = 1;
	toado t;
	t.x = Tuong_Trai;
	t.y = Tuong_tren;
	phong * p[30];
	int n;
	doc_dsPhong(p, n);
	Thuc_uong* u[30];
	int n_u;
	docfile_Thuc_uong(u, n_u);
	Thuc_An* a[32];
	int n_a;
	docFileThucAn(a, n_a);
	while (luachon!=0)
	{

		system("cls");
		backgrout();
		vetuong();
		vetuongGT();
		VEBienbr();
		opption();
		setTextColor(14);
		out_toando(t.x + 1, 1, "\t\t\tNHOM 3");
		out_toando(t.x + 1, 2, " Thanh vien 1: Le Huu Toan - 2001206939");
		out_toando(t.x + 1, 3, " Thanh vien 2: Huynh Dang Khoa - 2001207266");
		out_toando(t.x + 1, 4, " Thanh vien 3: Nguyen Anh Tuan - 2001207030");
		out_toando(t.x + 1, 5, " Thanh vien 4: Nguyen Bao Sanh - 2001207211");
		out_toando(t.x + 1, 6, " Thanh vien 5: Do Van Thao - 2001207293 ");
		setTextColor(11);
		noCursorType();
		gotoXY(++t.x+2, ++t.y);
		cout << "1. Tao phong";
		gotoXY(t.x+2, ++t.y);
		cout << "2. xuat danh sach phong dang hoat dong";
		gotoXY(t.x+2, ++t.y);
		cout << "3. xuat danh sach phong trong";
		gotoXY(t.x+2, ++t.y);
		cout << "4. xuat Menu do uong";
		gotoXY(t.x+2, ++t.y);
		cout << "5. cuat menu mon an";
		gotoXY(t.x+2, ++t.y);
		cout << "6. order do uong";
		gotoXY(t.x+2, ++t.y);
		cout << "7. order mon an";
		gotoXY(t.x + 2, ++t.y);
		cout << "8. xuat danh sach do uong cua phong";
		gotoXY(t.x + 2, ++t.y);
		cout << "9. xuat mon an cua phong";
		gotoXY(t.x + 2, ++t.y);
		cout << "10. Tinh tien do uong cua phong";
		gotoXY(t.x + 2, ++t.y);
		cout << "11. Tinh tien mon an cua phong";
		gotoXY(t.x + 2, ++t.y);
		cout << "12. Tinh tien Phong ";
		gotoXY(t.x+1, ++t.y);
		luachon= batsukien(t.y);
		switch (luachon)
		{
		case 1:
		{
			orderPhong(p, n);
			_getch();
			break;
		}
		case 2:
		{
			xuat_ds_phong_on(p, n);
			_getch();
			break;
		}
		case 3:
			xuatDsPhongTrong(p, n);
			_getch();
			break;
		case 4:
			xuatMenuThucUong(u, n_u);
			_getch();
			break;
		case 5:
			XuatMenuMonan(a, n_a);
			_getch();
			break;
		case 6:
			oder_douong(p, n);
			_getch();
			break;
		case 7:
			oder_thucAn(p, n);
			_getch();
			break;
			
		case 8:
			xuatDoUong_Phong(p, n);
			_getch();
			break;
		case 9:
			xuatTA_phong(p, n);
			_getch();
			break;
		case 10:
			tinhTienThucUong_phong(p, n);
			_getch();
			break;
		case 11:
			tinhTienThucAn_phong(p, n);
			_getch();
			break;
		case 12:
			tinhtien_phong(p, n);
			_getch();
			break;
		}
		t.x = Tuong_Trai;
		t.y = Tuong_tren;
	}
}
bool kt_Phonghoatdong(phong* p)
{
	if (p->KT_hoat_dong == true)
		return true;
	return false;
}
int xuatDsPhongTrong(phong* p[30], int n)
{
	system("cls");
	out_toando(20, 2, "Danh sach phong trong la\n");
	cout << "\nMa" << "\t\tSL_NV" << "\t\tGIA" << "\t\tloai phong";
	int flag = -1;
	for (int i = 0; i < n; i++)
	{
		if (kt_Phonghoatdong(p[i]) == false)
		{
			xuat1_phong(p[i]);
			flag = 1;
		}
	}
	if (flag == -1)
		cout << "\n\tPhong day";
	return flag;
}
int xuat_ds_phong_on(phong* p[30], int n)
{
	system("cls");
	out_toando(20, 2, "Danh sach phong Dang hoat dong la\n");
	int flag = -1;
	cout << "\nMa" << "\t\tSL_NV" << "\t\tGIA" << "\t\tloai phong";
	for (int i = 0; i < n; i++)
	{
		if (p[i]->KT_hoat_dong == true)
		{
			flag = 1;
			xuat1_phong(p[i]);
		}
	}
	if (flag == -1)
	{
		cout << "\n\tHien van chua co phong nao hoat dong";
		return flag;
	}
	return flag;
}
phong* find(phong* p[30], int n, string mp)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i]->Ma_Phong == mp)
			return p[i];
	}
	return NULL;
}
bool KT_phong_Ma(phong* p[30], int n, string mp)
{
	for (int i = 0; i < n; i++)
		if (p[i]->Ma_Phong == mp)
			return true;
	return false;
}
void orderPhong(phong* p[30], int n)
{
	system("cls");
	xuatDsPhongTrong(p, n);
	cout << "\nNhap ma phong: ";
	string mp;
	cin >> mp;
	while (find(p,n,mp)==NULL )
	{
		cout << "\nMa phong khong ton tai vui long nhap lai: ";
		cin >> mp;
	}
	phong* temp = find(p, n, mp);
	while (temp==NULL || temp->KT_hoat_dong==true)
	{
		cout << "\nPhong nay dang hoat dong hoac khong ton tai vui long nhap lai: ";
		cin >> mp;
		temp = find(p, n, mp);
	}
	for (int i = 0; i < n; i++)
	{
		if (p[i]->Ma_Phong == mp)
		{
			time_t now = time(0);
			tm* Time = localtime(&now);
			p[i]->KT_hoat_dong = true;
			p[i]->hours_star = Time->tm_hour * 60 + Time->tm_min;
			cout << "\n\tPhong da duoc tao";
			return;
		}
	}
}
void oder_thucAn(phong* p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return;
	string ma;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp == NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	while (temp == NULL || temp->KT_hoat_dong == false)
	{
		cout << "\nvui long nhap dung ma phong dang hoat dong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	Thuc_An* a[32];
	int n_a;
	docFileThucAn(a, n_a);
	XuatMenuMonan(a, n_a);
	string maTA;
	cout << "\nNhap ma thuc an: ";
	cin >> maTA;
	Thuc_An* tempTA = findTA(a, n_a, maTA);
	while (tempTA==NULL)
	{
		cout << "\nVui long nhap dung ma Thuc an: ";
		cin >> maTA;
		tempTA = findTA(a, n_a, maTA);
	}
	push_TA(temp->ds_Thuc_an, creatTA(tempTA));

}
void xuatTA_phong(phong* p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return;
	string ma;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp == NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	cout << "\n\tDanh sach Thuc an cua phong " << temp->Ma_Phong;
	if (xuat_thuc_an(temp->ds_Thuc_an) == -1)
		cout << "\n\tHien tai chua co thuc an";
}
void tinhTienThucAn_phong(phong* p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return ;
	string ma;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp == NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	if (xuat_thuc_an(temp->ds_Thuc_an) == -1)
		cout << "\n\tHien tai chua co thuc an";
	cout << "\nTong tien cua phong " << temp->Ma_Phong << " la: " << tinhTienMonAn(temp->ds_Thuc_an);
}
void oder_douong(phong* p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return;
	string ma;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp==NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	while (temp == NULL || temp->KT_hoat_dong==false)
	{
		cout << "\nvui long nhap dung ma phong dang hoat dong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	Thuc_uong* u[30];
	int n_u;
	docfile_Thuc_uong(u, n_u);
	xuatMenuThucUong(u, n_u);
	string maTU;
	cout << "\nNhap ma thuc uong: ";
	cin >> maTU;
	Thuc_uong *tempU = findTU(u, n_u, maTU);
	while (tempU==NULL)
	{
		cout << "\nVui long nhap chinh xac ma: ";
		cin >> maTU;
		tempU = findTU(u, n_u, maTU);
	}
	push_TU(temp->ds_thuc_uong, creatTU(tempU));
}
void xuatDoUong_Phong(phong *p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return;
	string ma;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp == NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	cout << "\n\tDanh sach do uong cua phong " << temp->Ma_Phong;
	if (xuat_thuc_uong(temp->ds_thuc_uong) == -1)
		cout << "\n\tHien tai chu co do uong";
}
void tinhTienThucUong_phong(phong* p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return;
	string ma;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp == NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	if (xuat_thuc_uong(temp->ds_thuc_uong) == -1)
		cout << "\n\tHien tai chu co do uong";
	cout << "\nTong tien cua phong " << temp->Ma_Phong << " la: " << tinhTienDoUong(temp->ds_thuc_uong);
}
long tinhtien_phong(phong* p[30], int n)
{
	if (xuat_ds_phong_on(p, n) == -1)
		return 0;
	string ma;
	long resuilt = 0;
	cout << "\n\tNhap ma phong: ";
	cin >> ma;
	phong* temp = find(p, n, ma);
	while (temp == NULL)
	{
		cout << "\nvui long nhap dun ma phong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	while (temp == NULL || temp->KT_hoat_dong == false)
	{
		cout << "\nvui long nhap dung ma phong dang hoat dong: ";
		cin >> ma;
		temp = find(p, n, ma);
	}
	time_t now = time(0);
	tm* Time = localtime(&now);
	cout << "\n\tThoi gian: " << temp->hours_star/60<<"h"<<temp->hours_star%60;
	temp->hours_end = Time->tm_hour * 60 + Time->tm_min;
	cout << " --> " << temp->hours_end/60 <<"h"<<temp->hours_end%60;
	resuilt = tinhTienMonAn(temp->ds_Thuc_an) + tinhTienDoUong(temp->ds_thuc_uong)+(temp->hours_end-temp->hours_star)*(temp->Gia)/60;
	if (xuat_thuc_uong(temp->ds_thuc_uong) == -1)
		cout << "\n\tHien tai chu co do uong";
	cout << "\nTong tien cua phong " << temp->Ma_Phong << " la: " << tinhTienDoUong(temp->ds_thuc_uong);
	if (xuat_thuc_an(temp->ds_Thuc_an) == -1)
		cout << "\n\tHien tai chua co thuc an";
	cout << "\nTong tien cua phong " << temp->Ma_Phong << " la: " << tinhTienMonAn(temp->ds_Thuc_an);
	ofstream f("HOADON//Hoa_don.txt", ios::out);
	f << "\n\tThoi gian: " << temp->hours_star / 60 << "h" << temp->hours_star % 60;
	f << " --> " << temp->hours_end / 60 << "h" << temp->hours_end % 60;
	f << "\n\tDanh sach Thuc an : ";
	if (temp->ds_Thuc_an.aHead == NULL)
		f << " khong";
	else
	{
		while (temp->ds_Thuc_an.aHead != NULL)
		{
			f << "\n" << temp->ds_Thuc_an.aHead->data->Ten_Mon_An << "\t" << temp->ds_Thuc_an.aHead->data->soluong << "\t" << temp->ds_Thuc_an.aHead->data->Gia_Tien;
			temp->ds_Thuc_an.aHead = temp->ds_Thuc_an.aHead->next;
		}
	}
	f << "\n\tDanh sach Do uong : ";
	if (temp->ds_thuc_uong.uHead == NULL)
		f << " khong";
	else
	{
		while (temp->ds_thuc_uong.uHead != NULL)
		{
			f << "\n" << temp->ds_thuc_uong.uHead->data->Ten_thuc_uong << "\t" << temp->ds_thuc_uong.uHead->data->soluong << "\t" << temp->ds_thuc_uong.uHead->data->Gia_tien;
			temp->ds_thuc_uong.uHead = temp->ds_thuc_uong.uHead->next;
		}
	}
	f << "\n\tTong Tien :  " << resuilt << "d";
	f << "\n***** Cam on qui khach, hen gap lai *****";
	temp->ds_Thuc_an.aHead = NULL;
	temp->ds_thuc_uong.uHead = NULL;
	temp->KT_hoat_dong = false;
	cout << "\ntong tien la: " << resuilt;
	cout << "\n\n\tHoa don duoc in trong file HOADON/Hoa_Don.txt";
}
