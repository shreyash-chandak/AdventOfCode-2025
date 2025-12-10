#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000

ll dist(vector<ll> &a, vector<ll> &b) {
    return (abs(a[0]-b[0])+1)*(abs(a[1]-b[1])+1);
}

void bound(vector<vector<ll>> &coords, vector<int> &boundL, vector<int> &boundR, int i) {
    int n = coords.size(), prev = (i-1+n)%n;
    int x1 = min(coords[prev][0], coords[i][0]);
    int x2 = max(coords[prev][0], coords[i][0]);
    int y1 = min(coords[prev][1], coords[i][1]);
    int y2 = max(coords[prev][1], coords[i][1]);
    for (int k = y1; k <= y2; k++) {
        if (x1 < boundL[k]) boundL[k] = x1;
        if (x2 > boundR[k]) boundR[k] = x2;
    }
}

bool check(vector<ll> &a, vector<ll> &b, vector<int> &boundL, vector<int> &boundR) {
    int x1 = min(a[0], b[0]), x2 = max(a[0], b[0]);
    int y1 = min(a[1], b[1]), y2 = max(a[1], b[1]);
    for (int k = y1; k <= y2; k++) {
        if (x1 < boundL[k] || x2 > boundR[k]) return false;
    }
    return true;
}

int main() {
    regex pattern("(\\d+),(\\d+)");
    vector<vector<ll>> coords;
    string line;
    smatch match;
    while (getline(cin, line)) {
        if (!regex_match(line, match, pattern)) continue;
        ll x = stoll(match[1].str());
        ll y = stoll(match[2].str());
        coords.push_back({x, y});
    }
    int n = coords.size();
    vector<int> boundL(N, INT_MAX);
    vector<int> boundR(N, -1);

    for (int i = 0; i < n; i++) bound(coords, boundL, boundR, i);
    ll partA = 0, partB = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            ll val = dist(coords[i], coords[j]);
            if (val > partA) partA = val;
            if (val > partB && check(coords[i], coords[j], boundL, boundR)) {
                partB = val;
            }
        }
    }

    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}