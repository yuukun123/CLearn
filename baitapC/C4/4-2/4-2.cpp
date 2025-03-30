#include <bits/stdc++.h>
using namespace std;

int n, m, a[10], b[10]; 
void readFile(){
	ifstream infile; 
	infile.open("NUM.INP");
	infile>>n>>m;
	for(int i = 0; i < n; i++){
		infile>>a[i];
	}
	infile.close();
}

void writeFile(){
	ofstream outfile;
	outfile.open("NUM.OUT");
	outfile<<n<<" "<<m<<endl;
	for(int i = 0; i < n; i++){
		outfile<<a[i]<<" ";
	} 

	//a
	int Max = INT_MIN;
	for(int i = 0; i < n; i++){
		if( a[i] > Max )
			Max = a[i];
	} outfile<<endl<<"a/ "<<Max<<endl;

	//b
	int len = 1;
	for(int i = 0; i < n; i++){
		b[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] && b[j] + 1 > b[i])
				b[i] = b[j]++;
		}
		if(b[i] > len)
			len = b[i];
	} outfile<<"b/ "<<len<<endl;

	//c
	int cnt[10] = {0}, result = 0;
	for(int i = 0; i < n; i++){
		if(m - a[i] >= 0 && m - a[i] < 10)
			result += cnt[m-a[i]];
		cnt[a[i]]++;
	} outfile<<"c/ "<<result<<endl;

	//d
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]) swap(a[i],a[j]);
		}
	}
	int temp = 0;
	if(n % 2 != 0){
		temp = a[n/2];
		outfile<<"d/ "<<temp;
	}
	outfile.close();
}

int main(){
	readFile();
	writeFile();
}