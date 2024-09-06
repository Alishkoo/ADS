#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Maxheap
{
    vector<int> heap;
    ll parent(int i)
    {
        return (i - 1) / 2;
    }
    ll left(int i)
    {
        return (2 * i) + 1;
    }
    ll right(int i)
    {
        return (2 * i) + 2;
    }

    void insert(ll val)
    {
        this->heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] < this->heap[i])
        {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    ll extractMAX()
    {
        if (heap.empty())
        {
            return INT_MIN;
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
        ll biggest = i;
        if (leftt < heap.size() && heap[leftt] > heap[biggest])
        {
            biggest = leftt;
        }
        if (rightt < heap.size() && heap[rightt] > heap[biggest])
        {
            biggest = rightt;
        }
        if (biggest != i)
        {
            swap(heap[i], heap[biggest]);
            heapify(biggest);
        }
    }
};

int main(){
    int n;
    cin >> n;

    Maxheap maxh;

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        maxh.insert(x);
    }

    while(maxh.heap.size() > 1){
        ll max_first = maxh.extractMAX();
        ll max_second = maxh.extractMAX();
        
        if(max_first != max_second){
            maxh.insert(max_first - max_second);
        }
    }

    if(!maxh.heap.empty()){
        cout << maxh.heap[0] << endl;
    }   
    else{
        cout << 0 << endl;
    }
}