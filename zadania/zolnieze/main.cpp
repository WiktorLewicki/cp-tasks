#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int tab[N], bat[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, wynik=0;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>tab[i]>>bat[i];
	sort(tab + 0, tab + n);
	sort(bat + 0, bat + n);
	for(int i=0;i<n;i++)
    {
    	if(tab[i]>bat[i])
    	{
    		cout<<"NIE";
    		return 0;
		}
		wynik+=(bat[i]-tab[i]);
	}
	cout<<wynik;
	return 0;
}
