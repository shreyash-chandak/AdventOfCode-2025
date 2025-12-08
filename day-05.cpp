#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool search(vector<vector<ll>> &ranges, ll x) {
    int left = 0, right = ranges.size() - 1;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (x >= ranges[mid][0] && x <= ranges[mid][1]) {
            return true;
        } else if (x < ranges[mid][0]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    regex pattern("(\\d+)-(\\d+)");
    smatch match;
    string line;
    vector<vector<ll>> ranges;
    while (getline(cin, line)) {
        if (line=="") break;
        if (!regex_match(line, match, pattern)) continue;
        ll a = stoll(match[1].str()), b = stoll(match[2].str());
        ranges.push_back({a, b});
    }
    sort(ranges.begin(), ranges.end(), [](vector<ll>& r1, vector<ll>& r2) {
        return r1[0] < r2[0];
    });
    int n = ranges.size();
    ll partA = 0, partB = 0, x;
    for (int i = 1; i < n; i++) {
        if (ranges[i][0] <= ranges[i-1][1]+1) {
            ranges[i-1][1] = max(ranges[i-1][1], ranges[i][1]);
            ranges.erase(ranges.begin()+i);
            i--, n--;
        }
    }
    while (cin >> x) {
        partA += search(ranges,x);
    }
    for (int i = 0; i < n; i++) partB += (ranges[i][1]-ranges[i][0]+1);
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}