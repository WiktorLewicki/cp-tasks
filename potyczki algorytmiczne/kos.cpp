#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long ans;
int tab[N], kub[N], ile;
bool cmp(int a, int b) {return a>b;}
vector<int> odl;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
		if(!kub[tab[i]]) ile++;
		kub[tab[i]]++;
	}
	if(ile<k){
		cout<<-1;
		return 0;
	}
	int wsk=1;
	for(int i=1;i<=n;i++) kub[i]=0;
	for(int i=1;i<=k;i++){
		if(!kub[tab[i]]){
			kub[tab[i]]++;
		}
		else{
			while(wsk<n&&kub[tab[wsk]]) wsk++;
			kub[tab[wsk]]++;
			ans+=wsk-i;
		}
	}
	cout<<ans;
	return 0;
}
