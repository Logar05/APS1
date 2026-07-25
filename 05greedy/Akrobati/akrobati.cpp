#include <bits/stdc++.h>
using namespace std;


bool customCmp(pair<long long, long long> &a, pair<long long, long long> &b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    int T;
    cin >> T;
    for(int k = 0; k < T; k++) {
        int N;
        cin >> N;
        vector<pair<long long, long long>> akrobati(N);
        for(int i = 0; i < N; i++) {
            long long t; // teze
            cin >> t;
            akrobati[i].first = t;
        }

        for(int i = 0; i < N; i++) {
            long long m; // moci
            cin >> m;
            akrobati[i].second = m;
        }

        sort(akrobati.begin(), akrobati.end(), customCmp);

        vector<long long> W(N, 0);
        for(int i = N - 2; i >= 0; i--) {
            W[i] = W[i + 1] + akrobati[i + 1].first;
        }
        string out = "DA";
        for(int i = 0; i < N; i++) {
            if(akrobati[i].second < W[i]) {
                out = "NE";
                break;
            }
        }
        cout << out << "\n";
    }
    return 0;
}