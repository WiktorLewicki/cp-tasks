#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int l[N], r[N];
long long dp[2][N];
vector<int> kraw[N];
bitset<N> odw;
void dfs(int x)
{
	odw[x] = true;
	for(auto v : kraw[x]) 
	{
		if(!odw[v]) 
		{
			dfs(v);
			dp[0][x]+=max(abs(l[x]-l[v])+dp[0][v],abs(l[x]-r[v])+dp[1][v]);
			dp[1][x]+=max(abs(r[x]-l[v])+dp[0][v], abs(r[x]-r[v])+dp[1][v]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tests;
	cin>>tests;
	while(tests--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i];	
		for(int i=1;i<=n-1;i++)
		{
			int a, b;
			cin>>a>>b;
			kraw[a].push_back(b);
			kraw[b].push_back(a);
		}
		dfs(1);
		cout<<max(dp[0][1], dp[1][1])<<"\n";
		for(int i=0;i<=n+5;i++) 
		{
			dp[0][i]=dp[1][i]=0;
			kraw[i].clear();
		}
		odw.reset();
	}
	return 0;
}
