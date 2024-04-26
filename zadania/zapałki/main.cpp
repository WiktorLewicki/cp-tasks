#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int tab[N], pref[N], suf[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, wynik= 1e9+5;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	 cin>>tab[i];
	 if(tab[i]) pref[i]=pref[i-1];
	 else pref[i]=pref[i-1]+1;
	}
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+tab[i];	
	for(int i=0;i<=n;i++) wynik=min(wynik, pref[i]+suf[i+1]);
	cout<<wynik;
	return 0;
}
