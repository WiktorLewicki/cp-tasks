#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int wynik[N];
pair<int, int> tab[N];
deque<pair<int, int>> Q;
int daj_max()
{
	if(Q.empty()) return -1e9;
	return Q.front().first;
}
void dodaj_index(int x)
{
	while (!Q.empty() && Q.back().first <= tab[x].first) {
		Q.pop_back();
	}
	Q.push_back(make_pair(tab[x].first, x));
}
void usun_index(int x)
{
	if (!Q.empty() && Q.front().second == x) {
		Q.pop_front();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		tab[i] = make_pair(x, y);
	}
	Q.push_back(make_pair(tab[1].first, 1));
	int ans=0, wsk=1;
	wynik[0]=2;
	for(int i=1;i<=n;i++)
	{
		wynik[i]=wynik[i-1]-1;
		int temp = daj_max();
		while(wsk<n&&temp<=tab[wsk+1].second)
		{
			wsk++;
			dodaj_index(wsk);
			wynik[i]++;
			temp = max(temp, tab[wsk].first);
		}
		usun_index(i);
	}
	for(int i=1;i<=n;i++) ans = max(ans, wynik[i]);
	cout<<ans;
	return 0;
}
