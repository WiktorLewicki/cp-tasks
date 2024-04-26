#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ans[N];
map<array<int, 3>, int> mapa;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int sz[3];
	cin>>sz[0]>>sz[1]>>sz[2];
	int A2, B2, C2;
	cin>>A2>>B2>>C2;
	for(int i=0;i<=sz[2]+1;i++) ans[i]=1e9;
	queue<array<int, 3>> order;
	mapa[{A2, B2, C2}]=0;
	order.push({A2, B2, C2});
	while(!order.empty()){
		auto t = order.front();
		order.pop();
		int wyn = mapa[{t[0], t[1], t[2]}];
		ans[t[0]]=min(ans[t[0]], wyn);
		ans[t[1]]=min(ans[t[1]], wyn);
		ans[t[2]]=min(ans[t[2]], wyn);
		for(int i=0;i<=2;i++){
			for(int j=0;j<=2;j++){
				if(i==j) continue;
				int a=min(sz[j]-t[j], t[i]);
				int zs[3] = {t[0], t[1], t[2]};
				zs[i]-=a;
				zs[j]+=a;
				if((zs[0]!=A2||zs[1]!=B2||C2!=zs[2])&&mapa[{zs[0], zs[1], zs[2]}]==0){
					mapa[{zs[0], zs[1], zs[2]}]=mapa[{t[0], t[1], t[2]}]+1;
					order.push({zs[0], zs[1], zs[2]});
				}
			}
		}
	}
	for(int i=0;i<=sz[2];i++){
		if(ans[i]==1e9) cout<<"-1 ";
		else cout<<ans[i]<<" ";
	}
	return 0;
}
