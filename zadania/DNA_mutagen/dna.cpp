#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ile[N][3][2], line[N][3][2];
int tsf(char c){
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='T') return 2;
}
void init(string a, string b){
	for(int i=0;i<a.length();i++){
		ile[i+1][tsf(a[i])][0]++;
		ile[i+1][tsf(b[i])][1]++;
		if(a[i]=='A'&&b[i]=='C') line[i+1][0][0]++;
		if(a[i]=='A'&&b[i]=='T')line[i+1][1][0]++;
		if(a[i]=='C'&&b[i]=='T')line[i+1][2][0]++;
		if(a[i]=='C'&&b[i]=='A') line[i+1][0][1]++;
		if(a[i]=='T'&&b[i]=='A')line[i+1][1][1]++;
		if(a[i]=='T'&&b[i]=='C')line[i+1][2][1]++;
		for(int j=0;j<=2;j++){
			ile[i+1][j][0]+=ile[i][j][0];
			ile[i+1][j][1]+=ile[i][j][1];
			line[i+1][j][0]+=line[i][j][0];
			line[i+1][j][1]+=line[i][j][1];
		}
	}
}
int get_distance(int x, int y){
	x++;
	y++;
	if(ile[y][0][0]-ile[x-1][0][0]!=ile[y][0][1]-ile[x-1][0][1]){
		return -1;
	}
	if(ile[y][1][0]-ile[x-1][1][0]!=ile[y][1][1]-ile[x-1][1][1]){
		return -1;
	}
	if(ile[y][2][0]-ile[x-1][2][0]!=ile[y][2][1]-ile[x-1][2][1]){
		return -1;
	}
	int wynik=0, err=0;
	for(int i=0;i<=2;i++){
		int pom1 = line[y][i][0]-line[x-1][i][0];
		int pom2 = line[y][i][1]-line[x-1][i][1];
		wynik+=(min(pom1, pom2));
		err+=abs(pom1-pom2);
	}
	wynik+=(err/3)*2;
	return wynik;
}
