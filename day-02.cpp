#include <bits/stdc++.h>
using namespace std;
#define ll long long

string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) output += a;
    return output;
}

bool checkIfRepeatedN(ll num, int n) {
    int digits = int(log10(num))+1;
    if (digits%n!=0) return false;
    string strnum = to_string(num);
    if (((strnum.substr(0, digits/n)) * n) == strnum) {
        // printf("%10s * %d = %10s\n", strnum.substr(0, digits/n).c_str(), n, strnum.c_str());
        return true;
    } else return false;
}

int main() {
    vector<pair<ll,ll>> store;
    string ranges;
    cin >> ranges;
    regex pattern("(\\d+)-(\\d+)");
    auto start = sregex_iterator(ranges.begin(), ranges.end(), pattern), end = sregex_iterator();
    for (auto it = start; it != end; it++) {
        smatch match = *it;
        store.push_back(make_pair(stoll(match[1].str()),stoll(match[2].str())));
    }
    ll partA = 0, partB = 0;
    for (int i = 0; i < store.size(); i++) {
        for (ll j = store[i].first; j <= store[i].second; j++) {
            for (int k = 2; k <= 10; k++) {
                bool res = checkIfRepeatedN(j, k);
                partB += res ? j : 0, partA += (res && k == 2) ? j : 0;
                if (res) break;
            }
        }
    }
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB << endl;
    return 0;
}