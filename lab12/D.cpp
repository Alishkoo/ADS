#include <iostream>

using namespace std;

const int N = 2e5+5 , inf = 2e9 + 7;
int x[N], y[N];
int p[N];
int ans = 0;

int getted_upd(int v) {
    if(v == p[v])
        return v;
    return p[v] = getted_upd(p[v]);
}

bool unite(int a, int b) {
    a = getted_upd(a);
    b = getted_upd(b);
    if(a == b)
        return 0;
    if(rand() % 2)
        swap(a, b);
    p[b] = a;
    return 1;
}

void bin(int l, int r, int n) {
    while(l <= r) {
        int md = l + r >> 1;
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (abs(x[i]-x[j]) + abs(y[i]-y[j]) <= md) unite(i, j);
            }
        }
        if(getted_upd(1) == getted_upd(n)) {
            ans = md;
            r = md - 1;
        }
        else {
            l = md + 1;
        }
    }
} 

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
    }
    bin(0, inf, n);
    cout << ans;
}