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
    bool canJump(vector<int> &nums)
    {
        int max_reachable = nums[0];
        int n = nums.size() - 1;
        if (max_reachable >= n)
            return true;

        for (int i = 0; i <= max_reachable; i++)
        {
            if (i + nums[i] > max_reachable)
                max_reachable = i + nums[i];
            if (max_reachable >= n)
                return true;
        }
        return false;
    }
};

int main()
{
    vi nums{3, 2, 1, 0, 4};
    Solution s;
    int ans = s.canJump(nums);
    cout << ans << endl;
}