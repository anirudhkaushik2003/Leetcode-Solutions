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
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());

        vll dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (coin > i)
                    break;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    Solution s;
    vi coins = {1, 2, 5};
    int ans = s.coinChange(coins, 11);
    cout << ans << endl;
}