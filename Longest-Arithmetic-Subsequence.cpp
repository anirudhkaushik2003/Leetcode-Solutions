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
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        int max_so_far = 0;
        int max_elem = 0;
        int min_elem = 501;
        int max_difference;
        for (int i = 0; i < n; i++)
        {
            max_elem = max(max_elem, nums[i]);
            min_elem = min(min_elem, nums[i]);
        }
        max_difference = max_elem - min_elem;

        for (int difference = -(max_difference); difference < (max_difference + 1); difference++)
        {
            unordered_map<int, int> dp;
            for (int i = 0; i < n; i++)
            {
                if (dp.count(nums[i] - difference) > 0)
                {
                    dp[nums[i]] = dp[nums[i] - difference] + 1;
                }
                else
                {
                    dp[nums[i]] = 1; // value with difference 0 if no other element with the same difference is present before it which has the same value;
                }
                max_so_far = max(max_so_far, dp[nums[i]]);
            }
        }
        return max_so_far;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vi arr = {5, 4, 3, 2, 1};
    cout << sol.longestArithSeqLength(arr) << endl;
    return 0;
}