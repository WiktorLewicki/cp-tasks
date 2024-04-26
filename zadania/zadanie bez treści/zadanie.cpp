#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int tab[N], rep[N];
int find_rep(int x){
	if(rep[x]==x) return x;
	rep[x] = find_rep(rep[x]);
	return rep[x];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>tab[i];
		rep[i]=i;
	}
	rep[n+1]=n+1;
	int q;
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		for(int i=a;i<=b;i++){
			i=find_rep(i);
			if(i>b) break;
			cout<<tab[rep[i]]<<" ";
			rep[i] = find_rep(i+1);
		}
		cout<<"\n";
	}
	return 0;
}
