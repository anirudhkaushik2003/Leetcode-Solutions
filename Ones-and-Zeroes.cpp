#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vi> dp(m + 1, vi(n + 1, 0));
        int s = strs.size();
        int cur_max = 0;
        for (int i = 0; i < s; i++)
        {
            int ones = 0, zeroes = 0;
            for (auto ch : strs[i])
            {
                if (ch == '1')
                    ones++;
                else
                    zeroes++;
            }
            for (int j = m; j >= zeroes; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeroes][k - ones]);
                    cur_max = max(cur_max, dp[j][k]);
                }
            }
        }
        return cur_max;
    }
};