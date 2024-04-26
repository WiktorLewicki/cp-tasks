#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
vector<int> kraw[N], drzewo[N], wsteczne[N], odp;
bitset<N> odw;
int low[N], gleb[N], poddrzewo[N], ojc[N], pref[N];
void dfs(int x){
	odw[x] = true;
	for(auto v : kraw[x]){
		if(!odw[v]){
			ojc[v]=x;
			drzewo[x].pb(v);
			drzewo[v].pb(x);
			dfs(v);
		}
		else if(v!=ojc[x]){
			wsteczne[x].pb(v);
			wsteczne[v].pb(x);
		}
	}
}
long long check(int x){
	long long rt=0;
	for(auto v : drzewo[x]){
		if(v==ojc[x]) continue;
		//cout<<v<<" "<<poddrzewo[v]<<"\n";
		if(low[v]>=gleb[x]){
			odp.pb(poddrzewo[v]);
			rt+=poddrzewo[v];
		}
	}
	return rt;
}
void dwuspojne(int x){
	odw[x] = true;
	poddrzewo[x]=1;
	low[x]=gleb[x];
	for(auto v : drzewo[x]){
		if(!odw[v]){
			gleb[v]=gleb[x]+1;
			dwuspojne(v);
			low[x]=min(low[x], low[v]);
			poddrzewo[x]+=poddrzewo[v];
		}
	}
	for(auto v : wsteczne[x]){
		low[x] = min(low[x], gleb[v]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	dfs(1);
	odw.reset();
	dwuspojne(1);
	for(int i=1;i<=n;i++){
		if(i==1&&drzewo[1].size()<2){
			cout<<2*(n-1)<<"\n";
			continue;
		}
		odp.clear();
		if(i>1)odp.pb(poddrzewo[1]-check(i)-1);
		else check(i);
			if(odp.size()==1){
			cout<<2*(n-1)<<"\n";
			continue;
		}
		long long pom=0, ans=0;
		for(auto v : odp) pom+=v;
		for(int i=0;i<odp.size();i++){
			ans+=(pom-odp[i])*odp[i];
		}
		cout<<ans+2*(n-1)<<"\n";
	}
	return 0;
}
