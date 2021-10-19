#include <iostream>
#include<string>
#include "Header.h"
using namespace std;

void menu()
{
	cout << "\n ------------------------------------------------------------------------";
	cout << "\n |------------------------ TAN THUAN KINH CHAO! ------------------------|";
	cout << "\n ||      1. Dao nguoc cac chu so cua so nguyen.                        ||";
	cout << "\n ||      2. Cong 2 so nguyen lon.                                      ||";
	cout << "\n ||      3. Tru 2 so nguyen lon.                                       ||";
	cout << "\n ||      4. Chuong trinh nhan 2 so nguyen lon (Thong thuong).          ||";
	cout << "\n ||      5. Chuong trinh nhan 2 so nguyen lon (Karatsuba).             ||";
	cout << "\n ||      0. Thoat khoi chuong trinh.                                   ||";
	cout << "\n ||      Luu y (*): O giai thuat Karatsuba chi dung voi truong hop     ||";
	cout << "\n ||      2 SNL co cung chu so va la boi cua 2!                         ||";
	cout << "\n |------------------ HAN HANH DUOC PHUC VU QUY KHACH! ------------------|";
	cout << "\n ------------------------------------------------------------------------";
	cout << endl;
}

//Nhân 2 số nguyên lớn (thông thường)
SNL kqNhanSNL(SNL a, SNL b)
{
	SNL x = nhan2SNL(a, b);
	if (a.dau == -1 && b.dau == -1 || a.dau == 1 && b.dau == 1)
		x.dau = 1;
	else
		x.dau = -1;
	return x;
}

SNL nhan2SNL(SNL a, SNL b)
{
	if (a.n == 1)
		return nhanSNLVoi1So(b, a.a[0]);
	else if (b.n == 1)
		return nhanSNLVoi1So(a, b.a[0]);
	SNL A = tachDauSNL(a);
	SNL B = tachCuoiSNL(a);
	SNL C = tachDauSNL(b);
	SNL D = tachCuoiSNL(b);

	SNL x1 = nhan2SNL(A, C);
	themNSo0VaoSauSNL(x1, B.n + D.n);

	SNL x2 = nhan2SNL(A, D);
	themNSo0VaoSauSNL(x2, B.n);

	SNL x3 = nhan2SNL(B, C);
	themNSo0VaoSauSNL(x3, D.n);

	SNL x4 = nhan2SNL(B, D);

	return cong2SNL(cong2SNL(cong2SNL(x1, x2), x3), x4);
}

//Nhân 2 số nguyên lớn (Karatsuba)
SNL kqnhan2SNLKaratsuba(SNL a, SNL b)
{
	SNL x = nhan2SNLKaratsuba(a, b);
	if (a.dau == -1 && b.dau == -1 || a.dau == 1 && b.dau == 1)
		x.dau = 1;
	else
		x.dau = -1;
	return x;
}

SNL nhan2SNLKaratsuba(SNL a, SNL b)
{
	if (a.n == 1)
		return nhanSNLVoi1So(b, a.a[0]);
	else if (b.n == 1)
		return nhanSNLVoi1So(a, b.a[0]);
	SNL A = tachDauSNL(a);
	SNL B = tachCuoiSNL(a);
	SNL C = tachDauSNL(b);
	SNL D = tachCuoiSNL(b);

	SNL x1 = nhan2SNLKaratsuba(A, C);
	themNSo0VaoSauSNL(x1, a.n);

	SNL x2 = tru2SNL(tru2SNL(nhan2SNLKaratsuba(cong2SNL(A, B), cong2SNL(C, D)), nhan2SNL(A, C)), nhan2SNL(B, D));
	themNSo0VaoSauSNL(x2, A.n);

	SNL x3 = nhan2SNLKaratsuba(B, D);

	return cong2SNL(cong2SNL(x1, x2), x3);
}

SNL nhapSNL()
{
	SNL x;
	cout << "Nhap so chu so cua so nguyen: ";
	cin >> x.n;
	while (x.n <= 0)
	{
		cout << "So chu so phai la so duong!" << endl;
		cout << "Vui long nhap lai: ";
		cin >> x.n;
	}
	cout << "Nhap vao so nguyen cua ban: ";
	string s;
	getchar();
thuancute:
	getline(cin, s);
	int n = s.length();
	for (int i = 1; i < n; i++)
	{
		
		if (s[i] < 48 || s[i] > 57)
		{
			cout << "Vui long chi nhap vao so: ";
			goto thuancute;
		}
	}
	if (s[0] == 45 || s[0] == 43)
		n--;
	else if(s[0] < 48 || s[0] > 57)
	{
		cout << "Vui long chi nhap vao so: ";
		goto thuancute;
	}
	while (n != x.n)
	{
		cout << "Vui long nhap dung so chu so: ";
		goto thuancute;
	}
	for (int i = 0, j = 0; i < n; i++)
	{
		if (s[i] == 45 || s[i] == 43)
		{
			n++;
			continue;
		}
		x.a[j] = s[i] - 48;
		j++;
	}
	if (s[0] == 45)
		x.dau = -1;
	else
		x.dau = 1;
	return x;

}

void xuatSNL(SNL x)
{
	
	for (int i = 0; i < x.n; i++)
	{
		if (i == 0)
			cout << x.a[0] * x.dau;
		else
			cout << x.a[i];
		int tam = x.n - i - 1;
		if (tam % 3 == 0 && tam != 0)
			cout << ",";
	}
}

void xuatSNLKhongDau(SNL x)
{
	for (int i = 0; i < x.n; i++)
	{
		int tam = x.n - i - 1;
		cout << x.a[i];
		if (tam % 3 == 0 && tam != 0)
			cout << ",";
	}
}

