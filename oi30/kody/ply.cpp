//autor: Wiktor Lewicki
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, cnt=0, ans=0;
	string S;
	cin>>n>>k>>S;
	for(int i=0;i<n;i++){
		if(S[i]=='(') cnt++;
		else cnt--;
		if(cnt>k){
			ans++;
			cnt-=2;
		}
		if(cnt==-1){
			ans++;
			cnt+=2;
		}
	}
	cout<<ans;
	return 0;
}
