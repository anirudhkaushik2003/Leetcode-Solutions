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

        int max_so_far = 2;
        int difference;

        vector<vi> dp(n, vi(1001, 1));

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                difference = nums[i] - nums[j];
                // cout << difference   << " " << nums[i] << " " << nums[j] << endl;
                // cout << difference << endl;

                dp[i][500 + difference] = dp[j][500 + difference] + 1;

                max_so_far = max(max_so_far, dp[i][500 + difference]);
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
    vi arr = {20, 1, 15 ,3, 10, 5, 8};
    cout << sol.longestArithSeqLength(arr) << endl;
    return 0;
}