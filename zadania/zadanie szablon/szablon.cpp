#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const int MOD = 1e9 + 207;
const int st = 37;
int p[N], push[N];
vector<int> pref;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string S = ".", z;
	cin>>z;
	int n = z.size();
	S+=z;
	z=".";
	for(int i=2;i<=n;i++){
		int prefiks = p[i-1];
		while(prefiks>0&&S[prefiks+1]!=S[i]) prefiks=p[prefiks];
		if(S[prefiks+1]==S[i]) prefiks++;
		p[i]=prefiks;
	}
	int prefiks=p[n];
	pref.pb(prefiks);
	while(p[prefiks]){
		prefiks=p[prefiks];
		pref.pb(prefiks);
	}
	reverse(pref.begin(), pref.end());
	int limit=0;
	for(int i=1;i<=n;i++){
		cout<<p[i]<<" ";
	}
	exit(0);
	for(auto v : pref){
		if(v<limit) continue;
		for(int i=0;i<=n;i++){
			push[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(p[i]==v){
				push[i+1]--;
				push[i-v]++;
			}
		}
		bool ok = false;
		//cout<<v<<"\n";
		for(int i=1;i<=n;i++){
			push[i]+=push[i-1];
			//cout<<push[i]<<" ";
			if(push[i]<1){
				limit=v*2;
				ok = true;
				//break;
			}
		}
	//	cout<<"\n";
		if(ok) continue;
		cout<<v;
		return 0;
	}
	cout<<n;
	return 0;
}
