#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> tab[N];
bitset<N> odw;
long long tury[N];
bitset<N> straz;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s, bubu;
	cin>>n>>m>>s;
	while(m--)
	{
		int a, b, temp;
		cin>>a>>b>>temp;
		tab[a].push_back(make_pair(b, temp));
		tab[b].push_back(make_pair(a, temp));	
	}
	while(s--)
	{
		int temp;
		cin>>temp;
		straz[temp] = true;
	}
	cin>>bubu;
	priority_queue<pair<long long, long long>> order;
	order.push(make_pair(0, 1));
	while(!order.empty())
	{
		auto x = order.top();
		swap(x.first, x.second);
		x.second*=-1;
		order.pop();
		if(!odw[x.first])
		{
			tury[x.first] = x.second;
			odw[x.first] = true;
			if(straz[x.first])
			{
				cout<<-1;
				return 0;
			}
			else if(x.first==bubu)
			{
				cout<<tury[bubu];
				return 0;
			}
			for(auto v : tab[x.first])	order.push(make_pair((x.second+v.second)*-1, v.first));	
		}
	}
	return 0;
}
