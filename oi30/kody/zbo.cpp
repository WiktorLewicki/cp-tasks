//Autor: Wiktor Lewicki
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll sum[4*N], push[4*N], d[4*N], pref[N], ans;
int sz[N], head[N], pos[N], ojc[N], gleb[N], pre[N], heavy[N], who[N], waga[N], cur_pos=1, rozm=1, n, k;
vector<pair<int, int>> kraw[N];
pair<ll, int> poddrzewo[4*N];
bitset<N> odw;
void add(int x, ll val){
	d[x]+=sum[x]*val;
	push[x]+=val;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
void create_sum(int x, int l, int r){
	if(l==r){
		if(l<=n) sum[x]=waga[l];
		return;
	}
	int sr = (l+r)/2;
	create_sum(x*2, l, sr);
	create_sum(x*2+1, sr+1, r);
	sum[x]=sum[x*2]+sum[x*2+1];
}
void dfs(int x, ll val){
	pre[x]=cur_pos;
	cur_pos++;
	pref[x]=val;
	sz[x]=1;
	odw[x]=true;
	int max_size=0;
	for(auto v : kraw[x]){
		if(!odw[v.first]){
			ojc[v.first]=x;
			gleb[v.first]=gleb[x]+1;
			who[v.first]=v.second;
			dfs(v.first, val+v.second);
			sz[x]+=sz[v.first];
			if(sz[v.first]>max_size){
				max_size=sz[v.first];
				heavy[x]=v.first;
			}
		}
	}
}
void decompose(int x, int h){
	odw[x]=true;
	head[x]=h;
	pos[x]=cur_pos;
	cur_pos++;
	if(heavy[x]){
		decompose(heavy[x], h);
	}
	for(auto v : kraw[x]){
		if(!odw[v.first]&&v.first!=heavy[x]){
			decompose(v.first, v.first);
		}
	}
}
ll query(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		return d[x];
	}
	pushuj(x);
	ll res=0;
	int sr = (l+r)/2;
	if(a<=sr){
		res+=query(x*2, l, sr, a, b);
	}
	if(sr<b){
		res+=query(x*2+1, sr+1, r, a, b);
	}
	d[x]=d[x*2]+d[x*2+1];
	return res;
}
ll HLD_QUERY(int a, int b){
	ll res=0;
	for(; head[a]!=head[b]; b=ojc[head[b]]){
		if(gleb[head[a]]>gleb[head[b]]){
			swap(a, b);
		}
		res+=query(1, 1, rozm, pos[head[b]], pos[b]);
	}
	if(gleb[a]>gleb[b]){
		swap(a, b);
	}
	res+=query(1, 1, rozm, pos[a], pos[b]);
	return res;
}
void update(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		add(x, 2);
		return;
	}
	pushuj(x);
	int sr = (l+r)/2;
	if(a<=sr){
		update(x*2, l, sr, a, b);
	}
	if(sr<b){
		update(x*2+1, sr+1, r, a, b);
	}
	d[x]=d[x*2]+d[x*2+1];
}
void HLD_UPDATE(int a, int b){
	for(; head[a]!=head[b]; b=ojc[head[b]]){
		if(gleb[head[a]]>gleb[head[b]]){
			swap(a, b);
		}
		update(1, 1, rozm, pos[head[b]], pos[b]);
	}
	if(gleb[a]>gleb[b]){
		swap(a, b);
	}
	update(1, 1, rozm, pos[a], pos[b]);
}
void pod_up(int x, int l, int r, int idx, ll val){
	if(l==r){
		poddrzewo[x]={val, 1};
		return;
	}
	int sr = (l+r)/2;
	if(idx<=sr){
		pod_up(x*2, l, sr, idx, val);
	}
	else{
		pod_up(x*2+1, sr+1, r, idx, val);
	}
	poddrzewo[x]={poddrzewo[x*2].first+poddrzewo[x*2+1].first, poddrzewo[x*2].second+poddrzewo[x*2+1].second};
}
pair<ll, int> pod_query(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		return poddrzewo[x];
	}
	pair<ll, int> res={0, 0};
	int sr=(l+r)/2;
	if(a<=sr){
		pair<ll, int> help = pod_query(x*2, l, sr, a, b);
		res.first+=help.first;
		res.second+=help.second;
	}
	if(sr<b){
		pair<ll, int> help = pod_query(x*2+1, sr+1, r, a, b);
		res.first+=help.first;
		res.second+=help.second;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n-1;i++){
		int a, b, c;
		cin>>a>>b>>c;
		kraw[a].pb({b, c});
		kraw[b].pb({a, c});
	}
	dfs(1, 0);
	ojc[1]=1;
	odw.reset();
	cur_pos=1;
	decompose(1, 1);
	for(int i=2;i<=n;i++){
		waga[pos[ojc[i]]]=who[ojc[i]];
	}
	create_sum(1, 1, rozm);
	pod_up(1, 1, rozm, 1, 0);
	while(k--){
		int test;
		cin>>test;
		pair<ll, int> pom=pod_query(1, 1, rozm, pre[test], pre[test]+sz[test]-1);
		ll help=poddrzewo[1].first-HLD_QUERY(1, test)+pref[test]*(poddrzewo[1].second-pom.second)+pref[test]*pom.second;
		help*=2;
		pod_up(1, 1, rozm, pre[test], pref[test]);
		HLD_UPDATE(1, test);
		ans+=help;
		cout<<ans<<"\n";
	}
	return 0;
}
