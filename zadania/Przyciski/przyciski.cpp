#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int d[3*N], push[3*N];

void add(int x, int ile) {
	d[x]=ile;
	push[x]=ile;
}
void pushuj(int x) {
	if(push[x]){
		add(x * 2, push[x]);
		add(x * 2 + 1, push[x]);
		push[x] = 0;
	}
}
void insert(int i, int l, int r, int x){
	if(l==r){
		d[x]++;
		return;
	}
	pushuj(x);
	int sr = (l+r) / 2;
	if(i<=sr){
		insert(i, l, sr, x*2);
	}
	else{
		insert(i, sr+1, r, x*2+1);
	}
	d[x] = max(d[x*2], d[x*2+1]);
}
void insert2(int a, int b, int l, int r, int x, int ile){
	if(a<=l&&r<=b){
		add(x, ile);
		return;
	}
	pushuj(x);
	int sr = (l+r) / 2;
	if(a<=sr){
		insert2(a, b, l, sr, x*2, ile);
	}
	if(sr<b){
		insert2(a, b, sr+1, r, x*2+1, ile);
	}
	d[x] = max(d[x*2], d[x*2+1]);
}
void przeladuj(int l, int r, int x){
	if(l==r){
		return;
	}
	int sr = (l+r) / 2;
	pushuj(x);
	przeladuj(l, sr, x*2);
	przeladuj(sr+1, r, x*2+1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, rozm=1;
	cin>>n>>m;
	while(rozm < n){
		rozm*=2;
	}
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		if(a!=n+1){
			insert(a, 1, rozm, 1);
		}
		else{
			insert2(1, rozm, 1, rozm, 1, d[1]);
		}
	}
	przeladuj(1, rozm , 1);
	for(int i=0;i<n;i++){
		cout<<d[i+rozm]<<" ";
	}
	return 0;
}
