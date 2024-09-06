#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Minheap
{
public:
    vector<ll> heap;
    ll parent(ll i)
    {
        return (i - 1) / 2;
    }
    ll left(ll i)
    {
        return (2 * i) + 1;
    }
    ll right(ll i)
    {
        return (2 * i) + 2;
    }

    void insert(ll val)
    {
        this->heap.push_back(val);
        ll i = heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i])
        {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    ll extractMin()
    {
        if (heap.empty())
        {
            return INT_MAX;
        }
        if (heap.size() == 1)
        {
            ll max = heap[0];
            heap.pop_back();
            return max;
        }
        ll max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return max;
    }
    void heapify(ll i)
    {
        ll leftt = left(i);
        ll rightt = right(i);
        ll smallest = i;
        if (leftt < heap.size() && heap[leftt] < heap[smallest])
        {
            smallest = leftt;
        }
        if (rightt < heap.size() && heap[rightt] < heap[smallest])
        {
            smallest = rightt;
        }
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
};


int main(){
    int n;
    Minheap minh;
    cin >> n;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        minh.insert(x);
    }

    ll cnt = 0;
    ll res = 0;
    while(minh.heap.size() >= 2){
        ll min_first = minh.extractMin();
        ll min_second = minh.extractMin();

       
        cnt += min_first;
        cnt += min_second;
        res += cnt;
        minh.insert(cnt);
        cnt = 0;
    }

    cout << res << endl;
}
