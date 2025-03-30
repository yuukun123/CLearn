#include <bits/stdc++.h>
using namespace std;

struct fraction {
	float tu, mau;
}; fraction a[50]; int n, cnt = 0, cnt1 = 0, cnt2 = -1, cnt3 = 0;

bool snt(int n){
	if( n < 2) return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	} return 1;
}

int UCLN(int a, int b){
	if( b == 0) return a;
	return UCLN(b,a % b);
}

fraction sum_2_frac(fraction x, fraction y) {
	fraction tong;
	if (x.mau != y.mau){
		tong.tu = (x.tu * y.mau) + (y.tu * x.mau);
		tong.mau = x.mau * y.mau;
	}
	else{
		tong.tu = x.tu + y.tu;
		tong.mau = x.mau;
	} return tong;
}

fraction all_frac(fraction a[]) {
	fraction tong = a[0];
	for (int i = 1; i < n; i++){
		tong = sum_2_frac(tong, a[i]);
	} return tong;
}

void readFile(fraction a[]){
	ifstream infile; 
	infile.open("input.txt");
	infile>>n;
	for(int i = 0; i < n; i++){
		infile>>a[i].tu;
		char x;
		infile>>x;
		infile>>a[i].mau;
	}
	infile.close();
}

void writeFile(fraction a[]){
	ofstream outfile;
	outfile.open("output.txt");
	outfile<<n<<endl;
	for(int i = 0; i < n; i++){
		outfile<<a[i].tu<<"/"<<a[i].mau<<"  ";
	} outfile<<endl<<endl;

	//a
	for(int i = 0; i < n; i++){
		if(a[i].tu / a[i].mau < 1)
			cnt++;
	} outfile<<"a/ "<<cnt<<endl; 

	//b
	for(int i = 0; i < n; i++){
		if((int)a[i].tu % (int)a[i].mau == 0)
			cnt1++;
	} outfile<<"b/ "<<cnt1<<endl;

	//c
	for(int i = 0; i < n; i++){
		if( snt(a[i].tu) && snt(a[i].mau) )
			cnt2++;
	} outfile<<"c/ "<<cnt2<<endl;

	//d
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		if(a[i].tu / a[i].mau > max)
			max = i;
	} outfile<<"d/ "<<a[max].tu<<"/"<<a[max].mau<<endl;

	//e
	int min_, Max_ = INT_MIN;
	for(int i = 0; i < n; i++){
		if(a[i].tu / a[i].mau < 1){
			min_ = i;
			if(a[min_].tu / a[min_].mau > Max_ ){
				Max_ = min_;
			}
		}
	} outfile<<"e/ "<<a[Max_].tu<<"/"<<a[Max_].mau<<endl;

	int Maxx = 0, Min_ = INT_MAX;
	for(int i = 0; i < n; i++){
		if( a[i].tu / a[i].mau > 1){
			Maxx = i;
			if( a[Maxx].tu / a[Maxx].mau < Min_){
				Min_ = Maxx;
			}
		}	
	} outfile<<"e/ "<<a[Min_].tu<<"/"<<a[Min_].mau<<endl;

	//f
	for(int i = 0; i < n; i++){
		if(UCLN(a[i].tu,a[i].mau) >= 1)
			cnt3++;
	} outfile<<"f/ "<<cnt3<<endl;

	//g
	fraction sum = all_frac(a);
	int gcd = UCLN(sum.tu,sum.mau);
	sum.tu /= gcd; sum.mau /= gcd;
	outfile<<"g/ "<<sum.tu<<"/"<<sum.mau * n;

	outfile.close();
}

int main(){
	readFile(a);
	writeFile(a);
}