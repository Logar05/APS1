#include <bits/stdc++.h>
using namespace std;

int main() {
    int P, K;
    int shortestPath = INT_MAX;
    vector<pair<int, int>> pozicija_vrsta;
    cin >> P >> K;
    for(int i = 0; i < P; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            pozicija_vrsta.push_back({x, i});
        }
    }

    sort(pozicija_vrsta.begin(), pozicija_vrsta.end());

    int R = 0;
    vector<int> freq(P);
    int n = pozicija_vrsta.size();
    int stVrst = 0;
    int shortestWindow = INT_MAX;
    int bestL = 0;
    int bestR = 0;
    int L;
    for(L = 0; L < n; L++) {
        while(R < n && stVrst < K) {
            int kandidatVrsta = pozicija_vrsta[R].second;
            freq[kandidatVrsta]++;
            if(freq[kandidatVrsta] == 1) stVrst++;
            R++;
        }
        int length = pozicija_vrsta[R - 1].first - pozicija_vrsta[L].first;
        if(length < shortestWindow && stVrst >= K) {
            bestL = L;
            bestR = R;
            shortestWindow = length;
        }
        int spodnjaVrsta = pozicija_vrsta[L].second;
        freq[spodnjaVrsta]--;
        if(freq[spodnjaVrsta] == 0) {
            stVrst--;
        }
    }
    cout << pozicija_vrsta[bestL].first << " " << pozicija_vrsta[bestR - 1].first;
    return 0;
}