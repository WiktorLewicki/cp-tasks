#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int tab[N*2], idx[N][2], push[4*N], n, rozm=1, q;
pair<int, int> d[4*N];
void add(int x, int ile){
	d[x].first+=ile;
	push[x]+=ile;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
pair<int ,int> setuj(pair<int, int>a, pair<int, int> b){
	if(a.first==b.first){
		return {a.first, a.second+b.second};
	}
	if(a.first<b.first) {
		return a;
	}
	return b;
}
void build(int x, int l, int r){
	if(l==r){
		if(l<=n+1) d[x].second=1;
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x]=setuj(d[x*2], d[x*2+1]);
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
	d[x] = setuj(d[x*2], d[x*2+1]);
}
void update_fast(int a, int b, int info){
	//cout<<a<<" "<<b<<"\n";
	if(a%2==0&&b%2==0){
		if(b/2+1<=n+1) update(b/2+1, n+1, 1, rozm, 1, info);
		//cout<<"x";
	}
	else if(a%2&&b%2){
		update(1, (a+1)/2, 1, rozm, 1, info);
		//cout<<"s";
	}
	else if(a%2==0&&b%2){
		update(a/2+1, (b+1)/2, 1, rozm, 1, info);
	//	cout<<"f";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	while(rozm<=n){
		rozm*=2;
	}
	build(1, 1, rozm);
	for(int i=1;i<=n*2;i++){
		cin>>tab[i];
		if(idx[tab[i]][0]){
			idx[tab[i]][1]=i;
		}
		else{
			idx[tab[i]][0]=i;
		}
	}
	for(int i=1;i<=n;i++){
		update_fast(idx[i][0], idx[i][1], 1);
	}
	//cout<<"\n\n";
	while(q--){
		int a, b;
		cin>>a>>b;
		if(tab[a]!=tab[b]){
			//cout<<idx[tab[a]][0]<<" "<<idx[tab[a]][1]<<"\n";
			//cout<<idx[tab[b]][0]<<" "<<idx[tab[b]][1]<<"\n";
			update_fast(idx[tab[a]][0], idx[tab[a]][1], -1);
			update_fast(idx[tab[b]][0], idx[tab[b]][1], -1);
		//	cout<<d[1].second<<"\n";
			if(idx[tab[a]][0]==a){
				idx[tab[a]][0]=b;
			}
			else idx[tab[a]][1]=b;
			if(idx[tab[b]][0]==b){
				idx[tab[b]][0]=a;
			}
			else idx[tab[b]][1]=a;
			if(idx[tab[a]][0]>idx[tab[a]][1]) swap(idx[tab[a]][0],idx[tab[a]][1]);
			if(idx[tab[b]][0]>idx[tab[b]][1]) swap(idx[tab[b]][0],idx[tab[b]][1]);
			swap(tab[a], tab[b]);
			//if(!d[1].first) cout<<d[1].second<<"\n";
			//else cout<<"0\n";
			//cout<<idx[tab[a]][0]<<" "<<idx[tab[a]][1]<<"\n";
			//cout<<idx[tab[b]][0]<<" "<<idx[tab[b]][1]<<"\n";
			update_fast(idx[tab[a]][0], idx[tab[a]][1], 1);
			update_fast(idx[tab[b]][0], idx[tab[b]][1], 1);
		}
		if(!d[1].first) cout<<d[1].second<<"\n";
		else cout<<"0\n";
	}
	return 0;
}
