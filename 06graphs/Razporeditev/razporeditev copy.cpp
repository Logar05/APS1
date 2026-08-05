#include <bits/stdc++.h>
using namespace std;
#define BLACK 0
#define WHITE 1
bool conflict = false;

struct otrok {
    int barva = -1;
    int stevilka;
};

void color(vector<int> &colors, vector<vector<int>> &adj, int n) {
    for(int i = 0; i < n; i++) {
        if(colors[i] == -1) {
            colors[i] = BLACK;
        }
        for(int y : adj[i]) {
            if(colors[y] == colors[i]) conflict = true;
            if(colors[y] == -1) colors[y] = (colors[i] + 1) % 2; 
        }
    }
}

bool customCmp(otrok a, otrok b) {
    if(a.barva != b.barva) return a.barva < b.barva;
    return a.stevilka < b.stevilka;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> colors(n, -1);
    vector<vector<int>> adj(n);
    vector<otrok> otroci(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 0; i < n; i++) {
        otrok novi;
        novi.stevilka = i + 1;
        otroci.push_back(novi);
    }

    color(colors, adj, n);
    
    for(int i = 0; i < n; i++) {
        otroci[i].barva = colors[i] + 1;
    }

    if(conflict) cout << -1;
    else {
        for(int i = 0; i < n; i++) {
            cout << otroci[i].barva;
        }
    }
    return 0;
}