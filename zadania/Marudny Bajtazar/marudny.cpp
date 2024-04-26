#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int kub[N*2][19], power[19], suf[N][19], cnt[19], lic;
bitset<N> tab;
void solve(){
	for(int i=1;i<=lic+1;i++){
		if(power[i]!=cnt[i]){
			cout<<i<<"\n";
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string S;
	cin>>n>>m>>S;
	for(int i=1;i<=n;i++){
		if(S[i-1]=='1') tab[i] = true;
	}
	S=".";
	int rozm=1;
	while(rozm<n){
		lic++;
		rozm*=2;
	}
	power[1]=2;
	for(int i=2;i<=20;i++){
		power[i]=power[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=lic;j++){
			if(i+j-1>n) break;
			suf[i][j]=(suf[i][j-1]<<1)+tab[i+j-1];
			kub[suf[i][j]][j]++;
			if(kub[suf[i][j]][j]==1) cnt[j]++;
		}
	}
	solve();
	while(m--){
		int a;
		cin>>a;
		tab[a]=!tab[a];
		for(int i=max(1, a-lic+1);i<=min(n, a+lic-1);i++){
			for(int j=1;j<=lic;j++){
				if(i+j-1>min(n, a+lic-1)) break;
				kub[suf[i][j]][j]--;
				if(!kub[suf[i][j]][j]) cnt[j]--;
				suf[i][j]=(suf[i][j-1]<<1)+tab[i+j-1];
				kub[suf[i][j]][j]++;
				if(kub[suf[i][j]][j]==1) cnt[j]++;
			}
		}
		solve();
	}
	return 0;
}
