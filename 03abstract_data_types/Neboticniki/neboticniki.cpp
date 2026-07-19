#include <bits/stdc++.h>
using namespace std;

int nextGreaterElementSum(vector<int> array) {
    int sum = 0;
    stack<int> sklad;
    int n = array.size();
    int sumOfRightSight = 0;
    int rightEdge = n - 1;
    vector<int> visibility(n);
    for(int i = n - 1; i >= 0; i--) {
        int currentElement = array[i];
        while((!sklad.empty()) && currentElement >= array[sklad.top()]) {
            sklad.pop();
        }
        if(!sklad.empty()) sumOfRightSight += (sklad.top() - i - 1);
        if(sklad.empty()) sumOfRightSight += (rightEdge - i);
        sklad.push(i);
    }

    return sumOfRightSight;
}

int main() {
    vector<int> left;
    vector<int> right;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        right.push_back(h);
    }

    for(int i = 0; i < n; i++) {
        left.push_back(right[n - 1 - i]);
    }

    int Z = 0;
    Z += nextGreaterElementSum(left);
    Z += nextGreaterElementSum(right);
    cout << Z;

    return 0;
}