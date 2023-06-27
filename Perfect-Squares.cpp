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
    int numSquaresSub(int n, vi &dp)
    {
        if (dp[n] != -1)
            return dp[n];
        int val = 1e9+7;


        for (int i = 1; i - 1 < (int)sqrt(n); i++)
        {
            val = min(val, 1 + numSquaresSub(n - i * i, dp));
        }
        dp[n] = val;
        return dp[n];
    }
    int numSquares(int n)
    {
        vi dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return numSquaresSub(n, dp);
    }
};

int main()
{
    Solution s;
    int ans = s.numSquares(12);
    cout << ans << endl;
}