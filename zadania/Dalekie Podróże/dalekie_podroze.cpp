#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int C = 2e2;
vector<int> kraw[N];
bitset<N> odw;
int n, m, q, tury[N][C], ls[C+5];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	for(int i=1;i<=C;i++){
		int pom = rand()%n+1;
		ls[i]=pom;
	}
	for(int i=1;i<=C;i++){
		queue<int> order;
		order.push(ls[i]);
		odw[ls[i]]=true;
		while(!order.empty()){
			auto x = order.front();
			order.pop();
			for(auto v : kraw[x]){
				if(!odw[v]){
					tury[v][i]=tury[x][i]+1;
					odw[v]=true;
					order.push(v);
				}
			}
		}
		for(int j=1;j<=n;j++){
			odw[j]=false;
		}	
	}
	while(q--){
		int a, b;
		cin>>a>>b;
		int ans=1e9;
		for(int i=1;i<=C;i++){
			ans=min(ans, tury[a][i]+tury[b][i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
