#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD = 1000002022;
vector<int> kraw[N];
bitset<N> odw, val;
ll dp[N][2];
void dfs(int x){
	odw[x] = true;
	vector<int> pom;
	ll x1, y1, x2, y2;
	for(auto v : kraw[x]){
		if(!odw[v]){
			dfs(v);
			pom.pb(v);
		}
	}
	if(kraw[x].empty()){
		if(val[x]){
			dp[x][1]=1;
		}
		else{
			dp[x][0]=1;
		}
		return;
	}
	x1=dp[pom[0]][0];
	y1=dp[pom[0]][1];
	x2=dp[pom[1]][0];
	y2=dp[pom[1]][1];
	ll wynik = (y1*x2)%MOD + (y2*x1)%MOD + (2*y1*y2)%MOD;
	wynik%=MOD;
	dp[x][1] = wynik;
	wynik = (2*x1*x2)%MOD + (x1*y2)%MOD + (x2*y1)%MOD;
	wynik%=MOD;
	dp[x][0]=wynik;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin>>n>>m>>q;
	for(int i=0;i<=n+m-1;i++){
		int a;
		cin>>a;
		if(a==-1) continue;
		kraw[a].pb(i);		
	}
	for(int i=n;i<=n+m-1;i++){
		int a;
		cin>>a;
		val[i]=a;
	}
	dfs(0);
	for(int i=0;i<=n+m-1;i++) cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	return 0;
/*
4 5 0
-1 0 0 1 1 3 3 2 2
0 1 1 1 0
*/
}
