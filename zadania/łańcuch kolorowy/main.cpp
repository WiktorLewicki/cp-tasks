#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, m, pom = 0, ciag[N], test = 0, l[N], c[N], lol = 0, k[N];
long long s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> k[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> ciag[i];
    for (int i = 1; i <= m; i++) s += k[i];
    for (int i = 1; i <= m; i++) l[c[i]] = k[i];
    if (s > n){
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= s; i++) l[ciag[i]]--;
    for (int j = 1; j <= n; j++) if (l[j] == 0) lol++;
    if (lol == n) test++;
    for (int i = 2; i <= n - s + 1; i++){
        if (l[ciag[i - 1]] == 0) lol--;
        if (l[ciag[i + s - 1]] == 0 && (l[ciag[i + s - 1]] - 1) != 0) lol--;
        l[ciag[i - 1]]++;
        l[ciag[i + s - 1]]--;
        if (l[ciag[i + s - 1]] == 0 && l[ciag[i + s - 1]] + 1 != 0) lol++;
        if (l[ciag[i - 1]] - 1 != 0 && (l[ciag[i - 1]]) == 0) lol++;
        if (lol == n) test++;
    }
    cout << test;
    return 0;
}
