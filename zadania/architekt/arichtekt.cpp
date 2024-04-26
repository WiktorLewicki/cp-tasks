#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<int, int> rep[N];
int ile[N];
long long pom;
int find_rep(int x){
	if(rep[x].first==x) return x;
	pom+=rep[x].second;
	return find_rep(rep[x].first);
}
void union_ver(int a, int b, int c){
	pom=0;
	a=find_rep(a);
	int pom1=pom;
	pom=0;
	b=find_rep(b);
	int pom2=pom;
	int price = pom1-pom2+c;
	if(ile[a]<ile[b]) {
		swap(a, b);
		price=-price;
	}
	ile[a]+=ile[b];
	rep[b] = make_pair(a, price);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, z;
	cin>>n>>z;
	for(int i=1;i<=n;i++) 
	{
		rep[i] = make_pair(i, 0);
		ile[i]=1;
	}
	for(int i=1;i<=z;i++){
		int a, b, c;
		cin>>a>>b>>c;
		if(find_rep(a)!=find_rep(b)){
			cout<<"TAK\n";
			union_ver(a, b, c);
		}
		else{
			pom=0;
			find_rep(a);
			long long suma1 = pom;
			pom = 0;
			find_rep(b);
			long long suma2 = pom;
			long long wynik = suma2-suma1;
			if(wynik==c) cout<<"TAK\n";
			else cout<<"NIE\n";
		}
	}
	return 0;
}
