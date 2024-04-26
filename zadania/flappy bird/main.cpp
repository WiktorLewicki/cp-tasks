#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int up[N], down[N], cord[N], dp[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	int n, X, upmax, downmax, dolny=0, gorny=0;
	cin>>n>>X;
	for(int i=1;i<=n;i++) cin>>cord[i]>>down[i]>>up[i];
	for(int i=1;i<=n;i++)
	{
		upmax=gorny+cord[i]-cord[i-1];
		downmax=dolny-(cord[i]-cord[i-1]);
		gorny=min(upmax, up[i]-1);
		dolny=max(downmax, down[i]+1);
		if((cord[i]+gorny)%2==1) gorny--;
		if((cord[i]+dolny)%2==1) dolny++;
		if((gorny>=up[i]&&dolny<=down[i])||gorny<dolny)
		{
			cout<<"NIE";
			return 0;
		}
	}
	cout<<(dolny+cord[n])/2;
	return 0;
}
