#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int monkey[N][2], wynik[N], rep[N], who[N*2], hand[N*2], mem[2*N], ile[N], co;
vector<int> spojna[N];
int find_rep_fast(int x) {
	if (rep[x] == x) {
		return x;
	}
	rep[x] = find_rep_fast(rep[x]);
	return rep[x];
}
void union_ver_fast(int a, int b, int czas) {
	bool ktore = false;
	if(a==co) ktore = true;
	a = find_rep_fast(a);
	b = find_rep_fast(b);
	if(co){
		if(ktore) for(auto v : spojna[a]) wynik[v] = czas;
		else for(auto v : spojna[b]) wynik[v] = czas;
	}
	if (ile[a]<ile[b]) {
		swap(a, b);
	}
	if(a!=b){
		ile[a]+=ile[b];
		for(auto v : spojna[b]) spojna[a].push_back(v);
	}
	rep[b] = a;
}
int wybor(int a, int b)
{
	if(find_rep_fast(a)==find_rep_fast(b)) return 0;
	if(find_rep_fast(a)==find_rep_fast(1)) return b;
	if(find_rep_fast(b)==find_rep_fast(1)) return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		rep[i]=i;
		spojna[i].push_back(i);
		wynik[i]=-1;
		ile[i]=1;
		cin>>monkey[i][0]>>monkey[i][1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>who[i]>>hand[i];
		hand[i]--;
		mem[i] = monkey[who[i]][hand[i]];
		monkey[who[i]][hand[i]] = -1;
	}
	for(int i=1;i<=n;i++) 
	{
		if(monkey[i][0]!=-1)union_ver_fast(i, monkey[i][0], 0);
		if(monkey[i][1]!=-1)union_ver_fast(i, monkey[i][1], 0);
	}
	for(int i=m;i>=1;i--)
	{
		co = wybor(mem[i], who[i]);
		union_ver_fast(mem[i], who[i], i-1);
	}
	for(int i=1;i<=n;i++) cout<<wynik[i]<<"\n";
	return 0;
}
