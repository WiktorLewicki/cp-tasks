#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int N = 5e5 + 5;
pii d[4*N];
int tab[N], kub[N], t1[N], t2[N], sum[N], kandydat[N], rozm=1, n, m;
vector<int> pocz[N], kon[N];
pii op(pii a, pii b){
	if(a.first==b.first){
		return {a.first, a.second+b.second};
	}
	else{
		if(a.second==b.second){
			return {0, 0};
		}
		else if(a.second>b.second){
			return {a.first, a.second-b.second};
		}
		else{
			return {b.first, b.second-a.second};
		}
	}
}
void build(int x, int l, int r){
	if(l==r){
		if(l<=n){
			d[x]={tab[l], 1};
		}
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x]=op(d[x*2], d[x*2+1]);
}
pii query(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		return d[x];
	}
	pii res={0, 0};
	int sr=(l+r)/2;
	if(a<=sr){
		res=op(res, query(x*2, l, sr, a, b));
	}
	if(sr<b){
		res=op(res, query(x*2+1, sr+1, r, a, b));
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n;i++){
		cin>>tab[i];
	}
	build(1, 1, rozm);
	for(int i=1;i<=m;i++){
		cin>>t1[i]>>t2[i];
		pocz[t1[i]].pb(i);
		kon[t2[i]].pb(i);
		kandydat[i]=query(1, 1, rozm, t1[i], t2[i]).first;
	}
	for(int i=1;i<=n;i++){
		for(auto v : pocz[i]){
			sum[v]=kub[kandydat[v]];
		}
		kub[tab[i]]++;
		for(auto v : kon[i]){
			sum[v]=kub[kandydat[v]]-sum[v];
		}
	}
	for(int i=1;i<=m;i++){
		if(sum[i]>(t2[i]-t1[i]+1)/2){
			cout<<kandydat[i]<<"\n";
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}
