#include <bits/stdc++.h>
using namespace std;

//NAIVE
int maxSt(int zepnina, vector<int> &cene) {
    int sum = 0;
    int counter = 0;
    for(int i = 0; i < cene.size(); i++) {
        if(sum + cene[i] <= zepnina) {
            sum = sum + cene[i];
            counter++;
        }
        else break;
    }
    return counter;
}
//

long long binarySearchCustom(int zepnina, vector<long long> &accumCene) {
    long long lo = 0;
    long long hi = accumCene.size() - 1;
    long long out = -1;
    while(lo <= hi) {
        long long mid = (lo + hi) / 2;
        if(accumCene[mid] <= zepnina) {
            out = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return out;
}

int main() {
    int S, D;
    cin >> S >> D;
    vector<long long> ceneSladic;

    for(int i = 0; i < S; i++) {
        int c;
        cin >> c;
        ceneSladic.push_back(c);
    }

    sort(ceneSladic.begin(), ceneSladic.end());
    
    vector<long long> accumulativeSum(S);
    accumulativeSum[0] = ceneSladic[0];
    for(int i = 1; i < S; i++) {
        accumulativeSum[i] = accumulativeSum[i - 1] + ceneSladic[i];
    }

    int sum = 0;
    for(int i = 0; i < D; i++) {
        long long z;
        cin >> z;
        //int out = maxSt(z, ceneSladic); NAIVEE
        long long out = binarySearchCustom(z, accumulativeSum) + 1;
        cout << out << " ";
    }

    return 0;
}