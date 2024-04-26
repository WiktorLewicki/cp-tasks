#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
pair<int, int> tab[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, maks=0, kiedy=0, lastmax=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		if(a<=n){
			if(kiedy>tab[a].second){
				tab[a]=make_pair(1, i);
				maks = max(lastmax+1, maks);
			}
			else{
				tab[a] = make_pair(tab[a].first+1, i);
				maks = max(maks, tab[a].first+lastmax);
			}
		}
		else{
			kiedy=i;
			lastmax=maks;
		}
	}
	for(int i=1;i<=n;i++){
		if(tab[i].second<kiedy){
			cout<<lastmax<<" ";
		}
		else cout<<tab[i].first+lastmax<<" ";
	}
	return 0;
}
