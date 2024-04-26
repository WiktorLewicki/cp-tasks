#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int K = 21;
int n, ojc[N], gleb[N], t[N];
pair<int, int> anc[N][K];
vector<pair<int, int>> kraw[N];
bitset<N> odw;
void dfs(int x, int i)
{
	odw[x] = true;
	gleb[x] = i;
	for(auto v : kraw[x])
	{
		if(!odw[v.first])
		{
			ojc[v.first]=x;
			t[v.first]=v.second;
			dfs(v.first, i+1);
		}
	}
}
void make_anc()
{
	for(int i=1;i<=n;i++) anc[i][0] = make_pair(ojc[i], t[i]);
	for(int k=1;k<K;k++) for(int i=1;i<=n;i++) anc[i][k] = make_pair(anc[anc[i][k-1].first][k-1].first, max(anc[i][k-1].second, anc[anc[i][k-1].first][k-1].second));
}
int lca(int a, int b)
{
	if(gleb[a]<gleb[b]) swap(a, b);
	for(int k=20;k>=0;k--) if(gleb[anc[a][k].first]>=gleb[b]) a = anc[a][k].first;
	if(a==b) return a;
	for(int k=20;k>=0;k--)
	{
		if(anc[a][k].first!=anc[b][k].first)
		{
			a = anc[a][k].first;
			b = anc[b][k].first;	
		}
	}
	return ojc[a];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		kraw[a].push_back(make_pair(b, c));
		kraw[b].push_back(make_pair(a, c));
		
	}
	dfs(1, 0);
	make_anc();
	while(true)
	{
		int a, b, wynik=-1e9;
		cin>>a;
		if(a==-1) return 0;
		cin>>b;
		int gdzie = lca(a, b);
		int l=K, ile = gleb[a]-gleb[gdzie];
		if(a==b) wynik=max(wynik, 0);
		for(int i=(1<<20);i>=1;i/=2)
		{
			l--;
			if(ile>=i)
			{
				wynik = max(wynik, anc[a][l].second);
				a = anc[a][l].first;
				ile-=i;
			}
		}
		l=K, ile = gleb[b]-gleb[gdzie];
		for(int i=(1<<20);i>=1;i/=2)
		{
			l--;
			if(ile>=i)
			{
				wynik = max(wynik, anc[b][l].second);
				b = anc[b][l].first;
				ile-=i;
			}
		}
		cout<<wynik<<"\n";
	}
}
