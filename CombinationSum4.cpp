#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
// static auto _ = []()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return nullptr;
// }();

class Solution
{
public:
    int combinationSum4sub(vector<int> &nums, int target, vector<unsigned int> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (dp[target] != -1)
        {
            return dp[target];
        }
        int ans = 0;
        for (auto num : nums)
        {
            if ( target >= num)
                ans += combinationSum4sub(nums, target - num, dp);
        }
        dp[target] = ans;
        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, -1);
        dp[0] = 1;

        return combinationSum4sub(nums, target, dp);
    }
};

int main()
{
    Solution obj;
    vi nums = {1, 2, 3};
    int target = 4;
    cout << obj.combinationSum4(nums, target);
    return 0;
}