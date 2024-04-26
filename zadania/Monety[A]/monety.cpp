#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll pref[N];
map<ll, int> spr;
int ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	string S;
	cin>>S;
	for(int i=0;i<n;i++){;
		if(S[i]=='O') pref[i+1]=1;
		else pref[i+1]=-k;
		pref[i+1]+=pref[i];
	}
	spr[0]=0;
	for(int i=1;i<=n;i++){
		auto it = spr.find(pref[i]);
		if(it!=spr.end()){
			ans=max(ans, i-(*it).second);
		}	
		else{
			spr[pref[i]]=i;
		}
	}
	cout<<ans;
	return 0;
}
