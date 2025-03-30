#include <bits/stdc++.h>
using namespace std;

int n, a[10], cnt = 0;
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
	infile>>n;
	for(int i = 0; i < n; i++){
		infile>>a[i];
	}
	infile.close();
}

void writeFile(){
	ofstream outfile;
	outfile.open("NUM.OUT");
	outfile<<n<<endl;
	for(int i = 0; i < n; i++){
		if( SNT(a[i]) )
			cnt++;
	} outfile<<"co "<<cnt<<" snt"<<endl;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if( a[i] > a[j])
				swap(a[i],a[j]);
		}
	}

	outfile<<"sau khi sap xep "; 
	for(int i = 0; i < n; i++){
		outfile<<a[i]<<" ";
	}
	outfile.close();
}

int main(){
	readFile();
	writeFile();
}