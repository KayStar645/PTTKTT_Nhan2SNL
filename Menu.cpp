#include <iostream>
#include "Header.h"
using namespace std;


int main()
{

	int luaChon;
	do
	{
		menu();
		cout << "Nhap vao su lua chon cua ban: ";
		cin >> luaChon;
		while (luaChon < 0 || luaChon > 5)
		{
			cout << "Lua chon cua ban khong co trong chuong trinh cua chung toi!" << endl;
			cout << "Ban vui long nhap lai: ";
			cin >> luaChon;
		}
		switch (luaChon)
		{
		case 1:
		{
			cout << "\n";
			SNL x = nhapSNL();
			daoNguocMang(x.a, x.n);
			cout << "So nguyen cua ban sau khi duoc dao nguoc: ";
			xuatSNLKhongDau(x);			
		}break;
		case 2:
		{
			cout << "\n";
			SNL x1 = nhapSNL();
			cout << "\n";
			SNL x2 = nhapSNL();

			SNL tong = cong2SNL(x1, x2);
			cout << "***Ket qua cua phep cong: (";
			xuatSNL(x1);
			cout << ") + (";
			xuatSNL(x2);
			cout << ") = ";
			xuatSNL(tong);			
		}break;
		case 3:
		{
			cout << "\n";
			SNL x1 = nhapSNL();
			cout << "\n";
			SNL x2 = nhapSNL();

			SNL hieu = tru2SNL(x1, x2);
			cout << "***Ket qua cua phep tru: (";
			xuatSNL(x1);
			cout << ") - (";
			xuatSNL(x2);
			cout << ") = ";
			xuatSNL(hieu);
		}break;
		case 4:
		{
			cout << "\n";
			SNL x1 = nhapSNL();
			cout << "\n";
			SNL x2 = nhapSNL();

			SNL kq = kqNhanSNL(x1, x2);
			cout << "***Ket qua cua phep nhan: (";
			xuatSNL(x1);
			cout << ") * (";
			xuatSNL(x2);
			cout << ") = ";
			xuatSNL(kq);
		}break;
		case 5:
		{
			cout << "\n";
			SNL x1 = nhapSNL();
			cout << "\n";
			SNL x2 = nhapSNL();

			SNL kq = kqnhan2SNLKaratsuba(x1, x2);
			cout << "***Ket qua cua phep nhan: (";
			xuatSNL(x1);
			cout << ") * (";
			xuatSNL(x2);
			cout << ") = ";
			xuatSNL(kq);
		}break;
		case 0:
		{
			cout << "\n -       Cam on ban da tin dung chuong trinh cua chung toi!             -";
			cout << "\n -                           Hen gap lai ban!                           -";
		}break;
		}
	} while (luaChon != 0);

	return 0;
}