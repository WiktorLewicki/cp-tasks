#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 207;
const int ST = 47;
const int N = 1e6 + 5;
int d[2097160][2], power[N], minpow[N], rozm=1;
long long fast_power(ll base, ll pt){
	if(!pt) return 1;
	if(pt&1){
		return (base*fast_power(base, pt-1))%MOD;
	}
	else{
		long long res = fast_power(base, pt/2);
		return (res*res)%MOD;
	}
}
void update(int l, int r, int idx, int var, int x, int info){
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
	d[x][info]=((ll)d[x*2][info]+(ll)d[x*2+1][info])%MOD;
}
int query(int l, int r, int a, int b, int x, int info){
	if(a<=l&&r<=b){
		return d[x][info];
	}
	int sr = (l+r)/2, res=0;
	if(a<=sr){
		res+=query(l, sr, a, b, x*2, info);
		res%=MOD;
	}
	if(sr<b){
		res+=query(sr+1, r, a, b, x*2+1, info);
		res%=MOD;
	}
	return res;
}
int read(int a, int b, int info){
	int pom = query(1, rozm, a, b, 1, info);
	pom = ((ll)pom*(ll)minpow[a-1])%MOD;
	return pom;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string S1 = ".", S2 = ".", nap;
	cin>>nap;
	S1+=nap;
	cin>>nap;
	S2+=nap;
	nap="";
	while(rozm<n){
		rozm*=2;
	}
	power[1]=1;
	minpow[0]=1;
	minpow[1]=fast_power(ST, MOD-2);
	for(int i=2;i<=n+2;i++){
		power[i]=((ll)power[i-1]*ST)%MOD;
	}
	for(int i=2;i<=n;i++){
		minpow[i]=((ll)minpow[i-1]*minpow[1])%MOD;
	}
	for(int i=1;i<=n;i++){
		ll upt = ((ll)power[i]*((ll)S1[i]-96))%MOD;
		update(1, rozm, i, upt, 1, 0);
		upt = ((ll)power[i]*((ll)S2[i]-96))%MOD;
		update(1, rozm, i, upt, 1, 1);
	}
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		a++;
		b++;
		int pom1 = (((ll)S1[a]-96)*power[b])%MOD;
		int pom2 = (((ll)S2[b]-96)*power[a])%MOD;
		swap(S1[a], S2[b]);
		update(1, rozm, a, pom2, 1, 0);
		update(1, rozm, b, pom1, 1, 1);
		if(d[1][0]==d[1][1]){
			cout<<"0\n";
			continue;
		}
		int l=0, r=n-1;
		while(l<r){
			int sr = (l+r)/2+1;
			if(query(1, rozm, 1, sr, 1, 0)!=query(1, rozm, 1, sr, 1, 1)){
				r=sr-1;
			}
			else l=sr;
		}
		if(S1[l+1]>S2[l+1]) cout<<"1\n";
		else cout<<"2\n";
	}
	return 0;
}
