#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long pref[4*N], ans, push[4*N], d[4*N];
int tab[N], kub[N], n, last_num[N], right_ind[N], wartosc[N];
void add(int x, long long ile){
	d[x]+=ile;
	push[x]+=ile;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
void build(int x, int l, int r){
	if(l==r){
		d[x] = pref[l];
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x] = max(d[x*2], d[x*2+1]);
}
void update(int a, int b, int l, int r, int x, int ile){
	if(a<=l&&r<=b){
		add(x, ile);
		return;
	}
	pushuj(x);
	long long sr = (l+r)/2;
	if(a<=sr){
		update(a, b, l, sr, x*2, ile);
	}
	if(sr<b){
		update(a, b, sr+1, r, x*2+1, ile);
	}
	d[x] = max(d[x*2], d[x*2+1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long m, rozm=1;
	cin>>n>>m;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n;i++) cin>>tab[i];
	for(int i=1;i<=m;i++) cin>>wartosc[i];
	for(int i=n;i>=1;i--){
		right_ind[i]=last_num[tab[i]];
		if(!right_ind[i]) right_ind[i]=n+1;
		last_num[tab[i]]=i;
	}
	for(int i=1;i<=n;i++){
		pref[i]=pref[i-1];
		kub[tab[i]]++;
		if(kub[tab[i]]==1){
			pref[i]+=wartosc[tab[i]];
		}
		if(kub[tab[i]]==2){
			pref[i]-=wartosc[tab[i]];
		}
	}
	build(1, 1, rozm);
	for(int i=1;i<=n;i++){
		ans = max(ans, d[1]);
		int pom1 = right_ind[i];
		int pom2 = right_ind[pom1];
		if(i==n) break;
		update(1, pom1-1, 1, rozm, 1, -wartosc[tab[i]]);
		if(pom1!=n+1) update(pom1, pom2-1, 1, rozm, 1, wartosc[tab[i]]);
	}
	cout<<ans;
	return 0;
}
