#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const int W = 51;

int n;
int rozm[N];
int koniec[N];
int dist[W][W][W][W];

int get_dist(vector<int> &vec) {
	return dist[vec[0]][vec[1]][vec[2]][vec[3]];	
}

void set_dist(vector<int> &vec, int ile) {
	dist[vec[0]][vec[1]][vec[2]][vec[3]] = ile;
}

bool is_end(vector<int> &vec) {
	for (int i = 0; i < n; i++) {
		if (vec[i] != koniec[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>rozm[i];
	}
	for (int i = 0; i < n; i++) {
		cin>>koniec[i];
	}
	
	queue<vector<int>> order;
	vector<int> pocz(N, 0);
	for (int i = 0; i < n; i++) {
		pocz[i] = rozm[i];
	}
	order.push(pocz);
	
	while (!order.empty()) {
		vector<int> x = order.front();
		order.pop();
		int new_dis = get_dist(x) + 1;
		if (is_end(x)) {
			cout<<new_dis-1;
			return 0;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j && x[i] > 0) {
					int tmp = x[i];
					x[i] = 0;
					if (!get_dist(x)) {
						set_dist(x, new_dis);
						order.push(x);
					}
					x[i] = tmp;
				}
				else if (x[i] > 0 && x[j] < rozm[j]) {
					int tmp1 = x[i], tmp2 = x[j];
					int ile = min(x[i], rozm[j] - x[j]);
					x[i] -= ile;
					x[j] += ile;
					if (!get_dist(x)) {
						set_dist(x, new_dis);
						order.push(x);
					}
					x[i] = tmp1, x[j] = tmp2;
				}
			}
		}
	}
	cout<<"NIE";
}
