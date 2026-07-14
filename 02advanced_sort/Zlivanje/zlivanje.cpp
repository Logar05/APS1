#include <bits/stdc++.h>
using namespace std;

int n, k, a;

int getMin(vector<vector<int>> &zunanji, vector<int> &indexArray, int startIx, int endIx) {
    int indexToInc = -1;
    int min = INT_MAX;
    int notranjiIndex = 0;
    int currentIx = indexArray[notranjiIndex];
    for(int i = startIx; i < endIx; i++) {
        currentIx = indexArray[notranjiIndex];
        if(currentIx >= zunanji[i].size()) {
            notranjiIndex++;
            continue;
        }
        int kandidatZaMin = zunanji[i][currentIx];
        if(kandidatZaMin < min) {
            indexToInc = notranjiIndex;
            min = kandidatZaMin;
        }
        notranjiIndex++;
    }
    if(indexToInc == -1) return -1;
    else {
        indexArray[indexToInc]++;
        return min;
    }
}

vector<int> k_way_merge(vector<vector<int>> &zunanji, int startIndex, int endIndex) {
    vector<int> merged;
    int diff = endIndex - startIndex;
    vector<int> indexArray(diff, 0);
    int minElement;
    while((minElement = getMin(zunanji, indexArray, startIndex, endIndex)) != -1) {
        merged.push_back(minElement);
    }
    return merged;
}

bool isSorted(vector<vector<int>> &zunanji) {
    int previous = zunanji[0][0];
    for(int i = 0; i < zunanji.size(); i++) {
        for(int j = 0; j < zunanji[i].size(); j++) {
            if(zunanji[i][j] < previous) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> k >> a;
    vector<vector<int>> zunanji;
    vector<int> notranji;

    int stevilo_cet = 0;
    bool ascending_flag = true;
    int prev_x;
    cin >> prev_x;
    notranji.push_back(prev_x);
    for(int i = 1; i < n; i++) {
        int current_x;
        cin >> current_x;
        if(current_x < prev_x) {
            stevilo_cet++;
            zunanji.push_back(notranji);
            notranji.clear();
            notranji.push_back(current_x);
        }
        else {
            notranji.push_back(current_x);
        }
        prev_x = current_x;
    }
    zunanji.push_back(notranji);

    int startIndex = 0;
    int endIndex = min(startIndex + k, (int)zunanji.size());

    for(int i = 0; i < a; i++) {
        vector<vector<int>> novZunanji;
        while(startIndex < endIndex && startIndex < zunanji.size()) {
            vector<int> mergedVector = k_way_merge(zunanji, startIndex, endIndex);
            
            novZunanji.push_back(mergedVector);

            startIndex += k;
            endIndex = min(startIndex + k, (int)zunanji.size());
        }
        zunanji = novZunanji;
        startIndex = 0;
        endIndex = min(startIndex + k, (int)zunanji.size());
    }

    for(int i = 0; i < zunanji.size(); i++) {
        for(int j = 0; j < zunanji[i].size(); j++) {
            cout << zunanji[i][j] << " ";
        }
    }
    
    return 0;
}