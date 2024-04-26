#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e4 + 5;
int tp[N], cnt[N], dp[N];
stack<int> topo;
bitset<N> odw;
vector<int> kraw[N][2], graf[N];
void dfs(int x, int info, int idx){
	odw[x] = true;
	for(auto v : kraw[x][info]){
		if(!odw[v]){
			dfs(v, info, idx);
		}
	}
	if(!info){
		topo.push(x);
	}
	else{
		tp[x]=idx;
		cnt[idx]++;
	}
}
void odp(int x){
	odw[x] = true;
	for(auto v : graf[x]){
		if(!odw[v]){
			odp(v);
		}
		dp[x]+=dp[v];
	}
	dp[x]+=cnt[x];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a, b;
		cin>>a>>b;
		kraw[a][0].pb(b);
		kraw[b][1].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(!odw[i])dfs(i, 0, 0);
	}
	int k=1;
	for(int i=1;i<=n;i++){
		int zm = topo.top();
		topo.pop();
		if(!odw[zm]){
			dfs(zm, 1, k);
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(auto v : kraw[i][0]){
			if(tp[i]!=tp[v]){
				graf[tp[i]].push_back(tp[v]);
			}
		}
	}
	odw.reset();
	for(int i=1;i<=n;i++){
		if(!odw[i]) odp(i);
	}
	for(int i=1;i<=n;i++){
		cout<<dp[tp[i]]-1<<"\n";
	}
	return 0;
}
