#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int,int> bisect(string str, int l, int r) {
    int max = -1, ind = -1;
    for (int i = l; i <= r; i++) {
        if (str[i]-'0' > max) {
            max = str[i]-'0';
            ind = i;
        }
    }
    return {max, ind};
}

ll joltage(string str, int n) {
    vector<int> jolts(n, 0);
    int size = str.length(), start = 0;
    for (int i = 0; i < n; i++) {
        pair<int,int> p = bisect(str, start, size - n + i);
        jolts[i] = p.first, start = p.second + 1;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) sum = sum*10 + jolts[i];
    return sum;
}

int main() {
    string str;
    vector<string> store;
    while (cin >> str) store.push_back(str);
    ll partA = 0, partB = 0;
    for (int i = 0; i < store.size(); i++) {
        partA += joltage(store[i], 2);
        partB += joltage(store[i], 12);
    }
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB << endl;
    return 0;
}