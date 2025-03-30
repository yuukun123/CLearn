#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int arr[100][100];
int m, n;
int i, j;

void nhap(int m, int n)
{
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
}
void xuat(int m, int n)
{
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}
void ss(int m, int n)
{
	int temp = INT_MAX;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (arr[i][j] < temp)
			{
				temp = arr[i][j];
			}
		}
	}
	cout << endl
		<< "chi phi nho nhat " << temp << endl;
}
void phancong(int arr[][100], int m, int n)
{
	int imin = 0, jmin = 0;
	int temp = INT_MAX;

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (arr[i][j] < temp)
			{
				temp = arr[i][j];
				imin = i;
				jmin = j;
			}
		}
	}
	cout << "(" << imin << ',' << jmin << ")" << endl;
}
void trungbinh_1_gio(int m, int n)
{
	for (i = 1; i <= m; i++)
	{
		float s = 0;
		for (j = 1; j <= n; j++)
		{
			s += arr[i][j];
		}
		cout << endl
			<< "chi phi trung binh 1 viec " << '\t' << setprecision(1) << fixed << s / n << endl;
	}
}
void trungbinh_1_nguoi(int m, int n)
{
	for (i = 1; i <= n; i++)
	{
		float s = 0;
		for (j = 1; j <= m; j++)
		{
			s += arr[j][i];
		}
		cout << endl
			<< "chi phi trung binh 1 nguoi tho " << '\t' << setprecision(1) << fixed << s / m << endl;
	}
}
int main()
{
	cout << "nhap hang: ";
	cin >> m;
	cout << "nhap cot: ";
	cin >> n;
	nhap(m, n);
	cout << endl;
	xuat(m, n);
	ss(m, n);
	phancong(arr, m, n);
	trungbinh_1_gio(m, n);
	trungbinh_1_nguoi(m, n);

	system("pause");
}