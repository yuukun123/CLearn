#include <bits/stdc++.h>
using namespace std;

int solution(int n, int ex){
    if(ex == 0) return 1;
    else{
        return n * solution(n,ex-1);
    }
}

main(){
    int n, exponent; cin>>n>>exponent;
    cout<<solution(n,exponent);
}