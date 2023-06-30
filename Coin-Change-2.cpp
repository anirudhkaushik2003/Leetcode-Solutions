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
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());

        vi dp(amount + 1);
        dp[0] = 1;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        }
        return dp[amount];
    }
};