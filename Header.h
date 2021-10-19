#define MAX 100

struct SNL
{
	int n, a[MAX];
	int dau = 1;
};

void menu();;
SNL nhapSNL();
void xuatSNL(SNL a);
void daoNguocMang(int a[], int n);
SNL cong2SNL(SNL a, SNL b);
SNL tru2SNL(SNL a, SNL b);
SNL nhanSNLVoi1So(SNL a, int n);
void themNSo0VaoSauSNL(SNL& a, int n);
SNL tachDauSNL(SNL a);
SNL tachCuoiSNL(SNL a);
SNL nhan2SNL(SNL a, SNL b);
int soSanh2Mang(int a[], int m, int b[], int n);
SNL kqNhanSNL(SNL a, SNL b);
int soSanh2SNL(SNL a, SNL b);
void xuatSNLKhongDau(SNL x);
SNL nhan2SNLKaratsuba(SNL a, SNL b);
SNL kqnhan2SNLKaratsuba(SNL a, SNL b);