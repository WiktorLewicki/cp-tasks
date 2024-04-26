#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, lic=0;
		cin>>n;
		string S = ".";
		vector<pair<int, pair<int, int>>> kl;
		string pom;
		cin>>pom;
		S+=pom;
		bool ok=true;
		for(int i=0;i<=n;i++){
			if(pom[i]=='1'){
				ok=false;
				lic++;
			}
		}
		if(ok){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		ok = false;
		for(int i=1;i<=n;i++){
			if(S[i]=='1'){
				ok = true;
			}
			if(ok){
				if(S[i]=='0') cnt++;
				else if(cnt!=0){
					kl.pb({cnt/2+(cnt%2),{-2,cnt}});
					cnt=0;
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(S[i]=='1') break;
			cnt++;
		}
		if(cnt) kl.pb({cnt,{-1,cnt}});
		cnt=0;
		for(int i=n;i>=1;i--){
			if(S[i]=='1') break;
			cnt++;
		}
		if(cnt) kl.push_back({cnt,{-1,cnt}});
		sort(kl.rbegin(), kl.rend());
		cnt=0;
		for(auto ciag : kl){
			if(ciag.first<=cnt){
				lic+=ciag.second.second;
				continue;
			}
			lic+=cnt*(ciag.second.first*-1);
			if(ciag.second.first==-2){
				if(cnt==ciag.first-1){
					cnt++;
					if(!(ciag.second.second%2)){
						lic++;
					}
				}
				else{
					cnt+=2;
					lic++;
				}
				continue;
			}
			cnt++;
		}
		cout<<lic<<"\n";
	}
	return 0;
}
