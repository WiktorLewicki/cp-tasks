#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int d[4*N][2], push[4*N][2], rozm=1, n;
bitset<4*N> odw[2];
void add(int x, int val, int info){
	d[x][info]=val;
	push[x][info]=val;
}
void pushuj(int x, int info){
	add(x*2, push[x][info]/2, info);
	odw[info][x*2]=true;
	odw[info][x*2+1]=true;
	add(x*2+1, push[x][info]/2, info);
	push[x][info]=0;
}
void build(int x, int l, int r, int info){
	if(l==r){
		return;
	}
	if(odw[info][x]) pushuj(x, info);
	odw[info][x]=false;
	int sr = (l+r)/2;
	build(x*2, l, sr, info);
	build(x*2+1, sr+1, r, info);
	d[x][info]=d[x*2][info]+d[x*2+1][info];
}
void update(int l, int r, int a, int b, int x, int val, int info){
	if(a<=l&&r<=b){
		add(x, (r-l+1)*val, info);
		odw[info][x]=true;
		return;
	}
	if(odw[info][x]) pushuj(x, info);
	odw[info][x]=false;
	int sr = (l+r)/2;
	if(a<=sr){
		update(l, sr, a, b, x*2, val, info);
	}
	if(sr<b){
		update(sr+1, r, a, b, x*2+1, val, info);
	}
	d[x][info]=d[x*2][info]+d[x*2+1][info];
}
int search(int l, int r, int x, int ile, int info){
	if(d[x][info]==ile) return min(n, r);
	if(odw[info][x]) pushuj(x, info);
	odw[info][x]=false;
	int ans=0, sr=(l+r)/2;
	if(d[x*2][info]>=ile){
		ans=search(l, sr, x*2, ile, info);
	}
	else{
		ans=search(sr+1, r, x*2+1, ile-d[x*2][info], info);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	string S;
	cin>>n>>m>>S;
	while(rozm<n){
		rozm*=2;
	}
	if(m<=100){
		while(m--){
			int p;
			char a, b;
			cin>>p>>a>>b;
			int cnt=0;
			for(int i=0;i<n;i++){
				if(S[i]==a){
					S[i]=b;
					cnt++;
				}
				if(cnt==p) break;
			}
		}
		cout<<S;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(S[i]=='a'){
			update(1, rozm, i+1, i+1, 1, 0, 0);
			update(1, rozm, i+1, i+1, 1, 1, 1);
		}
		else{
			update(1, rozm, i+1, i+1, 1, 1, 0);
			update(1, rozm, i+1, i+1, 1, 0, 1);
		}
	}
	while(m--){
		int p;
		char a, b;
		cin>>p>>a>>b;
		if(a=='b'){
			int idx=search(1, rozm, 1, p, 0);
			update(1, rozm, 1, idx, 1, 0, 0);
			update(1, rozm, 1, idx, 1, 1, 1);
		}
		else{
			int idx=search(1, rozm, 1, p, 1);
			update(1, rozm, 1, idx, 1, 1, 0);
			update(1, rozm, 1, idx, 1, 0, 1);
		}
	}
	build(1, 1, rozm, 0);
	for(int i=rozm;i<rozm+n;i++){
		if(d[i][0]) cout<<"b";
		else cout<<"a";
	}
	return 0;
}
