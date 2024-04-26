#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int K = 26;
int tab[N], ans[N], kub[N], spr[N][K];
vector<int> ts1[N];
vector<pair<int, int>> ts2[N];
int poss[N][K];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
	}
	for(int i=1;i<=m;i++){
		int a, b;
		cin>>a>>b;
		ts1[a].pb(i);
		ts2[b+1].pb({a, i});
		for(int k=0;k<K;k++){
			poss[i][k] = tab[rand()%(b-a+1)+a];
		}
	}
	for(int i=1;i<=n+1;i++){
		for(auto v : ts1[i]){
			for(int k=0;k<K;k++){
				spr[v][k]=kub[poss[v][k]];
			}
		}
		for(auto v : ts2[i]){
			for(int k=0;k<K;k++){
				if(kub[poss[v.second][k]]-spr[v.second][k]>(i-v.first)/2){
					ans[v.second]=poss[v.second][k];
				}
			}
		}
		kub[tab[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
