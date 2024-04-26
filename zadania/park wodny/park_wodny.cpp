//Autor: Wiktor Lewicki
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5; //inicjacja zmiennych i struktur
int cnt[N][N], n, how;
pair<int, int> rep[N][N];
pair<pair<int, int>, pair<int, int>> spojna[N][N];
bitset<N> odw[N], tab[N], fu[N];
vector<pair<int, int>> kraw[N][N], pom, all;
long long ans;
bool ok(int x1, int y1, int x2, int y2){//funkcja sprawdzająca czy można zbudować krawędź w grafie
	if(tab[x1][y1]&&tab[x2][y2]&&x1>0&&x2>0&&y1>0&&y2>0&&x1<=n&&x2<=n&&y1<=n&&y2<=n) return true;
	return false;
}
bool cord(int x, int y){//funkcja sprawdzająca czy nie wychodzimy za tablice + sprawdzamy czy odwiedziliśmy już wierzchołek
	if(!odw[x][y]&&tab[x][y]&&x>0&&x<=n&&y>0&&y<=n) return true;
	return false;
}
pair<int, int> find_rep(pair<int ,int>a){//find w F&U
	if(rep[a.first][a.second]==a){
		return a;
	}
	rep[a.first][a.second] = find_rep(rep[a.first][a.second]);
	return rep[a.first][a.second];
}
void union_ver(pair<int, int>a, pair<int, int>b){//union w F&U
	a=find_rep(a);
	b=find_rep(b);
	rep[b.first][b.second]=a;
}
void dfs(int i, int j){//liczymy ilość wierzchołków we wspólnym podgrafie
	odw[i][j]=true;
	pom.pb({i, j});
	how++;
	for(auto v : kraw[i][j]){
		if(!odw[v.first][v.second]){
			dfs(v.first, v.second);
		}
	}
}
void small_dfs(int i, int j){//zabezpieczenie przed podwójnym policzeniem (dla przypadku sąsiednich modyfikowanych alejek)
	odw[i][j]=true;
	pom.pb({i, j});
	for(auto v : kraw[i][j]){
		pom.pb({v.first, v.second});
		odw[v.first][v.second]=true;
	}
}
int short_if(int i, int j){//skrócenie kodu przez funkcję
	if(cord(i, j)){
		small_dfs(i, j);
		return cnt[i][j];
	}
	return 0;
}
bool spr(int x, int y){//sprawdzanie czy {i, j} nie wychodzi za tablicę i czy nie jest basenem
	if(x>0&&x<=n&&y>0&&y<=n&&!tab[x][y]) return true;
	return false;
}
bool cord_check(int i, int j){ //sprawdzanie czy łączymy dwa baseny + sprawdzamy czy nie wychodzimy za tablicę
	pair<int, int>a = find_rep({i, j});
	if(i>0&&i<=n&&j>0&&j<=n&&tab[i][j]&&!fu[a.first][a.second]) return true;
	return false;
}
int super_add(int i, int j, bool who){//liczenie dla niespójnych dwóch alejek
	int suma=0;
	if(cord_check(i, j-1)){
		pair<int ,int>a = find_rep({i, j-1});
		suma+=cnt[a.first][a.second];
		fu[a.first][a.second]=true;
		if(who)pom.pb({a.first, a.second});
		else all.pb({a.first, a.second});
	}
	if(cord_check(i, j+1)){
		pair<int ,int>a = find_rep({i, j+1});
		suma+=cnt[a.first][a.second];
		fu[a.first][a.second]=true;
		if(who)pom.pb({a.first, a.second});
		else all.pb({a.first, a.second});
	}
	if(cord_check(i-1, j)){
		pair<int ,int>a = find_rep({i-1, j});
		suma+=cnt[a.first][a.second];
		fu[a.first][a.second]=true;
		if(who)pom.pb({a.first, a.second});
		else all.pb({a.first, a.second});
	}
	if(cord_check(i+1, j)){
		pair<int ,int>a = find_rep({i+1, j});
		suma+=cnt[a.first][a.second];
		fu[a.first][a.second]=true;
		if(who)pom.pb({a.first, a.second});
		else all.pb({a.first, a.second});
	}
	return suma;
}
void build(int a1, int a2, int x1, int y1, int x2, int y2, pair<int, int>a){//skrócenie kodu poprzez przeniesienie checka do funkcji
	if(spr(a1, a2)){
		long long wyn=2+cnt[a.first][a.second];
		wyn+=super_add(a1, a2, true);
		for(int p=y1;p<=y2;p++){
			int wynik = super_add(x1-1, p, false);
			ans=max(wyn + wynik, ans);
			for(auto v : all){
				fu[v.first][v.second] = false;
			}
			all.clear();
		}
		for(int p=y1;p<=y2;p++){
			int wynik = super_add(x2+1, p, false);
			ans=max(wyn + wynik, ans);
				for(auto v : all){
					fu[v.first][v.second] = false;
				}
			all.clear();
		}
		for(int p=x1;p<=x2;p++){
			int wynik = super_add(p, y1-1, false);
			ans=max(wyn + wynik, ans);
			for(auto v : all){
				fu[v.first][v.second] = false;
			}
			all.clear();
		}
		for(int p=x1;p<=x2;p++){
			int wynik = super_add(p, y2+1, false);
			ans=max(wyn + wynik, ans);
				for(auto v : all){
					fu[v.first][v.second] = false;
				}
			all.clear();
		}
		for(auto v : pom){
			fu[v.first][v.second] = false;
		}
		pom.clear();
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){//wczytanie
		string c;
		cin>>c;
		for(int j=1;j<=n;j++){
			rep[i][j] = {i, j};
			if(c[j-1]=='B') tab[i][j] = true;
			else tab[i][j] = false;
		}
	}
	for(int i=1;i<=n;i++){//budowanie krawędzi i F&U
		for(int j=1;j<=n;j++){
			if(ok(i, j, i+1, j)){
				kraw[i][j].pb({i+1, j});
				kraw[i+1][j].pb({i, j});
				union_ver({i, j}, {i+1, j});
			}
			if(ok(i, j, i, j+1)){
				kraw[i][j].pb({i, j+1});
				kraw[i][j+1].pb({i, j});
				union_ver({i, j}, {i, j+1});
			}
		}
	}
	for(int i=1;i<=n;i++){//obliczenie wielkości spójnych i ustawianie ich
		for(int j=1;j<=n;j++){
			if(!odw[i][j]&&tab[i][j]){
				how=0;
				pom.clear();
				dfs(i, j);
			}
			for(auto v : pom){
				cnt[v.first][v.second]=how;
			}
		}
	}
	for(int i=1;i<=n;i++) odw[i].reset();
	for(int i=1;i<=n;i++){//obliczanie wierzchołków prostokątów spójnych (zopcone, działa w n^2)
		for(int j=1;j<=n;j++){
			if(!odw[i][j]&&tab[i][j]){
				pair<int, int> v = find_rep({i, j});
				int a=i, b=j;
				while(true){
					if(a==n&&b==n){
						break;
					}
					if(cnt[a][b]==cnt[a+1][b]&&a+1<=n) a++;
					else if(cnt[a][b]==cnt[a][b+1]&&b+1<=n) b++;
					else break;
				}
				spojna[v.first][v.second] = {{i, j}, {a, b}};
				for(int p=i;p<=a;p++){
					for(int k=j;k<=b;k++){
						odw[p][k] = true;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++) odw[i].reset();
	for(int i=1;i<=n;i++){//maksymalizowanie wyniku dla sąsiednich modyfikowanych alejek
		for(int j=1;j<=n;j++){
			long long wyn=2;
			if(j<n&&!tab[i][j]&&!tab[i][j+1]){//poziome
				wyn+=short_if(i-1, j);
				wyn+=short_if(i+1, j);
				wyn+=short_if(i, j-1);
				wyn+=short_if(i, j+1);
				wyn+=short_if(i-1, j+1);
				wyn+=short_if(i+1, j+1);
				wyn+=short_if(i, j);
				wyn+=short_if(i, j+2);
				for(auto v : pom){
					odw[v.first][v.second] = false;
				}
				pom.clear();
				ans = max(ans, wyn);
			}
			wyn=2;
			if(i<n&&!tab[i][j]&&!tab[i+1][j]){//pionowe
				wyn+=short_if(i-1, j);
				wyn+=short_if(i+1, j);
				wyn+=short_if(i, j-1);
				wyn+=short_if(i, j+1);
				wyn+=short_if(i, j);
				wyn+=short_if(i+2, j);
				wyn+=short_if(i+1, j-1);
				wyn+=short_if(i+1, j+1);
				for(auto v : pom){
					odw[v.first][v.second] = false;
				}
				pom.clear();
				ans = max(ans, wyn);
			}
		}
	}
	for(int i=1;i<=n;i++){//obliczanie wyników dla niespójnych alejek, ale jedną alejką MUSI być wierzchołek prostokąta
		for(int j=1;j<=n;j++){
			pair<int, int>a = find_rep({i, j});
			if(!odw[a.first][a.second]&&tab[i][j]){
				odw[a.first][a.second] = true;
				fu[a.first][a.second] = true;
				int x1 = spojna[a.first][a.second].first.first, y1 = spojna[a.first][a.second].first.second;
				int x2 = spojna[a.first][a.second].second.first, y2 = spojna[a.first][a.second].second.second;
				build(x1, y1-1, x1, y1, x2, y2, a);
				build(x1-1, y1, x1, y1, x2, y2, a);
				build(x2+1, y2, x1, y1, x2, y2, a);
				build(x2, y2+1, x1, y1, x2, y2, a);
				build(x1-1, y2, x1, y1, x2, y2, a);
				build(x1, y2+1, x1, y1, x2, y2, a);
				build(x2, y1-1, x1, y1, x2, y2, a);
				build(x2+1, y1, x1, y1, x2, y2, a);
				fu[a.first][a.second] = false;
			}
		}
	}
	for(int i=1;i<=n;i++) odw[i].reset();
	for(int i=1;i<=n;i++){//obliczanie wyników dla niespójnych alejek, ale bez wierzchołków prostokątów
		for(int j=1;j<=n;j++){
			pair<int, int>a = find_rep({i, j});
			if(!odw[a.first][a.second]){
				int x1 = spojna[a.first][a.second].first.first, y1 = spojna[a.first][a.second].first.second;
				int x2 = spojna[a.first][a.second].second.first, y2 = spojna[a.first][a.second].second.second;
				long long wyn=cnt[a.first][a.second];
				priority_queue<int> Q;
				odw[a.first][a.second] = true;
				fu[a.first][a.second] = true;
				int lic=0;
				for(int p=y1+1;p<=y2-1;p++){
					if(x1-1>0){
						Q.push(super_add(x1-1, p, true));
						if(!tab[x1-1][p])lic++;
					}
				}
				for(int p=y1+1;p<=y2-1;p++){
					if(x2+1<=n){
						Q.push(super_add(x2+1, p, true));
						if(!tab[x2+1][p])lic++;
					}
				}
				for(int p=x1+1;p<=x2-1;p++){
					if(y1-1>0){
						Q.push(super_add(p, y1-1, true));
						if(!tab[p][y1-1])lic++;
					}
				}
				for(int p=x1+1;p<=x2-1;p++){
					if(y2+1<=n){
						Q.push(super_add(p, y2+1, true));
						if(!tab[p][y2+1])lic++;
					}
				}
				for(auto v : pom){
					fu[v.first][v.second] = false;
				}
				if(lic>=2) wyn+=2;
				else if(lic==1) wyn+=1;
				fu[a.first][a.second] = false;
				pom.clear();
				long long lic1=0, lic2=0;
				if(!Q.empty()){
					lic1=Q.top();
					Q.pop();
				}
				if(!Q.empty()){
					lic2=Q.top();
				}
				ans = max(ans, wyn+lic1+lic2);
			}
		}
	}
	cout<<ans;
	return 0;
}
