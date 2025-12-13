#include <bits/stdc++.h>
using namespace std;

int main() {
    regex p1(R"(\[([.#]+)\])");
    regex p2(R"(\(([\d,]+)\))");
    string line;
    long long partA = 0;

    while (getline(cin, line)) {
        smatch match;
        if (!regex_search(line, match, p1)) continue;
        string inner = match[1].str();
        reverse(inner.begin(), inner.end());

        int want = 0;
        for (char c : inner) want = (want << 1) | (c == '#' ? 1 : 0);
        vector<int> have;
        sregex_iterator i(line.begin(), line.end(), p2), end;

        for (; i != end; ++i) {
            string str = (*i)[1].str();
            int mask = 0;
            stringstream ss(str);
            string segment;
            while (getline(ss, segment, ',')) {
                mask |= (1 << stoi(segment));
            }
            have.push_back(mask);
        }
        deque<pair<int, int>> q;
        q.push_back({0, 0}); 
        
        set<int> vis;
        vis.insert(0);
        
        bool found = false;
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop_front();
            
            int c = curr.first;
            int x = curr.second;

            if (x == want) {
                partA += c;
                found = true;
                break;
            }

            for (int h : have) {
                int next = x ^ h;
                if (vis.find(next) == vis.end()) {
                    vis.insert(next);
                    q.push_back({c + 1, next});
                }
            }
        }
    }

    cout << "Part A: " << partA << endl;
    return 0;
}