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
    ll countGoodStringsSub(int l, int zero, int one, vll &dp)
    {
        if (dp[l] != -1)
            return dp[l];
        if (l == 0)
            return 1;

        ll ans = 0;
        if (l >= zero)
            ans += countGoodStringsSub(l - zero, zero, one, dp);
        if (ans >= (1e9 + 7))
        {
            ans = ans % (ll)(1e9 + 7);
        }
        if (l >= one)
            ans += countGoodStringsSub(l - one, zero, one, dp);
        if (ans >= (1e9 + 7))
        {
            ans = ans % (ll)(1e9 + 7);
        }

        dp[l] = ans;
        return dp[l];
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        ll ans = 0;
        vll dp(high + 1, -1);
        for (int i = low; i <= high; i++)
        {
            ans += countGoodStringsSub(i, zero, one, dp);
            if (ans >= (1e9 + 7))
            {
                ans = ans % (ll)(1e9 + 7);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int ans = s.countGoodStrings(3,3,1,1);
    cout << ans << endl;
}