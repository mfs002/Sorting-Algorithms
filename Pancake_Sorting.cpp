#include <bits/stdc++.h>
using namespace std;

// Count minimum no of flips to sort the array
// when you can only flip any length prefix of the array

void flip(int a[], int ind)
{
	reverse(a, a + ind + 1);
}


signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; int a[n];
		for (int i = 0; i < n; i++) cin >> a[i];

		int no_of_flips = 0;

		vector<int> temp(a, a + n), corr_index(1e5, 0);
		sort(temp.begin(), temp.end());
		for (int i = 0; i < n; i++) corr_index[temp[i]] = i;

		int iter = 0;
		while (iter < n)
		{
			// ind -> index of maxn element till (n-iter) index
			int ind = 0, maxn = 0;
			for (int i = 0; i < n - iter; i++)
			{
				if (maxn < a[i])
				{
					maxn = a[i];
					ind = i;
				}
			}
			iter++;

			// check if we need to do the flip operation or not
			// check correct index of the current maxn element
			int corr_ind = corr_index[maxn];

			if (corr_ind == ind) continue;
			flip(a, ind);
			flip(a, n - iter);

			// Calculating no of flips
			if (ind == 0) no_of_flips++;
			else no_of_flips += 2;
		}

		cout << "flips : " << no_of_flips << endl;

		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << endl;
	}
}