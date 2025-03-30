#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10];
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
	int dem = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(SNT(a[i][j])) dem++;
		}
	}
	outfile<<"a/ "<<dem<<endl;

	//b
	int Max = INT_MIN, Min = INT_MAX;
	for(int i = 0 ; i < n; i++){
		int s = 0;
		for(int j = 0; j < m; j++){
			s += a[i][j];
			if( s > Max ) Max = s;
		} 
	} outfile<<"b/ "<<Max<<endl;

	//c
	for(int i = 0 ; i < m; i++){
		int s = 0;
		for(int j = 0; j < n; j++){
			s += a[j][i];
		} if( s < Min ) Min = s;
	} outfile<<"c/ "<<Min<<endl;

	outfile.close();
}

int main(){
	readFile();
	writeFile();
}