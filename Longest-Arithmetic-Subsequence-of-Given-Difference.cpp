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
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size();
        unordered_map<int, int> dp;
        int max_so_far = 1;
        for (auto it : arr)
        {
            dp[it] = dp.count(it - difference) ? dp[it - difference] + 1 : 1;
            max_so_far = max(max_so_far, dp[it]);
        }
        return max_so_far;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vi arr = {-10, 21, 3, 25, -8, -14, -18, 19, -11, 6, 11, -3, 1, 21, 11, -15, 1, 0, -14, 9, -20, 3, 27, -24, -12, -2, 23};
    int difference = -3;
    cout << sol.longestSubsequence(arr, difference) << endl;
    return 0;
}