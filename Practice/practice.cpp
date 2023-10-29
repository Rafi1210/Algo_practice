#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> contests;

    for (int i = 0; i < n; i++) {
        int luck, importance;
        cin >> luck >> importance;
        contests.push_back({luck, importance});
    }

    vector<int> importantLuck;

    int luckBalance = 0;

    for (const auto& contest : contests) {
        int luck = contest.first;
        int importance = contest.second;

        if (importance == 1) {
            importantLuck.push_back(luck);
        } else {
            luckBalance += luck;
        }
    }

    sort(importantLuck.begin(), importantLuck.end());

    for (int i = 0; i < importantLuck.size(); i++) {
        if (i < importantLuck.size() - k) {
            luckBalance -= importantLuck[i]; // Lose the most luck-intensive contests
        } else {
            luckBalance += importantLuck[i]; // Win the remaining important contests
        }
    }

    cout << luckBalance << endl;

    return 0;
}
