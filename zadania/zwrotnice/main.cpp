#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> tab[N];
bitset<N> odw;
int tury[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, A, y;
	cin>>n>>A>>y;
	for(int i=1;i<=n;i++)
	{
		int a, b;
		cin>>a>>b;
		tab[i].push_back(make_pair(a, 0));
		tab[i].push_back(make_pair(b, 1));
	}
	priority_queue<pair<int, int>> order;
	order.push(make_pair(0, A));
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
			for(auto v : tab[x.first])	order.push(make_pair((x.second+v.second)*-1, v.first));	
		}
	}
	if(!odw[y]) cout<<"BRAK";
	else cout<<tury[y];
	return 0;
}
