#include <bits/stdc++.h>
using namespace std;

string s[5]; int cnt = 0, n, total = 0;
void readFile(string right_word[]){
	ifstream infile; 
	infile.open("str.inp");
	infile>>n;
	for(int i = 0; i <= n; i++) {
		getline(infile,s[i]);
	
        string words[256];
		istringstream iss(s[i]);
		string word;
		while( iss >> word )
			words[cnt++] = word;

        right_word[i] = words[cnt-1];
        total += cnt;
	}
	infile.close();
}

void writeFile(string right_word[]){
	ofstream outfile;
	outfile.open("str.out");
	outfile<<n;

	for(int i = 0; i <= n; i++)
		outfile<<s[i]<<endl;

	//a
	outfile<<endl<<"a/ ";
	for(int i = 0; i <= n; i++)
		outfile<<right_word[i]<<endl;
	//b
    outfile<<endl<<"b/ "<<cnt;
	outfile.close();
}

int main(){
    string right_word[100];
    readFile(right_word);
	writeFile(right_word);
}