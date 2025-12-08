#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 4 // number of operand rows

int main() {
    regex operands("\\s*(\\d+)\\s*");
    regex operators("\\s*(\\+|\\*)\\s*");
    string line;
    vector<string> lines;
    vector<vector<int>> operandsList;
    vector<char> operatorsList;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        lines.push_back(line);
        vector<int> curr;
        sregex_iterator it(line.begin(), line.end(), operands), end;
        for (; it != end; it++) curr.push_back(stoi((*it)[1]));
        operandsList.push_back(curr);
    }
    getline(cin, line);
    sregex_iterator it(line.begin(), line.end(), operators), end;
    for (; it != end; it++) operatorsList.push_back((*it)[1].str()[0]);
    ll partA = 0, partB = 0;
    for (int i = 0; i < operandsList[0].size(); i++) {
        char op = operatorsList[i];
        ll ans = (op=='+') ? 0 : 1;
        for (int j = 0; j < operandsList.size(); j++) {
            ans = (op=='+') ? ans+operandsList[j][i] : ans*operandsList[j][i];
        }
        partA += ans;
    }
    int n = lines[0].length(), ops = operatorsList.size()-1;
    ll ans = (operatorsList[ops]=='+') ? 0 : 1;
    for (int i = n-1; i>=0; i--) {
        char op = operatorsList[ops];
        ll num = 0;
        for (int j = 0; j < N; j++) {
            if (isdigit(lines[j][i])) {
                num = num*10 + (lines[j][i]-'0');
            }
        }
        if (num==0) {
            partB += ans;
            ops--;
            ans = (operatorsList[ops]=='+') ? 0 : 1;
            continue;
        }
        ans = (op=='+') ? ans+num : ans*num;
        if (i==0) partB += ans;
    }
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}