#include <bits/stdc++.h>
using namespace std;

// ind is the index of the element to be downheapyfied
void downheapify(vector<int> &heap, int ind)
{
	// left child index
	int left_ind = 2 * ind + 1;
	// right child index
	int right_ind = 2 * ind + 2;

	// Base Case
	// i.e. both left and right child don't exist
	if (left_ind >= heap.size() and right_ind >= heap.size()) return;

	int maxn = ind;

	// if left child exists
	if (left_ind < heap.size() and heap[maxn] < heap[left_ind]) maxn = left_ind;
	// if right child exists
	if (right_ind < heap.size() and heap[maxn] < heap[right_ind]) maxn = right_ind;

	// maxn will contain index of the max of the parent and its 2 children
	// if (maxn == ind) then parent is at its correct position i.e, there's no need
	// to do anything coz parent > both its child. So, the structure is max_heap
	if (maxn == ind) return;

	// otherwise, max ele ko parent banao
	swap(heap[maxn], heap[ind]);

	// and check this new parent with its parent and so on.
	downheapify(heap, maxn);
}

signed main()
{
	int n; cin >> n; vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = n - 1; i >= 0; i--) downheapify(a, i);
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
}