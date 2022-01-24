#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &a, int n)
{
	int maxn = *max_element(a.begin(), a.end());
	vector<int> freq(maxn + 1, 0);

	for (int i = 0; i < n; i++) freq[a[i]]++;

	// prefix sum of frequencies array
	for (int i = 1; i <= maxn; i++) freq[i] += freq[i - 1];

	// correct index (0-based) of last a[i] in sorted array is pref_freq[a[i]] - 1

	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++)
	{
		//correct ind of last a[i]
		int corr_pos = freq[a[i]] - 1;
		ans[corr_pos] = a[i];
		freq[a[i]]--;
	}
	a = ans;
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		count_sort(a, n);

		for (int i : a) cout << i << ' ';
		cout << '\n';
	}
}