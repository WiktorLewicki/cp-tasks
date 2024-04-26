#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bitset<N> odw[N];
int tab[N][N], n, ans1, ans2;
bool czy_dobra(int x, int y, int ile, int akt){
	if(x>0&&x<=n&&y>0&&y<=n&&ile==akt&&!odw[x][y]){
		return true;
	}
	return false;
}
bool check(int x, int y){
	if(x>0&&x<=n&&y>0&&y<=n){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>tab[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(odw[i][j]) continue;
			queue<pair<int, int>> order;
			order.push({i, j});
			odw[i][j] = true;
			int mx=-1, mi=2e9;
			while(!order.empty()){
				auto x = order.front();
				order.pop();
				for(auto s : {make_pair(x.first-1, x.second-1), make_pair(x.first, x.second-1), make_pair(x.first-1, x.second), make_pair(x.first+1, x.second), make_pair(x.first, x.second+1), make_pair(x.first+1, x.second+1), make_pair(x.first-1, x.second+1), make_pair(x.first+1, x.second-1)}){
					if(check(s.first, s.second)){
						mi=min(tab[s.first][s.second], mi);
						mx=max(tab[s.first][s.second], mx);
					}
				}
				for(auto v : {make_pair(x.first-1, x.second-1), make_pair(x.first, x.second-1), make_pair(x.first-1, x.second), make_pair(x.first+1, x.second), make_pair(x.first, x.second+1), make_pair(x.first+1, x.second+1), make_pair(x.first-1, x.second+1), make_pair(x.first+1, x.second-1)} ){
					if(czy_dobra(v.first, v.second, tab[i][j], tab[v.first][v.second])){
						odw[v.first][v.second]=true;
						order.push({v.first, v.second});
						for(auto s : {make_pair(v.first-1, v.second-1), make_pair(v.first, v.second-1), make_pair(v.first-1, v.second), make_pair(v.first+1, v.second), make_pair(v.first, v.second+1), make_pair(v.first+1, v.second+1), make_pair(v.first-1, v.second+1), make_pair(v.first+1, v.second-1)}){
							if(check(s.first, s.second)){
								mi=min(tab[s.first][s.second], mi);
								mx=max(tab[s.first][s.second], mx);
							}
						}
					}
				}
			}
			if(mi==mx&&mx==tab[i][j]){
				ans1++;
				ans2++;
			}
			else if(mi<=tab[i][j]&&mx<=tab[i][j]) ans1++;
			else if(tab[i][j]<=mx&&tab[i][j]<=mi) ans2++;
		}
	}
	cout<<ans1<<" "<<ans2;
	
	
	return 0;
}
