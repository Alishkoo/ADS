#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct MaxHeap
{
    vector<ll> heap;

    ll parent(ll i)
    {
        return (i - 1) / 2;
    }
    ll left(ll i)
    {
        return 2 * i + 1;
    }
    ll right(ll i)
    {
        return 2 * i + 2;
    }
    void insert(ll value)
    {
        this->heap.push_back(value);
        ll i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] < this->heap[i])
        {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    ll extractMax()
    {
        if (this->heap.size() == 0)
            return INT_MIN;
        if (this->heap.size() == 1)
        {
            ll root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        ll root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void heapify(ll i)
    {
        ll l = this->left(i);
        ll r = this->right(i);
        ll biggest = i;
        if (l < this->heap.size() && this->heap[l] > this->heap[biggest])
            biggest = l;
        if (r < this->heap.size() && this->heap[r] > this->heap[biggest])
            biggest = r;
        if (biggest != i)
        {
            swap(this->heap[i], this->heap[biggest]);
            this->heapify(biggest);
        }
    }
    ll getSize()
    {
        return heap.size();
    }
};
int main()
{
    MaxHeap heap;
    ll n, x, sum = 0;
    cin >> n >> x;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        heap.insert(arr[i]);
    }
    while (x--)
    {
        ll seat = heap.extractMax();
        sum += seat;
        seat--;
        heap.insert(seat);
    }
    cout << sum;

    return 0;
}