#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int tab[N][N], tury[N][N], n, m, ans;
bitset<N> color[N], odw[N];
vector<pair<int, int>> clean;
bool czy_dobra(int x, int y, int how, int lic){
	if(x>0&&x<=n&&y>0&&y<=m&&how>=lic){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>tab[i][j];
			if(tab[i][j]<0){
				tab[i][j]=-tab[i][j];
				color[i][j]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(color[i][j]||odw[i][j]) continue;
			priority_queue<pair<int, pair<int, int>>> order;
			//odw[i][j]=true;
			order.push({tab[i][j], {i, j}});
			int ma=-1;
			tury[i][j]=0;
			pair<int, int> pom;
			//cout<<i<<"   "<<j<<":\n";
			while(!order.empty()){
				auto x = order.top();
				clean.push_back({x.second.first, x.second.second});
				order.pop();
				if(tury[x.second.first][x.second.second]>=ma){
					ma=tury[x.second.first][x.second.second];
					pom = {x.second.first, x.second.second};
				}
				if(odw[x.second.first][x.second.second]) continue;
				odw[x.second.first][x.second.second]=true;
				for(auto v : {make_pair(x.second.first-1, x.second.second-1), make_pair(x.second.first, x.second.second-1), make_pair(x.second.first-1, x.second.second), make_pair(x.second.first+1, x.second.second), make_pair(x.second.first, x.second.second+1), make_pair(x.second.first+1, x.second.second+1), make_pair(x.second.first-1, x.second.second+1), make_pair(x.second.first+1, x.second.second-1)}){
					if(czy_dobra(v.first, v.second, tab[i][j], tab[v.first][v.second])){
						tury[v.first][v.second]=tury[x.second.first][x.second.second];
						if(!color[v.first][v.second]){
							tury[v.first][v.second]++;
						}
						order.push({tab[v.first][v.second], {v.first, v.second}});
					}
				}
			}
			for(auto v : clean){
				odw[v.first][v.second]=false;
			}
			/*for(int h=1;h<=n;h++){
				for(int p=1;p<=m;p++){
					cout<<odw[h][p]<<" ";
				}
				cout<<"\n";
			}*/
			clean.clear();
			order.push({-tab[pom.first][pom.second], {pom.first, pom.second}});
			while(!order.empty()){
				auto x = order.top();
				order.pop();
				if(odw[x.second.first][x.second.second]) continue;
				odw[x.second.first][x.second.second]=true;
				for(auto v : {make_pair(x.second.first-1, x.second.second-1), make_pair(x.second.first, x.second.second-1), make_pair(x.second.first-1, x.second.second), make_pair(x.second.first+1, x.second.second), make_pair(x.second.first, x.second.second+1), make_pair(x.second.first+1, x.second.second+1), make_pair(x.second.first-1, x.second.second+1), make_pair(x.second.first+1, x.second.second-1)}){
					if(czy_dobra(v.first, v.second, tab[v.first][v.second], tab[x.second.first][x.second.second])){
						order.push({-tab[v.first][v.second], {v.first, v.second}});
					}
				}
			}
			/*for(int d=1;d<=n;d++){
				for(int f=1;f<=m;f++){
					cout<<odw[d][f]<<" ";
					//cout<<d<<" "<<f<<"   ";
					//cout<<ojc[d][f].first<<" "<<ojc[d][f].second<<"\n";
				}
				cout<<"\n";
			}
			exit(0);*/
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
