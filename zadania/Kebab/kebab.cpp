#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> kraw[N], path;
int reach[N], sz[N], ans[N], idx[N], n;
bitset<N> odw;
ll D[4*N];
int len(int x) {
	auto it = upper_bound(path.begin(), path.end(), make_pair(x, 1000000005));
	it--;
	if((*it).first>x) return 0;
	int where=it-path.begin();
	return where+1;
}
void update(int x,int w){
    if(x>n){
        return;
	}
    D[x]=D[x]+w;
    update(x+(x&(-x)), w);
}
ll sum(int x){
    if (x==0){
        return 0;
	}
    return D[x]+sum(x-(x&(-x)));
}
void dfs1(int x, int ojc){
	sz[x]=1;
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]){
			dfs1(v.first, x);
			sz[x]+=sz[v.first];
		}
	}
}
void dfs2(int x, int ojc, ll var){
	path.pb({var, x});
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]){
			dfs2(v.first, x, var+v.second);
		}
	}
}
int szukaj(int x, int ojc, int tr){
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]&&sz[v.first]*2>tr){
			return szukaj(v.first, x, tr);
		}
	}
	return x;
}
void change(int x, int ile, int ojc){
	update(idx[x], ile);
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]){
			change(v.first, ile, x);
		}
	}
}
void res(int x, int ile, int ojc){
	ans[x]+=sum(len(reach[x]-ile));
	for(auto v : kraw[x]){
		if(v.first!=ojc&&!odw[v.first]){
			res(v.first, ile+v.second, x);
		}
	}
}
void centroid(int x){
	dfs1(x, 0);
	int pom = szukaj(x, 0, sz[x]);
	odw[pom]=true;
	dfs1(pom, 0);
	if(sz[pom]==1){
		ans[pom]++;
		return;
	}
	path.clear();
	dfs2(pom, 0, 0);
	sort(path.begin(), path.end());
	for(int i=0;i<(int)path.size();i++){
		idx[path[i].second]=i+1;
	}
	for(int i=1;i<=sz[pom];i++){
		int ile=sum(i)-sum(i-1);
		update(i, 1 - ile);
	}
	ans[pom]+=sum(len(reach[pom]));
	for(auto v : kraw[pom]){
		if(!odw[v.first]){
			change(v.first, -1, 0);
			res(v.first, v.second, 0);
			change(v.first, 1, 0);
		}
	}
	for(auto v : kraw[pom]){
		if(!odw[v.first]){
			centroid(v.first);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>reach[i];
	}
	for(int i=1;i<=n-1;i++){
		int a, b, c;
		cin>>a>>b>>c;
		kraw[a].pb({b, c});
		kraw[b].pb({a, c});
	}
	centroid(1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
