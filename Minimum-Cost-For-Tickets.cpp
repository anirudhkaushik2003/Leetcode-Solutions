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
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vi dp(days[n - 1] + 1, 0);
        dp[days[0]] = min(costs[0], min(costs[1], costs[2]));
        int c1, c7, c30;
        // cout << "d: " << days[0] << " " << dp[days[0]] << endl;
        for (int i = 1; i < n; i++)
        {
            int d = days[i];
            c1 = dp[days[i - 1]] + costs[0];
            if (d - 7 < days[0])
            {
                c7 = costs[1];
            }
            else
            {
                auto it = upper_bound(days.begin(), days.end(), d - 7);
                it--;
                // cout << "it: " << *it << endl;
                c7 = dp[*it] + costs[1];
            }
            if (d - 30 < days[0])
            {
                c30 = costs[2];
            }
            else
            {
                auto it = upper_bound(days.begin(), days.end(), d - 30);
                it--;
                c30 = dp[*it] + costs[2];
            }
            dp[d] = min(c1, min(c7, c30));
            // cout << "d: " << d << " " << dp[d] << " " << c1 << " " << c7 << " " << c30 << endl;
        }
        return dp[days[n - 1]];
    }
};

int main()
{
    Solution s;
    vi days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vi costs = {2, 7, 15};
    int ans = s.mincostTickets(days, costs);
    cout << ans << endl;
}