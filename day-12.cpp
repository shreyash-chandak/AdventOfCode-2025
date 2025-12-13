#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int partA = 0;
    regex pattern(R"((\d+)x(\d+): (\d+) (\d+) (\d+) (\d+) (\d+) (\d+))");
    while (getline(cin, line)) {
        smatch match;
        if (!regex_match(line, match, pattern)) continue;
        int x = stoi(match[1]), y = stoi(match[2]), sum = 0;
        for (int i = 3; i <= 8; i++) sum += stoi(match[i]);
        if (sum*9 <= x*y) partA++;
    }
    cout << "Part A: " << partA << endl;
    return 0;
}