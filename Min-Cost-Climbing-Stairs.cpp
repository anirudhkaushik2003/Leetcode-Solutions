#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
// dp[i] = mininmum cost to climb to the ith step
// dp[i] = curr cost + min(dp[i-1], ((i>1)>1 ? dp[i-2]: INT_MAX))
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        cost.insert(cost.begin(),0); // cost to reach the zeroth step is 0
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if(i > 1)
            {
                if(dp[i-1] + cost[i-1]< dp[i-2] + cost[i-2])
                {
                    dp[i] = cost[i-1] + dp[i-1];
                }
                else
                {
                    dp[i] = cost[i-2] + dp[i-2];
                }
            }
            else{
                dp[i] = cost[i-1] + dp[i-1];
            }
        }
        return dp[n]; // cost to climb to the nth step
    }
};

int main()
{
    vi cost = {10,15,20};
    
    Solution s;
    int ans = s.minCostClimbingStairs(cost);
    cout << ans << endl;
}