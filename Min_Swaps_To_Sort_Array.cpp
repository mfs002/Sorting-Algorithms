#include <bits/stdc++.h>
using namespace std;

// Any kind of swapping is Allowed

int min_swaps(vector<int> &a)
{
	int n = a.size(); int swaps = 0;
	vector<int> temp = a;
	sort(temp.begin(), temp.end());

	map<int, int> ind;
	for (int i = 0; i < n; i++) ind[a[i]] = i;

	for (int i = 0; i < n; i++)
	{
		if (a[i] != temp[i])
		{

			/*	wrong sol: int correct_ind = ind[a[i]];
						   swap(a[i], a[correct_ind]);
						   swaps++;		*/

			// hume a[i] ko uske sahi index par pahuchana hai
			// so we will swap a[i] with the element at sahi index of a[i]

			// but the approach is wrong coz let's say that hamne first ele ko uske
			// sahi jagah pe swap karke pahuchaya, so kya guarantee hai ki swap hone
			// ke baad jo element first position pe aaya uski sahi jagah first pos
			// hi hogi

			// so approach should be this :
			// ith position ko sahi element se bharo i.e. har ith position
			// par sahi element daalo

			// i.e. the element which should be at ith position
			int corr_ele = temp[i];

			// so iss corr_ele ko ith index par laao
			int pos = ind[corr_ele];  // pos -> pos of corr_ele in a[]

			ind[a[i]] = pos; ind[a[pos]] = i;  // very important step coz we need to update the pos of swapped elements
			swap(a[i], a[pos]);
			swaps++;
		}
	}
	return swaps;
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; vector<int> a(n);

		for (int i = 0; i < n; i++) cin >> a[i];

		cout << min_swaps(a) << endl;
	}
}