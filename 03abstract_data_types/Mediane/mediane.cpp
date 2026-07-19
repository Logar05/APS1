#include <bits/stdc++.h>
using namespace std;


vector<int> sprotneMediane(int N, vector<int> &meritve) {
    priority_queue<int> manjsi;
    priority_queue<int, vector<int>, greater<int>> vecji;
    vector<int> runningMedians(N);
    for(int i = 0; i < N; i++) {
        manjsi.push(meritve[i]);
        int maxMin = manjsi.top();
        manjsi.pop();
        vecji.push(maxMin);

        if(vecji.size() > manjsi.size()) {
            int minMax = vecji.top();
            vecji.pop();
            manjsi.push(minMax);
        }
        runningMedians[i] = manjsi.top();
    }
    return runningMedians;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> meritve;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        meritve.push_back(x);
    }

    vector<int> runningMedians = sprotneMediane(N, meritve);
    for(int i = 0; i < N; i++) {
        cout << runningMedians[i] << "\n";
    }
    return 0;
}