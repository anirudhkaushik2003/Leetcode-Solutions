#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

class Solution {
public:

    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return {-1,-1};
        }
        int n = nums.size();
        int  l = 0, r = n - 1;

        while(l <r)
        {
            int mid =  (l+r) >>1 ;
            if(nums[mid] < target)
            {
                l = mid+1;

            }
            else
            {
                r = mid;
            }
        }

        if(nums[l] != target)
        {
            return {-1,-1};
        }
        vi ret(2);
        ret[0] = l;
        r= n-1;

        while(l < r)
        {
            int mid = ( (l+r) >>1) + 1;


            if(nums[mid] > target)
            {
                r = mid-1;
            }
            else
            {
                l = mid;
            }
        }
        if(nums[r] != target)
        {
            return {-1,-1};
        }
        ret[1] = r;
        return ret;

    }
};

int main()
{
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
}