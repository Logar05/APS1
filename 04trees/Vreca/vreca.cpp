#include <bits/stdc++.h>
using namespace std;
#define N 1048576

class RAQ {
    private:
        int n = N;
        vector<int> f;
        struct Node {
            int begin;
            int end;
            int amount;
        };
        vector<Node> tree;
    public:
        RAQ(vector<int> &a) {
            f = a;
            tree.resize(2 * N);
            build();
        }
        void build(int id = 1) {
            if(id >= N) {
                tree[id] = {id - n, id - n, f[id - n]};
                return;
            }
            int left = 2 * id;
            int right = 2 * id + 1;
            build(left);
            build(right);
            tree[id] = {tree[left].begin, tree[right].end, tree[left].amount + tree[right].amount};
        }

        void insert(int element) {
            f[element]++;
            insertInternal(element);
        }

        void insertInternal(int element, int id = 1) {
            int levaMeja = tree[id].begin;
            int desnaMeja = tree[id].end;
            if(element > desnaMeja || element < levaMeja) return;
            tree[id].amount++;
            if(id >= N) return;
            insertInternal(element, id * 2);
            insertInternal(element, id * 2 + 1);
        }

        void remove(int element) {
            if(f[element] == 0) return;
            f[element]--;
            removeInternal(element);
        }

        void removeInternal(int element, int id = 1) {
            int levaMeja = tree[id].begin;
            int desnaMeja = tree[id].end;
            if(element > desnaMeja || element < levaMeja) return;
            tree[id].amount--;
            if(id >= N) return;
            removeInternal(element, id * 2);
            removeInternal(element, id * 2 + 1);
        }

        int query(int l, int r, int id = 1) {
            int levaMeja = tree[id].begin;
            int desnaMeja = tree[id].end;
            if(levaMeja >= l && desnaMeja <= r) return tree[id].amount;
            if(desnaMeja < l || levaMeja > r) return 0;
            return query(l, r, id * 2) + query(l, r, id * 2 + 1);
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> f(N, 0);
    long long sum = 0;
    RAQ *raq = new RAQ(f);
    for(int i = 0; i < n; i++) {
        int s, x;
        cin >> s >> x;
        if(s < 0) raq->insert(x);
        if(s == 0) raq->remove(x);
        if(s > 0) {
            int a = min(s, x);
            int b = max(s, x);
            sum += raq->query(a, b);
        }
    }
    cout << sum;
    return 0;
}