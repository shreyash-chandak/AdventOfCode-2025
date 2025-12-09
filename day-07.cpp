#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<string> input;
    string line;
    while (getline(cin, line)) input.push_back(line);
    int N = input.size(), M = input[0].size();
    vector<vector<ll>> track(N, vector<ll>(M,0));
    ll partA = 0, partB = 0;
    for (int i = 0; i < M; i++) if (input[0][i]=='S') input[0][i] = '|', track[0][i] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[i-1][j]=='|' && input[i][j]!='^') input[i][j] = '|', track[i][j] += track[i-1][j];
            else if (input[i-1][j]=='|' && input[i][j]=='^') {
                partA++;
                if (j>0) input[i][j-1] = '|', track[i][j-1] += track[i-1][j];
                if (j<M-1) input[i][j+1] = '|', track[i][j+1] += track[i-1][j];
            }
        }
    }
    for (int i = 0; i < M; i++) partB += track[N-1][i];
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}