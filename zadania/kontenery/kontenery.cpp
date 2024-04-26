#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int sq, ans[N], lazy[2*N];
vector<pair<int, int>> big[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	sq = sqrt(n);
	while(k--){
		int a, b, c;
		cin>>a>>b>>c;
		int pom = a+(b-1)*c;
		if(c>sq){
			for(int i=a;i<=pom;i+=c){
				ans[i]++;
			}
		}
		else{
			big[c].pb({a, pom});
		}
	}
	for(int i=1;i<=sq;i++){
		for(auto v : big[i]){
			lazy[v.first]++;
			lazy[v.second+i]--;
		}
		for(int j=1;j<=n;j++){
			if(j-i>0){
				lazy[j]+=lazy[j-i];
			}
		}
		for(int j=1;j<=n+5;j++){
			ans[j]+=lazy[j];
			lazy[j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
