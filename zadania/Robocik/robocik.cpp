#include <bits/stdc++.h>//jebac
#define ll long long
#define dl double long
using namespace std;
const int N = 1e5 + 5;
const ll ZERO=0;
bool jd;
ll tab[N], battery, cost, k1, k2, cnt, BYDGOSZCZ, zwrot, n;
pair<ll, ll> vec, pkt, save;
bool check(pair<ll, ll> a, pair<ll, ll>b){
	ll x=k1, y=k2;
	if(a.first==b.first){
		if(a.second>b.second) swap(a, b);
		ll odl_x = a.first-x;
		dl ss = (dl)odl_x/(dl)vec.first;
		if(ss>=0&&ss-(ll)ss==0){
			ll pom = y+(ll)ss*vec.second;
			if((ll)ss<cnt&&a.second<=pom&&pom<=b.second) return true;
		}
	}
	else{
		if(a.first>b.first) swap(a, b);
		ll odl_y = a.second-y;
		dl ss = (dl)odl_y/(dl)vec.second;
		if(ss>=0&&ss-(ll)ss==0){
			ll pom = x+(ll)ss*vec.first;
			if((ll)ss<cnt&&a.first<=pom&&pom<=b.first) return true;
		}
	}
	return false;
}
ll check1(pair<ll, ll> a, pair<ll, ll>b){
	ll x=k1, y=k2;
	if(a.first!=x) return 0;
	if(a.second>b.second) swap(a, b);
	if(vec.second<0){
		if(y<a.second) return 0;
		ll mx = y+vec.second*cnt, msc1, msc2;
		if(y>b.second){
			ll pom=b.second+1-y;
			pom=(pom/vec.second)+1;
			if(y+vec.second*pom<a.second) return 0;
			msc1=y+vec.second*pom;
		}
		else msc1=y;
		if(msc1<mx) return 0;
		ll odl=a.second-y;
		msc2=odl/vec.second;
		msc2=y+vec.second*msc2;
		msc2=max(msc2, mx);
		odl = msc2-msc1;
		odl=odl/vec.second;
		return odl+1;
	}
	else{
		if(y>b.second) return 0;
		ll mx = y+vec.second*cnt, msc1, msc2;
		if(y<a.second){
			ll pom=a.second-1-y;
			pom=(pom/vec.second)+1;
			if(y+vec.second*pom>b.second) return 0;
			msc1=y+vec.second*pom;
		}
		else msc1=y;
		if(msc1>mx) return 0;
		ll odl=b.second-y;
		msc2=odl/vec.second;
		msc2=y+vec.second*msc2;
		msc2=min(msc2, mx);
		odl = msc2-msc1;
		odl=odl/vec.second;
		return odl+1;
	}
}

