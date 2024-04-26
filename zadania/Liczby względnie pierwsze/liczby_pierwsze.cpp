#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll N, K, C;
vector<ll> pom;
ll inout(ll border, ll idx, ll war, ll lic){
	ll wyn=0;
	if(lic%2&&war>1) wyn-=border/war;
	else if(war>1) wyn+=border/war;
	for(ll i=idx;i<(ll)pom.size();i++){
		wyn+=inout(border, i+1, war*pom[i], lic+1);
	}
	return wyn;
}
ll formula(ll ZM, ll border){
	ll ans=border;
	for(ll i=2;i*i<=ZM;i++){
		bool ok=false;
		while(ZM%i==0){
			ok=true;
			ZM/=i;
		}
		if(ok) pom.pb(i);
	}
	if(ZM!=1) pom.pb(ZM);
	ans+=inout(border, 0, 1, 0);
	pom.clear();
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>K>>C;
	ll l=1, r=1e18, sr, FIRST=1e18;
	while(l<=r){
		sr = (l+r)/2;
		if(formula(N, sr)<K){
			l=sr+1;
		}
		else{
			r=sr-1;
			FIRST=min(FIRST, sr);
		}
	}
	ll cnt=0;
	for(ll i=FIRST;i<=1e18;i++){
		if(__gcd(i, N)==1){
			cout<<i<<" ";
			cnt++;
		}
		if(cnt==C){
			break;
		}
	}
	return 0;
}
