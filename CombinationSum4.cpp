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
    int combinationSum4sub(vector<int> &nums, int target, vi &dp)
    {
        if (dp[target] != 0)
        {
            return dp[target];
        }
        if (target == 0)
        {
            return 1;
        }

        for (auto num : nums)
        {
            if (num > target)
                break;
            dp[target] += combinationSum4sub(nums, target - num, dp);
        }
        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vi dp(target + 1, 0);
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