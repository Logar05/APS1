#include <bits/stdc++.h>
using namespace std;

struct segment {
    int primarnaOddaljenost;
    int sekundarnaOddaljenost;
    int length;
    int levaMeja;
    int desnaMeja;
    int indeks;
    int mesto;
};

bool comparatorZaPQ(segment &a, segment &b) {
    if(a.primarnaOddaljenost != b.primarnaOddaljenost) return a.primarnaOddaljenost < b.primarnaOddaljenost;
    if(a.sekundarnaOddaljenost != b.sekundarnaOddaljenost) return a.sekundarnaOddaljenost < b.sekundarnaOddaljenost;
    if(a.indeks != b.indeks) return a.indeks > b.indeks;
    return false;
}



int main() {
    int N, K;
    string s;
    cin >> N >> K;
    cin >> s;
    priority_queue<segment, vector<segment>, decltype(&comparatorZaPQ)> pq(&comparatorZaPQ);
    int lastTakenSeat = -1;
    for(int i = 0; i < N; i++) {
        if(s[i] == '*') {
            segment novi;
            novi.length = i - lastTakenSeat - 1;
            novi.levaMeja = lastTakenSeat;
            novi.desnaMeja = i;
            novi.mesto = (novi.levaMeja + novi.desnaMeja) / 2;
            novi.indeks = novi.mesto;
            novi.primarnaOddaljenost = min(novi.desnaMeja - novi.mesto, novi.mesto - novi.levaMeja);
            novi.sekundarnaOddaljenost = max(novi.desnaMeja - novi.mesto, novi.mesto - novi.levaMeja);
            lastTakenSeat = i;
            if(novi.length > 0) pq.push(novi);
        }
    }
    segment novi;
    novi.length = N - lastTakenSeat - 1;
    novi.levaMeja = lastTakenSeat;
    novi.desnaMeja = N;
    novi.mesto = (novi.levaMeja + novi.desnaMeja) / 2;
    novi.indeks = novi.mesto;
    novi.primarnaOddaljenost = min(novi.desnaMeja - novi.mesto, novi.mesto - novi.levaMeja);
    novi.sekundarnaOddaljenost = max(novi.desnaMeja - novi.mesto, novi.mesto - novi.levaMeja);
    lastTakenSeat = N;
    if(novi.length > 0) pq.push(novi);

    for(int i = 0; i < K; i++) {
        segment vrhni = pq.top();
        s[vrhni.mesto] = '*';
        segment levi, desni;
        levi.desnaMeja = vrhni.mesto;
        levi.levaMeja = vrhni.levaMeja;
        levi.mesto = (levi.levaMeja + levi.desnaMeja) / 2;
        levi.indeks = levi.mesto;
        levi.length = levi.desnaMeja - levi.levaMeja - 1;
        levi.primarnaOddaljenost = min(levi.desnaMeja - levi.mesto, levi.mesto - levi.levaMeja);
        levi.sekundarnaOddaljenost = max(levi.desnaMeja - levi.mesto, levi.mesto - levi.levaMeja);

        desni.desnaMeja = vrhni.desnaMeja;
        desni.levaMeja = vrhni.mesto;
        desni.mesto = (desni.levaMeja + desni.desnaMeja) / 2;
        desni.indeks = desni.mesto;
        desni.length = desni.desnaMeja - desni.levaMeja - 1;
        desni.primarnaOddaljenost = min(desni.desnaMeja - desni.mesto, desni.mesto - desni.levaMeja);
        desni.sekundarnaOddaljenost = max(desni.desnaMeja - desni.mesto, desni.mesto - desni.levaMeja);

        pq.pop();
        pq.push(levi);
        pq.push(desni);
    }

    cout << s;

    return 0;
}