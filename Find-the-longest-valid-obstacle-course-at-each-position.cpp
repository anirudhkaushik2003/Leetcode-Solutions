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
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        const int INF = 1e9;
        vector<int> d(n+1, INF);
        d[0] = -INF;
        vi ans(n, 1);
        for (int i = 0; i < n; i++) {
            int l = upper_bound(d.begin(), d.end(), obstacles[i]) - d.begin();
            if (d[l-1] <= obstacles[i] && obstacles[i] <= d[l])
                d[l] = obstacles[i];
            if(d[l-1] <= obstacles[i])
            {
                ans[i] = max(ans[i], l);
            }
        }

        return ans;
    }
};
