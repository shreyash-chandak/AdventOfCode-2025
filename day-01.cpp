#include <bits/stdc++.h>
using namespace std;

#define mod (int)1e6

int main() {
    regex pattern(R"(^(L|R)(\d+)$)");
    smatch match;
    int dial = 50, partA = 0, partB = 0;
    string input;
    while (cin >> input) {                 
        if (!regex_match(input, match, pattern)) continue; 
        string dir = match[1].str();
        int num = stoi(match[2].str());
        if (dir == "L" && (dial-num)<=0) {
            partB += abs(dial-num)/100 + (dial!=0);
        } else if (dir == "R" && (dial+num)>=100) {
            partB += (dial+num)/100;
        }
        dial = (dir=="R") ? (dial+num)%100 : (dial-num+mod)%100;
        if (dial==0) partA++;
    }
    cout << "Part A: " << partA << endl;
    cout << "Part B: " << partB;
    return 0;
}
