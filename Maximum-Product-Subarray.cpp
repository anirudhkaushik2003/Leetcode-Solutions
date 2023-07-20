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
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        ll max_so_far = nums[0];
        ll min_so_far = nums[0];
        ll ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            ll temp = max_so_far;

            max_so_far = max(max(max_so_far * (ll)nums[i], min_so_far * (ll)nums[i]), (ll)nums[i]);
            min_so_far = min(min(temp * (ll)nums[i], min_so_far * (ll)nums[i]), (ll)nums[i]);
            if (max_so_far > ans)
            {
                ans = max_so_far;
            }
        }
        return ans;
    }
};

int main()
{
    vi nums = {-3, 0, 1, -2};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}