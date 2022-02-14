#include <bits/stdc++.h>
using namespace std;

// 1 <= a[i] <= 1e5
vector<int> index[100001];

// But if a[i] <= 1e9, then use
// map<int, vector<int>> index;

signed main()
{
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) index[a[i]].push_back(i);
	for (int i = 0; i < n; i++) index[a[i]].push_back(1e9);

	int q; cin >> q;

	while (q--)
	{
		int l, r, m; cin >> l >> r >> m;

		int l_b = lower_bound(index[m].begin(), index[m].end(), l) - index[m].begin();
		int u_b = lower_bound(index[m].begin(), index[m].end(), r) - index[m].begin();
		int cnt = u_b - l_b;

		if (u_b < 1e9 and index[m][u_b] == r) cnt++;

		cout << cnt << endl;
	}
}