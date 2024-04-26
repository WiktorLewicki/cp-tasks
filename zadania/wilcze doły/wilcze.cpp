#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int doly[N], dl, n;
long long worki, pref[N], desk[N];
deque<pair<long long, int>> Q;
long long daj_max()
{
	if(Q.empty()) return -1e9;
	return Q.front().first;
}
void dodaj_index(int x)
{
	while(!Q.empty()&&Q.back().first<=desk[x]){
		Q.pop_back();
	}
	Q.push_back(make_pair(desk[x], x));
}
void usun_index(int x)
{
	if (!Q.empty() && Q.front().second == x) {
		Q.pop_front();
	}
}
bool czy_dobra(int beg, int end)
{
	long long wyn = pref[end]-pref[beg-1];
	long long deska = max(daj_max(), desk[end-dl+1]);
	if(worki>=wyn-deska) return true;
	else return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>worki>>dl;
	for(int i=1;i<=n;i++)
	{
		cin>>doly[i];
		pref[i]=pref[i-1]+doly[i];
	}
	for(int i=1;i<=n-dl+1;i++) desk[i] = pref[i+dl-1]-pref[i-1];
	int wynik=dl, wsk=dl;
	dodaj_index(1);
	for(int i=1;i<=n-dl;i++)
	{
		while(wsk<n&&czy_dobra(i, wsk+1))
		{
			wsk++;
			dodaj_index(wsk-dl+1);
		}
		wynik = max(wynik, wsk-i+1);
		usun_index(i);
	}
	cout<<wynik;
	return 0;
}
