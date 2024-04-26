#include <bits/stdc++.h>
using namespace std;
const int N = 524290;
long long d[N*2];
int n, rozm=1, cnt=1, ile=0;
void insert(int l, int r, int idx, int var, int x){
	if(l==r){
		d[x]+=var;
		return;
	}
	int sr = (l+r)/2;
	if(idx<=sr){
		insert(l, sr, idx, var, x*2);
	}
	else{
		insert(sr+1, r, idx, var, x*2+1);
	}
	d[x]=d[x*2]+d[x*2+1];
}
void setuj(int l, int r, int idx, int var, int x){
	if(l==r){
		d[x]=var;
		return;
	}
	int sr = (l+r)/2;
	if(idx<=sr){
		setuj(l, sr, idx, var, x*2);
	}
	else{
		setuj(sr+1, r, idx, var, x*2+1);
	}
	d[x]=d[x*2]+d[x*2+1];
}
long long query(int l, int r, int a, int b, int x){
	if(a<=l&&r<=b){
		return d[x];
	}
	long long res=0;
	int sr = (l+r)/2;
	if(a<=sr){
		res+=query(l, sr, a, b, x*2);
	}
	if(sr<b){
		res+=query(sr+1, r, a, b, x*2+1);
	}
	return res;
}
void inicjuj(int m){
	n=m;
	while(rozm<n){
		rozm*=2;
	}
}
void dodaj(int k){
	ile++;
	setuj(1, rozm, cnt, k, 1);
	cnt++;
	if(cnt>n) cnt-=n;
}
void koryguj(int i, int k){
	int pom=cnt-i;
	if(pom<1) pom+=n;
	insert(1, rozm, pom, k, 1);
}
long long suma(int i){
	if(i>=ile) return d[1];
	int pom=cnt-i;
	if(pom<1){
		pom+=n;
		if(cnt==pom) return d[1];
		long long ans = d[1] - query(1, rozm, cnt, pom-1, 1);
		return ans;
	}
	else{
		long long ans = query(1, rozm, pom, cnt-1, 1);
		return ans;
	}
}
