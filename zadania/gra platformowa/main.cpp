#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>hole[N];
vector<vector<pair<pair<int, int>, int>>> tab[N];
vector<int> tury[N];
vector<bool> odw[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, X, z;
	cin>>n>>X>>z;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		tab[i].emplace_back();
		tury[i].emplace_back();
		odw[i].emplace_back();
		for(int j=0;j<k;j++) 
		{
			int a;
			cin>>a;
			a--;
			
			hole[i].push_back(a);
			tab[i].emplace_back();
			tury[i].emplace_back();
			odw[i].emplace_back();
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(int)hole[i].size();j++)
		{
			tab[i][j+1].push_back(make_pair(make_pair(i, j), 1));
			if(i!=n-1)
			{
			auto iterator = lower_bound(hole[i+1].begin(), hole[i+1].end(), hole[i][j]);
			int index = iterator - hole[i+1].begin();
			tab[i+1][index].push_back(make_pair(make_pair(i, j), 0));
			}
		}
		if(!i) continue;
		for(int j=0;j<(int)hole[i-1].size();j++)
		{
			auto iterator = lower_bound(hole[i].begin(), hole[i].end(), hole[i-1][j]);
			int index = iterator - hole[i].begin();
			tab[i-1][j+1].push_back(make_pair(make_pair(i, index), 1));	
		}
	}
	deque<pair<pair<int, int>, int>>order;
	for(int i=0;i<n;i++)
	{
		order.push_back(make_pair(make_pair(i, hole[i].size()), 0));
	}
	while(!order.empty())
	{
		auto x = order.front();
		order.pop_front();
		if(!odw[x.first.first][x.first.second])
		{
			tury[x.first.first][x.first.second] = x.second;
			odw[x.first.first][x.first.second] = true;
			for(auto v : tab[x.first.first][x.first.second])
			{
				if(v.second) order.push_back(make_pair(make_pair(v.first.first, v.first.second), x.second+v.second));
				else order.push_front(make_pair(make_pair(v.first.first, v.first.second), x.second+v.second));
			}
		}
	}
	while(z--)
	{
		int test;
		cin>>test;
		cout<<tury[test-1][0]<<"\n";
	}
	return 0;
}
