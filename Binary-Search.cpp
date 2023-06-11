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
        int r = nums.size() - 1;
        int l = 0;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};
