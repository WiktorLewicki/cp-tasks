#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 4e4 + 5;
vector<int> kraw[N];
bitset<N> odw;
int tury[N][2], lic1, lic2, sr1, sr2;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	queue<int> order;
	order.push(1);
	odw[1] = true;
	while(!order.empty()){
		auto x = order.front();
		order.pop();
		for(auto v : kraw[x]){
			if(!odw[v]){
				tury[v][0]=tury[x][0]+1;
				if(tury[v][0]==1) lic1++;
				if(tury[v][0]==2) sr1++;
				odw[v]=true;
				order.push(v);
			}
		}
	}
	odw.reset();
	order.push(2);
	odw[2] = true;
	while(!order.empty()){
		auto x = order.front();
		order.pop();
		for(auto v : kraw[x]){
			if(!odw[v]){
				tury[v][1]=tury[x][1]+1;
				if(tury[v][1]==1) lic2++;
				if(tury[v][1]==2) sr2++;
				odw[v]=true;
				order.push(v);
			}
		}
	}
	int a=lic1, b=sr1, c=lic2, d=sr2;
	long long ans=-m;
	int pom=n-a-b-c-d-2;
	if(a>c) b+=pom;
	else d+=pom;
	ans+=a;
	ans+=a*b;
	for(int i=1;i<=a-1;i++) ans+=i;
	ans+=b*d;
	for(int i=1;i<=b-1;i++) ans+=i;
	ans+=c*d;
	for(int i=1;i<=c-1;i++) ans+=i;
	ans+=c;
	for(int i=1;i<=d-1;i++) ans+=i;
	cout<<ans;
	return 0;
}
