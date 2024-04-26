#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 * 2 + 10;
vector<int> tab[N];
bitset<N> ozn;
vector<pair<int, pair<int, int>>> test[N];
vector<pair<int, bool>> wyniki;
int tury[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b + n);
        tab[b].push_back(a + n);
        tab[a + n].push_back(b);
        tab[b + n].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        int x1, y, z;
        cin >> x1 >> y >> z;
        test[x1].push_back(make_pair(y, make_pair(z, i)));
    }
    for (int j = 1; j <= n; j++) {
        if (test[j].empty()) continue;
        int x1 = j;
        for (int i = 0; i <= n * 2; i++) tury[i] = 0;
        ozn.reset();
        queue<int> order;
        order.push(x1);
        ozn[x1] = true;
        while (!order.empty()) {
            int x = order.front();
            order.pop();
            for (int v : tab[x]) {
                if (!ozn[v]) {
                    tury[v] = tury[x] + 1;
                    ozn[v] = true;
                    order.push(v);
                }
            }
        }
        for (auto x : test[j]) {
            bool nr;
            int y = x.first, z = x.second.first;
            if (z & 1) {
                if (tury[y + n] && tury[y + n] <= z) nr = true;
                else nr = false;
            }
            else {
                if (x1 == y) {
                    if (tab[x1].empty() && z == 0) nr = true;
                    else if (!tab[x1].empty()) nr = true;
                    else nr = false;
                }
                else {
                    if (tury[y] && tury[y] <= z) nr = true;
                    else nr = false;
                }
            }
            wyniki.push_back(make_pair(x.second.second, nr));
        }
    }
    sort(wyniki.begin(), wyniki.end());
    for (auto x : wyniki) {
        if (x.second) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}
