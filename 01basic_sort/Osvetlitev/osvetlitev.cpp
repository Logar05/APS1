#include <bits/stdc++.h>
using namespace std;


bool customCmp(pair<int, int> i1, pair<int, int> i2) {
    if(i1.first < i2.first) return true;
    else if(i1.first > i2.first) return false;
    else return i1.second < i2.second;
}

int main() {
    int n, m;
    cin >> m >> n;
    vector<pair<int, int>> intervali;

    for(int i = 0; i < n; i++) {
        int x, d;
        cin >> x >> d;
        int dl = max(0, x - d);
        int dr = min(m, x + d);
        intervali.push_back({dl, dr});
    }

    if(intervali.size() == 0) {
        cout << m;
        return 0;
    }

    sort(intervali.begin(), intervali.end(), customCmp);
    int prevLeft = intervali[0].first;
    int prevRight = intervali[0].second;
    int neosvetljeno = prevLeft;
    for(int i = 1; i < intervali.size(); i++) {
        int currentLeft = intervali[i].first;
        int currentRight = intervali[i].second;
        int razlika = currentLeft - prevRight;
        if(razlika >= 0) neosvetljeno = neosvetljeno + razlika;
        if(currentRight > prevRight) prevRight = currentRight;
        prevLeft = currentLeft;
    }
    neosvetljeno = neosvetljeno + (m - prevRight);

    cout << neosvetljeno << "\n";

    return 0;
}