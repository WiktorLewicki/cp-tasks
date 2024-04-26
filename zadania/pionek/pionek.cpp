#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 2e5 + 5;
pair<double, int> vc[N*2];
pair<int, int> ins[N];
ll ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		double a, b, res;
		cin>>a>>b;
		ins[i] = {a, b};
		res = atan2(a, b) * 180 / M_PI;
		if(a<0) res=360+res;
		vc[i]={res, i};
	}
	sort(vc+1, vc+n+1);
	for(int i=1;i<=n;i++){
		vc[i+n]=vc[i];
		vc[i+n].first+=360.0;
	}
	ll a=0, b=0, wsk=0;
	vc[0].first=vc[1].first;
	for(int i=0;i<=n*2;i++){
		while(wsk<n*2&&(double)(vc[i].first+180.0)>=vc[wsk+1].first){
			a+=ins[vc[wsk+1].second].first;
			b+=ins[vc[wsk+1].second].second;
			wsk++;
			ans=max(ans, a*a+b*b);
		}
		a-=ins[vc[i].second].first;
		b-=ins[vc[i].second].second;
		ans=max(ans, a*a+b*b);
	}
	cout<<ans;
	return 0;
}
