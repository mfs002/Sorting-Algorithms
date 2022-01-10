#include <bits/stdc++.h>
using namespace std;

// T.C = O(N^2)

void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int curr_ele = a[i];
		// now we will find the correct pos for this curr_ele to be inserted in the sorted part

		int j = i - 1;

        // here you can't write a[i] instead of curr_ele coz we are shifting a[j] by 1 position
        // if a[j] > a[i], so for next iteration a[i] will be this a[j] coz ab ith index par
        // koi dusra ele aa gya
		while (j >= 0 and a[j] > curr_ele)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = curr_ele;
	}
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; int a[n];

		for (int i = 0; i < n; i++) cin >> a[i];

		insertion_sort(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << endl;
	}
}