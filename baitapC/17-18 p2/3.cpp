#include <iostream>
#include <climits>               
using namespace std;

struct fraction
{
	int tu, mau;
} fr[100][100]; int n, m;

void input(fraction &fr)
{
	cout<<"numerator: "; cin>>fr.tu;
	cout<<"denominator: "; cin>>fr.mau;
}
void show(fraction fr)
{
	cout<<fr.tu<<"/"<<fr.mau<<'\t';
}

void input_arr(fraction fr[][100], int &n, int &m){
	do{
		cout<<"nhap dong: "; cin>>n;
		cout<<"nhap cot: "; cin>>m;
	}while(n <= 0 || n > 100 );	
	for (int i = 0; i < n; i++)	{
		for(int j = 0; j < m; j++){
			cout<<"\n\tfraction "<<i+1<<endl;
			input(fr[i][j]);			
		}
	}
}

void show_arr(fraction fr[][100], int n, int m){
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++){
			show(fr[i][j]); 	
		} cout<<endl<<endl;
	}
}

void max_num(fraction fr[][100], int n, int m){
	double temp = INT_MIN;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if ( ((fr[i][j].tu) / (fr[i][j].mau)) > temp ){
				temp = (fr[i][j].tu) / (fr[i][j].mau);
			}
		}
	}
	cout<<endl<<"phan so lon nhat ";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if( temp == ((fr[i][j].tu) / (fr[i][j].mau)) ){
				cout<<fr[i][j].tu<<"/"<<fr[i][j].mau;
			}
		}
	} 
}

int UCLN(int x, int y)
{
	if (x < 0)
	{
		x *= -1;
	}
	if (y < 0)
	{
		y *= -1;
	}
    int r;
    while (x%y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
	return y;
}

int mscps(fraction fr[][100], int n, int m) {
    int msc = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            msc *= fr[i][j].mau;
        }
    }
    return msc;
}
void sum(fraction fr[][100], int n, int m) {
    int sumt = 0;
    int summ = mscps(fr, n, m);
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            sumt += (summ / (fr[i][j].mau)) * fr[i][j].tu;
        }
    }
    cout << "Tong cua cac phan so la : " << sumt/UCLN(sumt, summ) << "/" << summ/UCLN(sumt, summ);
}
int main(){
	input_arr(fr,n,m); cout<<endl;
	show_arr(fr,n,m);

	max_num(fr,n,m); cout<<endl;

	sum(fr,n,m);
	
}