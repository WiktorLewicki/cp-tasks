#include <bits/stdc++.h>
using namespace std;
bitset<200>odw[200];
int tury[200][200], n, m;
bool is_valid(pair<int, int> x) {
  return 0 < x.first && x.first <= n && 0 < x.second && x.second <= m && !odw[x.first][x.second];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char pom;
			cin>>pom;
			if(pom=='1') odw[i][j] = true;
			else odw[i][j] = false;
		}
	}
	queue<pair<int,int>> order;
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++) if(odw[i][j]) order.push(make_pair(i, j));
	while (!order.empty()) {
		auto x = order.front();
		order.pop();
		
		for (auto v : {make_pair(x.first, x.second - 1), make_pair(x.first-1,x.second),make_pair(x.first,x.second+1),make_pair(x.first+1,x.second)}) {
			if (is_valid(v)) {
				tury[v.first][v.second] = tury[x.first][x.second] + 1;
				odw[v.first][v.second] = true;
				order.push(v);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=m;j++) cout<<tury[i][j]<<" ";
	 cout<<"\n";
	}

	return 0;
}
