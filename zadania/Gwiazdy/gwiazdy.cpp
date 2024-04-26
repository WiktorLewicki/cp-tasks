#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
bitset<N> tab;
int in[N][2], border1, border2, n, s;
long long ans;
vector<int> odp;
void right(int ile){
	stack<int> S;
	for(int i=border2-1;i>=border2-ile;i--){
		if(i==s){
			ile++;
			continue;
		}
		S.push(i);
	}
	border2-=ile;
	while(!S.empty()){
		odp.push_back(S.top());
		S.pop();
	}
}
void left(int ile){
	stack<int>S;
	for(int i=border1+1;i<=border1+ile;i++){
		if(i==s){
			ile++;
			continue;
		}
		S.push(i);
	}
	border1+=ile;
	while(!S.empty()){
		odp.push_back(S.top());
		S.pop();
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	border2=n+1;
	for(int i=1;i<=n-1;i++){
		int a, b;
		cin>>a>>b;
		in[i][0]=a;
		in[i][1]=b;
		if(a<b){
			tab[i] = false;
		}
		else{
			tab[i] = true;
		}
	}
	if(s==1){
		tab[1]=true;
		in[1][0]=2e9-1;
	}
	else if(s==n){
		tab[1] = false;
		in[n][1]=2e9-1;
	}
	int ile=1;
	for(int i=2;i<=n-1;i++){
		if(tab[1]!=tab[i]) break;
		ile++;
	}
	if(!tab[1]&&ile>=s){
		int mi=2e9, idx=1;
		for(int i=1;i<=min(ile, s);i++){
			if(in[i][1]-in[i][0]<mi){
				mi=in[i][1]-in[i][0];
				idx=i;
			}
		}
		tab[idx]=!tab[idx];
	}
	else if(tab[1]&&n-s<ile){
		int mi=2e9, idx=1;
		for(int i=1;i<=min(ile, n-s+1);i++){
			if(in[i][0]-in[i][1]<mi){
				mi=in[i][0]-in[i][1];
				idx=i;
			}
		}
		tab[idx]=!tab[idx];
	}
	odp.push_back(s);
	for(int i=1;i<=n-1;i++){
		int cnt=1;
		while(tab[i]==tab[i+cnt]&&i+cnt<n) cnt++;
		if(tab[i]){
			right(cnt);
		}
		else{
			left(cnt);
		}
		i+=cnt-1;
	}
	for(int i=1;i<=n-1;i++){
		if(odp[i]>s) ans+=in[i][1];
		else ans+=in[i][0];
		s=odp[i];
	}
	cout<<ans<<"\n";
	for(auto v : odp) cout<<v<<" ";
	
	return 0;
}
