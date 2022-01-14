#include <bits/stdc++.h>
using namespace std;

// merge two sorted arrays
void merge(int a[], int st1, int en1, int st2, int en2)
{
	// a1[] -> a[st1] to a[en1]
	// a2[] -> a[st2] to a[en2]
	// st2 = en1 + 1

	int n1 = (en1 - st1 + 1), n2 = (en2 - st2 + 1);
	int sz =  n1 + n2;

	int merged_array[sz] = {0}; int k = 0;
	int i = st1, j = st2;

	while (i <= en1 and j <= en2)
	{
		if (a[i] <= a[j])
		{
			merged_array[k] = a[i];
			i++; k++;
		}

		else
		{
			merged_array[k] = a[j];
			j++; k++;
		}
	}

	while (i <= en1)
	{
		merged_array[k] = a[i];
		i++; k++;
	}

	while (j <= en2)
	{
		merged_array[k] = a[j];
		j++; k++;
	}

	for (int i = st1; i <= en2; i++)
	{
		a[i] = merged_array[i - st1];
	}
}

void merge_sort(int a[], int st, int en)
{
	// Base Case
	// = sign (st == en) bhi aayega base case mein kyonki, when there is only
	// 1 element in the array, then we can't divide the array in 2 parts

	if (st >= en) return;

	int mid = st + (en - st) / 2;
	merge_sort(a, st, mid);
	merge_sort(a, mid + 1, en);
	merge(a, st, mid, mid + 1, en);
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; int a[n];

		for (int i = 0; i < n; i++) cin >> a[i];

		merge_sort(a, 0, n - 1);

		for (int i = 0 ; i < n ; i++) cout << a[i] << ' ';
		cout << endl;
	}
}
