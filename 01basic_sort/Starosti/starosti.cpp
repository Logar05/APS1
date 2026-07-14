#include <bits/stdc++.h>
using namespace std;

bool customCmp(pair<int, string> &p1, pair<int, string> &p2) {
    if(p1.first < p2.first) return false;
    else if (p1.first > p2.first) return true;
    return false;
}

bool cmpName(pair<int, string> &p1, pair<int, string> &p2) {
    int i = 0;
        while(i < p1.second.length() && i < p2.second.length()) {
            if(p1.second[i] < p2.second[i]) return true;
            else if (p1.second[i] > p2.second[i]) return false;
            i++;
        }
        if(p1.second.length() < p2.second.length()) return true;
        else return false; 
}

//insertion
void customSortAge(vector<pair<int, string>> &osebe) {
    int n = osebe.size();
    for(int i = 1; i < n; i++) {
        int x = osebe[i].first;
        pair<int, string> osebaToCmp = osebe[i];
        int j = i - 1;
        while(j >= 0 && osebe[j].first < x) {
            osebe[j + 1] = osebe[j];
            j--;
        }
        osebe[j + 1] = osebaToCmp;
    }
}

void customSortName(vector<pair<int, string>> &osebe) {
    int n = osebe.size();
    for(int i = 1; i < n; i++) {
        pair<int, string> osebaToCmp = osebe[i];
        int j = i - 1;
        while(j >= 0 && cmpName(osebaToCmp, osebe[j])) {
            osebe[j + 1] = osebe[j];
            j--;
        }
        osebe[j + 1] = osebaToCmp;
    }

} 

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, string>> osebe;
    for(int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> name >> age;
        pair<int, string> oseba = {age, name};
        osebe.push_back(oseba);
    }
    
    /*sort(osebe.begin(), osebe.end(), customCmp);
    sort(osebe.begin(), osebe.begin() + k, cmpName);
    vector<pair<int, string>> imena;
    */
    customSortAge(osebe);
    vector<pair<int, string>> subVec;
    subVec.assign(osebe.begin(), osebe.begin() + k);
    customSortName(subVec);
    for(int i = 0; i < k; i++) {
        cout << subVec[i].second << "\n";
    }

    return 0;
}