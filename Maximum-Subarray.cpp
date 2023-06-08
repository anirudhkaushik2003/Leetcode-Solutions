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
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vi dp(n, 0);
        int i = 0;
        dp[i] = nums[i];
        ++i;
        int max_so_far = dp[i - 1];
        for (; i < n; i++)
        {
            dp[i] = nums[i] + max(dp[i - 1], 0);
            max_so_far = max(max_so_far, dp[i]);
        }

        return max_so_far;
    }
};

int main()
{
    vi nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int ans = s.maxSubArray(nums);
    cout << ans << endl;
}