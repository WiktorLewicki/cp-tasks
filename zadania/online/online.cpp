#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct node{
	int pref=0, suf=0, ans=0;
};
int tab[N], n;
node d[(1<<20)+20];
void update(int x, int l, int r, int idx){
	if(l==r){
		return;
	}
	int sr=(l+r)/2;
	if(idx<=sr){
		update(x*2, l, sr, idx);
	}
	else{
		update(x*2+1, sr+1, r, idx);
	}
	d[x].ans=max(d[x*2].ans, d[x*2+1].ans);
	d[x].pref=d[x*2].pref;
	d[x].suf=d[x*2+1].suf;
	if(sr<=n&&tab[sr]<tab[sr+1]){
		d[x].ans=max(d[x*2].ans, d[x*2+1].ans);
		d[x].ans=max(d[x].ans, d[x*2].suf+d[x*2+1].pref);
		if(d[x*2].pref==sr+1-l) d[x].pref=d[x*2].pref+d[x*2+1].pref;
		if(d[x*2+1].suf==r-sr) d[x].suf=d[x*2+1].suf+d[x*2].suf;
	}
}
void build(int x, int l, int r){
	if(l==r){
		if(l<=n) d[x]={1, 1, 1};
		return;
	}
	int sr=(l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x].ans=max(d[x*2].ans, d[x*2+1].ans);
	d[x].pref=d[x*2].pref;
	d[x].suf=d[x*2+1].suf;
	if(sr<=n&&tab[sr]<tab[sr+1]){
		d[x].ans=max(d[x*2].ans, d[x*2+1].ans);
		d[x].ans=max(d[x].ans, d[x*2].suf+d[x*2+1].pref);
		if(d[x*2].pref==sr+1-l) d[x].pref=d[x*2].pref+d[x*2+1].pref;
		if(d[x*2+1].suf==r-sr) d[x].suf=d[x*2+1].suf+d[x*2].suf;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int rozm=1;
	cin>>n;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n;i++){
		cin>>tab[i];
	}
	build(1, 1, rozm);
	cout<<d[1].ans<<"\n";
	int q;
	cin>>q;
	while(q--){
		int idx, val;
		cin>>idx>>val;
		tab[idx]=val;
		update(1, 1, rozm, idx);
		cout<<d[1].ans<<"\n";
	}
	return 0;
}
