#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10], b[10][10], c[10][10];
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
	outfile<<"a/ "<<endl;
	int Min[10], s_i = 0;
	for(int i = 0 ; i < n; i++){
		Min[i] = a[i][0];
		for(int j = 1; j < m; j++){
			if( a[i][j] < Min[i] ){
				Min[i] = a[i][j];
			}
		}
		for(int j = 0; j < m; j++){
			b[i][j] = a[i][j] * Min[i];
			outfile<<b[i][j]<<" ";
			s_i += b[i][j];
		} outfile<<endl;
	}outfile<<endl<<s_i<<endl<<endl;

	//b
	int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = a[i][j];
            if (SNT(x)) {
                sum += x;
            }
            else{
                int left = x;
                int right = x;
                while( !SNT(left) ) left--;
                while( !SNT(right) ) right++;
                if( abs(x - left) <= abs(right - x) )
                    sum += left;
                else
                    sum += right;
            }
        }
    } outfile<<"b/ "<<sum<<endl<<endl;

	//c
	outfile<<"c/ "<<endl;
	bool found = false; 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			bool isMax = true, isMin = true; 
			for (int k = 0; k < m; k++) { 
				if (a[i][k] > a[i][j]) { 
					isMax = false; break; 
				} 
			} 
			for (int k = 0; k < n; k++) { 
				if (a[k][j] < a[i][j]) { 
					isMin = false; break; 
				} 
			} 
			if (isMax && isMin) { 
				outfile << "Phan tu 'yen ngua': " << a[i][j] << " tai vi tri (" << i << ", " << j << ")" << endl; 
				found = true; 
				break; 
			} 
		} if (found) break; 
	} 
	if (!found) 
		outfile<< "Khong tim thay phan tu 'yen ngua'" << endl; 

	outfile.close();
}

int main(){
	readFile();
	writeFile();
}