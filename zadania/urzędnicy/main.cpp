#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int wynik=0;
vector<int> kraw[N];
int potomkowie[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a;
		cin>>a;
		kraw[a].push_back(i+1);
	}
	for(int i=n;i>=1;i--)
	{
		int ile=1;
		for(auto v : kraw[i]) ile+=potomkowie[v];
		potomkowie[i]=ile;
		if(potomkowie[i]>1)
		{
			wynik++;
			potomkowie[i]-=2;
		}
	}
	cout<<wynik;
	return 0;
}
