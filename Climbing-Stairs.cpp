#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
// dp[i] = number of ways to climb to ith step
// dp[i] = dp[i-1] + ((i>1)>1 ? dp[i-2]: 0)
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + ((i > 1) ? dp[i - 2] : 0);
        }
        return dp[n];
    }
};

int main()
{
    int n;
    
    Solution s;
    int ans = s.climbStairs(n);
    cout << ans << endl;
}