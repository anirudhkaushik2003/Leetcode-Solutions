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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vi nums_copy = nums;
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                return {m[target - nums[i]], i};
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return { -1, -1 };
    }
};

int main()
{
    Solution sol;
    vi nums = {2, 7, 11, 15};
    int target = 9;
    vi res = sol.twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}