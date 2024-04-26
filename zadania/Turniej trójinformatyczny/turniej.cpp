#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const pair<int, int> zero = {0, 0};
const pair<int, int> MX = {1e9, 1e9};
int score[N][3], place[N][3], rozm=1, tp[N], cz=0, n, q;
pair<int, int> d[4*N][3];
array<int, 4> tab[N];
vector<int> spj[N];
bitset<N> odw;
stack<int> nr;
bool cmp(array<int, 4>a, array<int, 4> b){
	return a[1] < b[1];
}
void build(int x, int l, int r, int info, int str){
	if(l==r){
		if(l<=n){
			if(info==0){
				d[x][info]={tab[l][1], tab[l][3]};
			}
			else{
				d[x][info]={tab[l][2], tab[l][3]};
			}
		}
		else if(str) d[x][info]={1e9, 1e9};
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr, info, str);
	build(x*2+1, sr+1, r, info, str);
	if(!str) d[x][info]=max(d[x*2][info], d[x*2+1][info]);
	else d[x][info]=min(d[x*2][info], d[x*2+1][info]);
}
void update(int l, int r, int x, int idx, int info, int who){
	if(l==r){
		if(who==0) d[x][info]={0, 0};
		else d[x][info]={1e9, 1e9};
		return;
	}
	int sr = (l+r)/2;
	if(idx<=sr){
		update(l, sr, x*2, idx, info, who);
	}
	else{
		update(sr+1, r, x*2+1, idx, info, who);
	}
	if(who==0) d[x][info]=max(d[x*2][info], d[x*2+1][info]);
	else d[x][info]=min(d[x*2][info], d[x*2+1][info]);
}
pair<int, int> query(int l, int r, int a, int b, int x, int info, int who){
	if(a<=l&&r<=b){
		return d[x][info];
	}
	pair<int, int> res;
	if(who==0) res = {0, 0};
	else res = {1e9, 1e9};
	int sr = (l+r)/2;
	if(a<=sr){
		if(who==0) res = max(res, query(l, sr, a, b, x*2, info, who));
		else res = min(res, query(l, sr, a, b, x*2, info, who));
	}
	if(sr<b){
		if(who==0) res = max(res, query(sr+1, r, a, b, x*2+1, info, who));
		else res = min(res, query(sr+1, r, a, b, x*2+1, info, who));
	}
	return res;
}
void dfs1(int x){
	odw[x] = true;
	update(1, rozm, 1, place[x][0], 0, 0);
	update(1, rozm, 1, place[x][1], 1, 0);
	update(1, rozm, 1, place[x][2], 2, 0);
	pair<int, int> pom = {1, 0};
	while(pom!=zero){
		if(place[x][0]==n) break;
		pom=query(1, rozm, place[x][0]+1, n, 1, 0, 0);
		if(score[x][1]>pom.first){
			break;
		}
		dfs1(pom.second);
	}
	pom = {1, 0};
	while(pom!=zero){
		if(place[x][1]==n) break;
		pom=query(1, rozm, place[x][1]+1, n, 1, 1, 0);
		if(score[x][2]>pom.first){
			break;
		}
		dfs1(pom.second);
	}
	pom = {1, 0};
	while(pom!=zero){
		if(place[x][2]==n) break;
		pom=query(1, rozm, place[x][2]+1, n, 1, 2, 0);
		if(score[x][2]>pom.first){
			break;
		}
		dfs1(pom.second);
	}
	nr.push(x);
}
void dfs2(int x){
	odw[x] = true;
	spj[cz].pb(x);
	tp[x]=cz;
	update(1, rozm, 1, place[x][0], 0, 1);
	update(1, rozm, 1, place[x][1], 1, 1);
	update(1, rozm, 1, place[x][2], 2, 1);
	pair<int, int> pom = {1, 0};
	while(pom!=MX){
		if(place[x][0]==1) break;
		pom=query(1, rozm, 1, place[x][0]-1, 1, 0, 1);
		if(score[x][1]<pom.first){
			break;
		}
		dfs2(pom.second);
	}
	pom = {1, 0};
	while(pom!=MX){
		if(place[x][1]==1) break;
		pom=query(1, rozm, 1, place[x][1]-1, 1, 1, 1);
		if(score[x][2]<pom.first){
			break;
		}
		dfs2(pom.second);
	}
	pom = {1, 0};
	while(pom!=MX){
		if(place[x][2]==1) break;
		pom=query(1, rozm, 1, place[x][2]-1, 1, 2, 1);
		if(score[x][2]<pom.first){
			break;
		}
		dfs2(pom.second);
	}
}
bool win(int a, int b){
	int lic=0;
	if(score[a][0]<score[b][0]) lic++;
	if(score[a][1]<score[b][1]) lic++;
	if(score[a][2]<score[b][2]) lic++;
	if(lic>1) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n;i++){
		cin>>tab[i][0];
		score[i][0]=tab[i][0];
	}
	for(int i=1;i<=n;i++){
		cin>>tab[i][1];
		score[i][1]=tab[i][1];
	}
	for(int i=1;i<=n;i++){
		cin>>tab[i][2];
		score[i][2]=tab[i][2];
	}
	for(int i=1;i<=n;i++){
		tab[i][3] = i;
	}
	sort(tab+1, tab+n+1);
	build(1, 1, rozm, 0, 0);
	for(int i=1;i<=n;i++){
		place[tab[i][3]][0]=i;
		place[tab[i][3]][1]=i;
	}
	build(1, 1, rozm, 1, 0);
	sort(tab+1, tab+n+1, cmp);
	build(1, 1, rozm, 2, 0);
	for(int i=1;i<=n;i++){
		place[tab[i][3]][2]=i;
	}
	for(int i=1;i<=n;i++){
		tp[i]=i;
		if(!odw[i]) dfs1(i);
	}
	odw.reset();
	
	for(int i=1;i<=n;i++){                                                      
        tab[i][0]=score[i][0];                                                  
        tab[i][1]=score[i][1];                                                  
        tab[i][2]=score[i][2];                                                  
        tab[i][3]=i;                                                            
    }                                                                           
    sort(tab+1, tab+n+1);                                                       
    build(1, 1, rozm, 0, 1);     
    for(int i=1;i<=n;i++){                                                      
        place[tab[i][3]][0]=i;                                                  
        place[tab[i][3]][1]=i;                                                  
    }                                                                           
    build(1, 1, rozm, 1, 1);                                                       
    sort(tab+1, tab+n+1, cmp);                                                  
    build(1, 1, rozm, 2, 1);                                                       
    for(int i=1;i<=n;i++){                                                      
        place[tab[i][3]][2]=i;                                                  
    }
	while(!nr.empty()){
		int at = nr.top();
		nr.pop();
		if(!odw[at]){
			cz++;
			dfs2(at);
		}
	}
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		if(tp[a]==tp[b]){
			cout<<"TAK\n";
			continue;
		}
		if(win(a, b)){
			cout<<"TAK\n";
			continue;
		}
		cout<<"NIE\n";
	}
	return 0;
}
