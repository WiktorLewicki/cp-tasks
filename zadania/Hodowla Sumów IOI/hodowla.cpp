#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const long long LL = 1e18;
ll ans;
map<ll, ll> dp[N][2];
vector<pair<ll, ll>> pref[N];
vector<int> wys[N];
bool ok[N];
ll max_weights(int n, int m, vector<int>X, vector<int>Y, vector<int>Z){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		pref[X[i]].pb({Y[i], Z[i]});
		if(Y[i]==0) ok[X[i]]=true;
		wys[X[i]].pb(Y[i]);
	}
	for(int i = 0; i < n; ++i) {
        wys[i].pb(n);
        if(!ok[i]) wys[i].pb(0);
        sort(wys[i].begin(), wys[i].end());
    }
	for(int i=0;i<n;i++){
		sort(pref[i].begin(), pref[i].end());
		ll suma=0;
		for(int j=0;j<(int)pref[i].size();j++) {
            suma+=pref[i][j].second;
            pref[i][j].second = suma;
        }
        pref[i].insert(pref[i].begin(), make_pair(-1, 0));
	}
	for(int i=1;i<n;i++){
		vector<pair<ll, ll>> spr1, spr2;
		for(ll pom : wys[i-1]){
			dp[i][0][0]=max({dp[i][0][0], dp[i-1][0][pom], dp[i-1][1][pom]});
			dp[i][1][0]=max({dp[i][1][0], dp[i-1][0][pom], dp[i-1][1][pom]});
			ll res=0;
			if(!spr1.empty()) res=spr1.back().second;
			auto it = upper_bound(pref[i-1].begin(), pref[i-1].end(), make_pair(pom-1, LL));
			it--;
			res=max(res, dp[i-1][0][pom]-it->second);
			spr1.pb({pom, res});
		}
		reverse(wys[i-1].begin(), wys[i-1].end());
		for(ll pom : wys[i-1]){
			ll res=0;
			if(!spr2.empty()) res=spr2.back().second;
			auto it = upper_bound(pref[i].begin(), pref[i].end(), make_pair(pom-1, LL));
			it--;
			res = max(res, dp[i - 1][0][pom] + it->second);
            res = max(res, dp[i - 1][1][pom] + it->second);
            spr2.pb({pom, res});
		}
		reverse(spr2.begin(), spr2.end());
		for(ll pom : wys[i]){
			auto op1 = upper_bound(spr1.begin(), spr1.end(), make_pair(pom, LL));
			op1--;
			auto op2 = lower_bound(spr2.begin(), spr2.end(), make_pair(pom, -LL));
			auto tmp1 = upper_bound(pref[i-1].begin(), pref[i-1].end(), make_pair(pom-1, LL));
			tmp1--;
			dp[i][0][pom]=max(dp[i][0][pom], op1->second + tmp1->second);
			auto tmp2 = upper_bound(pref[i].begin(), pref[i].end(), make_pair(pom-1, LL));
			tmp2--;
			dp[i][1][pom]=max(dp[i][1][pom], op2->second - tmp2->second);
		}
	}
	for(int i=0;i<=n;i++){
		ans = max({ans, dp[n-1][0][i], dp[n-1][1][i]});
	}
	return ans;
}
