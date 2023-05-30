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
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        if(n==1) return;
        vector<int> dp = nums;
        int mid = (n+1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];

        for(int i = 0,  j =0, k=n-1 ;j<=k ;)
        {
            if(dp[j] < median)
            {
                swap(dp[i], dp[j]);
                i++;j++;
            }
            else if(dp[j] > median)
            {
                swap(dp[j], dp[k]);
                k--;
            }
            else
            {
                j++;
            }
        }
        for(int i = mid-1,j=0; i >=0, j < n; i--, j += 2) nums[j] = dp[i];
        for(int i =  n-1, j=1; i >= mid, j < n ; i--, j+= 2) nums[j] = dp[i];
    }
};
int main()
{
    // vi nums;
    // int k;
    Solution s;
    vi nums = {1,3,2,2,3,1};
    s.wiggleSort(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    // int ans = s.findKthLargest(nums, k);
    // cout << ans << endl;
}