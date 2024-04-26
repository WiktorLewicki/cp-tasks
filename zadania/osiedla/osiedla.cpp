#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
int res;
vector<pair<int, int>>kraw[N];
vector<int> graf[N][2];
stack<int> topo;
bool ok;
pair<int, int> tab[N];
bitset<N> odw, ans, mem;
void dfs(int x){
	odw[x] = true;
	for(auto v : kraw[x]){
		if(!odw[v.first]){
			if(x==tab[v.second].second){
				ans[v.second]=1;
			}
			mem[v.second] = true;
			dfs(v.first);
		}
		if(!mem[v.second]){
			if(x==tab[v.second].second){
				ans[v.second]=1;
			}
			mem[v.second]=true;
		}
	}
}
void odp(int x, int info){
	odw[x] = true;
	for(auto v : graf[x][info]){
		if(!odw[v]){
			odp(v, info);
		}
	}
	if(!info){
		topo.push(x);
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
		tab[i] = {a, b};
		kraw[a].pb({b, i});
		kraw[b].pb({a, i});
	}
	for(int i=1;i<=n;i++){
		if(!odw[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]){
			graf[tab[i].second][0].pb(tab[i].first);
			graf[tab[i].first][1].pb(tab[i].second);
		}
		else{
			graf[tab[i].first][0].pb(tab[i].second);
			graf[tab[i].second][1].pb(tab[i].first);
		}
	}
	odw.reset();
	for(int i=1;i<=n;i++){
		if(!odw[i]) odp(i, 0);
	}
	odw.reset();
	for(int i=1;i<=n;i++){
		if(!odw[topo.top()]){
			odp(topo.top(), 1);
			res++;
		}
		topo.pop();
	}
	cout<<res<<"\n";
	for(int i=1;i<=m;i++){
		if(ans[i])cout<<"<";
		else cout<<">";
	}	
	return 0;
}
