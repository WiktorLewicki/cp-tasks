#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll ans=1e18, rozm=1, LG=1;
ll fpow(ll a, ll b){
	ll wyn=1;
	for(ll i=1;i<=b;i++){
		wyn*=a;
	}
	return wyn;
}
ll prw(ll a, ll b){
	return pow(a, 1.0/(long double)b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, a, b;
	cin>>n>>a>>b;
	while(rozm<n){
		rozm*=2;
		LG++;
	}
	n++;
	for(ll i=1;i<=LG;i++){
		ll pom=(ll)prw(n, i);
		for(ll j=0;j<=i;j++){
			ll jeden=1;
			ll pom1 = max(jeden, fpow(pom, j)), pom2=max(jeden, fpow(pom+1, i-j));
			if(pom1*pom2>=n){
				ans=min(ans, a*i+(pom*j+(pom+1)*(i-j)-i)*b);
			}
		}
	}
	cout<<ans;
	return 0;
}
