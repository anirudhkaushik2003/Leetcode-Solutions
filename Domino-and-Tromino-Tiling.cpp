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
    int numTilings(int n)
    {
        if (n == 0)
            return 0;

        vll dp(max(n + 1,3), 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            if (dp[i] > 1e9 + 7)
                dp[i] = dp[i]%(int)(1e9 + 7);
        }
        return dp[n];
    }
};
int main()
{
    Solution s;
    int ans = s.numTilings(3);
    cout << ans << endl;
}