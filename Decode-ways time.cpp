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
    // bottom up approach
    vector<int> dp = vector<int>(101, -1);

public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size();
        dp[n] = 1; // dp_i = number of ways to decode a string starting at i and ending at n
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i + 1];
                if (i + 1 < n)
                {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))
                    {
                        dp[i] += dp[i + 2];
                    }
                }
            }
            // cout << i << " " << dp[i] << endl;
        }
        return dp[0]; // starting at 0 and ending at n
    }
};