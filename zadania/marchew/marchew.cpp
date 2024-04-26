#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long inf = -1e18;
int tab[N], n, m, g1, g2, cnt1, cnt2;
long long d[4*N], push[4*N], d2[4*N], push2[4*N];
void add(int x, int ile){
	d[x]+=ile;
	push[x]+=ile;
}
void add2(int x, int ile){
	d2[x]+=ile;
	push2[x]+=ile;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;	
}
void pushuj2(int x){
	add2(x*2, push2[x]);
	add2(x*2+1, push2[x]);
	push2[x]=0;	
}
void build(int x, int l, int r){
	if(l==r){
		if(l>n) d[x]=inf;
		else d[x] = tab[l];
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x] = max(d[x*2], d[x*2+1]);
}
void build2(int x, int l, int r){
	if(l==r){
		if(l>n) d2[x]=inf;
		else d2[x] = tab[l];
		return;
	}
	int sr = (l+r)/2;
	build2(x*2, l, sr);
	build2(x*2+1, sr+1, r);
	d2[x] = max(d2[x*2], d2[x*2+1]);
}
void update(int a, int b, int l, int r, int x, int ile){
	if(a<=l&&r<=b){
		add(x, ile);
		return;
	}
	pushuj(x);
	int sr = (l+r)/2;
	if(a<=sr){
		update(a, b, l, sr, x*2, ile);
	}
	if(sr<b){
		update(a, b, sr+1, r, x*2+1, ile);
	}
	d[x] = max(d[x*2], d[x*2+1]);
}
void update2(int a, int b, int l, int r, int x, int ile){
	if(a<=l&&r<=b){
		add2(x, ile);
		return;
	}
	pushuj2(x);
	int sr = (l+r)/2;
	if(a<=sr){
		update2(a, b, l, sr, x*2, ile);
	}
	if(sr<b){
		update2(a, b, sr+1, r, x*2+1, ile);
	}
	d2[x] = max(d2[x*2], d2[x*2+1]);
}
void query(int g, int l, int r, int x){
	if(l==r){
		if(d[x]>=g){
			cnt1++;
			d[x]=inf;
		}
		return;
	}
	pushuj(x);
	int sr = (l+r)/2;
	if(d[x*2]>=g){
		query(g, l, sr, x*2);
	}
	if(d[x*2+1]>=g){
		query(g, sr+1, r, x*2+1);
	}
	d[x] = max(d[x*2], d[x*2+1]);
}
void query2(int g, int l, int r, int x){
	if(l==r){
		if(d2[x]>=g){
			cnt2++;
			d2[x]=inf;
		}
		return;
	}
	pushuj2(x);
	int sr = (l+r)/2;
	if(d2[x*2]>=g){
		query2(g, l, sr, x*2);
	}
	if(d2[x*2+1]>=g){
		query2(g, sr+1, r, x*2+1);
	}
	d2[x] = max(d2[x*2], d2[x*2+1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>g2>>g1;
	int rozm=1;
	while(rozm < n){
		rozm*=2;
	}
	for(int i=1;i<=n;i++) cin>>tab[i];
	build(1, 1, rozm);
	build2(1, 1, rozm);
	while(m--){
		int a, b, c;
		cin>>a>>b>>c;
		g1--;
		g2--;
		update(a, b, 1, rozm, 1, c);
		update2(a, b, 1, rozm, 1, c);
		query(g1, 1, rozm, 1);
		query2(g2, 1, rozm, 1);
		cout<<cnt1<<" "<<cnt2-cnt1<<"\n";
	}
	return 0;
}
