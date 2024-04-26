#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
vector<pair<int, int>> kraw[N], t2[N], ans;
vector<pair<pair<int, int>, pair<int, int>>> mf;
int pom, kub[N], wsk=0, n, m, q, info[N], gleb[N], zm[N], ojc[N], idx[N];
pair<int, int> wr[N];
bitset<N> odw;
vector<int> t1[N], ety;
void cl(){
	for(int j=0;j<=n+3;j++) odw[j] = false;
}
void dfs(int x){
	odw[x] = true;
	for(int i=0;i<kraw[x].size();i++){
		if(!odw[kraw[x][i].first]){
			idx[kraw[x][i].first]=i;
			dfs(kraw[x][i].first);
		}
	}
}
void lic_gleb(int x, int i){
	odw[x]=true;
	gleb[x]=i;
	for(auto v : kraw[x]){
		if(!odw[v.first]){
			ojc[v.first]=x;
			lic_gleb(v.first, i+1);
		}
	}
}
void odp_dfs(int x){
	odw[x] = true;
	vector<pair<pair<int, int>, pair<int, int>>> used;
	vector<int> l;
	for(auto v : t1[x]){
		for(auto s : mf){
			if(v>s.first.first){
				used.pb(s);
				l.pb(info[s.second.first]);
				kub[info[s.second.first]]--;
				if(kub[info[s.second.first]]==0) wsk--;
				kub[s.first.second]++;
				if(kub[s.first.second]==1) wsk++;
				info[s.second.first]=s.first.second;
			}
		}
		ans.pb({v, wsk});
		for(int i=used.size()-1;i>=0;i--){
			info[used[i].second.first]=l[i];
			if(kub[used[i].first.second]==1) wsk--;
			kub[used[i].first.second]--;
			if(kub[info[used[i].second.first]]==0) wsk++;
			kub[info[used[i].second.first]]++;
		}
		l.clear();
		used.clear();
	}
	for(auto v : kraw[x]){
		if(!odw[v.first]){
			for(auto s : t2[v.first]){
				mf.pb({s, v});
			}
			info[v.first] = v.second;
			kub[v.second]++;
			if(kub[v.second]==1) wsk++;
			odp_dfs(v.first);
			kub[v.second]--;
			if(!kub[v.second]) wsk--;
			for(auto s : t2[v.first]){
				mf.pop_back();
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q>>m;
	pom=sqrt(m);
	ojc[1]=1;
	for(int i=1;i<=n-1;i++){
		int a, b, c;
		cin>>a>>b>>c;
		wr[i] = {a, b};
		kraw[a].pb({b, c});
		kraw[b].pb({a, c});
	}
	dfs(1);
	cl();
	lic_gleb(1, 0);
	cl();
	int lic=0;
	for(int i=1;i<=m;i++){
		lic++;
		int a, b;
		char s;
		cin>>s;
		if(s=='Z'){
			cin>>a;
			t1[a].pb(i);
		}
		else{
			cin>>a>>b;
			if(gleb[wr[a].first]>gleb[wr[a].second]){
				swap(wr[a].first, wr[a].second);
			}
			t2[wr[a].second].pb({i, b});
			zm[wr[a].second]=b;
		}
		if(lic==pom){
			lic=0;
			cl();
			odp_dfs(1);
			for(int j=2;j<=n;j++){
				if(zm[j]){
					kraw[ojc[j]][idx[j]]={j, zm[j]};
					zm[j]=0;
				}
			}
			for(int j=1;j<=n;j++){
				t1[j].clear();
				t2[j].clear();
			}
		}
	}
	cl();
	odp_dfs(1);
	sort(ans.begin(), ans.end());
	for(auto v : ans){
		cout<<v.second<<"\n";
	}
	return 0;
}
