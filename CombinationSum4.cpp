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
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (auto num : nums)
            {
                if (num > i)
                    break;

                dp[i] += dp[i - num];
            }
        }

        return dp[target];
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