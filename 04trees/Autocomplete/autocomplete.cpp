#include <bits/stdc++.h>
using namespace std;

struct trieNode {
    trieNode* otroci[26] = {};
    bool jeBeseda = false;
    int maxWeight;
    int maxIndex = 0;
}; 

int searchString(const string &s, trieNode* current) {
    int n = s.length();
    int returnIndeks = 0;
    for(int i = 0; i < n; i++) {
        int indeks = s[i] - 'a';
        if(current->otroci[indeks] == NULL) return 0;
        returnIndeks = current->otroci[indeks]->maxIndex;
        current = current->otroci[indeks];
    }
    return returnIndeks;
}

void insert(const string &s, int weight, trieNode* current, int indeksDodaje) {
    int n = s.length();
    for(int i = 0; i < n; i++) {
        int indeks = s[i] - 'a';
        if(current->otroci[indeks] == NULL) {
            trieNode* novi = new trieNode();
            if(i == n - 1) novi->jeBeseda = true;
            novi->maxWeight = weight;
            novi->maxIndex = indeksDodaje;
            current->otroci[indeks] = novi;
        } else {
            trieNode* naslednik = current->otroci[indeks];
            if(naslednik->maxWeight < weight) {
                naslednik->maxWeight = weight;
                naslednik->maxIndex = indeksDodaje;
            }
        }
        current = current->otroci[indeks];
    }
}

void dfsPrint(trieNode* current, string buffer) {
    if(current->jeBeseda) {
        cout << buffer << " ";
    }
    for(int i = 0; i < 26; i++) {
        if(current->otroci[i] == NULL) continue;
        char znak = 'a' + i;
        buffer = buffer + znak;
        dfsPrint(current->otroci[i], buffer);
    }
}

int main() {
    int n;
    cin >> n;
    trieNode* root = new trieNode();
    for(int i = 0; i < n; i++) {
        string s;
        int w;
        cin >> s >> w;
        insert(s, w, root, i + 1);
    }
    int m;
    cin >> m;
    vector<int> results;
    for(int i = 0; i < m; i++) {
        string srchStr;
        cin >> srchStr;
        int retVal = searchString(srchStr, root);
        results.push_back(retVal);
    }

    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << "\n";
    }

    return 0;
}