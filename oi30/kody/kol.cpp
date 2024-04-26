//autor: Wiktor Lewicki
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
int m, pr, q;
int tab[N][N], moment[N][N];
vector<int> ans;
pair<int, int> pose={1, 1};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>pr>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			tab[i][j]=-1;
		}
	}
	for(int i=1;i<=pr;i++){
		int a, b, c;
		cin>>a>>b>>c;
		tab[a][b]=c;
	}
	ans.pb(-1);
	ans.pb(0);
	int dl=1, czas=1;
	moment[1][1]=1;
	while(q--){
		char c;
		cin>>c;
		moment[pose.first][pose.second]=czas;
		if(c=='P'){
			pose.second++;
		}
		else if(c=='L'){
			pose.second--;
			
		}
		else if(c=='G'){
			pose.first--;
			
		}
		else if(c=='D'){
			pose.first++;
			
		}
		if(c!='Z'){
			czas++;
			if(tab[pose.first][pose.second]!=-1){
				dl++;
				ans.pb(tab[pose.first][pose.second]);
				tab[pose.first][pose.second]=-1;
			}
		}
		else{
			int a, b;
			cin>>a>>b;
			if(!moment[a][b]){
				cout<<"-1\n";
				continue;
			}
			int pom=czas-moment[a][b]+1;
			if(pom>dl){
				cout<<"-1\n";
			}
			else{
				cout<<ans[dl-pom+1]<<"\n";
			}
		}
	}
	return 0;
}
