//Autor: Wiktor Lewicki
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll suma[N], repair[N], ile[N], sz[N];
vector<pair<int, ll>> kraw[N];
vector<pair<ll, ll>> path[N];
bitset<N> odw;
void dfs1(int x, int ojc);
void dfs2(int x, int ojc, ll var, int owner);
int szukaj(int x, int ojc, int tr);
void centroid(int x);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int a, b, c;
		cin>>a>>b>>c;
		kraw[a].pb({b, c});
		kraw[b].pb({a, c});
	}
	centroid(1);
	ile[1]=1;
	for(int i=0;i<(int)path[1].size()-1;i++){
		suma[path[1][i].first]+=path[1][i].second;
		repair[path[1][i+1].first]+=path[1][i].second;
		ile[path[1][i].first]++;
	}
	ll ans=0;
	while(k--){
		int test;
		cin>>test;
		ll pom=suma[test];
		for(int i=0;i<(int)path[test].size()-1;i++){
			pom+=(suma[path[test][i].first])-repair[path[test][i+1].first];
			pom+=(ile[path[test][i].first]-ile[path[test][i+1].first])*path[test][i].second;
			suma[path[test][i].first]+=path[test][i].second;
			repair[path[test][i+1].first]+=path[test][i].second;
			ile[path[test][i].first]++;
		}
		ile[test]++;
		pom*=2;
		ans+=pom;
		cout<<ans<<"\n";
	}
	return 0;
}
void dfs1(int x, int ojc){
	sz[x]=1;
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]){
			dfs1(v.first, x);
			sz[x]+=sz[v.first];
		}
	}
}
void dfs2(int x, int ojc, ll var, int owner){
	path[x].pb({owner, var});
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]){
			dfs2(v.first, x, var+v.second, owner);
		}
	}
}
int szukaj(int x, int ojc, int tr){
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]&&sz[v.first]*2>tr){
			return szukaj(v.first, x, tr);
		}
	}
	return x;
}
void centroid(int x){
	dfs1(x, 0);
	int pom = szukaj(x, 0, sz[x]);
	dfs2(pom, 0, 0, pom);
	odw[pom]=true;
	for(auto v : kraw[pom]){
		if(!odw[v.first]){
			centroid(v.first);
		}
	}
}
