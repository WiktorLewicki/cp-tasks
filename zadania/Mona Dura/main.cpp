#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<pair<long long, pair<long long, long long>>> kamery;
vector<int> kraw[N];
bitset<N> odw;
void dfs(int x)
{
	odw[x] = true;
	for(auto v : kraw[x]) if(!odw[v]) dfs(v);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s;
	cin>>n>>m>>s;
	for(int i=0;i<s;i++)
	{
		int x, y, price;
		cin>>x>>y>>price;
		kamery.push_back(make_pair(price, make_pair(x, y)));
	}
	for(int i=0;i<s;i++)
	{
		for(int j=i+1;j<s;j++)
		{
			long long bok1_2 = kamery[i].second.first-kamery[j].second.first;
			long long bok1 = bok1_2 * bok1_2;
			long long bok2_2 = kamery[i].second.second-kamery[j].second.second;
			long long bok2 = bok2_2 * bok2_2;
			long long minimum = bok1 + bok2;
			long long ile_2 = kamery[i].first + kamery[j].first;
			long long ile = ile_2 * ile_2;
			if(ile>=minimum)
			{
				kraw[i].push_back(j);
				kraw[j].push_back(i);
			}
		}
	}
	for(int i=0;i<s;i++)
	{
		int w1 = kamery[i].second.first, w2 = kamery[i].first, w3 = kamery[i].second.second;
		if(w1-w2<=0||w3+w2>=m)
		{
			kraw[i].push_back(s+1);
			kraw[s+1].push_back(i);
		}
		if(w1+w2>=n||w3-w2<=0)
		{
			kraw[i].push_back(s+2);
			kraw[s+2].push_back(i);
		}
	}
	dfs(s+1);
	if(odw[s+2]) cout<<"N";
	else cout<<"S";
	return 0;
}
