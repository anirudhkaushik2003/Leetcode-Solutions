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
    int binarySearch(vector<pii> arr, int l, int r, int target)
    {
        int mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (arr[mid].first == target)
            {
                return mid;
            }
            if (arr[mid].first < target)
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
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size();
        map<int, vector<int>> m;
        vi dp(n, 1);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (m.find(arr[i]) == m.end())
            {
                m[arr[i]] = vi();
                m[arr[i]].push_back(i);
            }
            else
            {
                m[arr[i]].push_back(i);
            }
        }

        for(auto it :m)
        {
            sort(m[it.first].begin(), m[it.first].end());
        }
        int cur_max = 0;
        int cur, req, ind, cond, j;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                // cout << arr[i] << " ";
                visited[i] = true;
                cur = arr[i];
                req = arr[i] + difference;
                ind = i;
                // it = binarySearch(sorted, 0, n - 1, req);
                while (m.find(req) != m.end() )
                {
                    cur = req;
                    cond = 0;
                    for(auto it: m[req])
                    {
                        if(it > ind)
                        {
                            ind = it;
                            cond = 1;
                            break;
                        }
                    }
                    if(cond == 0)
                    {
                        break;
                    }
                    // cout << cur << " ";
                    // ind = sorted[it].second;
                    visited[ind] = true;
                    req = cur + difference;
                    dp[i]++;
                    // it = binarySearch(sorted, 0, n - 1, req);
                }
                // cout << endl;
                cur_max = max(cur_max, dp[i]);
            }
        }
        return cur_max;
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