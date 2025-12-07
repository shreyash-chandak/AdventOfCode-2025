#include <bits/stdc++.h>
using namespace std;

bool accessible(vector<string> &grid, int i, int j, int flag) {
    int N = grid.size(), M = grid[0].length();
    int n = (i>0 && grid[i-1][j]=='@') ? 1 : 0;
    int ne = (i>0 && j+1<M && grid[i-1][j+1]=='@') ? 1 : 0;
    int e = (j+1<M && grid[i][j+1]=='@') ? 1 : 0;
    int se = (i+1<N && j+1<M && grid[i+1][j+1]=='@') ? 1 : 0;
    int s = (i+1<N && grid[i+1][j]=='@') ? 1 : 0;
    int sw = (i+1<N && j>0 && grid[i+1][j-1]=='@') ? 1 : 0;
    int w = (j>0 && grid[i][j-1]=='@') ? 1 : 0; 
    int nw = (i>0 && j>0 && grid[i-1][j-1]=='@') ? 1 : 0;
    if ((n+ne+e+se+s+sw+w+nw)<4) {
        if (flag) grid[i][j] = 'x';
        return 1;
    } else return 0;
}

int main() {
    vector<string> grid;
    string str;
    int partA = 0, partB = 0;
    while (cin >> str) grid.push_back(str);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].length(); j++) {
            if (grid[i][j]=='@') partA += accessible(grid, i, j, 0);
        }
    }
    here:
    int curr = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].length(); j++) {
            if (grid[i][j]=='@') curr += accessible(grid, i, j, 1);
        }
    }
    if (curr>0) goto here;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].length(); j++) {
            if (grid[i][j]=='x') partB++;
        }
    }
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB << endl;
    return 0;
}