ll check2(pair<ll, ll> a, pair<ll, ll>b){
	ll x=k1, y=k2;
	swap(x, y);
	if(a.second!=x) return 0;
	if(a.first>b.first) swap(a, b);
	if(vec.first<0){
		if(y<a.first) return 0;
		ll mx = y+vec.first*cnt, msc1, msc2;
		if(y>b.first){
			ll pom=b.first+1-y;
			pom=(pom/vec.first)+1;
			if(y+vec.first*pom<a.first) return 0;
			msc1=y+vec.first*pom;
		}
		else msc1=y;
		if(msc1<mx) return 0;
		ll odl=a.first-y;
		msc2=odl/vec.first;
		msc2=y+vec.first*msc2;
		msc2=max(msc2, mx);
		odl = msc2-msc1;
		odl=odl/vec.first;
		return odl+1;
	}
	else{
		if(y>b.first) return 0;
		ll mx = y+vec.first*cnt, msc1, msc2;
		if(y<a.first){
			ll pom=a.first-1-y;
			pom=(pom/vec.first)+1;
			if(y+vec.first*pom>b.first) return 0;
			msc1=y+vec.first*pom;
		}
		else msc1=y;
		if(msc1>mx) return 0;
		ll odl=b.first-y;
		msc2=odl/vec.first;
		msc2=y+vec.first*msc2;
		msc2=min(msc2, mx);
		odl = msc2-msc1;
		odl=odl/vec.first;
		return odl+1;
	}
}
bool spr(pair<int, int>a, pair<int, int> b){
	if(a.first==b.first){
		if(k1!=a.first) return false;
		if(a.second>b.second) swap(a, b);
		if(a.second<=k2&&k2<=b.second) return true;
	}
	else{
		if(k2!=a.second) return false;
		if(a.first>b.first) swap(a, b);
		if(a.first<=k1&&k1<=b.first) return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>battery;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
		cost+=tab[i];
	}
	cost+=n;
	cin>>k1>>k2;
	if(n%4==0){
		cnt=battery/cost;
		battery-=cnt*cost;
		for(int i=1;i<=n;i++){
			if(!zwrot) pkt.second+=tab[i];
			else if(zwrot==1) pkt.first+=tab[i];
			else if(zwrot==2) pkt.second-=tab[i];
			else pkt.first-=tab[i];
			zwrot++;
			if(zwrot==4) zwrot=0;
		}
		zwrot=0;
		vec=pkt;
		save = {vec.first*cnt, vec.second*cnt};
		vec = {-vec.first, -vec.second};
		pkt={0, 0};
		if(vec.first&&vec.second){
			for(int i=1;i<=n;i++){
				if(!zwrot){
					if(check(pkt, {pkt.first, pkt.second+tab[i]-1})) BYDGOSZCZ++;
					pkt.second+=tab[i];
				}
				else if(zwrot==1){
					if(check(pkt, {pkt.first+tab[i]-1, pkt.second})) BYDGOSZCZ++;
					pkt.first+=tab[i];
				}
				else if(zwrot==2){
					if(check(pkt, {pkt.first, pkt.second-tab[i]+1})) BYDGOSZCZ++;
					pkt.second-=tab[i];
				}
				else{
					if(check(pkt, {pkt.first-tab[i]+1, pkt.second})) BYDGOSZCZ++;
					pkt.first-=tab[i];
				}
				zwrot++;
				if(zwrot==4) zwrot=0;
			}
		}
		else if(!vec.first&&vec.second){
			for(int i=1;i<=n;i++){
				if(!zwrot){
					ll help = check1(pkt, {pkt.first, pkt.second+tab[i]-1});
					BYDGOSZCZ+=help;
					pkt.second+=tab[i];
				}
				else if(zwrot==1){
					BYDGOSZCZ+=check(pkt, {pkt.first+tab[i]-1, pkt.second});
					pkt.first+=tab[i];
				}
				else if(zwrot==2){
					ll help = check1(pkt, {pkt.first, pkt.second-tab[i]+1});
					BYDGOSZCZ+=help;
					pkt.second-=tab[i];
				}
				else{
					BYDGOSZCZ+=check(pkt, {pkt.first-tab[i]+1, pkt.second});
					pkt.first-=tab[i];
				}
				zwrot++;
				if(zwrot==4) zwrot=0;
			}
		}
		else if(vec.first&&!vec.second){
			for(int i=1;i<=n;i++){
				if(!zwrot){
					BYDGOSZCZ+=check(pkt, {pkt.first, pkt.second+tab[i]-1});
					pkt.second+=tab[i];
				}
				else if(zwrot==1){
					ll help = check2(pkt, {pkt.first+tab[i]-1, pkt.second});
					BYDGOSZCZ+=help;
					pkt.first+=tab[i];
				}
				else if(zwrot==2){
					BYDGOSZCZ+=check(pkt, {pkt.first, pkt.second-tab[i]+1});
					pkt.second-=tab[i];
				}
				else{
					ll help = check2(pkt, {pkt.first-tab[i]+1, pkt.second});
					BYDGOSZCZ+=help;
					pkt.first-=tab[i];
				}
				zwrot++;
				if(zwrot==4) zwrot=0;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(!zwrot){
					BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second+tab[i]-1});
					pkt.second+=tab[i];
				}
				else if(zwrot==1){
					BYDGOSZCZ+=spr(pkt, {pkt.first+tab[i]-1, pkt.second});
					pkt.first+=tab[i];
				}
				else if(zwrot==2){
					BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second-tab[i]+1});
					pkt.second-=tab[i];
				}
				else{
					BYDGOSZCZ+=spr(pkt, {pkt.first-tab[i]+1, pkt.second});
					pkt.first-=tab[i];
				}
				zwrot++;
				if(zwrot==4) zwrot=0;
			}
			BYDGOSZCZ*=cnt;
		}
		zwrot=0;
	}
	else if(n%2==0){
		cnt=battery/(2*cost);
		battery-=cnt*cost*2;
		for(int i=1;i<=n;i++){
			if(!zwrot){
				BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second+tab[i]-1});
				pkt.second+=tab[i];
			}
			else if(zwrot==1){
				BYDGOSZCZ+=spr(pkt, {pkt.first+tab[i]-1, pkt.second});
				pkt.first+=tab[i];
			}
			else if(zwrot==2){
				BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second-tab[i]+1});
				pkt.second-=tab[i];
			}
			else{
				BYDGOSZCZ+=spr(pkt, {pkt.first-tab[i]+1, pkt.second});
				pkt.first-=tab[i];
			}
			zwrot++;
			if(zwrot==4) zwrot=0;
			if(jd&&i==n) break;
			if(i==n){
				jd=true;
				zwrot=2;
				i=0;
			}
		}
		BYDGOSZCZ*=cnt;
	}
	else{
		int ile=0;
		cnt=battery/(4*cost);
		battery-=cnt*cost*4;
		for(int i=1;i<=n;i++){
			if(!zwrot){
				BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second+tab[i]-1});
				pkt.second+=tab[i];
			}
			else if(zwrot==1){
				BYDGOSZCZ+=spr(pkt, {pkt.first+tab[i]-1, pkt.second});
				pkt.first+=tab[i];
			}
			else if(zwrot==2){
				BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second-tab[i]+1});
				pkt.second-=tab[i];
			}
			else{
				BYDGOSZCZ+=spr(pkt, {pkt.first-tab[i]+1, pkt.second});
				pkt.first-=tab[i];
			}
			zwrot++;
			if(zwrot==4) zwrot=0;
			if(ile==3&&i==n) break;
			if(i==n){
				ile++;
				i=0;
			}
		}
		BYDGOSZCZ*=cnt;
	}
	zwrot=0;
	pkt=save;
	int ile=0;
	for(int i=1;i<=n;i++){
		if(!zwrot){
			if(tab[i]>battery){
				battery=max(ZERO, battery);
				BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second+battery});
				break;
			}
			BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second+tab[i]-1});
			pkt.second+=tab[i];
			battery-=tab[i];
		}
		else if(zwrot==1){
			if(tab[i]>battery){
				battery=max(ZERO, battery);
				BYDGOSZCZ+=spr(pkt, {pkt.first+battery, pkt.second});
				break;
			}
			BYDGOSZCZ+=spr(pkt, {pkt.first+tab[i]-1, pkt.second});
			pkt.first+=tab[i];
			battery-=tab[i];
		}
		else if(zwrot==2){
			if(tab[i]>battery){
				battery=max(ZERO, battery);
				BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second-battery});
				break;
			}
			BYDGOSZCZ+=spr(pkt, {pkt.first, pkt.second-tab[i]+1});
			pkt.second-=tab[i];
			battery-=tab[i];
		}
		else{
			if(tab[i]>battery){
				battery=max(ZERO, battery);
				BYDGOSZCZ+=spr(pkt, {pkt.first-battery, pkt.second});
				break;
			}
			BYDGOSZCZ+=spr(pkt, {pkt.first-tab[i]+1, pkt.second});
			pkt.first-=tab[i];
			battery-=tab[i];
		}
		zwrot++;
		battery--;
		if(zwrot==4) zwrot=0;
		if(ile==3&&i==n) break;
		if(i==n){
			ile++;
			i=0;
		}
	}
	cout<<BYDGOSZCZ;
	return 0;
}
