#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5 + 5;
vector<int> kraw[N];
double mor[N];
int siz[N];
bitset<N> odw;
void dfs(int x)
{
	odw[x] = true;
	for(auto v : kraw[x])
	{
		if(!odw[v])
		{
			dfs(v);
			siz[v]=1;
			for(auto c : kraw[v]) siz[v]+=siz[c];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		int a;
		cin>>a;
		kraw[a].push_back(i);
	}
	dfs(1);
	siz[1]=1;
	for(auto v : kraw[1]) siz[1]+=siz[v];
	for(int i=1;i<=n;i++) if(siz[i]==1) mor[i]=1;
	for(int i=n;i>=1;i--)
	{
		if(siz[i]==1) continue;
		double ile = 0;
		for(auto v : kraw[i]) ile=max(ile, min(mor[v],(double)siz[v]/(double)(siz[i]-1)));  
		mor[i]=ile;
	}
	double wynik=0;
	for(int i=1;i<=n;i++) if(siz[i]>k) wynik=max(wynik, mor[i]);
	cout<<wynik;
	return 0;
}
