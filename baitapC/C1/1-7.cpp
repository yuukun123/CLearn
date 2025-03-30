#include <bits/stdc++.h>
using namespace std;

// tong cac phan tu
// tim amx
// dem snt

int a[] = {1, 2, 3, 4, 5}, n = 5;

int out(int a[], int n)
{
	if (n == 1)
		return a[0];
	return out(a, n - 1) + a[n - 1];
}

int max(int a[], int n)
{
	if (n == 1)
		return a[0];
	else
	{
		if (a[n - 1] > max(a, n - 1))
			return a[n - 1];
		else
			return max(a, n - 1);
	}
}

bool ktr(int A)
{
	if (A < 2)
		return 0;
	for (int i = 2; i <= sqrt(A); i++)
	{
		if (A % i == 0)
			return 0;
	}
	return 1;
}

int Cnt_SNT(int a[], int n)
{
	if (n < 1)
		return 0;
	return ktr(a[n - 1]) ? Cnt_SNT(a, n - 1) + 1 : Cnt_SNT(a, n - 1);
}

int main()
{
	cout << out(a, n) << endl
		<< max(a, n) << endl
		<< Cnt_SNT(a, n);
}