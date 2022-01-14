#include <bits/stdc++.h>
using namespace std;

void upheapify(vector<int> &heap, int ind)
{
	if (ind == 0) return;
	int parent_ind = (ind - 1) / 2;

	if (heap[parent_ind] < heap[ind])
	{
		swap(heap[parent_ind], heap[ind]);
		upheapify(heap, parent_ind);
	}

	else return;
}

signed main()
{
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> heap;
	for (int i = 0; i < n; i++)
	{
		heap.push_back(a[i]);
		upheapify(heap, i);
	}

	for (int ele : heap) cout << ele << ' ';
}