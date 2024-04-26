#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int tab[N];
set<int> S;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	n--;
	string A=".", B=".", pom;
	cin>>pom;
	A+=pom;
	cin>>pom;
	B+=pom;
	pom="";
	for(int i=1;i<=n;i++){
		tab[i]=(A[i]-'0')+(B[i]-'0');
		if(tab[i]!=9) S.insert(i);
	}
	while(m--){
		char W;
		cin>>W;
		if(W=='S'){
			int a, x=0;
			cin>>a;
			a=n-a+1;
			auto pom = S.upper_bound(a);
			if(pom!=S.end()){
				if(tab[*pom]>9){
					x++;
				}
			}
			cout<<(tab[a]+x)%10<<"\n";
		}
		else{
			int a;
			char c;
			cin>>a>>c;
			a=n-a+1;
			if(W=='W'){
				if(A[a]==c) continue;
				A[a]=c;
				if(tab[a]==9){
					S.insert(a);
				}
				tab[a]=(A[a]-'0')+(B[a]-'0');
				if(tab[a]==9){
					S.erase(S.find(a));
				}
			}
			else{
				if(B[a]==c) continue;
				B[a]=c;
				if(tab[a]==9){
					S.insert(a);
				}
				tab[a]=(A[a]-'0')+(B[a]-'0');
				if(tab[a]==9){
					S.erase(S.find(a));
				}
			}
		}
	}
	return 0;
}
