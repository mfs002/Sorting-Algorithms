#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cnt_inv;

void merge(ll a[], ll st1, ll en1, ll st2, ll en2)
{
	ll n1 = (en1 - st1 + 1), n2 = (en2 - st2 + 1);
	ll sz =  n1 + n2;

	ll merged_array[sz] = {0}; ll k = 0;
	ll i = st1, j = st2;

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
			cnt_inv += (n1 - (i - st1));
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

	for (ll i = st1; i <= en2; i++)
	{
		a[i] = merged_array[i - st1];
	}
}

void merge_sort(ll a[], ll st, ll en)
{
	// Base Case
	if (st >= en) return;

	ll mid = st + (en - st) / 2;
	merge_sort(a, st, mid);
	merge_sort(a, mid + 1, en);
	merge(a, st, mid, mid + 1, en);
}

ll func(ll a[], ll N)
{
	cnt_inv = 0;
	merge_sort(a, 0, N - 1);
	return cnt_inv;
}

signed main()
{
	ll t; cin >> t;
	while (t--)
	{
		ll n; cin >> n; ll a[n];
		for (ll i = 0; i < n; i++) cin >> a[i];

		cout << func(a, n) << endl;
	}
}