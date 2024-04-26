#include <bits/stdc++.h>
using namespace std;
const int N = 1600;
const int MOD1 = 1e9 + 207;
const int st1 = 2137;
const int st2 = 2141;
const int MOD2 = 1e9 + 9;
bitset<N> odw;
int tab[N], n;
long long power1[N], power2[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	set<pair<int, int>> zbior;
	power1[0]=1;
	power2[0]=1;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
	}
	for(int i=1;i<=1235;i++){
		power1[i]=(power1[i-1]*st1)%MOD1;
		power2[i]=(power2[i-1]*st2)%MOD2;
	}
	for(int i=1;i<=n;i++){
		long long hashowanie1=0;
		long long hashowanie2=0;
		for(int j=i;j<=n;j++){
			if(odw[tab[j]]) continue;
			odw[tab[j]] = true;
			hashowanie1 = (hashowanie1+power1[tab[j]])%MOD1;
			hashowanie2 = (hashowanie2+power2[tab[j]])%MOD2;
			zbior.insert({hashowanie1, hashowanie2});
		}
		odw.reset();
	}
	cout<<zbior.size();	
	return 0;
}
