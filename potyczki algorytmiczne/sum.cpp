#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
pair<long long, int> tab[N];
bitset<N> ans;
bool check(int who){
	long long pom = tab[who].first;
	for(int i=1;i<=n;i++){
		if(i==who) continue;
		if(tab[i].first>=pom){
			return false;
		}
		pom+=tab[i].first;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	bool ok = true;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		tab[i] = {a, i};
		if(i>1&&a!=tab[i-1].first) ok = false;
	}
	if(ok){
		for(int i=1;i<=n;i++) cout<<"N";
		return 0;
	}
	sort(tab+1, tab+n+1);
	int l=1, r=n;
	while(l<r){
		int sr=(l+r)/2;
		if(check(sr)){
			r=sr;
		}
		else{
			l=sr+1;
		}
	}
	for(int i=r;i<=n;i++){
		ans[tab[i].second]=true;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]) cout<<"T";
		else cout<<"N";
	}
	return 0;
}
