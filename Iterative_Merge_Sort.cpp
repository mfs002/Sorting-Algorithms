#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int st1, int en1, int st2, int en2)
{
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

void merge_sort(int a[], int n)
{
    for (int sz = 1; sz < n; sz *= 2)
    {
        // size of both the divided arrays = sz
        for (int st1 = 0; st1 < n - 1; st1 += 2 * sz)
        {
            // en1 is the end point of the 1st divided array
            // and en1 can't exceed n-1
            int en1 = min(st1 + sz - 1, n - 1);
            int st2 = en1 + 1, en2 = min(st2 + sz - 1, n - 1);
            merge(a, st1, en1, st2, en2);
        }
    }
}

signed main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n; int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        merge_sort(a, n);

        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}