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

#define INF 1e9

bool sortcol(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }
    else
    {
        return a[0] < b[0];
    }
}
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), sortcol);
        int n = envelopes.size();
        vi dp(n + 1, INF);
        dp[0] = -INF;
        int l;
        for (int i = 0; i < n; i++)
        {
            l = upper_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            if(dp[l-1] < envelopes[i][1] && envelopes[i][1] < dp[l])
            {
                dp[l] = envelopes[i][1];
            }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << dp[i].first << " " << dp[i].second << " ";
        // }
        // cout << endl;
        for (int i = n; i > 0; i--)
        {
            if (dp[i] < INF)
            {
                return i;
            }
        }
        return 1;
    }
};

int main()
{
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution s;
    auto ans = s.maxEnvelopes(envelopes);
    cout << ans << endl;
}