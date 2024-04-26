#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
long long ans;
int tab[N*2][2], d[8*N][2], leftt[N], righ[N], n, rozm=1;
ll OR1, OR2;
void build(int x, int l, int r){
	if(l==r){
		if(l<=n*2){
			d[x][0]=tab[l][0];
			d[x][1]=tab[l][1];
		}
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x][0] = d[x*2][0] | d[x*2+1][0];
	d[x][1] = d[x*2][1] | d[x*2+1][1];
}
int query(int a, int b, int l, int r, int x, int inf){
	if(a<=l&&r<=b){
		return d[x][inf];
	}
	int res=0, sr = (l+r)/2;
	if(a<=sr){
		res|=query(a, b, l, sr, x*2, inf);
	}
	if(sr<b){
		res|=query(a, b, sr+1, r, x*2+1, inf);
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int spr, L=0;
	cin>>spr>>n;
	for(int i=1;i<=spr;i++){
		L+=rozm;
		rozm*=2;
	}
	rozm=1;
	while(rozm<n){
		rozm*=2;
	}
	rozm*=2;
	for(int i=1;i<=n;i++){
		cin>>tab[i][0];
		tab[i+n][0]=tab[i][0];
		tab[i][1]=tab[i][0]^L;
		tab[i+n][1]=tab[i][1];
		OR1|=tab[i][0];
		OR2|=tab[i][1];
	}
	build(1, 1, rozm);
	int wsk1=1, wsk2=n*2;
	for(int i=1;i<=n+1;i++){
		while(query(i, wsk1, 1, rozm, 1, 0)!=OR1||query(i, wsk1, 1, rozm, 1, 1)!=OR2){
			wsk1++;
		}
		leftt[i]=wsk1;
	}
	for(int i=n*2;i>=n+1;i--){
		while(query(wsk2, i, 1, rozm, 1, 0)!=OR1||query(wsk2, i, 1, rozm, 1, 1)!=OR2){
			wsk2--;
		}
		righ[i-n]=wsk2;
	}
	leftt[1]+=n;
	for(int i=1;i<=n;i++){
		leftt[i+1]+=n;
		ans+=max(0, n-leftt[i+1]+righ[i]);
	}
	cout<<ans/2;
	return 0;
}
