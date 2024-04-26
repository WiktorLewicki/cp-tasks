#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
vector<int> kraw[N];
bitset<N> odw[N][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a1, a2;
	cin>>n>>m>>a1>>a2;
	while(m--)
	{
		int a, b;
		cin>>a>>b;
		kraw[a].push_back(b);
	}
	
	queue<pair<pair<bool, int>, pair<int, int>>> order;
	order.push(make_pair(make_pair(false, 0), make_pair(a1, a2)));
	odw[a1][a2][0] = true;
	while(!order.empty())
	{
		auto x = order.front();
		order.pop();
		if(!x.first.first)
		{
			for(auto v : kraw[x.second.first])
			{
				if(!odw[v][1][x.second.second])
				{
					order.push(make_pair(make_pair(true, x.first.second + 1), make_pair(v, x.second.second)));
					odw[v][1][x.second.second] = true;
				}
			}
		}
		else
		{
			for(auto v: kraw[x.second.second])
			{
				if(!odw[x.second.first][0][v])
				{
					order.push(make_pair(make_pair(false, x.first.second + 1), make_pair(x.second.first, v)));
					odw[x.second.first][0][v] = true;
					if(x.second.first == v)
					{
						cout<<(x.first.second+1)/2;
						return 0;
					}
					
				}
			}	
		}
	}
	cout<<"NIE";
	return 0;
}
