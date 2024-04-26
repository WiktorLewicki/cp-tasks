#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
int tp[N], odp1[N], odp2[N], dp[N], kub[N], push[N], lic, ans;
vector<int> kraw[N][2], graf[N][2], spr[N], odp;
stack<int> topo;
bitset<N> odw;
void pre(int x, int info){
	odw[x] = true;
	for(auto v : kraw[x][info]){
		if(!odw[v]){
			pre(v, info);
		}
	}
	if(!info) topo.push(x);
	else tp[x]=lic;
}
void dfs(int x){
	odw[x] = true;
	for(auto v : graf[x][0]){
		if(!odw[v]){
			dfs(v);
		}
	}
	odp.pb(x);
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
		if(!odw[i]){
			pre(i, 0);
		}
	}	
	odw.reset();
	while(!topo.empty()){
		int a = topo.top();
		topo.pop();
		if(!odw[a]){
			lic++;
			pre(a, 1);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto v : kraw[i][0]){
			if(tp[i]!=tp[v]){
				graf[tp[i]][0].pb(tp[v]);
				graf[tp[v]][1].pb(tp[i]);
			}
		}
	}
	odw.reset();
	for(int i=1;i<=lic;i++){
		if(!odw[i]){
			dfs(i);
		}
	}
	reverse(odp.begin(), odp.end());
	for(int i=0;i<(int)odp.size();i++){
		kub[odp[i]]=i+1;
	}
	for(int i=1;i<=lic;i++){
		int mi=lic+2, ma=0;
		for(auto v : graf[i][1]){
			ma = max(ma, kub[v]);
		}
		push[ma+1]+=1;
		push[i]-=1;
		for(auto v : graf[i][0]){
			mi=min(mi, kub[v]);
		}
		push[i+1]+=1;
		push[mi]-=1;
	}
	for(int i=1;i<=lic;i++){
		push[i]+=push[i-1];
		if(!push[i]) ans++;
	}
	vector<int> read;
	for(int i=1;i<=n;i++){
		if(!push[tp[i]]){
			read.pb(i);
		}
	}
	cout<<read.size()<<"\n";
	for(auto v : read){
		cout<<v<<" ";
	}
	return 0;
}
