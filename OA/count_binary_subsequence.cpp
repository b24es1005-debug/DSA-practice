#include <bits/stdc++.h>
using namespace std;

long long countSubsequences(string s, int k) {
    string p = "";
    // Binary representation
    while (k) {
        p.push_back((k & 1) + '0');
        k >>= 1;
    }
    reverse(p.begin(), p.end());

    int m = p.size();
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;
    for (char c : s) {
        // Traverse backwards to avoid recomputing
        for (int j = m; j >= 1; j--) {
            if (c == p[j - 1])
                dp[j] += dp[j - 1];
        }
    }
    return dp[m];
}