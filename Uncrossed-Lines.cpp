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
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        if (n < m)
        {
            swap(n, m);
            swap(nums1, nums2);
        }

        vi prev(n + 1, 0);
        vi cur(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[j-1] == nums2[i-1])
                {
                    cur[j] = prev[j - 1] + 1;
                }
                else
                    cur[j] = max(prev[j - 1], max(prev[j], cur[j - 1]));
            }
            prev = cur;
        }
        return cur[n];
    }
};