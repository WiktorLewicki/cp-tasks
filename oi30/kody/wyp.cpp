//Autor: Wiktor Lewicki
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
pair<ll, ll> odejmij(ll a1, ll b1, ll a2, ll b2){
	a1*=b2;
	a2*=b1;
	a1-=a2;
	return {a1, b1*b2};
}
struct ulamek{
    ll c;
	ll a, b;
	ulamek operator / (const ulamek ul) const{
	    ll pom=c*ul.b;
        ll dz=pom/ul.a;
        pom-=dz*ul.a;
        if(pom==0){
            return {dz, 0, 1};
        }
		return {dz, pom, ul.a};
	}
	ulamek operator - (const ulamek ul) const{
		pair<ll, ll> p = odejmij(a, b, ul.a, ul.b);
		return {0, p.first, p.second};
	}
	bool operator < (const ulamek ul) const{
	    if(c==ul.c){
		    return (a*ul.b)<(ul.a*b);
	    }
	    return c < ul.c;
	}
};
int rep[N], rev[N];
int find_rep(int a){
	if(a==rep[a]){
		return a;
	}
	rep[a]=find_rep(rep[a]);
	return rep[a];
}
int find_rev(int a){
	if(a==rev[a]){
		return a;
	}
	rev[a]=find_rev(rev[a]);
	return rev[a];
}
void union_rep(int a, int b){
	a=find_rep(a);
	b=find_rep(b);
	rep[a]=b;
}
void union_rev(int a, int b){
	a=find_rev(a);
	b=find_rev(b);
	rev[b]=a;
}
ll pos[N][2], pref[N], dl[N];
ulamek speed[N], czas[N], akt[N];
set<pair<ulamek, int>> qr;
vector<pair<ulamek, int>> V;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, D, W, M;
	cin>>n>>D>>W>>M;
	ulamek fast={0, W, M};
	for(int i=1;i<=n;i++){
		rep[i]=i;
		rev[i]=i;
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		pos[i][0]=a;
		pos[i][1]=b;
		dl[i]=pos[i][1];
		speed[i]={0, c, d};
		if(i>1){
			pref[i]=pref[i-1]+pos[i][0]-pos[i][1]-pos[i-1][0];
		}
	}
	for(int i=1;i<=n-1;i++){
		if(speed[i+1]<speed[i]){
			ulamek dr = {pos[i+1][0]-pos[i+1][1]-pos[i][0], 0, 1};
			ulamek ins = dr/(speed[i]-speed[i+1]);
			qr.insert({ins, i});
			akt[i]=ins;
		}
	}
	while(!qr.empty()){
		auto it = qr.begin();
		qr.erase(it);
		pair<ulamek, int> war = *it;
		V.pb(war);
		czas[war.second]=war.first;
		int idx=war.second;
		union_rep(idx, idx+1);
		union_rev(idx, idx+1);
		find_rep(idx);
		find_rev(idx+1);
		if(rev[idx]>1&&speed[rep[idx]]<speed[rev[idx]-1]){
			if(akt[rev[idx]-1].b!=0){
				qr.erase({akt[rev[idx]-1], rev[idx]-1});
			}
			ulamek dr = {pref[rep[idx]]-pref[rev[idx]-1], 0, 1};
			ulamek ins = dr/(speed[rev[idx]-1]-speed[rep[idx]]);
			qr.insert({ins, rev[idx]-1});
			akt[rev[idx]-1]=ins;
		}
	}
	for(int i=1;i<=n;i++){
		rep[i]=i;
	}
	int ans=1, wsk=0;
	for(int i=1;i<=n-1;i++){
		ulamek dr = {pos[i][0]+D, 0, 1};
		ulamek jump = dr/(fast-speed[i]);
		if(czas[i].b!=0&&czas[i]<jump){
			continue;
		}
		while(wsk<(int)V.size()&&V[wsk].first<jump){
			int idx=V[wsk].second;
			union_rep(idx, idx+1);
			find_rep(idx);
			dl[rep[idx]]+=dl[idx];
			wsk++;
		}
		find_rep(i+1);
		dr={pos[rep[i+1]][0]-dl[rep[i+1]], 0, 1};
		ulamek pos2=dr/(fast-speed[rep[i+1]]);
		if((pos2<jump)==false){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
