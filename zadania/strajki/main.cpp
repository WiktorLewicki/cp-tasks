#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> tab[N];
int synowie[N], ojciec[N]; 
bitset<N> odw;
void dfs(int x)
{
	odw[x] = true;
	for(auto v : tab[x])
	{
		if(!odw[v])
		{
			ojciec[v]=x;
			dfs(v);
			synowie[x]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a, b;
		cin>>a>>b;
		tab[a].push_back(b);
		tab[b].push_back(a);
	}
	dfs(1);
	odw.reset();
	int tests, ile=1;
	odw[0]=true;
	cin>>tests;
	while(tests--)
	{
		int x;
		cin>>x;
		if(x>0)
		{
			odw[x] = true;
			synowie[ojciec[x]]--;
			int val = synowie[x]+(odw[ojciec[x]]==false)-1;
			ile+=val;
			cout<<ile<<"\n";
		}
		if(x<0)
		{
			x*=-1;
			odw[x] = false;
			synowie[ojciec[x]]++;
			int val = synowie[x]+(odw[ojciec[x]]==false)-1;
			ile-=val;
			cout<<ile<<"\n";
		}	
	}
	return 0;
}
