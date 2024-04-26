#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int K = 21;
vector<int> kraw[N];
bitset<N>odw;
int n, ojciec[N], gleb[N], anc[N][K];
long long kub[N];
void dfs(int x, int i)
{
	odw[x]=true;
	gleb[x]=i;
	for(auto v : kraw[x])
	{
		if(!odw[v])
		{
			ojciec[v]=x;
			dfs(v, i+1);
		}
	}
}
void dfs2(int x)
{
	odw[x]=true;
	for(auto v : kraw[x])
	{
		if(!odw[v])
		{
			dfs2(v);
			kub[x]+=kub[v];
		}
	}
}
void make_anc()
{
	for(int i=1;i<=n;i++) anc[i][0]=ojciec[i];
	for(int k=1;k<K;k++) for(int i=1;i<=n;i++) anc[i][k]=anc[anc[i][k-1]][k-1];
}
int lca(int a, int b)
{
	if(gleb[a]<gleb[b]) swap(a, b);
	for(int k=K-1;k>=0;k--) if(gleb[anc[a][k]]>=gleb[b]) a = anc[a][k];
	if(a==b) return a;
	for(int k=K-1;k>=0;k--)
	{
		if(anc[a][k]!=anc[b][k])
		{
			a = anc[a][k];
			b = anc[b][k];
		}
	}
	return ojciec[a];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int a, b;
		cin>>a>>b;
		kraw[a].push_back(b);
		kraw[b].push_back(a);
	}
	dfs(0, 0);
	make_anc();
	odw.reset();
	while(m--)
	{
		int a, b, x;
		cin>>a>>b>>x;
		kub[a]+=x;
		kub[b]+=x;
		kub[lca(a, b)]-=(x*2);
	}
	dfs2(0);
	long long wynik=0;
	for(int i=1;i<n;i++) wynik=max(wynik, kub[i]);
	cout<<wynik;
	return 0;
}
