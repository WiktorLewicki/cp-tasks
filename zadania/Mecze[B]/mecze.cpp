#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e4 + 5;
const int MOD1 = 1e9+207;
const int MOD2 = 1e9 + 7;
const int st1 = 47;
const int st2 = 43;
vector<int> tab[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n/2;j++){
			int a;
			cin>>a;
			tab[a].push_back(1);
		}
		for(int j=n/2+1;j<=n;j++){
			int a;
			cin>>a;
			tab[a].push_back(2);
		}
	}
	set<ll> S;
	for(int i=1;i<=n;i++){
		long long hs1=0;
		long long hs2=0;
		for(int j=tab[i].size()-1;j>=0;j--){
			hs1=(hs1*st1+tab[i][j])%MOD1;
		}
		S.insert(hs1);
	}
	int ile=0;
	for(auto v : S) ile++;
	if(ile==n) cout<<"TAK";
	else cout<<"NIE";
	return 0;
}
