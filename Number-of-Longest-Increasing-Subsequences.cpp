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
    int findNumberOfLIS(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> dp2(n, 0);
        map<int, int> m;

        int max_so_far = 1;
        m[1] = n;
        dp2[0] = 1;
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] == 1)
            {
                dp2[i] = 1;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i] && dp[j] + 1 == dp[i])
                    {
                        dp2[i] += dp2[j];
                    }
                }
                if (m.find(dp[i]) == m.end())
                {
                    m[dp[i]] = dp2[i];
                }
                else
                {
                    m[dp[i]] += dp2[i];
                }
            }

            // cout << dp[i] << " " << m[dp[i]] << endl;
            max_so_far = max(max_so_far, dp[i]);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dp2[i] << " ";
        // }
        // cout << endl;
        return m[max_so_far];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> nums = {1,2,4,3,5,4,7,2};
    cout << sol.findNumberOfLIS(nums) << endl;
    return 0;
}