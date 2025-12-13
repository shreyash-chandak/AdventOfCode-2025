#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<tuple<string, int, int>, ll> cache;

ll findPaths(map<string, vector<string>> &paths, string key, ll dac, ll fft) {
    tuple<string, int, int> state = make_tuple(key, dac, fft);
    if (cache.find(state) != cache.end()) return cache[state];
    ll ans = 0;
    for (auto v : paths[key]) {
        if (v == "out") return dac&&fft;
        else ans += findPaths(paths, v, (dac | v == "dac"), (fft | v == "fft"));
    }
    return cache[state] = ans;
}

int main() {
    regex pattern(R"(\w+)");
    string line;
    map<string, vector<string>> paths;
    while (getline(cin, line)) {
        sregex_iterator it(line.begin(), line.end(), pattern), end;
        vector<string> temp;
        string key = it++->str();
        for (; it != end; ++it) temp.push_back(it->str());
        paths[key] = temp;
    }
    ll partA = 0, partB = 0;
    deque<string> dq;
    dq.push_back("you");
    while (!dq.empty()) {
        string key = dq.front();
        dq.pop_front();
        if (key=="out") {
            partA++;
            continue;
        }
        for (auto i: paths[key]) dq.push_back(i);
    }
    partB = findPaths(paths, "svr", 0, 0);
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}