#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
vector<int> kraw[N][2], krw[N][2];
int tp[N], anc[N][21], ojc[N], gleb[N], n, m, t=1;
bitset<N> odw, who;
void pre_dfs(int x){
	tp[x]=1;
	for(auto v : krw[x][0]){
		pre_dfs(v);
	}
}
void build(int ojc, vector<int>a){
	vector<int> pom;
	bool ok = false;
	for(auto z : a){
		if(kraw[z][0].size()){
			for(auto v : kraw[z][0]){
				if(!ok){
					ok=true;
					t++;
				}
				pom.pb(v);
				tp[v]=t;
			}
			krw[ojc][0].pb(t);
		}
	}
	ok=false;
	if(pom.size()) build(t, pom);
	pom.clear();
	for(auto z : a){
		if(kraw[z][1].size()){
			if(!ok){
				ok=true;
				t++;
			}
			for(auto v : kraw[z][1]){
				pom.pb(v);
				tp[v]=t;
			}
			krw[ojc][1].pb(t);
			who[t]=true;
		}
	}
	if(pom.size()) build(t, pom);
}
void dfs(int x){
	odw[x]=true;
	for(auto v : krw[x][0]){
		if(odw[v]) continue;
		ojc[v]=x;
		gleb[v]=gleb[x]+1;
		dfs(v);
	}
	for(auto v : krw[x][1]){
		if(odw[v]) continue;
		ojc[v]=x;
		gleb[v]=gleb[x]+1;
		dfs(v);
	}
}
void make_anc(){
	for(int i=1;i<=t;i++){
		anc[i][0]=ojc[i];
	}
	for(int k=1;k<=20;k++){
		for(int i=1;i<=t;i++){
			anc[i][k]=anc[anc[i][k-1]][k-1];
		}
	}
}
pair<int, int> lca(int a, int b){
	for(int k=20;k>=0;k--){
		if(anc[a][k]!=anc[b][k]){
			a=anc[a][k];
			b=anc[b][k];
		}
	}
	return {a, b};
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		tp[i]=i;
		int a, b;
		cin>>a>>b;
		if(a) krw[i][0].pb(a);
		if(b) krw[i][1].pb(b);
	}
	pre_dfs(1);
	for(int i=1;i<=n;i++){
		for(auto v : krw[i][0]){
			if(tp[i]!=tp[v]){
				kraw[tp[i]][0].pb(tp[v]);
			}
		}
		for(auto v : krw[i][1]){
			if(tp[i]!=tp[v]){
				kraw[tp[i]][1].pb(tp[v]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		krw[i][0].clear();
		krw[i][1].clear();
	}
	vector<int> st;
	st.pb(1);
	build(1, st);
	ojc[1]=1;
	dfs(1);
	make_anc();
	cin>>m;
	while(m--){
		int a, b;
		cin>>a>>b;
		a=tp[a];
		b=tp[b];
		if(gleb[a]!=gleb[b]){
			if(gleb[a]>gleb[b]) cout<<"TAK\n";
			else cout<<"NIE\n";
		}
		else{
			pair<int, int> pom = lca(a, b);
			a=pom.first;
			b=pom.second;
			if(who[a]||who[a]==who[b]) cout<<"TAK\n";
			else cout<<"NIE\n";
		}
	}
	return 0;
}
