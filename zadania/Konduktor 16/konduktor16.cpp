#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 6e2 + 5;
int sum[N][N];
ll pref[N][N], arr[3];
pair<ll, pair<int, int>> dp[N][60];
vector<int> ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, K;
	cin>>n>>K;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			int a;
			cin>>a;
			sum[i][i+j]-=a;
			sum[i][i]+=a;
		}
		for(int j=i;j<=n;j++){
			sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pref[i][j]=pref[i][j-1]+sum[j][i];
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int k=1;k<=min(K, i);k++){
			for(int j=k-1;j<=i-1;j++){
				if(dp[i][k].first < dp[j][k-1].first+pref[i][i]-pref[i][j]){
					dp[i][k]=max(dp[i][k], {dp[j][k-1].first+pref[i][i]-pref[i][j], {j, k-1}});
				}
				if(dp[i][k].first>=arr[0]&&k>=arr[2]){
					arr[0]=dp[i][k].first;
					arr[1]=i;
					arr[2]=k;
				}
			}
		}
	}
	ans.pb(arr[1]);
	pair<int, int> pom = {dp[arr[1]][arr[2]].second};
	while(pom.first){
		ans.pb(pom.first);
		pom = {dp[pom.first][pom.second].second};
	}
	reverse(ans.begin(), ans.end());
	for(auto v : ans){
		cout<<v<<" ";
	}
	return 0;
}
