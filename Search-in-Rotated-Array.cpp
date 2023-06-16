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
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0;
        int r = n - 1;
        int k = 0;
        int mid = (l + r) >> 1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (mid > 0 && nums[mid] < nums[mid - 1])
            {
                k = mid;
                break;
            }
            else if (nums[mid] >= nums[0]) // search in right half
            {
                l = mid + 1;
            }
            else // search in left half
            {
                r = mid - 1;
            }
            // cout <<  l << " " << r << endl;
        }
        // rotate(nums.begin(), nums.begin() + k, nums.end());
        l = 0;
        r = n - 1;
        if (nums[n - 1] >= target)
        {
            l = k;
        }
        else
        {
            r = k - 1;
        }

        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else // nums[mid] < target
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    vi nums = {3, 1};
    int target = 1;
    cout << s->search(nums, target) << endl;
}