#include <iostream>
using namespace std;

double t, m, p;
int tongtien;

void cauA()
{
	cout << "nhap tien muon: ";
	cin >> t; // nhập vô số tiền mà mình muốn vay
	cout << "nhap thoi han vay: ";
	cin >> m; // nhập thời hanj mình vay // trong đề là 24 tháng thì nhập m = 24
	cout << "nhap lai p ";
	cin >> p;									 // lãi suất trong đề nó cho ct lãi suất %/12 thì mình sẽ đổi nó thành p/1200 vì p sẽ thay đổi theo đề
	int tien_goc_hang_thang = t / m;			 // tiền gốc tháng đầu = số tiền vay (t) * thời hạn mình vay (m)
	int tien_lai_thang_dau = t * p * 1.0 / 1200; // tiền lãi tháng đầu = số tiền vay (t) * p*1.0/1200
	double tien_lai_thang_t2;					 // tiền lãi từ tháng thứ 2 thì sẽ theo công thức bên dưới nè
	int s = 0;
	for (int i = 1; i <= m; i++)											// khởi tạo i là số tháng sẽ chạy từ i = 1 đến i = 24 là số tháng
	{																		// theo công thức trong đề bài thì mình thu được công thức như vậy
		tien_lai_thang_t2 = (t - tien_goc_hang_thang * i) * p * 1.0 / 1200; // số tiền từ tháng thứ 2 = ( tiền vay (t) - i * tiền gốc tháng đầu ) * lãi suất ( p*1.0/1200 )
		s += tien_lai_thang_t2;												// chỗ này là cộng dồn tiền lãi tháng 2 đến tháng 24
	}
	tongtien = t + s + tien_lai_thang_dau; // tống tiền = tiền vay (t) + tiền từ t2 đến t24 + têinf lãi tháng đầu
	cout << "tong tien khach phai tra ngan hang " << tongtien << endl;
}
void cauB()
{
	cout << "nhap tien muon: ";
	cin >> t;
	cout << "nhap thoi han vay: ";
	cin >> m;
	cout << "nhap lai p ";
	cin >> p;
	int tien_goc_hang_thang = t / m;
	int tien_lai_thang_dau = t * p * 1.0 / 1200;
	double tien_lai_thang_t2;
	int s = 0;
	for (int i = 1; i <= m; i++)
	{
		tien_lai_thang_t2 = (t - tien_goc_hang_thang * i) * p * 1.0 / 1200;
		s += tien_lai_thang_t2;
	}
	tongtien = t + s + tien_lai_thang_dau;
	cout << "tong tien khach tra ngan hang khi het thoi han vay " << tongtien << endl;
}

int main()
{
	cauA();
	cout << endl;
	cauB();
}