void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void daoNguocMang(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		swap(a[i], a[n - i - 1]);
}

void themNSo0VaoSauSNL(SNL& a, int n)
{
	for (int i = a.n; i < a.n + n; i++)
		a.a[i] = 0;
	a.n += n;
}

SNL tachDauSNL(SNL a)
{
	SNL x;
	if (a.n % 2 != 0)
		x.n = a.n / 2 + 1;
	else
		x.n = a.n / 2;
	for (int i = 0; i < x.n; i++)
		x.a[i] = a.a[i];
	return x;
}

SNL tachCuoiSNL(SNL a)
{
	SNL x;
	int tam;
	if (a.n % 2 != 0)
	{
		tam = a.n - (a.n / 2 + 1);
		x.n = tam;
		tam++;
	}
	else
	{
		tam = a.n - a.n / 2;
		x.n = tam;
	}
	for (int i = 0, j = tam; i < x.n; i++, j++)
		x.a[i] = a.a[j];
	return x;
}

SNL cong2SNL(SNL a, SNL b)
{
	SNL x;
	if (a.dau == -1 && b.dau == 1)	//a < 0, b > 0 => a + b <=> b - (-a);
	{
		a.dau = 1;
		x = tru2SNL(b, a);
	}
	else if (a.dau == 1 && b.dau == -1)	//a > 0, b <0 => a + b <=> a - (-b);
	{
		b.dau = 1;
		x = tru2SNL(a, b);
	}
	else if (a.dau == -1 && b.dau == -1)	//a, b < 0 => a + b <=> -((-a) + (-b))
	{
		a.dau = 1;
		b.dau = 1;
		x = cong2SNL(a, b);
		x.dau = -1;
	}
	else // a, b > 0
	{
		int nho = 0;
		daoNguocMang(a.a, a.n);
		daoNguocMang(b.a, b.n);
		x.n = a.n > b.n ? a.n : b.n;
		if (a.n - b.n != 0)
		{
			if (a.n > b.n)
				themNSo0VaoSauSNL(b, a.n - b.n);
			else
				themNSo0VaoSauSNL(a, b.n - a.n);
		}
		int i;
		for (i = 0; i <= x.n; i++)
		{
			if (i < x.n)
			{
				x.a[i] = (a.a[i] + b.a[i] + nho) % 10;
				nho = (a.a[i] + b.a[i] + nho) / 10;
			}
			else if (i == x.n && nho > 0)
			{
				x.a[i] = nho;
				x.n++;
				break;
			}
		}
		daoNguocMang(x.a, x.n);
	}
	return x;
}

SNL tru2SNL(SNL a, SNL b)
{
	SNL x;
	if (a.dau == 1 && b.dau == -1)
	{
		b.dau = 1;
		x = cong2SNL(a, b);
	}
	else if (a.dau == -1 && b.dau == 1)
	{
		a.dau = 1;
		x = cong2SNL(a, b);
		x.dau = -1;
	}
	else if (a.dau == -1 && b.dau == -1)
	{
		b.dau = 1;
		x = cong2SNL(a, b);
	}
	else
	{
		if (soSanh2SNL(a, b) == -1)
		{
			x = tru2SNL(b, a);
			x.dau = -1;
		}
		else
		{
			int muon = 0;
			daoNguocMang(a.a, a.n);
			daoNguocMang(b.a, b.n);
			x.n = a.n > b.n ? a.n : b.n;
			if (a.n - b.n != 0)
			{
				if (a.n > b.n)
					themNSo0VaoSauSNL(b, a.n - b.n);
				else
					themNSo0VaoSauSNL(a, b.n - a.n);
			}
			int i;
			for (i = 0; i < x.n; i++)
			{
				if (a.a[i] >= b.a[i] + muon)
				{
					x.a[i] = a.a[i] - b.a[i] - muon;
					muon = 0;
				}
				else
				{
					x.a[i] = (a.a[i] + 10) - b.a[i] - muon;
					muon = 1;
				}
			}
			daoNguocMang(x.a, x.n);
		}
	}
	return x;
}

int soSanh2Mang(int a[], int m, int b[], int n)
{
	if (m > n)
		return 1;	// a > b
	else if (m < n)
		return -1;	// a < b
	for (int i = 0; i < m; i++)
	{
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
	}
	return 0;
}

int soSanh2SNL(SNL a, SNL b)
{
	if (a.dau == 1 && b.dau == 1)
		return soSanh2Mang(a.a, a.n, b.a, b.n);
	if (a.dau == -1 && b.dau == -1)
		return soSanh2Mang(b.a, b.n, a.a, a.n);
	if (a.dau == 1 && b.dau == -1)
		return 1;
	if (a.dau == -1 && b.dau == 1)
		return -1;
}

SNL nhanSNLVoi1So(SNL a, int n)
{
	SNL x;
	x.n = a.n;
	x.dau = a.dau;
	daoNguocMang(a.a, a.n);
	int nho = 0;
	for (int i = 0; i <= x.n; i++)
	{
		if (i < x.n)
		{
			x.a[i] = (a.a[i] * n + nho) % 10;
			nho = (a.a[i] * n + nho) / 10;
		}
		else if (i == x.n && nho > 0)
		{
			x.a[i] = nho;
			x.n++;
			break;
		}
	}
	daoNguocMang(x.a, x.n);
	//Xử lý dấu
	if (a.dau == 1 && n > 0 || a.dau == -1 && n < 0)
		x.dau = 1;
	else
		x.dau = -1;
	return x;
}