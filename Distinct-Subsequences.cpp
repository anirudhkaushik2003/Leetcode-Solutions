#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();

        s = " " + s;
        t = " " + t;

        if (n < m)
        {
            return 0;
        }
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 1;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[j][0] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[j] == t[i])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};