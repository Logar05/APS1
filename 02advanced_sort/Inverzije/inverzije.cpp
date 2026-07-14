#include <bits/stdc++.h>
using namespace std;
long long stInverzij = 0;

vector<long long> merge(vector<long long> &l, vector<long long> &r) {
    vector<long long> c;
    long long i = 0; long long j = 0;
    while(i < l.size() || j < r.size()) {
        if(i < l.size() && j < r.size()) {
            if(l[i] <= r[j]) c.push_back(l[i++]);
            else {
                c.push_back(r[j++]);
                stInverzij += l.size() - i;
            }
        }
        else if (i < l.size()) c.push_back(l[i++]);
        else {
            c.push_back(r[j++]);
        }
    }
    return c;
}

vector<long long> mergeSort(vector<long long> &seznam) {
    long long n = seznam.size();
    if(n <= 1) return seznam;
    vector<long long> l(seznam.begin(), seznam.begin() + n/2);
    vector<long long> r(seznam.begin() + n/2, seznam.end());
    l = mergeSort(l);
    r = mergeSort(r);
    return merge(l, r);
}

int main() {
    long long n;
    cin >> n;
    vector<long long> seznam;
    for(long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        seznam.push_back(x);
    }
    mergeSort(seznam);
    cout << stInverzij << "\n";
    return 0;
}