#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10];

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
	int Min[10], Max = INT_MIN;
	for(int i = 0 ; i < n; i++){
		Min[i] = a[i][0];
		for(int j = 1; j < m; j++){
			if( a[i][j] < Min[i] )
				Min[i] = a[i][j];
		} 
		if( Min[i] > Max )
			Max = Min[i];
	}outfile<<"a/ "<<Max<<endl;

	//b 
	//tim khoang cach giua 2 so nho nhat va vi tri
	int min = INT_MAX;
	int min_i, min_j, min_k, min_l;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = i + 1; k < n; k++){
				for(int l = j + 1; l < m; l++){
					int dis = abs(a[i][j] - a[k][l]);
					if( dis < min ){
						min = dis;
						min_i = i;
						min_j = j;
						min_k = k;
						min_l = l; 
					}
				}
			}
		}
	} outfile<<"b/ "<<min<<" "<<"( "<<min_i + 1<<" "<<min_j + 2 <<" )"<<" "<<"( "<<min_k + 1<<" "<<min_l + 2<<" ) ";

	outfile.close();
}

int main(){
	readFile();
	writeFile();
}