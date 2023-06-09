#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

// dp i = money earned by robbing houses 0 to i
// dp i = dp[i-2] + reward[i] if i > 1
// else dpi = reward i

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp(n,0);
        int current_max = 0;
        for(int i = 0; i< n; i++)
        {
            if(i >1)
            {
                dp[i] = nums[i] + *max_element(dp.begin(), dp.begin() + i - 1);
            }
            else{
                dp[i] = nums[i];
            }
            if(dp[i] > current_max)
            {
                current_max = dp[i];
            }
        }
        return current_max;
    }
};

int main()
{
    vi nums {};
    Solution s;
    int ans = s.rob(nums);
    cout << ans << endl;
}