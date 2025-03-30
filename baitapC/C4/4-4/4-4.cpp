#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10], cnt = 0;
bool SNT(int A){
	if( A < 2) return 0;
	for(int i = 2; i <= sqrt(A); i++){
		if(A % i == 0)
			return 0;
	} return 1;
}

void readFile(){
	ifstream infile; 
	infile.open("NUM.INP");
	infile>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			infile>>a[i][j];
		}
	}
	infile.close();
}

void writeFile(){
	ofstream outfile;
	outfile.open("NUM.OUT");
	outfile<<n<<" "<<m<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			outfile<<a[i][j]<<" ";
		} outfile<<endl;
	} outfile<<endl;

	//a
	int Max = INT_MIN;
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			if( a[i][j] > Max ){
				Max = a[i][j];
				cnt = 1;
			}
			else if(Max == a[i][j])
				cnt++;
		} 
	} outfile<<"a/ "<<"so lon nhat "<<Max<<" "<<"co "<<cnt<<endl;

	//b
	outfile<<"b/ tong so tung cot ";
	for(int i = 0 ; i < m; i++){
		int s = 0;
		for(int j = 0; j < n; j++){
			s += a[j][i];
		} outfile<<s<<" ";
	} outfile<<endl;

	//c 
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if( SNT(a[i][j]) && SNT(a[i][j+1]) && SNT(a[i+1][j]) && SNT(a[i+1][j+1]) ){
				int s = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
				if( s > max ){
					max = s;
				}
				else if ( s < 0 ) outfile<<"NULL";
			}
		}
	} outfile<<"c/ so lon nhat cua tong cot "<<max;

	outfile.close();
}

int main(){
	readFile();
	writeFile();
}