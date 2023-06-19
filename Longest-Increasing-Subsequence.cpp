#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

# define INF 1e9
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vi dp(n+1, INF);
        dp[0] = -INF;

        for(int i = 0 ; i < n; i++)
        {
            int l = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(dp[l-1] < nums[i] && nums[i] < dp[l])
            {
                dp[l] = nums[i];
            }
        }

        int ans = 1;
        for(int i = n; i>=1;i--)
        {
            if(dp[i] < INF)
            {
                ans = i;
                break;
            }
        }

        return ans;        
    }
};

int main()
{
    vi nums = {10,9,2,5,3,7,101,18};
    Solution s;
    auto ans = s.lengthOfLIS(nums);
    cout << ans << endl;
}