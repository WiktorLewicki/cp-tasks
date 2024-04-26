#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
vector<int> kraw[N];
int kub[N];
string A, B, S1, S2;
void dfs1(int x, int ojc){
	if(A[x]=='1') S1+='1';
	else S1+='0';
	for(auto v : kraw[x]){
		if(v==ojc) continue;
		dfs1(v, x);
	}
}
void dfs2(int x, int ojc){
	if(B[x]=='1') S2+='1';
	else S2+='0';
	for(auto v : kraw[x]){
		if(v==ojc) continue;
		dfs2(v, x);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		bool ok = false;
		cin>>n;
		A = ".", B = ".", S1 = ".", S2 = ".";
		string z;
		cin>>z;
		A+=z;
		cin>>z;
		B+=z;
		bool check0 = false, check1 = false, wz0 = false, wz1 = false;
		for(int i=1;i<=n;i++){
			if(A[i]=='0') check0 = true;
			else check1 = true;
			if(B[i]=='0') wz0 = true;
			else wz1 = true;
		}
		for(int i=0;i<=n+3;i++){
			kub[i]=0;
			kraw[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			int a, b;
			cin>>a>>b;
			kraw[a].pb(b);
			kraw[b].pb(a);
			kub[a]++;
			kub[b]++;
		}
		if((wz0&&!check0)||(wz1&&!check1)){
			cout<<"NIE\n";
			continue;
		}
		int wsk;
		for(int i=1;i<=n;i++){
			if(kub[i]==1) wsk=i;
			if(kub[i]>2){
				ok = true;
				cout<<"TAK\n";
				break;
			}
		}
		if(ok) continue;
		if(n==1){
			if(A!=B){
				cout<<"NIE\n";
				continue;
			}
			cout<<"TAK\n";
			continue;
		}
		dfs1(wsk, 0);
		dfs2(wsk, 0);
		if(S1==S2){
			cout<<"TAK\n";
			continue;
		}
		set<int> zera, jedynki;
		string COPY = S1;
		for(int i=1;i<=n;i++){
			if(S1[i]=='1') jedynki.insert(i);
			else zera.insert(i);
		}
		for(int i=1;i<=n;i++){
			if(i>1&&S1[i]!=S1[i-1]&&S1[i-1]==S2[i]){//////////
				if(S1[i-1]=='1'){
					S1[i]='1';
					zera.erase(i);
					jedynki.insert(i);
				}
				else{
					S1[i]='0';
					zera.insert(i);
					jedynki.erase(i);
				}
			}
			if(S1[i]==S2[i]) continue;
			if(S1[i]=='0'){
				auto pom = jedynki.upper_bound(i);
				if(pom==jedynki.end()){
					ok = true;
					break;
				}
				for(int j=i;j<*pom;j++){
					if(S1[j]=='1') continue;
					S1[j]='1';
					zera.erase(j);
					jedynki.insert(j);
				}
			}
			else{
				auto pom = zera.upper_bound(i);
				if(pom==zera.end()){
					ok = true;
					break;
				}
				for(int j=i;j<*pom;j++){
					if(S1[j]=='0') continue;
					S1[j]='0';
					jedynki.erase(j);
					zera.insert(j);
				}
			}
		}
		if(ok){
			ok = false;
			S1 = COPY;
			jedynki.clear();
			zera.clear();
			jedynki.insert(-1);
			zera.insert(-1);
			for(int i=1;i<=n;i++){
				if(S1[i]=='1') jedynki.insert(i);
				else zera.insert(i);
			}
			for(int i=n;i>=1;i--){
				if(i<n&&S1[i]!=S1[i+1]&&S1[i+1]==S2[i]){
					if(S1[i+1]=='1'){
						S1[i]='1';
						zera.erase(i);
						jedynki.insert(i);
					}
					else{
						S1[i]='0';
						zera.insert(i);
						jedynki.erase(i);
					}
				}
				if(S1[i]==S2[i]) continue;
				if(S1[i]=='0'){
					auto pom = jedynki.upper_bound(i);
					pom--;
					if(*pom==-1){
						ok = true;
						break;
					}
					for(int j=i;j>*pom;j--){
						if(S1[j]=='1') continue;
						S1[j]='1';
						zera.erase(j);
						jedynki.insert(j);
					}
				}
				else{
					auto pom = zera.upper_bound(i);
					pom--;
					if(*pom==-1){
						ok = true;
						break;
					}
					for(int j=i;j>*pom;j--){
						if(S1[j]=='0') continue;
						S1[j]='0';
						zera.insert(j);
						jedynki.erase(j);
					}
				}
			}
			if(ok){
				cout<<"NIE\n";
				continue;
			}
		}
		cout<<"TAK\n";
	}
	return 0;
}
