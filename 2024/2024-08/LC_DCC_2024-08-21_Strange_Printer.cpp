// LC DCC 2024/08/21
// 664. Strange Printer
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;

            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] + 1;

                for(int k = i; k < j; ++k)
                    if(s[k] == s[j])
                        dp[i][j] = min(dp[i][j], dp[i][k] + ((k + 1 <= j - 1)? dp[k + 1][j - 1]: 0));
            }
        }
        
        return dp[0][n - 1];
    }
};

int main() {
    int T = 1;
    cin >> T;
    Solution ob;
    while (T--) {
        string s;
        cin >> s;
        cout << ob.strangePrinter(s) << endl;
    }

    return 0;
}

/* Sample Input
2
aaabbb
aba

Sample Output
2
2

*/