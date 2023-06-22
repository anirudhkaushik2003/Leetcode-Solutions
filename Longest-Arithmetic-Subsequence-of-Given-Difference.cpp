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
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        vi dp(n, 1);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (m.find(arr[i]) == m.end())
            {
                m[arr[i]] = priority_queue<int, vector<int>, greater<int>>();
                m[arr[i]].push(i);
            }
            else
            {
                m[arr[i]].push(i);
            }
        }
        int cur_max = 0;
        int cur, req, ind;

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
                priority_queue<int, vector<int>, greater<int>> pq = m[req];
                while (m.find(req) != m.end())
                {
                    pq = m[req];
                    cur = req;
                    while (!pq.empty() && pq.top() <= ind)
                    {
                        pq.pop();
                    }
                    if (pq.empty())
                    {
                        break;
                    }
                    ind = pq.top();
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