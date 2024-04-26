#include <bits/stdc++.h>
using namespace std;
const int N = 15e3 + 5;
int tab[N][2], dp[N][2], rmb[N], idx[N][2];
map<int, int> po;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tab[i][0];
		idx[i][0]=po[tab[i][0]];
		po[tab[i][0]]=i;
	}
	po.clear();
	for(int i=1;i<=m;i++){
		cin>>tab[i][1];
		idx[i][1]=po[tab[i][1]];
		po[tab[i][1]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[j][0]=dp[j][1];
		}
		for(int j=1;j<=m;j++){
			dp[j][1]=max(dp[j-1][1], dp[j][0]);
			if(tab[i][0]==tab[j][1]&&idx[j][1]&&idx[i][0]){
				dp[j][1]=max(dp[j][1], rmb[idx[j][1]]+2);
			}
		}
		for(int j=1;j<=m;j++){
			if(tab[i][0]==tab[j][1]){
				rmb[j]=dp[j-1][0];
			}
		}
	}
	cout<<dp[m][1];
	return 0;
}
