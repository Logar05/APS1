#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &map, int h, int w, int startRow, int startCol) {
    if(!map[startRow][startCol]) return 0;
    vector<pair<int, int>> adj;
    int sum = 0;
    map[startRow][startCol] = 0;
    if(startCol - 1 >= 0 && map[startRow][startCol - 1]) adj.push_back({startRow, startCol - 1});
    if(startCol + 1 < w && map[startRow][startCol + 1]) adj.push_back({startRow, startCol + 1});
    if(startRow - 1 >= 0 && map[startRow - 1][startCol]) adj.push_back({startRow - 1, startCol});
    if(startRow + 1 < h && map[startRow + 1][startCol]) adj.push_back({startRow + 1, startCol});
    for(auto [row, col] : adj) {
        sum += dfs(map, h, w, row, col);
    }
    return 1 + sum;
}

void customDfs(vector<vector<int>> &map, int h, int w, vector<int> &results) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j]) results.push_back(dfs(map, h, w, i, j));
        }
    }
}


int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> map(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c == '#')
                map[i][j] = 1;
            else map [i][j] = 0;
        }
    }
    vector<int> results;

    customDfs(map, h, w, results);

    sort(results.begin(), results.end());

    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }

    return 0;
}