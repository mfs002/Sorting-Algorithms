#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

void count_sort(vector<pair<int, int>> &digits, vector<int> &a, int n)
{
	int maxn = 0;
	for (int i = 0; i < n; i++) maxn = max(maxn, digits[i].ss);

	vector<int> freq(maxn + 1, 0);
	for (int i = 0; i < n; i++) freq[digits[i].ss]++;

	// prefix sum of frequencies array
	for (int i = 1; i <= maxn; i++) freq[i] += freq[i - 1];

	// correct index (0-based) of last a[i].ss in sorted array is pref_freq[a[i]] - 1
	vector<pair<int, int>> ans(n, {0, 0});
	for (int i = n - 1; i >= 0; i--)
	{
		//correct ind of last a[i]
		int corr_pos = freq[digits[i].ss] - 1;
		ans[corr_pos] = digits[i];
		freq[digits[i].ss]--;
	}
	digits = ans;
	for (int i = 0; i < n; i++) a[i] = digits[i].ff;
}

void radix_sort(vector<int> &a, int n)
{
	// maxn no of digits considering base b
	int maxn_digits = 10, div = 10;
	vector<int> temp = a;

	for (int dig = 1; dig <= maxn_digits; dig++)
	{
		vector<pair<int, int>> digits;
		for (int i = 0; i < n; i++)
		{
			digits.push_back({a[i], temp[i] % 10});
		}
		count_sort(digits, a, n);

		for (int i = 0; i < n; i++)
		{
			temp[i] = digits[i].ff / div;
		}
		div *= 10;
	}
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		radix_sort(a, n);

		for (int i : a) cout << i << ' ';
		cout << '\n';
	}
}