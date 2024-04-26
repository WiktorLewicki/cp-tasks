#include <bits/stdc++.h>
#include "glolib.h"
using namespace std;
const int N = 2e5 + 5;
int wsk[N], ojc[N];
vector<int> kraw[N];
bitset<N> odw;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n = daj_n(), pom;
	for(int i=2;i<=n;i++){
		int p = daj_przelozonego(i);
		ojc[i]=p;
		kraw[p].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(kraw[i].empty()){
			int x=i;
			while(x){
				odw[x]=true;
				x=ojc[x];
			}
			pom=ruch(i);
			break;
		}
	}
	odw[0]=true;
	for(int i=1;i<=n;i++){
		int x = pom;
		while(!odw[x]){
			odw[x]=true;
			x=ojc[x];
		}
		while(!kraw[x].empty()){
			while(odw[kraw[x][wsk[x]]]){
				wsk[x]++;
			}
			x=kraw[x][wsk[x]];
			odw[x]=true;
		}
		pom=ruch(x);
	}
	return 0;
}
