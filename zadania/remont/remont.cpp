#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 2e5 + 5;
vector<int> kraw[N];
int pre_order[N], ile[N], anc[N][21], gleb[N], ojc[N], nr=1, n;
ll d[4*N], push[4*N];
bitset<N> odw;
void dfs(int x, int i){
	ile[x]=1;
	gleb[x]=i;
	pre_order[x]=nr;
	odw[x] = true;
	for(auto v : kraw[x]){
		if(!odw[v]){
			ojc[v]=x;
			nr++;
			dfs(v, i+1);
			ile[x]+=ile[v];
		}
	}
}
void make_anc(){
	for(int i=1;i<=n;i++) anc[i][0]=ojc[i];
	for(int k=1;k<=20;k++){
		for(int i=1;i<=n;i++){
			anc[i][k]=anc[anc[i][k-1]][k-1];
		}
	}
}
int lca(int a, int b){
	if(gleb[a]<gleb[b]){
		swap(a, b);
	}
	for(int k=20;k>=0;k--){
		if(gleb[anc[a][k]]>=gleb[b]){
			a=anc[a][k];
		}
	}
	if(a==b){
		return a;
	}
	for(int k=20;k>=0;k--){
		if(anc[a][k]!=anc[b][k]){
			a=anc[a][k];
			b=anc[b][k];
		}
	}
	return ojc[a];
}
void add(int x, ll val){
	push[x]+=val;
	d[x]+=val;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
void update(int l, int r, int a, int b, int x, ll val){
	if(a<=l&&r<=b){
		add(x, val);
		return;
	}
	pushuj(x);
	int sr = (l+r)/2;
	if(a<=sr){
		update(l, sr, a, b, x*2, val);
	}
	if(sr<b){
		update(sr+1, r, a, b, x*2+1, val);
	}
	d[x] = d[x*2]+d[x*2+1];
}
ll query(int l, int r, int a, int b, int x){
	if(a<=l&&r<=b){
		return d[x];
	}
	pushuj(x);
	ll res=0;
	int sr = (l+r)/2;
	if(a<=sr){
		res+=query(l, sr, a, b, x*2);
	}
	if(sr<b){
		res+=query(sr+1, r, a, b, x*2+1);
	}
	d[x] = d[x*2]+d[x*2+1];
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int rozm=1;
	cin>>n;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n-1;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	dfs(1, 0);
	make_anc();
	int m;
	cin>>m;
	while(m--){
		char znak;
		cin>>znak;
		if(znak=='-'){
			int a;
			cin>>a;
			update(1, rozm, pre_order[a], pre_order[a]+ile[a]-1, 1, 1);
		}
		else if(znak=='+'){
			int a;
			cin>>a;
			update(1, rozm, pre_order[a], pre_order[a]+ile[a]-1, 1, -1);
		}
		else{
			int a, b;
			cin>>a>>b;
			int pom = lca(a, b);
			ll pom1=query(1, rozm, pre_order[a], pre_order[a], 1);
			ll pom2=query(1, rozm, pre_order[b], pre_order[b], 1);
			ll pom3=0;
			if(pom>1) pom3=query(1, rozm, pre_order[ojc[pom]], pre_order[ojc[pom]], 1);
			if(pom1+pom2-2*pom3==0) cout<<"TAK\n";
			else cout<<"NIE\n";
		}
	}
	return 0;
}
