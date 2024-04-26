#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
const int N = 1e3 + 5;
int pole[N][N], tury[N][N][7], dr[N][N], n;
pair<int, int> bomba[N][N][7], P, K;
bool odw[N][N][7], fin[N][N];
bool check(int x, int y){
	if(x<1||x>n||y<1||y>n||pole[x][y]==2) return false;
	return true;
}
bool spr(int x, int y, int ile){
	if(x<1||x>n||y<1||y>n||pole[x][y]||ile-dr[x][y]!=1) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string S;
		cin>>S;
		for(int j=0;j<n;j++){
			if(S[j]=='#') pole[i][j+1]=1;
			else if(S[j]=='X') pole[i][j+1]=2;
			else if(S[j]=='P') P={i, j+1};
			else if(S[j]=='K') K={i, j+1};
		}
	}
	queue<array<int, 5>> order;
	odw[P.ff][P.ss][0] = true;
	order.push({0, P.ff, P.ss, 0, 0});
	while(!order.empty()){
		auto x = order.front();
 		int i=x[1], j=x[2], b1=x[3], b2=x[4], type=x[0];
		order.pop();
		if(check(i-1, j)){
			int pom1=i-1, pom2=j;
			if(type==0){
				if(pole[pom1][pom2]==0&&!odw[pom1][pom2][0]){
					odw[pom1][pom2][0]=true;
					tury[pom1][pom2][0]=tury[i][j][0]+1;
					order.push({0, pom1, pom2, P.first, P.second});
					bomba[pom1][pom2][0]=P;
				}
				else if(!odw[pom1][pom2][1]){
					odw[pom1][pom2][1]=true;
					tury[pom1][pom2][1]=tury[i][j][0]+1;
					order.push({1, pom1, pom2, pom1, pom2});
					bomba[pom1][pom2][1]={pom1, pom2};
				}
			}
			if(type==1){
				if(!odw[pom1][pom2][2]){
					odw[pom1][pom2][2]=true;
					tury[pom1][pom2][2]=tury[i][j][1]+1;
					order.push({2, pom1, pom2, i, j});
					bomba[pom1][pom2][2]={i, j};
				}
			}
			if(type==2){
				if(!odw[pom1][pom2][2]){
					odw[pom1][pom2][2]=true;
					tury[pom1][pom2][2]=tury[i][j][2]+1;
					order.push({2, pom1, pom2, b1, b2});
					bomba[pom1][pom2][2]={b1, b2};
				}
			}
			if(type==3){
				if(!odw[pom1][pom2][5]){
					odw[pom1][pom2][5]=true;
					tury[pom1][pom2][5]=tury[i][j][3]+1;
					order.push({5, pom1, pom2, i, j});
					bomba[pom1][pom2][5]={i, j};
				}
			}
			if(type==4){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][4]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
			}
			if(type==5){
				if(!odw[pom1][pom2][5]){
					odw[pom1][pom2][5]=true;
					tury[pom1][pom2][5]=tury[i][j][5]+1;
					order.push({5, pom1, pom2, b1, b2});
					bomba[pom1][pom2][5]={b1, b2};
				}
			}
			if(type==6){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][6]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
				
			}
		}//////////////////
		if(check(i+1, j)){
			int pom1=i+1, pom2=j;
			if(type==0){
				if(pole[pom1][pom2]==0&&!odw[pom1][pom2][0]){
					odw[pom1][pom2][0]=true;
					tury[pom1][pom2][0]=tury[i][j][0]+1;
					order.push({0, pom1, pom2, P.first, P.second});
					bomba[pom1][pom2][0]=P;
				}
				else if(!odw[pom1][pom2][1]){
					odw[pom1][pom2][1]=true;
					tury[pom1][pom2][1]=tury[i][j][0]+1;
					order.push({1, pom1, pom2, pom1, pom2});
					bomba[pom1][pom2][1]={pom1, pom2};
				}
			}
			if(type==1){
				if(!odw[pom1][pom2][2]){
					odw[pom1][pom2][2]=true;
					tury[pom1][pom2][2]=tury[i][j][1]+1;
					order.push({2, pom1, pom2, i, j});
					bomba[pom1][pom2][2]={i, j};
				}
			}
			if(type==2){
				if(!odw[pom1][pom2][2]){
					odw[pom1][pom2][2]=true;
					tury[pom1][pom2][2]=tury[i][j][2]+1;
					order.push({2, pom1, pom2, b1, b2});
					bomba[pom1][pom2][2]={b1, b2};
				}
			}
			if(type==3){
				if(!odw[pom1][pom2][5]){
					odw[pom1][pom2][5]=true;
					tury[pom1][pom2][5]=tury[i][j][3]+1;
					order.push({5, pom1, pom2, i, j});
					bomba[pom1][pom2][5]={i, j};
				}
			}
			if(type==4){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][4]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
			}
			if(type==5){
				if(!odw[pom1][pom2][5]){
					odw[pom1][pom2][5]=true;
					tury[pom1][pom2][5]=tury[i][j][5]+1;
					order.push({5, pom1, pom2, b1, b2});
					bomba[pom1][pom2][5]={b1, b2};
				}
			}
			if(type==6){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][6]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
				
			}
		}//////////////////
		if(check(i, j-1)){
			int pom1=i, pom2=j-1;
			if(type==0){
				if(pole[pom1][pom2]==0&&!odw[pom1][pom2][0]){
					odw[pom1][pom2][0]=true;
					tury[pom1][pom2][0]=tury[i][j][0]+1;
					order.push({0, pom1, pom2, P.first ,P.second});
					bomba[pom1][pom2][0]=P;
				}
				else if(!odw[pom1][pom2][1]){
					odw[pom1][pom2][1]=true;
					tury[pom1][pom2][1]=tury[i][j][0]+1;
					order.push({1, pom1, pom2, pom1, pom2});
					bomba[pom1][pom2][1]={pom1, pom2};
				}
			}
			if(type==1){
				if(!odw[pom1][pom2][3]){
					odw[pom1][pom2][3]=true;
					tury[pom1][pom2][3]=tury[i][j][1]+1;
					order.push({3, pom1, pom2, i, j});
					bomba[pom1][pom2][3]={i, j};
				}
			}
			if(type==2){
				if(!odw[pom1][pom2][4]){
					odw[pom1][pom2][4]=true;
					tury[pom1][pom2][4]=tury[i][j][2]+1;
					order.push({4, pom1, pom2, i, j});
					bomba[pom1][pom2][4]={i, j};
				}
			}
			if(type==3){
				if(!odw[pom1][pom2][3]){
					odw[pom1][pom2][3]=true;
					tury[pom1][pom2][3]=tury[i][j][3]+1;
					order.push({3, pom1, pom2, b1, b2});
					bomba[pom1][pom2][3]={b1, b2};
				}
			}
			if(type==4){
				if(!odw[pom1][pom2][4]){
					odw[pom1][pom2][4]=true;
					tury[pom1][pom2][4]=tury[i][j][4]+1;
					order.push({4, pom1, pom2, b1, b2});
					bomba[pom1][pom2][4]={b1, b2};
				}
			}
			if(type==5){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][5]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
			}
			if(type==6){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][6]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
			}
		}///////
		if(check(i, j+1)){
			int pom1=i, pom2=j+1;
			if(type==0){
				if(pole[pom1][pom2]==0&&!odw[pom1][pom2][0]){
					odw[pom1][pom2][0]=true;
					tury[pom1][pom2][0]=tury[i][j][0]+1;
					order.push({0, pom1, pom2, P.first ,P.second});
					bomba[pom1][pom2][0]=P;
				}
				else if(!odw[pom1][pom2][1]){
					odw[pom1][pom2][1]=true;
					tury[pom1][pom2][1]=tury[i][j][0]+1;
					order.push({1, pom1, pom2, pom1, pom2});
					bomba[pom1][pom2][1]={pom1, pom2};
				}
			}
			if(type==1){
				if(!odw[pom1][pom2][3]){
					odw[pom1][pom2][3]=true;
					tury[pom1][pom2][3]=tury[i][j][1]+1;
					order.push({3, pom1, pom2, i, j});
					bomba[pom1][pom2][3]={i, j};
				}
			}
			if(type==2){
				if(!odw[pom1][pom2][4]){
					odw[pom1][pom2][4]=true;
					tury[pom1][pom2][4]=tury[i][j][2]+1;
					order.push({4, pom1, pom2, i, j});
					bomba[pom1][pom2][4]={i, j};
				}
			}
			if(type==3){
				if(!odw[pom1][pom2][3]){
					odw[pom1][pom2][3]=true;
					tury[pom1][pom2][3]=tury[i][j][3]+1;
					order.push({3, pom1, pom2, b1, b2});
					bomba[pom1][pom2][3]={b1, b2};
				}
			}
			if(type==4){
				if(!odw[pom1][pom2][4]){
					odw[pom1][pom2][4]=true;
					tury[pom1][pom2][4]=tury[i][j][4]+1;
					order.push({4, pom1, pom2, b1, b2});
					bomba[pom1][pom2][4]={b1, b2};
				}
			}
			if(type==5){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][5]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
			}
			if(type==6){
				if(!odw[pom1][pom2][6]&&pole[pom1][pom2]==0){
					odw[pom1][pom2][6]=true;
					tury[pom1][pom2][6]=tury[i][j][6]+1;
					order.push({6, pom1, pom2, b1, b2});
					bomba[pom1][pom2][6]={b1, b2};
				}
			}
		}///////
	}
	int ans=1e9, who=0;
	string droga="";
	for(int i=0;i<=6;i++){
		if(tury[K.first][K.second][i]&&tury[K.first][K.second][i]<ans){
			ans=tury[K.first][K.second][i];
			who=i;
		}
	}
	int bomb1= bomba[K.first][K.second][who].first, bomb2=bomba[K.first][K.second][who].second;
	for(int i=bomb1;i>=1;i--){
		if(pole[i][bomb2]==2) break;
		pole[i][bomb2]=0;
	}
	for(int i=bomb1;i<=n;i++){
		if(pole[i][bomb2]==2) break;
		pole[i][bomb2]=0;
	}
	for(int j=bomb2;j>=1;j--){
		if(pole[bomb1][j]==2) break;
		pole[bomb1][j]=0;
	}
	for(int j=bomb2;j<=n;j++){
		if(pole[bomb1][j]==2) break;
		pole[bomb1][j]=0;
	}
	if(ans==1e9){
		cout<<"NIE";
		return 0;
	}
	queue<pair<int, int>> kolejka;
	kolejka.push(K);
	fin[K.first][K.second]=true;
	while(!kolejka.empty()){
		auto x = kolejka.front();
		kolejka.pop();
		for(auto v : {make_pair(x.first-1, x.second), make_pair(x.first+1, x.second), make_pair(x.first, x.second-1), make_pair(x.first, x.second+1)}){
			if(!fin[v.first][v.second]&&check(v.first, v.second)&&!pole[v.first][v.second]){
				fin[v.first][v.second]=true;
				dr[v.first][v.second]=dr[x.first][x.second]+1;
				kolejka.push(v);
			}
		}
	}
	int help1=P.first, help2=P.second, var=dr[P.first][P.second];
	while(help1!=K.first||help2!=K.second){
		if(spr(help1-1, help2, var)){
			var--;
			help1--;
			droga+='G';
		}
		else if(spr(help1+1, help2, var)){
			var--;
			help1++;
			droga+='D';
		}
		else if(spr(help1, help2-1, var)){
			var--;
			help2--;
			droga+='L';
		}
		else if(spr(help1, help2+1, var)){
			var--;
			help2++;
			droga+='P';
		}
	}
	cout<<ans<<"\n";
	cout<<bomb1<<" "<<bomb2<<"\n";
	cout<<droga<<"\n";
	return 0;
}
