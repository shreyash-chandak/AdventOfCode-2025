#include <bits/stdc++.h>
using namespace std;
#define N 1000
#define ll long long
#define ld long double

struct DSU {
    vector<int> parent, size; 
    
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int iroot = find(i);
        int jroot = find(j);
        
        if (iroot != jroot) {
            if (size[iroot] < size[jroot]) swap(iroot, jroot);
            parent[jroot] = iroot;
            size[iroot] += size[jroot]; 
            return true;
        }
        return false;
    }
};

ld dist(vector<int> &a, vector<int> &b) {
    return (pow(a[0]-b[0],2) + pow(a[1]-b[1],2) + pow(a[2]-b[2],2));
}

int main() {
    regex pattern("(\\d+),(\\d+),(\\d+)");
    string line;
    vector<vector<int>> coords;
    vector<vector<ld>> dists;
    while (getline(cin, line)) {
        smatch match;
        if (!regex_match(line,match,pattern)) continue;
        coords.push_back({stoi(match[1]), stoi(match[2]), stoi(match[3])});
    }
    int n = coords.size();
    for (ld i = 0; i < n-1; i++) {
        for (ld j = i+1; j < n; j++) {
            dists.push_back({i, j, dist(coords[i], coords[j])});
        }
    }
    sort(dists.begin(),dists.end(), [](vector<ld> &a, vector<ld> &b) {
        return a[2] < b[2];
    });

    DSU dsu(n);
    ll partA = 0, partB = 0;
    for (int k = 0; k < dists.size(); k++) {
        int u = (int)dists[k][0];
        int v = (int)dists[k][1];
        dsu.unite(u, v);

        if (k == N-1) {
            vector<int> sizes;
            for (int i = 0; i < n; i++) {
                if (dsu.parent[i] == i) sizes.push_back(dsu.size[i]);
            }
            sort(sizes.rbegin(), sizes.rend());
            
            ll a = (sizes.size() > 0) ? sizes[0] : 1;
            ll b = (sizes.size() > 1) ? sizes[1] : 1;
            ll c = (sizes.size() > 2) ? sizes[2] : 1;
            partA = a * b * c;
        }

        if (dsu.size[dsu.find(u)] == n) {
            partB = (ll)coords[u][0] * (ll)coords[v][0];
            break;
        }
    }
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}