#include <bits/stdc++.h> //zle
#define ll long long
using namespace std;
const int MOD1 = 1e9 + 207;
const int MOD2 = 1e9 + 7;
const int ST1 = 47;
const int ST2 = 43;
const int N = 1e3 + 5;
pair<int, int> d[4*N][102];
int power1[N], power2[N], ans[N], rozm=1;
string S[N];
map<pair<int, int>, int> mapa;
void update(int l, int r, int idx, pair<int, int> var, int x, int info){
	if(l==r){
		d[x][info]=var;
		return;
	}
	int sr = (l+r)/2;
	if(idx<=sr){
		update(l, sr, idx, var, x*2, info);
	}
	else{
		update(sr+1, r, idx, var, x*2+1, info);
	}
	int pom1 = ((ll)d[x*2][info].first+(ll)d[x*2+1][info].first)%MOD1;
	int pom2 = ((ll)d[x*2][info].second+(ll)d[x*2+1][info].second)%MOD2;
	d[x][info] = {pom1, pom2};
}
pair<int, int> query(int l, int r, int a, int b, int x, int info){
	if(a<=l&&r<=b){
		return d[x][info];
	}
	int sr = (l+r)/2;
	pair<int, int> res = {0, 0};
	if(a<=sr){
		pair<int, int> pom=query(l, sr, a, b, x*2, info);
		res.first = ((ll)res.first+pom.first)%MOD1;
		res.second = ((ll)res.second+pom.second)%MOD2;
	}
	if(sr<b){
		pair<int, int> pom=query(sr+1, r, a, b, x*2+1, info);
		res.first = ((ll)res.first+pom.first)%MOD1;
		res.second = ((ll)res.second+pom.second)%MOD2;
	}
	return res;
}
pair<int, int> read(int a, int b, int info){
	return query(1, rozm, a, b, 1, info);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin>>m>>n>>t;
	while(rozm<n){
		rozm*=2;
	}
	power1[1]=1;
	power2[1]=1;
	for(int i=2;i<=n;i++){
		power1[i]=((ll)power1[i-1]*ST1)%MOD1;
		power2[i]=((ll)power2[i-1]*ST2)%MOD2;
	}
	for(int i=1;i<=m;i++){
		cin>>S[i];
		for(int j=0;j<n;j++){
			ll upt1 = ((ll)power1[j+1]*((ll)S[i][j]-96))%MOD1;
			ll upt2 = ((ll)power2[j+1]*((ll)S[i][j]-96))%MOD2;
			update(1, rozm, j+1, {upt1, upt2}, 1, i);
		}
		mapa[d[1][i]]++;
	}
	for(int k=1;k<=m;k++){
		ans[k] = max(ans[k], mapa[d[1][k]]);
	}
	while(t--){
		int a1, b1, a2, b2;
		cin>>a1>>b1>>a2>>b2;
		mapa[d[1][a1]]--;
		if(a1!=a2)mapa[d[1][a2]]--;
		char xd1=S[a1][b1-1], xd2=S[a2][b2-1];
		swap(S[a1][b1-1], S[a2][b2-1]);
		ll upt1 = ((ll)power1[b1]*((ll)xd2-96))%MOD1;
		ll upt2 = ((ll)power2[b1]*((ll)xd2-96))%MOD2;
		update(1, rozm, b1, {upt1, upt2}, 1, a1);
		upt1 = ((ll)power1[b2]*((ll)xd1-96))%MOD1;
		upt2 = ((ll)power2[b2]*((ll)xd1-96))%MOD2;
		update(1, rozm, b2, {upt1, upt2}, 1, a2);
		mapa[d[1][a1]]++;
		if(a1!=a2)mapa[d[1][a2]]++;
		for(int k=1;k<=m;k++){
			ans[k] = max(ans[k], mapa[d[1][k]]);
		}
	}
	for(int k=1;k<=m;k++){
		cout<<ans[k]<<"\n";
	}
	return 0;
}
