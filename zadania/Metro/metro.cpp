#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e6 + 5;
vector<int> kraw[N], pom1, pom2;
bitset<N> odw;
int dp[N], odp[N], wyn[N];
void dfs(int x){
	odw[x] = true;
	for(auto v : kraw[x]){
		if(!odw[v]){
			dp[x]++;
			dp[v]++;
			dfs(v);
		}
	}
	if(dp[x]==1){
		pom1.pb(x);
		dp[x]--;
	}
}
void tura(vector<int> spr, bool ok, int war){
	for(auto v : spr){
		for(auto vx : kraw[v]){
			if(odw[vx]) continue;
			dp[vx]--;
			if(dp[vx]==1){
				dp[vx]--;
				odp[vx]=war;
				wyn[war]++;
				if(ok) pom2.pb(vx);
				else pom1.pb(vx);
			}
		}
		
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	dfs(1);
	wyn[0]=pom1.size();
	odw.reset();
	bool OK = true;
	for(int i=1;i<=n;i++){
		for(auto v : pom1){
			odw[v]=true;
		}
		for(auto v : pom2){
			odw[v]=true;
		}
		if(OK){
			tura(pom1, 1, i);
			pom1.clear();
		}
		else{
			tura(pom2, 0, i);
			pom2.clear();
		}
		OK=!OK;
	}
	int pom, lic=0;
	for(int i=0;i<=n;i++){
		if(wyn[i]<=k){
			pom=i;
			cout<<i<<" "<<max(2, wyn[i])<<"\n";
			break;
		}
	}
	int last=0;
	for(int i=1;i<=n;i++){
		if(lic==wyn[pom]) break;
		if(odp[i]==pom){
			last=i;
			lic++;
			cout<<i<<" ";
		}
	}
	if(wyn[pom]==1){
		if(last==1) cout<<2;
		else cout<<1;
	}
	return 0;
}
