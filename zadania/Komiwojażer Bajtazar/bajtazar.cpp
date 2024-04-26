#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
const int K = 16;

vector<int> kraw[N];
int n, ojc[N], gleb[N], ancestor[N][K];
bitset<N> odw;
void dfs(int x, int i)
{
	gleb[x] = i;
	odw[x] = true;
	for(auto v : kraw[x])
	{
		if(!odw[v])
		{
			ojc[v]=x;
			dfs(v, i+1);
		}
	}
}

void make_ancestor() {
	for (int i = 1; i <= n; i++) {
		ancestor[i][0] = ojc[i];
	}
	
	for (int k = 1; k < K; k++) {
		for (int i = 1; i <= n; i++) {
			ancestor[i][k] = ancestor[ancestor[i][k - 1]][k - 1];
		}
	}
}

int lca(int a, int b) {
	if (gleb[a] < gleb[b]) {
		swap(a, b);
	}
	
	for (int k = K - 1; k >= 0; k--) {
		if (gleb[ancestor[a][k]] >= gleb[b]) {
			a = ancestor[a][k];
		}
	}
	if (a == b) {
		return a;
	}
			
	for (int k = K - 1; k >= 0; k--) {
		if (ancestor[a][k] != ancestor[b][k]) {
			a = ancestor[a][k];
			b = ancestor[b][k];
		}
	}
	return ojc[a];
}

int main(){
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
	dfs(1, 0);
	make_ancestor();
	int m, last=1;
	long long wynik=0;
	cin>>m;
	while(m--)
	{
		int test, gdzie;
		cin>>test;
		gdzie = lca(last, test);
		if(!gdzie) gdzie=1;
		wynik+=((gleb[last]-gleb[gdzie])+(gleb[test]-gleb[gdzie]));
		last=test;
	}
	cout<<wynik;
	return 0;
}
