#include <bits/stdc++.h>
using namespace std;

// a[] is sorted in increasing order form index [lo, lo+n/2-1]
// and sorted in decreasing order from index [lo + n/2, hi]

// In some recursive call, the whole a[] from [lo, hi] may be 
// sorted either in increasing or decreasing order

// T.C of MERGE() function -> O(N * log N)
void merge(vector<int> &a, int lo, int hi, int dir)
{
	// Base Case
	if (lo >= hi) return;

	int n = hi - lo + 1;
	for (int i = lo; i < lo + n / 2; i++)
	{
		if (dir == (a[i] > a[i + n / 2])) swap(a[i], a[i + n / 2]);
	}

	merge(a, lo, lo + n / 2 - 1, dir);
	merge(a, lo + n / 2, hi, dir);
}

void bitonic_sort(vector<int> &a, int lo, int hi, int dir)
{
	// Base Case
	if (lo >= hi) return;

	int n = hi - lo + 1;  // size of current array

	// sort left part in ascending order
	int left_end = lo + n / 2 - 1;
	bitonic_sort(a, lo, left_end, 1);

	// sort right part in descendinng order
	bitonic_sort(a, lo + n / 2, hi, 0);

	// merge the above two arrays
	merge(a, lo, hi, dir);
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		bitonic_sort(a, 0, n - 1, 1);
		for (int i : a) cout << i << ' ';
		cout << endl;
	}
}