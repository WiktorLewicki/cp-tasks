#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt=0, n;
	cin>>n;
	string S;
	cin>>S;
	for(int i=0;i<S.size();i++){
		if(S[i]=='1') cnt++;
	}
	cnt-=n*2;
	if(cnt<n||cnt>4*n){
		cout<<"NIE";
		return 0;
	}
	cnt-=n;
	for(int i=1;i<=n;i++){
		if(cnt-3>=0){
			cout<<'o';
			cnt-=3;
		}
		else if(cnt-2>=0){
			cout<<'z';
			cnt-=2;
		}
		else if(cnt-1>=0){
			cout<<'c';
			cnt-=1;
		}
		else if(cnt-0>=0){
			cout<<'a';
			cnt-=0;
		}
	}
	return 0;
}
