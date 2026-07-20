#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> nadrejeni(N + 1);
vector<int> povisice(N + 1);
vector<int> podrejeni[N + 1];

void dfsPoDrevesu(int sum, int oseba) {
    povisice[oseba] += sum;
    for(int podrejen : podrejeni[oseba]) {
        dfsPoDrevesu(povisice[oseba], podrejen);
    }
}

int main() { 
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int nadrejen;
        cin >> nadrejen;
        nadrejeni[i] = nadrejen;
        int podrejen = i;
        podrejeni[nadrejen].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        povisice[i] = d;
    }


    for(int podrejen : podrejeni[0]) {
        dfsPoDrevesu(0, podrejen); //podrejeni od 0 -> sefi, vrh hierarhije, root drevesa
    }

    for(int i = 1; i <= n; i++) {
        cout << povisice[i] << " ";
    }

    return 0;
}