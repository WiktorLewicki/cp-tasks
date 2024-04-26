#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int tab[N];
long long sum_pref[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, x;
    cin >> n;
    for (int i = 1; i <= n; i++)  cin >> tab[i];
    sort(tab + 1, tab + n + 1);
    for (int i = 1; i <= n; i++) sum_pref[i] = sum_pref[i - 1] + tab[i];
    cin >> t;
    while (t--) {
        cin >> x;
        cout << sum_pref[x] << "\n";
    }

    return 0;
}
