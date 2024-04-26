#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define int long long
using namespace std;
const int N = 3e5 + 5;
const int pomx = 1;
pair<int, int> info[N];
ll push[N], TEL[N], push_c[N], pref[N], push_m[N];
long double ans;
vector<array<int, 3>> update;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	const int pierw = sqrt(m);
	int lic=0;
	while(m--){
		char c;
		cin>>c;
		if(c=='P'){
			int a, b, c;
			cin>>a>>b>>c;
			update.pb({a, b, c});
			lic++;
		}
		else if(c=='U'){
			int a;
			cin>>a;
			update.pb({0, 0, a});
			lic++;
		}
		else{
			int a, b;
			cin>>a>>b;
			ans=pref[b]-pref[a-1];
			for(auto v : update){
				if(v[0]){
					info[v[0]]={v[1], v[2]};
					int range = v[1]/v[2] - (v[1]%v[2]==0);
					ll b1 = max(pomx, v[0]-range), b2 = min(n, v[0]+range);
					ll pom1 = max(b1, (ll)a);
					ll pom2 = min(v[0], (ll)b);
					if(pom1<=pom2){
						long double help = (v[1]-(v[0]-pom1)*v[2])+(v[1]-(v[0]-pom2)*v[2]);
						help/=(2.0);
						help*=(pom2-pom1+1);
						ans+=help;
					}
					pom1 = max(a, v[0]+1);
					pom2 = min(b, b2);
					if(pom1<=pom2){
						long double help = (v[1]-(pom1-v[0])*v[2])+(v[1]-(pom2-v[0])*v[2]);
						help/=(2.0);
						help*=(pom2-pom1+1);
						ans+=help;
					}
				}
				else{
					v[0]=v[2];
					v[1]=info[v[0]].first;
					v[2]=info[v[0]].second;
					int range = v[1]/v[2] - (v[1]%v[2]==0);
					ll b1 = max(pomx, v[0]-range), b2 = min(n, v[0]+range);
					ll pom1 = max(b1, (ll)a);
					ll pom2 = min(v[0], (ll)b);
					if(pom1<=pom2){
						long double help = (v[1]-(v[0]-pom1)*v[2])+(v[1]-(v[0]-pom2)*v[2]);
						help/=(2.0);
						help*=(pom2-pom1+1);
						ans-=help;
					}
					pom1 = max(a, v[0]+1);
					pom2 = min(b, b2);
					if(pom1<=pom2){
						long double help = (v[1]-(pom1-v[0])*v[2])+(v[1]-(pom2-v[0])*v[2]);
						help/=(2.0);
						help*=(pom2-pom1+1);
						ans-=help;
					}
				}
			}
			ans/=(b-a+1);
			cout<<(ll)ans<<"\n";
		}
		if(lic==pierw){
			lic=0;
			vector<pair<int, ll>> pom1, pom2;
			for(auto v : update){
				if(v[0]){
					info[v[0]]={v[1], v[2]};
					int range = v[1]/v[2] - (v[1]%v[2]==0);
					int b1 = max(pomx, v[0]-range), b2 = min(n, v[0]+range);
					push_c[b1]+=v[1];
					push_c[b2+1]-=v[1];
					push[v[0]+1]-=v[2];
					push[b2+1]+=v[2];
					pom1.pb({b2+1, (ll)v[2]*(b2-v[0])});
					push_m[v[0]-1]-=v[2];
					push_m[b1-1]+=v[2];
					pom2.pb({b1-1, v[2]*(v[0]-b1)});
				}
				else{
					v[0]=v[2];
					v[1]=info[v[0]].first;
					v[2]=info[v[0]].second;
					int range = v[1]/v[2] - (v[1]%v[2]==0);
					int b1 = max(pomx, v[0]-range), b2 = min(n, v[0]+range);
					push_c[b1]-=v[1];
					push_c[b2+1]+=v[1];
					push[v[0]+1]+=v[2];
					push[b2+1]-=v[2];
					pom1.pb({b2+1, -((ll)v[2]*(b2-v[0]))});
					push_m[v[0]-1]+=v[2];
					push_m[b1-1]-=v[2];
					pom2.pb({b1-1, -(v[2]*(v[0]-b1))});
				}
			}
			for(int i=1;i<=n;i++){
				push[i]+=push[i-1];
			}
			for(int i=n;i>=1;i--){
				push_m[i]+=push_m[i+1];
			}
			for(auto v : pom1){
				push[v.first]+=v.second;
			}
			for(auto v : pom2){
				push_m[v.first]+=v.second;
			}
			for(int i=n;i>=1;i--){
				push_m[i]+=push_m[i+1];
			}
			for(int i=1;i<=n;i++){
				push_c[i]+=push_c[i-1];
				push[i]+=push[i-1];
				TEL[i]+=push[i];
				TEL[i]+=push_c[i];
				TEL[i]+=push_m[i];
				pref[i]=pref[i-1]+TEL[i];
			}
			for(int i=1;i<=n;i++){
				push[i]=push_c[i]=push_m[i]=0;
			}
			update.clear();
		}
	}
	return 0;
}
