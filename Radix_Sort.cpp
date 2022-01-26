#include <bits/stdc++.h>
using namespace std;

int no_of_digits(int n)
{
	int cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return cnt;
}

void count_sort(vector<int> &a, int div)
{
	// base = 10
	vector<int> freq(10, 0); int n = a.size();

	for (int i = 0; i < n; i++)
	{
		int curr_digit = (a[i] / div) % 10;
		freq[curr_digit]++;
	}
	for (int i = 1; i < 10; i++) freq[i] += freq[i - 1];

	vector<int> ans(n, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		int curr_digit = (a[i] / div) % 10;
		int corr_ind = freq[curr_digit] - 1;
		ans[corr_ind] = a[i];
		freq[curr_digit]--;
	}
	a = ans;
}

void radix_sort(vector<int> &a)
{
	int maxn = no_of_digits(*max_element(a.begin(), a.end()));
	int div = 1;
	while (maxn >= 1)
	{
		count_sort(a, div);
		div *= 10;
		maxn--;
	}
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		radix_sort(a);
		for (int i : a) cout << i << ' ';
		cout << endl;
	}
}