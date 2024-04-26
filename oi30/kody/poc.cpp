//Autor: Wiktor Lewicki
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
int tab1[N], tab2[N], ver1[N], ver2[N], n, m, k;
bitset<N> odw;
vector<int> ozn[N];
vector<pair<int, int>> przedzialy[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>tab1[i];
		ozn[tab1[i]].pb(i);
	}
	for(int i=1;i<=m;i++){
		cin>>tab2[i];
	}
	int wsk=1;
	for(int i=1;i<=m;i++){
		while(wsk<n&&tab1[wsk]!=tab2[i]){
			wsk++;
		}
		ver1[i]=wsk;
		wsk++;
	}
	wsk=n;
	for(int i=m;i>=1;i--){
		while(wsk>1&&tab1[wsk]!=tab2[i]){
			wsk--;
		}
		ver2[i]=wsk;
		wsk--;
	}
	for(int i=1;i<=m;i++){
		przedzialy[tab2[i]].pb({ver1[i], ver2[i]});
	}
	for(int i=1;i<=k;i++){
		int help=0;
		for(auto v : ozn[i]){
			while(help<(int)przedzialy[i].size()&&przedzialy[i][help].first<=v){
				int x = przedzialy[i][help].first;
				int y = przedzialy[i][help].second;
				if(x<=v&&v<=y){
					odw[v]=true;
					break;
				}
				help++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<odw[i]<<" ";
	}
	return 0;
}
