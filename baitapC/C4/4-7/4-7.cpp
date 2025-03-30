#include <bits/stdc++.h>
using namespace std;

char s; int cnt[30] = {0};
void readFile(){
	ifstream infile; 
	infile.open("input.txt");
	while ( infile.get(s) ){
		if( isalpha(s) ){
			s = tolower(s);
			cnt[s-'a']++;
		}
	}
	infile.close();
}

void writeFile(){
	ofstream outfile;
	outfile.open("output.txt");
	for(int i = 0; i < 30; i++){
		if(cnt[i] > 0)
			outfile<<char('a'+i)<<" "<<cnt[i]<<" ";
	}
	outfile.close();
}

int main(){
	readFile();
	writeFile();
}