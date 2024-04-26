#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<int> kraw[N];
bitset<N> odw;
int dp[N], n, bin;
void dfs(int x);
bool czy_dobra(int test);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a, b;
		cin>>a>>b;
		kraw[a].push_back(b);
		kraw[b].push_back(a);
	}
	int l=0, p=n, sr, last=n;
	while(l<=p)
	{
		sr = (l+p)/2;
		if(czy_dobra(sr)) 
		{
			last=min(last, sr);
			p=sr-1;
		}
		else l=sr+1;
	}
	cout<<last;
	return 0;
}

bool czy_dobra(int test)
{
		odw.reset();
		for(int j=0;j<=n;j++) dp[j]=0;
		bin=test;
		dfs(1);
		int suma=0;
		for(auto v : kraw[1]) suma+=dp[v];
		dp[1]=suma-bin+kraw[1].size();
		if(dp[1]<=0) return true;
		return false;
}
void dfs(int x)
{
	odw[x] = true;
	for(int v : kraw[x])
	{
		if(!odw[v]) 
		{
			dfs(v);
			int suma=0;
			for(auto u : kraw[v]) suma+=dp[u];
			int val = suma-bin+kraw[v].size()-1;
			dp[v] = max(0, val);
		}
	}
}
