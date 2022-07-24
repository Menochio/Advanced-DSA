#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    

    public:
    vector<int> seg;

    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    int queries( int ind, int low, int high, int l, int r)
    {
        if (high < l || r < low)
            return INT_MAX;

        else if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) / 2;
        int left = queries( 2 * ind + 1, low, mid, l, r);
        int right = queries( 2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
        {
            update(2 * ind + 1, low, mid, i, val);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, i, val);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void buildSegTrees( int arr[], int low, int high, int index)
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }
        int mid = (low) + (high - low) / 2;

        buildSegTrees( arr, low, mid, 2 * index + 1);
        buildSegTrees( arr, mid + 1, high, 2 * index + 2);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};
