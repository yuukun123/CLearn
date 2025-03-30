#include <bits/stdc++.h>
using namespace std;
string s[5]; int n;

void readFile(string words[][100], int Cnt[]){
	ifstream infile; 
	infile.open("str-in.txt");
	infile>>n;
	for(int i = 0; i <= n; i++) {
		getline(infile,s[i]);
		istringstream iss(s[i]);
		string word;
		while( iss >> word )
			words[i][Cnt[i]++] = word;
	}
	infile.close();
}

void writeFile(string words[][100], int Cnt[]){
	ofstream outfile;
	outfile.open("str-out.txt");
	outfile<<n;
	for(int i = 0; i <= n; i++){
		outfile<<s[i]<<endl;
	}

	//A
	outfile<<endl<<"a/ ";
	for(int i = 0; i <= n; i++){
		int maxLen = 0;
		int maxIdex = 0;
		for(int j = 0; j < Cnt[i]; j++){
			if(words[i][j].length() > maxLen){
				maxLen = words[i][j].length();
				maxIdex = j;
			}
		} outfile<<words[i][maxIdex]<<endl;
	}

	//B
	outfile<<endl<<"b/ ";
	for(int i = 0; i <= n; i++){
		outfile<<words[i][0]<<" "<<words[i][Cnt[i]-1]<<endl;
	}

	//C	
	int maxLine = 0;
	int maxLineIndex = 0;
	for(int i = 0; i < n; i++){
		if(s[i].length() > maxLine){
			maxLine = s[i].length();
			maxLineIndex = i;
		}
	} outfile<<endl<<"c/ "<<endl<<s[maxLineIndex]<<endl;

	//D
	int total = 0;
	for(int i = 0; i <= n; i++){
		total += Cnt[i];
	} outfile<<endl<<"d/ "<<total<<endl;
	
	//E
	int cnt = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < Cnt[i]; j++){
			if(words[i][j] == "your"){
				cnt++;
			}
		}
	} outfile<<endl<<"e/ "<<cnt;
	outfile.close();
}

int main(){
    string words[100][100];
    int Cnt[100] = {0};
    readFile(words,Cnt);
	writeFile(words,Cnt);
}