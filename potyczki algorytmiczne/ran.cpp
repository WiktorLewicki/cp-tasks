#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int tab[N], kub[N];
pair<int, int> info[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
		kub[tab[i]]=i;
	}
	info[0]={1e9, 0};
	for(int i=n;i>=1;i--){
		info[n-i+1].first=min(kub[i], info[n-i].first);
		info[n-i+1].second=max(kub[i], info[n-i].second);
	}
	ll ans=n*2+1, ile=0;
	for(int i=1;i<=n;i++){
		int k;
		if(i%2) k=(i+1)/2;
		else k=i/2+1;
		int a=info[k].first, b=info[k].second, dl=b-a+1;
		int pom=i-dl;
		if(pom<0) continue;
		int border1=max(1, a-pom);
		int border2=min(n, b+pom);
		border1=a-border1;
		border2-=b;
		ile+=max(0,((border1+border2)-pom+1));
	}
	cout<<ans<<" "<<ile;
	return 0;
}
